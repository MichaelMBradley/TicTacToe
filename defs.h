#ifndef DEFS_H
#define DEFS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef enum {X, O, CLEAR} FillType;
typedef enum {NOWIN, XWIN, OWIN, BOTHWIN} AINoteType;

typedef struct Node {
	struct Node *next;
	AINoteType note;
} NodeType;

typedef struct {
	NodeType *head;
	int size;
} ListType;

typedef struct {
	FillType board[9];
	ListType *moves;
} BoardType;

// game.c
int main(int, char**);
int random(int);

// func.c
int getNumPlayers(int, char**);

#endif
