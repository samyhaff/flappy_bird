#include "SDL2/SDL.h"
#include "constants.h"

void render(SDL_Renderer *renderer, Bird bird, Pipe pipes[])
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /* SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); */
    SDL_Rect bird_rect = {bird.x, bird.y, BIRD_WIDTH, BIRD_HEIGHT};
    /* SDL_RenderFillRect(renderer, &bird_rect); */
    SDL_RenderCopy(renderer, bird.texture, NULL, &bird_rect);

    for (int i = 0; i < 5; i++)
    {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_Rect pipe_top_rect = {pipes[i].x, 0, PIPE_WIDTH, pipes[i].y};
        SDL_RenderFillRect(renderer, &pipe_top_rect);
        SDL_Rect pipe_bottom_rect = {pipes[i].x, pipes[i].y + GAP, PIPE_WIDTH, HEIGHT};
        SDL_RenderFillRect(renderer, &pipe_bottom_rect);
    }

    SDL_RenderPresent(renderer);
}

