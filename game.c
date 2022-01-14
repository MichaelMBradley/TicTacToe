#include "defs.h"

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
	switch(argc) {
		case 1:
			return 1;
		case 2:
			sscanf(argv[1], "%d", &numPlayers);
			if(numPlayers < 1 || 2 < numPlayers) {
				break;
			}
			return numPlayers;
	}
	printf("Please enter as an argument the number of players: {1, 2}\n");
	return -1;
}
