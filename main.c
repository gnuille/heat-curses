#include <settings.h>
#include <stdlib.h>
#include <unistd.h>
#include <screen.h>
#include <utils.h>
#include <heat.h>


int main(int argc, char **argv) {

	
	//initialize screen
	if(!screen_init()){
		screen_fini();
		error_exit((char*) "Error initializing curses", 2);
	}

	
	//settings
	Settings *s = parse_args(argc, argv);

	Heat *c = heat_new(s->xmax, s->ymax);
	
	for(int i = 0; i < s->nSources; i++){
		if( !heat_add_heatsource(c, s->heatSources[i])){
			screen_fini();
			error_exit((char *) "Error adding Heat Source",2);
		}
	}

	while( heat_jacobi(c) > s->residual){
		heat_colormap(c, 250);
		screen_draw_colormap(c->colormap);
		usleep(s->udelay);
	}

	//wait to end
	screen_input();
	//end
	screen_fini();
}
