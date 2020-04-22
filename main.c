#include <stdlib.h>
#include <unistd.h>
#include "screen.h"
#include "utils.h"
#include "heat.h"

int main() {

	//initialize screen
	if(!screen_init()){
		screen_fini();
		error_exit((char*) "Error initializing curses", 2);
	}

	//get terminal values
	int xmax = screen_xmax();
	int ymax = screen_ymax();

	Heat *c = heat_new(xmax, ymax);

	if( !heat_add_source(c, 40, 30, 20, 10000) ){
		screen_fini();
		error_exit((char*) "Error adding heat source", 1);		
	}

	if( !heat_add_source(c, 100, 10, 29, 10000) ){
		screen_fini();
		error_exit((char*) "Error adding heat source", 1);		
	}

	if( !heat_add_source(c, 60, 10, 29, 10000) ){
		screen_fini();
		error_exit((char*) "Error adding heat source", 1);		
	}

	while( heat_jacobi(c) > 0.1 ){
		heat_colormap(c, 250);
		screen_draw_colormap(c->colormap);
		usleep(10000);
	}

	//wait to end
	screen_input();
	//end
	screen_fini();
}
