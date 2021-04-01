#include "constants.h"
#include <stdlib.h>

void updatePos(Bird *bird)
{
    bird->vy+=GRAVITY;
    bird->y+=bird->vy;

    if (bird->y >= HEIGHT - BIRD_HEIGHT)
    {
        bird->y = HEIGHT - BIRD_HEIGHT;
        bird->vy = 0;
    }

    if (bird->y < 0)
    {
        bird->y = 0;
        bird->vy = 0;
    }
}

void updatePipe(Pipe pipes[])
{
    for (int i = 0; i < 4; i++) 
    {
        pipes[i].x -= PIPE_SPEED;      
    }
}
