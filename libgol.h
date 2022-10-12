#ifndef LIBGOL_H
# define LIBGOL_H

# include <SDL.h>

void    mousePress(SDL_MouseButtonEvent b, SDL_Renderer *renderer, int **map);
void    make_next_map(int **current_map, int **next_map, int width, int height);
void    mapcpy(int **mapdest, int **mapsrc, int width, int height);
void    free_map(int **map, int height);
void    clear_map(int **map, SDL_Renderer *renderer, int width, int height);
char    keyPress(SDL_KeyboardEvent k);
int     cell_next_state(int **current_map, int x, int y, int neighbours);
int     **init_map(int x, int y);

#endif