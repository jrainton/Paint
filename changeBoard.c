/*
* This programs purpose is to add, delete, or resize the board to the desired settings
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "struct.h"

/*
* This function adds rows or columns to the board
*/
void add(struct Board* main, char type, int point) {
	 int i;
	 int j;
	 if(type == 'r') { // if user wants to add rows
	 	main->row = main->row + 1; // increase total rows by 1
	 	point = main->row - point - 1; // sets point to desired location
	 	main->board = (char**)realloc(main->board, sizeof(char*) * main->row); // resize 
	 	main->board[main->row - 1] = (char*)malloc(sizeof(char) * main->col); // make memory for new location
	 	for(i = main->row - 1; i > point; i--) {
	 		for(j = 0; j < main->col; j++) {
	 			main->board[i][j] = main->board[i - 1][j]; // moves all numbers down by 1 till loop reaches point
	 		}
	 	}
	 	for(j = 0; j < main->col; j++) {
	 		main->board[point][j] = '*'; // sets the desired row to '*'s
	 	}
	 }
	 
	 if(type == 'c') { // if user wants to add columns
	 	main->col = main->col + 1; // increase total columns by 1
	 	for(i = 0; i < main->row; i++) {
	 		main->board[i] = (char*)realloc(main->board[i], sizeof(char) * main->col); // resize
	 		for(j = main->col - 1; j > point - 1; j--) {
	 			main->board[i][j] = main->board[i][j - 1]; // moves all numbers right by 1 till loop reaches point
	 		}
	 	}
	 	for(i = 0; i < main->row; i++) { // sets the desired column to '*'s
	 		main->board[i][point] = '*';
	 	}
	 }
}

/*
* This function deletes rows or columns
*/
void Delete(struct Board* main, char type, int point) {
	int i;
	int j;

	if(type == 'r') { // if user wants to delete a row
	 	point = main->row - point - 1; // gets right point
	 	for(i = point; i < main->row - 1; i++) {
	 		for(j = 0; j < main->col; j++) {
	 			main->board[i][j] = main->board[i + 1][j]; // moves board up by 1 starting from desired point
	 		}
	 	}
	 		free(main->board[main->row - 1]); // removes last row
	 	main->row = main->row - 1; // removes 1 from total number of rows
	 }

	 if(type == 'c') { // if user wants to delete a column
	 	for(i = 0; i < main->row; i++) {
	 		for(j = point; j < main->col - 1; j++) {
	 			main->board[i][j] = main->board[i][j + 1]; // moves board left by 1 starting from desired point
	 		}
	 	}
	 		for(i = 0; i < main->row; i++){
	 			main->board[i] = (char*)realloc(main->board[i], sizeof(char) * (main->col - 1)); // removes the column
	 		}
	 	main->col = main->col - 1; // removes 1 from the total number of columns
	 }
}

/*
* The function resizes the board by x rows and y columns
*/
void resize(struct Board* main, int num_rows, int num_cols) {
	struct Board holder;
	holder.row = num_rows;
	holder.col = num_cols;

	int i;
	int j;

	if(main->row - num_rows  >= 0) { // if the desired rows is smaller than the original rows
		holder.board = (char**)malloc(sizeof(char*) * holder.row);  // memory for new array
		for(i = 0; i < holder.row; i++) {
			holder.board[i] = (char*)malloc(sizeof(char) * holder.col); // memory for new array
			for(j = 0; j < holder.col; j++) {
				if(j < main->col) { // prints out board[rows][cols]
					holder.board[i][j] = main->board[main->row - num_rows + i][j];
				}
				else { // if desired columns is greater than original columns
					holder.board[i][j] = '*';
				}
			}
		}
	}

	else { // if the desired rows is greater than the original rows
		holder.board = (char**)malloc(sizeof(char*) * holder.row); //memory for new array
		for(i = 0; i < holder.row; i++) {
			holder.board[i] = (char*)malloc(sizeof(char) * holder.col); // memory for new array
			for(j = 0; j < holder.col; j++) {
				if(i >= num_rows - main->row) { // prints out board[rows]
					if(j < main->col) { // prints out board[rows][cols]
						holder.board[i][j] = main->board[i - (num_rows - main->row)][j];
					}
					else { // if desired columns is greater than original columns
						holder.board[i][j] = '*';
					}
				}
				else { // when desired rows is greater than original rows
					holder.board[i][j] = '*';
				}
			}
		}
	}

	main->row = holder.row; // sets original # of columns to new # of columns
	main->col = holder.col; // sets original # of columns to new # of columns
	main->board = holder.board; // sets original array to new array

}