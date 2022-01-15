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
