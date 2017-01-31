#ifndef CHANGEBOARD_H
#define CHANGEBOARD_H
#include "struct.h"

void add(struct Board* main, char type, int point);
void Delete(struct Board* main, char type, int point);
void resize(struct Board* main, int num_rows, int num_cols);
#endif