/*
* This program prints the board out
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct.h"

/*
* Function prints the board
*/
void printBoard(struct Board main) {
	int i; // row
	int j; // col
	for(i = 0; i < main.row; i++) {
		if(main.row - i - 1 < 10) {
			printf(" ");
		}
		printf("%d", main.row - i - 1); // prints out # of row
		for(j = 0; j < main.col; j++) {
			printf("  %c", main.board[i][j]); // prints out [row][col]
		}
		printf("\n");
	}
	printf("  ");
	for(j = 0; j < main.col; j++) {
		if(j < 10) {
			printf(" ");
		}
		printf(" %d", j); //prints out # of col
	}
	printf("\n");
}
