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
    for (int i = 0; i < 5; i++) 
    {
        if ((pipes[i].x < 0) && (i != 4))
        {
            pipes[4].x = pipes[i].x;
            pipes[4].y = pipes[i].y;
            pipes[i].x = WIDTH;
            pipes[i].y = rand() % (HEIGHT - GAP);    
        }
        pipes[i].x -= PIPE_SPEED;      
    }
}
