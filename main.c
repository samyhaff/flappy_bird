#include <SDL2/SDL.h>
#include "constants.h"
#include "draw.h"
#include "input.h"
#include "logic.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("DVD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Bird bird = {WIDTH / 3, HEIGHT / 2, 0, HEIGHT / 20, HEIGHT / 20};

    int done = 0;
    SDL_Event event;

    while (!done)
    {
        updatePos(&bird);
        render(renderer, bird);
        done = processInput(&event, &bird);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();

    return 0;
}
