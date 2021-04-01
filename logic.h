#ifndef LOGIC_H
#define LOGIC_H

#include "constants.h"

void updatePos(Bird *);
void updatePipe(Pipe[], int *);
int gameOver(Bird, Pipe[]);

#endif
