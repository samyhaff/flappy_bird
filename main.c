#include <SDL2/SDL.h>
#include "constants.h"
#include "draw.h"
#include "input.h"
#include "logic.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("DVD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Bird bird = {WIDTH / 4, HEIGHT / 2, 0};

    Pipe pipes[5];
    for (int i = 0; i < 4; i++)
    {
        pipes[i].x = WIDTH + (i * SPACING);
        pipes[i].y = rand() % (HEIGHT - GAP);
    }

    int done = 0;
    SDL_Event event;

    while (!done)
    {
        updatePos(&bird);
        updatePipe(pipes);
        render(renderer, bird, pipes);
        done = processInput(&event, &bird) || gameOver(bird, pipes);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();

    return 0;
}
