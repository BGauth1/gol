#include "libgol.h"

int    **init_map(int x, int y)
{
    int i;
    int j;
    int **map;

    i = 0;
    j = 0;
    printf("%d\n", x);
    printf("%d\n", y);
    map = malloc(y * sizeof(int *));
    while (i < y)
    {
        map[i] = malloc(x * sizeof(int));
        j = 0;
        while (j < x)
        {
            map[i][j] = 0;
            j++;
        }
        i++;
    }
    return (map);
}

void    make_next_map(int **current_map, int **next_map, int width, int height)
{
    int i;
    int j;
    int k;
    int l;
    int neighbours;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            neighbours = 0;
            k = -1;
            while (k < 2)
            {
                l = -1;
                while (l < 2)
                {
                    if ((k != 0 || l != 0) && k + i >= 0 && k + i < height && l + j >= 0 && l + j < width)
                        if (current_map[k + i][l + j] == 1)
                            neighbours++;
                    l++;
                }
                k++;
            }
            next_map[i][j] = cell_next_state(current_map, j, i, neighbours);
            j++;
        }
        i++;
    }
}

int cell_next_state(int **current_map, int x, int y, int neighbours)
{
    if (current_map[y][x] == 1 && (neighbours == 2 || neighbours == 3))
        return (1);
    if (current_map[y][x] == 0 && neighbours == 3)
        return (1);
    return (0);
}

void    mapcpy(int **mapdest, int **mapsrc, int width, int height)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            mapdest[i][j] = mapsrc[i][j];
            j++;
        }
        i++;
    }
}

void    clear_map(int **map, SDL_Renderer *renderer, int width, int height)
{
    int i;
    int j;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect cell = {
        .x = 0,
        .y = 0,
        .w = width * 10,
        .h = height * 10,
    };
    SDL_RenderFillRect(renderer, &cell);
    SDL_RenderPresent(renderer);
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            map[i][j] = 0;
            j++;
        }
        i++;
    }
}