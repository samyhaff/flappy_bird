#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>

#define WIDTH  1920
#define HEIGHT 1080

#define GRAVITY 1
#define FLAPP  17
#define BIRD_WIDTH  HEIGHT / 10
#define BIRD_HEIGHT HEIGHT / 10

#define SPACING     500 
#define GAP         300
#define PIPE_WIDTH  150
#define PIPE_SPEED    5

typedef struct Bird Bird;
struct Bird 
{
    int x, y, vy;
    SDL_Texture *texture;
    SDL_Surface *surface;
};

typedef struct Pipe Pipe;
struct Pipe 
{
    int x, y;
};

#endif
