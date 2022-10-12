#include <stdio.h>
#include "libgol.h"

void    draw_next_map(int **current_map, int **next_map, SDL_Renderer *renderer, int width, int height)
{
    int i;
    int j;

    SDL_Rect cell = {
        .x = 0,
        .y = 0,
        .w = 10,
        .h = 10,
    };
    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            if (current_map[i][j] != next_map[i][j])
            {
                if (next_map[i][j] == 1)
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                else
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                cell.x = j * 10;
                cell.y = i * 10;
                SDL_RenderFillRect(renderer, &cell);
            }
            j++;
        }
        i++;
    }
    SDL_RenderPresent(renderer);
}

int main(int ac, char **av)
{
    SDL_Window      *window;
    SDL_Renderer    *renderer;
    SDL_Event       event;
    int             **current_map;
    int             **next_map;
    int             width;
    int             height;

    if (SDL_Init(SDL_INIT_VIDEO))
    {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    if (ac > 2)
    {
        width = atoi(av[1]) / 10 * 10;
        height = atoi(av[2]) / 10 * 10;
    }
    else
    {
        width = 640;
        height = 480;
    }
    window = SDL_CreateWindow("GameOfLife", 0, 0, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    current_map = init_map(width / 10, height / 10);
    next_map = init_map(width / 10, height / 10);

    while (SDL_WaitEvent(&event))
    {
        if (event.type == SDL_QUIT)
            break;
        else if (event.type == SDL_MOUSEBUTTONDOWN)
            mousePress(event.button, renderer, current_map);
        else if (event.type == SDL_KEYDOWN)
            if (keyPress(event.key) == 'n')
            {
                make_next_map(current_map, next_map, width / 10, height / 10);
                draw_next_map(current_map, next_map, renderer, width / 10, height / 10);
                mapcpy(current_map, next_map, width / 10, height / 10);
            }
            else if (keyPress(event.key) == 'q')
                break;
            else if (keyPress(event.key) == 'c')
                clear_map(current_map, renderer, width / 10, height / 10);
    }
    free_map(current_map, height / 10);
    free_map(next_map, height / 10);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}