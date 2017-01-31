/*
* This program reads in the values and sets the board for initial sequence
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "struct.h"

void readInput(int argc, char *argv[], struct Board* board);
void setBoard(struct Board* mainBoard);
char readCommand();

/*
* This function reads in the commands
*/
char readCommand() {
	char c;
	printf("Enter your command: ");
	scanf("%c", &c);
	
	return c;
}

/*
* This function reads in command line inputs
*/
void readInput(int argc, char *argv[], struct Board* board) {
	int row;
	int col;
	int i;

	row = 0;
	col = 0;

	if(argc == 1) { // if basic board
		row = 10;
		col = 10;
	}
	else if(argc == 3) {
		for(i = 0; i < strlen(argv[1]); i++) { // sets first input to row
			if(argv[1][i] == '-') { // if negative
				printf("The number of rows is less than 1.\n");
				row = 10;
				col = 10;
				printf("Making default board of %d X %d.\n", row, col);
				board->row = row;
				board->col = col;
				return;
			}
			if(!isdigit(argv[1][i])) { // if not a digit
				printf("The number of rows is not an integer.\n");
				row = 10;
				col = 10;
				board->row = row;
				board->col = col;
				printf("Making default board of %d X %d.\n", row, col);
				return;
			}
			row+= (argv[1][i] - '0') * pow(10, (strlen(argv[1]) - i - 1));
		}
		for(i = 0; i < strlen(argv[2]); i++) { // sets second input to column
			if(argv[2][i] == '-') { // if negative
				printf("The number of columns is less than 1.\n");
				row = 10;
				col = 10;
				printf("Making default board of %d X %d.\n", row, col);
				board->row = row;
				board->col = col;
				return;
			}

			if(!isdigit(argv[2][i])) { // if not a digit
				printf("The number of columns is not an integer.\n");
				row = 10;
				col = 10;
				printf("Making default board of %d X %d.\n", row, col);
				board->row = row;
				board->col = col;
				return;
			}
			col+= (argv[2][i] - '0') * pow(10, (strlen(argv[2]) - i - 1));
		}
		if(row < 1){ // if row is 0 or negative
			printf("The number of rows is less than 1.\n");
			row = 10;
			col = 10;
			printf("Making default board of %d X %d.\n", row, col);
		}
		if(col < 1) { // if column is 0 or negative 
			printf("The number of columns is less than 1.\n");
			row = 10;
			col = 10;
			printf("Making default board of %d X %d.\n", row, col);
		}
	}
	else { // if inputted wrong
		printf("Wrong number of command line arguements entered.\n");
		printf("Usage: ./paint.out [num_rows num_cols]\n");
		row = 10;
		col = 10;
		printf("Making default board of %d X %d.\n", row, col);
	}
	
	board->row = row; // sets board row to row
	board->col = col; // sets board column to column
}

/*
* This function sets the board initially
*/
void setBoard(struct Board* mainBoard) {
	int i;
	int j;

	mainBoard->board = (char**)malloc(sizeof(char*) * mainBoard->row); // makes memory 
	for(i = 0; i < mainBoard->row; i++) {
		mainBoard->board[i] = (char*)malloc(sizeof(char) * mainBoard->col); // makes memory
		for(j = 0; j < mainBoard->col; j++) {
			mainBoard->board[i][j] = '*'; // sets whole board to '*'s
		}
	}

}