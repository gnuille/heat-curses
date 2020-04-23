#include "settings.h"


Settings* parse_args(int argc, char **argv){
	Settings* s = malloc(sizeof(Settings));
	s->nSources = 0;
	s->xmax=screen_xmax();
	s->ymax=screen_ymax();
	s->udelay=0;
	int aux;
	while( (aux = getopt(argc, argv, "t:m:")) != -1){
		switch(aux){
			case 't':
				s->udelay=atof(optarg);
				break;
			case 'm':
				if (strcmp(optarg, "center") == 0){
					s->heatSources = realloc(s->heatSources, sizeof(HeatSource*)*(s->nSources+1)); 

					int radium = min(s->xmax, s->ymax)/3;

					s->heatSources[s->nSources] = heat_new_heatsource(((int) (s->xmax/2))-radium/2, ((int) s->ymax/2)-radium/2, radium, 500);
					s->nSources++;

				}else{
					error_exit("Error mode not recognized", 2);
				}
				break;
			case '?':
				error_exit("Error option not recognized", 2);
		}
	}

	return s;

}
