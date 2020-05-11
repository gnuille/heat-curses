#ifndef __SETTINGS_H_
#define __SETTINGS_H_
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "utils.h"
#include "heat.h"

typedef struct {
	double udelay;
	HeatSource **heatSources;
	int nSources;
	double residual;
	int xmax;
	int ymax;
} Settings;

//parse arguments and returns a settings struct 
Settings* parse_args(int argc, char **argv);

#endif

