#ifndef __SCREEN_H_
#define __SCREEN_H_
#include <ncurses.h>

//Initializes screen environment
//returns 1 on success 0 otherwise
int screen_init();

//Finalizes screen environment
void screen_fini();

//Draws pixel at (x,y) with color
int screen_draw_cell(int color, int x, int y);

//Draws whole screen
void screen_draw_colormap(int *color);

//Returns ncurses LINES
int screen_xmax();

//Returns ncurses COLS
int screen_ymax();

//Testing purposes only
void screen_input();

#endif
