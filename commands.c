/*
* The purpose of this program is to execute the command the user wanted
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "struct.h"
#include "directions.h"
#include "changeBoard.h"

/*
* This function prints out the needed help lines
*/
void commandHelp() {
	char holder;
	scanf("%c", &holder);
	if(holder != '\n') { // tests to see if inputted correctly
			while(holder != '\n') {
				scanf("%c", &holder);
			}
			printf("Unrecognized command. Type h for help.\n");
			return;
		}
	printf("Commands:\n");
	printf("Help: h\n");
	printf("Quit: q\n");
	printf("Draw line: w row_start col_start row_end col_end\n");
	printf("Resize: r num_rows num_cols\n");
	printf("Add row or column: a [r | c] pos\n");
	printf("Delete row or column: d [r | c] pos\n");
	printf("Erase: e row col\n");
	printf("Save: s file_name\n");
	printf("Load: l file_name\n");
}

/*
* This function writes out the line the user inputted
*/
void commandWrite(struct Board* main) {
	int row_start;
	int col_start;
	int i;
	char holder;
	int row_end;
	int col_end;
	int direction; // direction of the line
	scanf("%c", &holder);
	if(holder == '\n' || holder != ' ') {
		while(holder != '\n') {
			scanf("%c", &holder);
		}
		printf("Improper draw command.\n");
		return;
	}
	for(i = 0; i < 3; i++){ // tests to see if inputted correctly
		if(i == 0) {
			scanf("%d", &row_start);
		}
		else if(i == 1){
			scanf("%d", &col_start);
		}
		else if(i == 2) {
			scanf("%d", &row_end);
		}
		scanf("%c", &holder);
		if(holder != ' ') {
			while(holder != '\n') {
				scanf("%c", &holder);
			}
			printf("Improper draw command.\n");
			return;
		}
	}

	scanf("%d", &col_end);
	while(holder != '\n') {
		scanf("%c", &holder);
		if(holder == ' ' || holder == '\n') {
			continue;
		}
		else {
			while(holder != '\n') {
				scanf("%c", &holder);
			}
			printf("Improper draw command.\n");
			return;
		}
	}

	if(row_start < 0 || row_start > main->row - 1) { // if not valid row start input
		printf("Improper draw command.\n");
			return;
	}
	if(col_start < 0 || col_start > main->col - 1) { // if not valid column start input
		printf("Improper draw command.\n");
			return;
	}
	if(row_end < 0 || row_end > main->row - 1) { // if not valid row end input
		printf("Improper draw command.\n");
			return;
	}
	if(col_end < 0 || col_end > main->col - 1) { // if not valid column end input
		printf("Improper draw command.\n");
			return;
	}

	row_start = main->row - row_start - 1; // gets rights row start
	row_end = main->row - row_end - 1; // gets right row end

	direction = getDirection(row_start, col_start, row_end, col_end); // finds directions

	changeBoard(direction, main, row_start, col_start, row_end, col_end); // changes the board
}

/*
* This function adds a row or column to the board
*/
void commandAdd(struct Board* main) {
	int point;
	char type;
	char holder;
	
	scanf("%c", &holder); // tests to see if inputted correctly
	if(holder == '\n' || holder != ' ') {
		while(holder != '\n') {
			scanf("%c", &holder);
		}
		printf("Improper add command.\n");
		return;
	}

	scanf("%c", &type);
	scanf("%c", &holder);

	if(holder != ' ' || !(type == 'r' || type == 'c')) {
		while(holder != '\n') {
			scanf("%c", &holder);
		}
		printf("Improper add command.\n");
		return;
	}

	scanf("%d", &point);
	while(holder != '\n') {
		scanf("%c", &holder);
		if(holder == ' ' || holder == '\n') {
			continue;
		}
		else {
			while(holder != '\n') {
				scanf("%c", &holder);
			}
			printf("Improper add command.\n");
			return;
		}
	}

	if((point < 0 || point > main->row) && type == 'r'){ // if not valid row
		printf("Improper add command.\n");
			return;
	}
	if((point < 0 || point > main->col) && type == 'c'){ // if not valid column
		printf("Improper add command.\n");
			return;
	}
	add(main, type, point); // adds the row or column
	
}

/*
* This function deletes a row or column from the board
*/
void commandDelete(struct Board* main) {
	int point;
	char type;
	char holder;
	
	scanf("%c", &holder); // tests to see if inputted correctly
	if(holder == '\n' || holder != ' ') {
		while(holder != '\n') {
			scanf("%c", &holder);
		}
		printf("Improper delete command.\n");
		return;
	}

	scanf("%c", &type);
	scanf("%c", &holder);

	if(holder != ' ' || !(type == 'r' || type == 'c')) {
		while(holder != '\n') {
			scanf("%c", &holder);
		}
		printf("Improper delete command.\n");
		return;
	}

	scanf("%d", &point);
	while(holder != '\n') {
		scanf("%c", &holder);
		if(holder == ' ' || holder == '\n') {
			continue;
		}
		else {
			while(holder != '\n') {
				scanf("%c", &holder);
			}
			printf("Improper delete command.\n");
			return;
		}
	}
	if((point < 0 || point > main->row - 1) && type == 'r'){ // if valid row input
		printf("Improper delete command.\n");
			return;
	}
	if((point < 0 || point > main->col - 1) && type == 'c'){ // if valid column input
		printf("Improper delete command.\n");
			return;
	}
	Delete(main, type, point); // deletes row or column
	
}

