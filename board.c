#include "defs.h"

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
void initBoard(BoardType *board)
{
	for(int i = 0; i < BOARD_SQUARES; ++i)
	{
		board->board[i] = CLEAR;
	}
	initList(&(board->moves));
}

/*
 * Function: initList
 * Purpose: Initializes a list structure
 *      in: List to initialize
 */
void initList(ListType *list)
{
	list->size = 0;
	list->head = NULL;
}
