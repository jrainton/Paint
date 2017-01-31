/*
* This program runs all the programs together
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "read.h"
#include "board.h"
#include "commands.h"
#include "loop.h"

// runs program
int main(int argc, char *argv[]) {
	char command;
	struct Board mainBoard;
	readInput(argc, argv, &mainBoard); // reads inputs
	setBoard(&mainBoard); // sets inputs
	printBoard(mainBoard); // prints boards
	command = 'p';
	loop(command, mainBoard); // loops program

	return 0;
}