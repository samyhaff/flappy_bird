#include "SDL2/SDL.h"
#include "constants.h"

void render(SDL_Renderer *renderer, Bird bird)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect rect = {bird.x, bird.y, bird.width, bird.height};
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

