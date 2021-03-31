#include "constants.h"
#include <stdlib.h>

void updatePos(Bird *bird)
{
    bird->vy+=GRAVITY;
    bird->y+=bird->vy;

    if (bird->y >= HEIGHT - bird->height) 
    {
        bird->y = HEIGHT - bird->height;
        bird->vy = 0;
    }

    if (bird->y < 0)
    {
        bird->y = 0;
        bird->vy = 0;
    }
}
