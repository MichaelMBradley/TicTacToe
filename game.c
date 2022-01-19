#include "defs.h"

/*
 * Function: fillTypeToAINoteType
 * Purpose: Converts a FillType to the relevant AINoteType
 *      in: FillType to convert
 */
AINoteType fillTypeToAINoteType(FillType fill)
{
	switch(fill)
	{
		case PLAYER_X:
			return X_WIN;
		case PLAYER_O:
			return O_WIN;
		default:
			return NO_WIN;
	}
}

AINoteType gameWinner(BoardType *board)
{
	// Iterate through rows
	for(int i = 0; i < BOARD_SQUARES; i += 3)
	{
		// If row is homogenous and not clear
		if(board->board[i] != CLEAR
		&& board->board[i] == board->board[i+1]
		&& board->board[i] == board->board[i+2])
		{
			return fillTypeToAINoteType(board->board[i]);
		}
	}

	// Iterate through columns
	for(int i = 0; i < 3; ++i)
	{
		// If column is homogenous and not clear
		if(board->board[i] != CLEAR
		   && board->board[i] == board->board[i+3]
		   && board->board[i] == board->board[i+6])
		{
			return fillTypeToAINoteType(board->board[i]);
		}
	}

	// Check diagonals
	if(board->board[0] == board->board[4]
	&& board->board[0] == board->board[8])
	{
		return fillTypeToAINoteType(board->board[0]);
	}
	if(board->board[2] == board->board[4]
	   && board->board[2] == board->board[6])
	{
		return fillTypeToAINoteType(board->board[2]);
	}
	return NO_WIN;
}

int getComputerInput(BoardType *board)
{
	int id = -1;

	// Search for game-winning moves
	for(NodeType *node = board->moves->head; node != NULL; node = node->next)
	{
		switch(node->note)
		{
			case BOTH_WIN:
			case O_WIN:
				// Return game winning move
				return node->id;
			case X_WIN:
				// Save move that prevents X from winning
				// (Irrelevant if game-winning move found later)
				id = node->id;
			default:
				continue;
		}
	}

	// If no game-winning move was found but a move from X could win
	if(id != -1)
	{
		return id;
	}

	// If all else fails, make a random move
	NodeType *node = board->moves->head;
	for(int i = 0; i < random(board->moves->size - 1); ++i)
	{
		node = node->next;
	}
	return node->id;
}

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
	while(input < 1 || input > BOARD_SQUARES || board->board[boardIndexFromInput(input)] != CLEAR)
	{
		printf("The value you inter must be an integer {1,9} that is not already played.\n");
		printf("Player %c, please enter the square you would like to play: ", player);
		fgets(in, MAX_STR, stdin);
		sscanf(in, "%d", &input);
	}

	return input;
}

/*
 * Function: initAINotes
 * Purpose: Initializes the list of moves
 *      in: List to initialize
 */
void initAINotes(ListType *list)
{
	for(int i = 0; i < BOARD_SQUARES; ++i)
	{
		NodeType *node;
		initNode(NO_WIN, i, &node);
		addToBack(list, node);
	}
}

/*
 * Function: runGame
 * Purpose: Runs a game of tic-tac-toe
 *      in: Number of players {1, 2}
 */
AINoteType runGame(int numPlayers)
{
	// Initialization
	BoardType *board;
	initBoard(&board);
	initAINotes(board->moves);

	// Choose starting player randomly
	FillType player;
	if(random(2) == 0)
	{
		player = PLAYER_O;
	}
	else
	{
		player = PLAYER_X;
	}
	printf("Starting player randomly chosen...\n");
	if(numPlayers == 1 && player == PLAYER_O)
	{
		printf("AI (O) moving first...\n");
	}

	// Run game
	int play;
	while(gameWinner(board) == NO_WIN && board->moves->size > 0)
	{
		if(player == PLAYER_X)
		{
			printf("\n");
			printBoard(board);
			play = boardIndexFromInput(getPlayerInput(board, 'X'));
			board->board[play] = PLAYER_X;
			player = PLAYER_O;
		}
		else
		{
			if(numPlayers == 2)
			{
				// Get input from other player
				printf("\n");
				printBoard(board);
				play = boardIndexFromInput(getPlayerInput(board, 'O'));
			} else {
				// Get input from AI
				updateAINotes(board);
				play = getComputerInput(board);
				printf("AI played square %d\n", inputFromBoardIndex(play));
			}
			board->board[play] = PLAYER_O;
			player = PLAYER_X;
		}
		if(removeNode(board->moves, play) == NODE_NOT_FOUND)
		{
			printf("Something went wrong.\n");
			exit(1);
		}
	}

	// Show result, clean up
	printBoard(board);
	AINoteType winner = gameWinner(board);
	cleanBoard(board);
	return winner;
}

/*
 * Function: testMove
 * Purpose: Tests a potential move for the AI
 *          Assumes board square to be empty
 *      in: Board to test move on
 *      in: Move location
 *      in: Player making move
 * returns: TEST_SUCCESS or TEST_FAILURE
 */
int testMove(BoardType *board, int id, FillType fill)
{
	board->board[id] = fill;
	AINoteType winner = gameWinner(board);
	board->board[id] = CLEAR;
	if(winner == fillTypeToAINoteType(fill))
	{
		return TEST_SUCCESS;
	}
	else
	{
		return TEST_FAILURE;
	}
}

/*
 * Function: updateAINotes
 * Purpose: Updates the notes that the AI uses to make decisions
 *      in: Current game board
 */
void updateAINotes(BoardType *board)
{
	for(NodeType *node = board->moves->head; node != NULL; node = node->next)
	{
		if(node->note == BOTH_WIN)
		{
			// No need to calculate if we already know results
			continue;
		}

		// Simulate X moving here and save result
		if(node->note != X_WIN && testMove(board, node->id, PLAYER_X) == TEST_SUCCESS)
		{
			if(node->note == O_WIN)
			{
				node->note = BOTH_WIN;
			}
			else
			{
				node->note = X_WIN;
			}
		}

		// Simulate O moving here and save result
		if(node->note != O_WIN && testMove(board, node->id, PLAYER_O) == TEST_SUCCESS)
		{
			if(node->note == X_WIN)
			{
				node->note = BOTH_WIN;
			}
			else
			{
				node->note = O_WIN;
			}
		}
	}
}
