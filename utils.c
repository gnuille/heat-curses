#include "utils.h"

int in_boundary(int x, int y, int xmax, int ymax){
	return ( x < 0 || y < 0 || x >= xmax || y >= ymax) ? 0 : 1;
}

void error_exit(char *msg, int c){
	printf("%s\n", msg);
	exit(c);
}
