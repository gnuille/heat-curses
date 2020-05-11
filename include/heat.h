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

typedef struct {
	int x;
	int y;
	int r;
	double T;
} HeatSource;

//Initializes a new heat diffusion algorithm
Heat* heat_new(int x, int y);

//Adds a heat source at (x,y) of radium r and temp T
//Returns 1 on sucess 0 otherwise
int heat_add_source(Heat* h, int x, int y, int r, double T);

//Initializes a new heat source structure
HeatSource* heat_new_heatsource(int x, int y, int r, double T);

//Adds a heat source denoted by s and frees s
//Returns 1 on sucess 0 otherwise
int heat_add_heatsource(Heat* h, HeatSource* s);

//Computes jacobi intt ttemp, swaps t and ttmemp pointers.
//Returns residual value
double heat_jacobi(Heat* h);

//Computes a color heatmap based on temperatures and n colors.
void heat_colormap(Heat* h, int ncolors);

#endif
