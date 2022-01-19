#include "defs.h"

/*
 * Function: cleanBoard
 * Purpose: Frees a board from memory
 *      in: Board to deallocate
 */
void cleanBoard(BoardType *board)
{
	cleanList(board->moves);
	free(board);
}

/*
 * Function: boardIndexFromInput
 * Purpose: Convert the user input to an array index
 *      in: User input {1->9}
 *
 * 7|8|9    0|1|2
 * -+-+-    -+-+-
 * 4|5|6 -> 3|4|5
 * -+-+-    -+-+-
 * 1|2|3    6|7|8
 */
int boardIndexFromInput(int input)
{
	if(input <= 3)
	{
		return input + 5;
	}
	else if(input >= 7)
	{
		return input - 7;
	}
	else
	{
		return input - 1;
	}
}

/*
 * Function: inputFromBoardIndex
 * Purpose: Convert the array index to the corresponding user input
 *      in: Array index {0->8}
 *
 * 0|1|2    7|8|9
 * -+-+-    -+-+-
 * 3|4|5 -> 4|5|6
 * -+-+-    -+-+-
 * 6|7|8    1|2|3
 */
int inputFromBoardIndex(int index)
{
	if(index <= 2)
	{
		return index + 7;
	}
	else if(index >= 6)
	{
		return index - 5;
	}
	else
	{
		return index + 1;
	}
}

/*
 * Function: initBoard
 * Purpose: Initializes a board structure
 *      in: Pointer to board to be initialized
 */
void initBoard(BoardType **board)
{
	(*board) = (BoardType *) malloc(sizeof(BoardType));
	for(int i = 0; i < BOARD_SQUARES; ++i)
	{
		(*board)->board[i] = CLEAR;
	}
	initList(&((*board)->moves));
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
		case PLAYER_X:
			printf("X");
			break;
		case PLAYER_O:
			printf("O");
			break;
	}
}
