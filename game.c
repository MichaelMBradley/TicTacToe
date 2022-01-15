#include "defs.h"

/*
 * Function: runGame
 * Purpose: Runs a game of tic-tac-toe
 *      in: Number of players {1, 2}
 */
AINoteType runGame(int numPlayers)
{
	BoardType board;
	initBoard(&board);
	printBoard(&board);

	return NOWIN;
}

/*
 * Function: printBoard
 * Purpose: Prints the game board
 *      in: Board to print
 */
void printBoard(BoardType *board)
{
	// Prints each square in order
	// Placing dividers in between
	for(int y = 0; y < 3; ++y)
	{
		for(int x = 0; x < 3; ++x)
		{
			printBoardSquare(board->board[y * 3 + x], y * 3 + x);
			if(x != 2)
			{
				// In between squares
				printf("|");
			}
			else
			{
				// After lines
				printf("\n");
			}
		}
		if(y != 2)
		{
			printf("-+-+-\n");
		}
	}
	printf("\n");
}

/*
 * Function: printBoardSquare
 * Purpose: Prints a square on the game board
 *      in: What is in the square
 *      in: Index of array at print position
 */
void printBoardSquare(FillType fill, int index)
{
	// Only three possible cases
	// Print the relevant symbol
	switch(fill)
	{
		case CLEAR:
			printf("%d", inputFromBoardIndex(index));
			break;
		case X:
			printf("X");
			break;
		case O:
			printf("O");
			break;
	}
}
