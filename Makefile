EXE = ttt
OBJ = main.o game.o
CC = gcc -Wall

all:	$(OBJ)
	$(CC) -o $(EXE) $(OBJ)

main.o:	main.c defs.h
	$(CC) -c main.c

game.o:	game.c defs.h
	$(CC) -c game.c

clean:
	rm -rf $(EXE) $(OBJ)