EXE = ttt
OBJ = main.o game.o board.o list.o
CC = gcc -Wall

all:	$(OBJ)
	$(CC) -o $(EXE) $(OBJ)

main.o:	main.c defs.h
	$(CC) -c main.c

game.o:	game.c defs.h
	$(CC) -c game.c

board.o:	board.c defs.h
	$(CC) -c board.c

list.o:	list.c defs.h
	$(CC) -c list.c

clean:
	rm -rf $(EXE) $(OBJ)
