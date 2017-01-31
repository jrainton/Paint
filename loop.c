/*
* This program loops the program
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "board.h"
#include "commands.h"
#include "read.h"

/*
* This function loops the whole program
*/
void loop(char command, struct Board main) {
char test;

while(command != 'q') { // if the user did not input quit
		command = readCommand(&test);
		if(command == 'q' || command == '\0') { // if they input q or null
			scanf("%c", &test);
			if(test != '\n') {
				while(test != '\n') {
					scanf("%c", &test);
				}
				printf("Unrecognized command. Type h for help.\n");
				command = 'p';
			}
			else {
				continue;
			}
		}
		else if(command == 'h') { // if help
			commandHelp();
		}
		else if(command == 'w') { // if write
			commandWrite(&main);
		}
		else if(command == 'a') { // if add
			commandAdd(&main);
		}
		else if(command == 'd') { // if delete
			commandDelete(&main);
		}
		else if(command == 'r') { // if remove
			commandResize(&main);
		}
		else if(command == 'e') { // if erase
			commandErase(&main);
		}
		else if(command == 's') { // if save
			commandSave(&main);
		}
		else if(command == 'l') { // if load
			commandLoad(&main);
		}
		else {
			while(command != '\n') { // if wrong input
				scanf("%c", &command);
			}
			printf("Unrecognized command. Type h for help.\n");
		}
		printBoard(main); // prints board
	}
}
