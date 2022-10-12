#include "libgol.h"

void    mousePress(SDL_MouseButtonEvent b, SDL_Renderer *renderer, int **map)
{
    int xMouse;
    int yMouse;

    SDL_GetMouseState(&xMouse, &yMouse);
    if (b.button == SDL_BUTTON_LEFT)
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        map[yMouse / 10][xMouse / 10] = 1;
    }
    else if (b.button == SDL_BUTTON_RIGHT)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        map[yMouse / 10][xMouse / 10] = 0;
    }
    SDL_Rect cell = {
        .x = (xMouse) / 10 * 10,
        .y = (yMouse) / 10 * 10,
        .w = 10,
        .h = 10,
    };
    SDL_RenderFillRect(renderer, &cell);
    SDL_RenderPresent(renderer);
}

char    keyPress(SDL_KeyboardEvent k)
{
    if (k.keysym.sym == SDLK_n)
        return ('n');
    else if (k.keysym.sym == SDLK_q)
        return ('q');
    else if (k.keysym.sym == SDLK_c)
        return ('c');
}