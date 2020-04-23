#ifndef __UTILS_H_
#define __UTILS_H_
#include <stdlib.h>
#include <stdio.h>

//return min a b
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
//return max a b
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

//Returns 1 if in boundary 0 otherwise
int in_boundary( int x, int y, int xmax, int ymax);

//Prints error and exits
void error_exit( char *msg, int c);

#endif
