#include "libgol.h"

void    free_map(int **map, int height)
{
    while (0 <= height - 1)
    {
        free(map[height - 1]);
        height--;
    }
    free(map);
}