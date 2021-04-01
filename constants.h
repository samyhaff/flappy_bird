#ifndef CONSTANTS_H
#define CONSTANTS_H

#define WIDTH  1920
#define HEIGHT 1080

#define GRAVITY 1
#define FLAPP  17
#define BIRD_WIDTH  HEIGHT / 15
#define BIRD_HEIGHT HEIGHT / 15

#define SPACING     500 
#define GAP         300
#define PIPE_WIDTH  200
#define PIPE_SPEED    5

typedef struct Bird Bird;
struct Bird 
{
    int x, y, vy;
};

typedef struct Pipe Pipe;
struct Pipe 
{
    int x, y;
    int width;
};

#endif
