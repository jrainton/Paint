/*
* The purpose of this function it fo find the right direction and set the board appropriately
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct.h"

int getDirection(int row_start, int col_start, int row_end, int col_end);


/*
* This function gets the direction
*/
int getDirection(int row_start, int col_start, int row_end, int col_end) {
	if(row_start == row_end && col_start > col_end) { // horizontal right
		return 0;
	}
	else if(row_start == row_end && col_end > col_start) { // horizontal left
		return 1;
	}

	else if(col_start == col_end && row_start > row_end) { // vertical up
		return 2;
	}

	else if(col_start == col_end && row_end > row_start) { // vertical down
		return 3;
	}

	else if(row_end > row_start && col_end > col_start && (row_end - row_start == col_end - col_start)) { // right diagonal down
		return 4;
	}
	
	else if(row_end < row_start && col_end < col_start && (row_start - row_end == col_start - col_end)) { // right diagonal up
		return 5;
	}

	else if(row_start > row_end && col_start < col_end && (row_start - row_end == col_end - col_start)) { // left diagonal up
		return 6;
	}

	else if(row_start < row_end && col_start > col_end && (row_end - row_start == col_start - col_end)) { // left diagonal down
		return 7;
	}
	else if(row_start == row_end && col_start == col_end) { // same position
		return 8;
	}
	else {
		return 9;
	}

}

/*
* The funtion changes the board based on the start and end points, and gets the right character for the direction
*/
void changeBoard(int input, struct Board* main, int row_start, int col_start, int row_end, int col_end) {
	int i;
	if(input == 9) { // if no input
		printf("Cannot draw the line as it is not straight.\n");
	}
	else if(input == 0) { // horizontal left
		for(i = 0; i < (col_start - col_end + 1); i++) {
			if(main->board[row_start][col_start - i] == '-' || main->board[row_start][col_start - i] == '*') {
				main->board[row_start][col_start - i] = '-';
			}
			else {
				main->board[row_start][col_start - i] = '+';
			}
		}
	}

	else if(input == 1) { // horizontal right
		for(i = 0; i < (col_end - col_start + 1); i++) {
			if(main->board[row_start][col_start + i] == '-' || main->board[row_start][col_start + i] == '*') {
				main->board[row_start][col_start + i] = '-';
			}
			else {
				main->board[row_start][col_start + i] = '+';
			}
		}

	}

	else if(input == 2) { // vertical up
		for(i = 0; i < (row_start - row_end + 1); i++) {
			if(main->board[row_start - i][col_start] == '|' || main->board[row_start - i][col_start] == '*') {
				main->board[row_start - i][col_start] = '|';
			}
			else {
				main->board[row_start - i][col_start] = '+';
			}
		}

	}

	else if(input == 3) { // vertical down
		for(i = 0; i < (row_end - row_start + 1); i++) {
			if(main->board[row_start + i][col_start] == '|' || main->board[row_start + i][col_start] == '*') {
				main->board[row_start + i][col_start] = '|';
			}
			else {
				main->board[row_start + i][col_start] = '+';
			}
		}

	}

	else if(input == 4) { // right diagonal down
		for(i = 0; i < (col_end - col_start + 1); i++) {
			if(main->board[row_start + i][col_start + i] == '\\' || main->board[row_start + i][col_start + i] == '*') {
				main->board[row_start + i][col_start + i] = '\\';
			}
			else {
				main->board[row_start + i][col_start + i] = '+';
			}
		}

	}

	else if(input == 5) { // right diagonal up
		for(i = 0; i < (col_start - col_end + 1); i++) {
			if(main->board[row_start - i][col_start - i] == '\\' || main->board[row_start - i][col_start - i] == '*') {
				main->board[row_start - i][col_start - i] = '\\';
			}
			else {
				main->board[row_start - i][col_start - i] = '+';
			}
		}

	}

	else if(input == 6) { // left diagonal 
		for(i = 0; i < (col_end - col_start + 1); i++) {
			if(main->board[row_start - i][col_start + i] == '/' || main->board[row_start - i][col_start + i] == '*') {
				main->board[row_start - i][col_start + i] = '/';
			}
			else {
				main->board[row_start - i][col_start + i] = '+';
			}
		}

	}

	else if(input == 7) { // left diagonal down
		for(i = 0; i < (col_start - col_end + 1); i++) {
			if(main->board[row_start + i][col_start - i] == '/' || main->board[row_start + i][col_start - i] == '*') {
				main->board[row_start + i][col_start - i] = '/';
			}
			else {
				main->board[row_start + i][col_start - i] = '+';
			}
		}

	}
	else if(input == 8) { // same position
		main->board[row_start][col_start] = '-';
	}

}

