#ifndef __HEAT_H_
#define __HEAT_H_
#include "utils.h"
#include <stdlib.h>

//Struct representing heat diffusion algorithm
typedef struct {
	int xmax;
	int ymax;
	double *t;
	double *ttemp;

	//for colors
	int *colormap;
	double tmax;
} Heat;

//Initializes a new heat diffusion algorithm
Heat* heat_new(int x, int y);

//Adds a heat source at (x,y) of radium r and temp T
//Returns 1 on sucess 0 otherwise
int heat_add_source(Heat* h, int x, int y, int r, double T);

//Computes jacobi intt ttemp, swaps t and ttmemp pointers.
//Returns residual value
double heat_jacobi(Heat* h);

//Computes a color heatmap based on temperatures and n colors.
void heat_colormap(Heat* h, int ncolors);

#endif
