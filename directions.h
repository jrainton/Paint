#ifndef DIRECTIONS_H
#define DIRECTIONS_H
#include "struct.h"

int getDirection(int row_start, int col_start, int row_end, int col_end);
void changeBoard(int input, struct Board* main, int row_start, int col_start, int row_end, int col_end);

#endif