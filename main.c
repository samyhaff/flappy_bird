#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "constants.h"
#include "draw.h"
#include "input.h"
#include "logic.h"
#include "stdlib.h"

// TODO textures
// TODO sound effects
// TODO score
// TODO animations
// TODO game over page 

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("DVD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    

    Bird bird = {WIDTH / 4, HEIGHT / 2, 0, NULL, NULL};
    int score = 0;

    bird.surface = IMG_Load("bird.png");
    bird.texture = SDL_CreateTextureFromSurface(renderer, bird.surface);
    SDL_FreeSurface(bird.surface);

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
        updatePipe(pipes, &score);
        render(renderer, bird, pipes);
        done = processInput(&event, &bird) || gameOver(bird, pipes);
    }

    SDL_DestroyTexture(bird.texture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();

    return 0;
}
