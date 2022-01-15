#ifndef DEFS_H
#define DEFS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SQUARES 9

typedef enum {X, O, CLEAR} FillType;
typedef enum {NOWIN, XWIN, OWIN, BOTHWIN} AINoteType;

typedef struct Node
{
	struct Node *next;
	AINoteType note;
} NodeType;

typedef struct
{
	NodeType *head;
	int size;
} ListType;

typedef struct
{
	FillType board[BOARD_SQUARES];
	ListType moves;
} BoardType;

// board.c
int boardIndexFromInput(int);
int inputFromBoardIndex(int);
void initBoard(BoardType*);
void initList(ListType*);

// game.c
AINoteType runGame(int);
void printBoard(BoardType*);
void printBoardSquare(FillType, int);

// main.c
int main(int, char**);
int getNumPlayers(int, char**);
int random(int);

#endif