/*
* This function resizes the board to the desired lengths
*/
void commandResize(struct Board* main) {

	int num_rows;
	int num_cols;
	char holder;
	
	scanf("%c", &holder); // tests to see if inputted correctly
	if(holder == '\n' || holder != ' ') {
		while(holder != '\n') {
			scanf("%c", &holder);
		}
		printf("Improper resize command.\n");
		return;
	}

	scanf("%d", &num_rows);
	scanf("%c", &holder);
	if(holder != ' ') {
		while(holder != '\n') {
			scanf("%c", &holder);
		}
		printf("Improper resize command.\n");
		return;
	}

	scanf("%d", &num_cols);
	while(holder != '\n') {
		scanf("%c", &holder);
		if(holder == ' ' || holder == '\n') {
			continue;
		}
		else {
			printf("Improper resize command.\n");
			return;
		}
	}

	if(num_cols < 1 || num_rows < 1) { // tests to see if either the rows or columns is inputted wrong
		printf("Improper resize command.\n");
			return;
	}

	resize(main, num_rows, num_cols); // resizes board to desired lengths

}

/*
* This function deletes a point on the board
*/
void commandErase(struct Board* main) {
	int row;
	int col;
	char holder;
	
	scanf("%c", &holder); // tests to see if inputted correctly
	if(holder == '\n' || holder != ' ') {
		while(holder != '\n') {
			scanf("%c", &holder);
		}
		printf("Improper erase command.\n");
		return;
	}

	scanf("%d", &row);
	scanf("%c", &holder);

	if(holder != ' ') {
		while(holder != '\n') {
			scanf("%c", &holder);
		}
		printf("Improper erase command.\n");
		return;
	}

	scanf("%d", &col);
	while(holder != '\n') {
		scanf("%c", &holder);
		if(holder == ' ' || holder == '\n') {
			continue;
		}
		else {
			printf("Improper erase command.\n");
			return;
		}
	}
	if(row < 0 || row > main->row - 1) { // if row input is inputted wrong
		printf("Improper erase command.\n");
			return;
	}
	if(col < 0 || col > main->col - 1) { // if column input is inputted wrong
		printf("Improper erase command.\n");
			return;
	}
	main->board[main->row - row - 1][col] = '*'; // removes that point
}

/*
* This function saves the board to a file
*/
void commandSave(struct Board* main) {
	FILE* outFile = NULL; // File pointer
    char holder;
    char fileName[100] = " ";
    int i;
    int j;

    scanf("%c", &holder); // tests to see if inputted correctly
	if(holder == '\n' || holder != ' ') {
		printf("Improper save command or file could not be created.\n");
		return;
	}

	scanf("%s", fileName);
	scanf("%c", &holder);
	if(holder != '\n') {
			while(holder != '\n') {
				scanf("%c", &holder);
			}
			printf("Improper save command or file could not be created.\n");
			return;
		}
   // Open file
   outFile = fopen(fileName, "w");
   
   if (outFile == NULL) { // if no file
      printf("Failed to open file: %s\n", fileName);
      return;
   }
   
   // Write to file
   fprintf(outFile, "%d\n", main->row); // writes # of rows
   fprintf(outFile, "%d\n", main->col); // writes # of columns
   for(i = 0; i < main->row; i++) {
   		for(j = 0; j < main->col; j++) {
   			fprintf(outFile, "%c\n", main->board[i][j]); // writes each point
   		}
   }
   
   // Done with file, so close it
   fclose(outFile);
   
}

/*
* This function loads a file
*/
void commandLoad(struct Board* main) {
	struct Board tester;
	FILE* inFile = NULL; // File pointer
    char holder;
    char fileName[100] = " ";
    int i;
    int j;

    scanf("%c", &holder); // tests to see if inputted correctly
	if(holder == '\n' || holder != ' ') {
		printf("Improper save command or file could not be opened.\n");
		return;
	}

	scanf("%s", fileName);
	scanf("%c", &holder);
	if(holder != '\n') {
			while(holder != '\n') {
				scanf("%c", &holder);
			}
			printf("Improper save command or file could not be opened.\n");
			return;
		}
   // Open file
   inFile = fopen(fileName, "r");
   
   if (inFile == NULL) {
      printf("Failed to open file: %s\n", fileName);
      return;
   }
    // Read file
   fscanf(inFile, "%d\n", &tester.row); // gets row
   fscanf(inFile, "%d\n", &tester.col); // gets column
   tester.board = (char**)malloc(sizeof(char*) * tester.row); // makes memory
   for(i = 0; i < tester.row; i++) {
   		tester.board[i] = (char*)malloc(sizeof(char) * tester.col); // makes memory
   		for(j = 0; j < tester.col; j++) {

   			fscanf(inFile, "%c\n", &tester.board[i][j]); // gets each point
   		}
   }
   
   // Done with file, so close it
   fclose(inFile);

   main->row = tester.row; // sets original row to new row
   main->col = tester.col; // sets original column to new column
   main->board = tester.board; // sets original board to new board
}