#ifndef DEFS_H
#define DEFS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_STR 64
#define BOARD_SQUARES 9

#define NODE_FOUND 0
#define NODE_NOT_FOUND 1
#define TEST_SUCCESS 2
#define TEST_FAILURE 3

typedef enum {PLAYER_X, PLAYER_O, CLEAR} FillType;
typedef enum {NO_WIN, X_WIN, O_WIN, BOTH_WIN} AINoteType;

typedef struct Node
{
	struct Node *next;
	AINoteType note;
	int id;
} NodeType;

typedef struct
{
	NodeType *head;
	int size;
} ListType;

typedef struct
{
	FillType board[BOARD_SQUARES];
	ListType *moves;
} BoardType;

// board.c
void cleanBoard(BoardType*);
int boardIndexFromInput(int);
int inputFromBoardIndex(int);
void initBoard(BoardType**);
void printBoard(BoardType*);
void printBoardSquare(FillType, int);

// game.c
AINoteType fillTypeToAINoteType(FillType);
AINoteType gameWinner(BoardType*);
int getComputerInput(BoardType*);
int getPlayerInput(BoardType*, char player);
void initAINotes(ListType*);
AINoteType runGame(int);
int testMove(BoardType*, int, FillType);
void updateAINotes(BoardType*);

// main.c
int main(int, char**);
int getNumPlayers(int, char**);
int random(int);

// list.c
void addToBack(ListType*, NodeType*);
void cleanList(ListType*);
void initList(ListType**);
void initNode(AINoteType, int, NodeType**);
int removeNode(ListType*, int);

#endif
