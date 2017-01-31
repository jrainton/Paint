paint.out: main.o read.o board.o commands.o directions.o changeBoard.o loop.o
	gcc -g -Wall -Werror -o paint.out main.o read.o board.o commands.o directions.o changeBoard.o loop.o -lm

read.o: read.c struct.h
	gcc -g -Wall -Werror -c -o read.o read.c 

commands.o: commands.c struct.h directions.h changeBoard.h
	gcc -g -Wall -Werror -c -o commands.o commands.c

changeBoard.o: changeBoard.c struct.h
	gcc -g -Wall -Werror -c -o changeBoard.o changeBoard.c

board.o: board.c struct.h
	gcc -g -Wall -Werror -c -o board.o board.c 

main.o: main.c read.h board.h commands.h loop.h
	gcc -g -Wall -Werror -c -o main.o main.c

directions.o: directions.c struct.h
	gcc -g -Wall -Werror -c -o directions.o directions.c

loop.o: loop.c board.h commands.h read.h
	gcc -g -Wall -Werror -c -o loop.o loop.c

clean:
	rm -f *.o *.out
