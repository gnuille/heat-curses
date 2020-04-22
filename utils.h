#ifndef __UTILS_H_
#define __UTILS_H_
#include <stdlib.h>
#include <stdio.h>

//Returns 1 if in boundary 0 otherwise
int in_boundary( int x, int y, int xmax, int ymax);

//Prints error and exits
void error_exit( char *msg, int c);

#endif
