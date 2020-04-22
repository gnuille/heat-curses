#include "screen.h"

int screen_init(){
	initscr();

	//initalize colorspace
	if (has_colors() == FALSE){
		endwin();
		return 0;
	}

	start_color();

	int cnt = 1;
	//Blue to Green transition
	for(int i=1; i < 1001; i+=8){
		init_color(cnt, 0, i, 1000-i);
		cnt++;
	}

	//Green to Red transition
	for(int i=1; i < 1001; i+=8){
		init_color(cnt, i, 1000-i, 0);
		cnt++;
	}

	//init colorpairs
	for(int i=1; i <= cnt; i++){
		init_pair(i, i, i);		
	}

	cbreak();
	noecho();
	clear();

	return 1;
}

void screen_fini(){
	endwin();
}

int screen_draw_cell(int color, int x, int y){
	if (x >= screen_xmax()) return 0;
	if (y >= screen_ymax()) return 0;
	
	attron(COLOR_PAIR(color));
	mvaddch(y, x, '.');
	refresh();

	return 1;
}


void screen_draw_colormap(int *color){
	int xmax = screen_xmax();
	int ymax = screen_ymax();

	for (int i=0; i<xmax; i++){
		for(int j=0; j<ymax; j++){
			attron(COLOR_PAIR(color[i*ymax+j]));
			mvaddch(j, i, '.');
		}
	}

	refresh();
}

int screen_xmax(){
	return getmaxx(stdscr);
}

int screen_ymax(){
	return getmaxy(stdscr);
}

void screen_input(){
	getch();
}
