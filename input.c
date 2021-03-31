#include <SDL2/SDL.h>
#include "constants.h"

int processInput(SDL_Event *eventPtr, Bird *bird) 
{
    while (SDL_PollEvent(eventPtr)) 
    {
        switch (eventPtr->type) 
        {
            case SDL_QUIT:
                return 1;
            break;
            case SDL_KEYDOWN:
            {
                switch (eventPtr->key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        return 1;
                    break;
                    case SDLK_SPACE:
                        bird->vy = -FLAPP;
                    break;
                }
            }
        }
    }
    return 0;
}
