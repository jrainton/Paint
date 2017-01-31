#ifndef READ_H
#define READ_H
#include "struct.h"

void readInput(int argc, char *argv[], struct Board* board);
void setBoard(struct Board* mainBoard);
char readCommand();

#endif