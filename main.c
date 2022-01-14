#include "defs.h"

/*
 * Function: main
 * Purpose: Runs the game
 */
int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));

	int numPlayers = getNumPlayers(argc, argv);
	printf("%d\n", numPlayers);
	if(numPlayers == -1) {
		exit(1);
	}

	return 0;
}

/*
 * Function: random
 * Purpose: Generates a random integer from 1-max (exclusive)
 *      in: Exclusive max
 *     out: Random integer
 */
int random(int max)
{
	return (int) (max * ((double) rand() / ((double) (RAND_MAX + 1))));
}
