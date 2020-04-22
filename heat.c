#include "heat.h"

Heat* heat_new(int x, int y){
	Heat* n = (Heat*) malloc(sizeof(Heat));
	n->xmax = x;
	n->ymax = y;

	n->t = (double*) calloc(x*y, sizeof(double));
	n->ttemp = (double*) malloc(sizeof(double)*x*y);

	n->colormap = (int*) malloc(sizeof(double)*x*y);
	n->tmax = 0;

	return n;
}

int heat_add_source(Heat* h, int x, int y, int r, double T){
	if ( !in_boundary(x+r,y+r, h->xmax, h->ymax) ){
		return 0;
	}

	for(int i=x; i<x+r; i++){
		for(int j=y; j<y+r; j++){
			h->t[i*h->ymax+j]=T;
		}
	}

	if(T > h->tmax) h->tmax = T;

	return 1;
}

double heat_jacobi(Heat* h){
	
	//compute
	double res=0;
	double diff;
	for(int i=1; i < h->xmax -1; i++){
		for(int j=1; j < h->ymax -1; j++){
			h->ttemp[i*h->ymax+j] = 0.25*( h->t[i*h->ymax + j-1] + 
					     	       h->t[(i-1)*h->ymax + j] +
						       h->t[(i+1)*h->ymax + j] +
						       h->t[i*h->ymax+j+1]);
			diff = (h->ttemp[i*h->ymax +j]-h->t[i*h->ymax+j]);
			res+=diff*diff;
		}
	}

	//pointer swap
	double *aux = h->t;
	h->t=h->ttemp;
	h->ttemp=aux;

	return res;
}

void heat_colormap(Heat* h, int ncolors){
	double step = h->tmax / ncolors;

	for(int i=0; i < h->xmax; i++){
		for(int j=0; j < h->ymax; j++){
			//compute color
			h->colormap[i*h->ymax+j] = ((int) (h->t[i*h->ymax+j]/step));

			//assert valid color
			if (h->colormap[i*h->ymax+j] < 1) h->colormap[i*h->ymax+j]=1;
			if (h->colormap[i*h->ymax+j] > 250) h->colormap[i*h->ymax+j]=250;
		}
	}
}

