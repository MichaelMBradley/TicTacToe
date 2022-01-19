#include "defs.h"

/*
 * Function: getPlayerInput
 * Purpose: Gets the square that the player wishes to play
 *      in: The current board
 * returns: The board position that the player wants to play (NOT array index)
 */
int getPlayerInput(BoardType *board, char player)
{
	char in[MAX_STR];
	int input = -1;

	printf("Player %c, please enter the square you would like to play: ", player);
	fgets(in, MAX_STR, stdin);
	sscanf(in, "%d", &input);

	// If input is out of range or on an already-input square
	while(input < 1 || input > BOARD_SQUARES || (*board->board[input]) != CLEAR)
	{
		printf("The value you inter must be an integer {1,9} that is not already played.\n");
		printf("Player %c, please enter the square you would like to play: ", player);
		fgets(in, MAX_STR, stdin);
		sscanf(in, "%d", &input);
	}

	return input;
}

/*
 * Function: runGame
 * Purpose: Runs a game of tic-tac-toe
 *      in: Number of players {1, 2}
 */
AINoteType runGame(int numPlayers)
{
	BoardType *board;
	initBoard(&board);
	printBoard(board);

	cleanBoard(board);

	return NO_WIN;
}
