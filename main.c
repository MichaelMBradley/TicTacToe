#include "defs.h"

/*
 * Function: main
 * Purpose: Runs the game
 */
int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));

	int numPlayers = getNumPlayers(argc, argv);
	printf("Number of players: %d\n\n", numPlayers);

	if(numPlayers == -1)
	{
		exit(1);
	}

	switch(runGame(numPlayers))
	{
		case X_WIN:
			printf("Player X wins!\n");
			break;
		case O_WIN:
			printf("Player O wins!\n");
			break;
		default:
			printf("Tie!\n");
	}

	return 0;
}

/*
 * Function: getNumPlayers
 * Purpose: Gets the user-indicated number of players from the command line arguments
 *      in: number of arguments
 *      in: arguments
 * returns: Number of players, or -1 if the input was invalid
 */
int getNumPlayers(int argc, char *argv[])
{
	int numPlayers = -1;
	switch(argc)
	{
		case 1:
			return 1;
		case 2:
			sscanf(argv[1], "%d", &numPlayers);
			if(numPlayers < 1 || 2 < numPlayers)
			{
				break;
			}
			return numPlayers;
	}
	printf("Please enter as an argument the number of players: {1, 2}\n");
	return -1;
}

/*
 * Function: random
 * Purpose: Generates a random integer from [1-max)
 *      in: Exclusive max
 *     out: Random integer
 */
int random(int max)
{
	return (int) (max * ((double) rand() / ((double) (RAND_MAX + 1))));
}
