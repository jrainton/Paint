#ifndef COMMANDS_H
#define COMMANDS_H
#include "struct.h"

void commandHelp();
void commandWrite(struct Board* main);
void commandAdd(struct Board* main);
void commandDelete(struct Board* main);
void commandResize(struct Board* main);
void commandErase(struct Board* main);
void commandSave(struct Board* main);
void commandLoad(struct Board* main);

#endif