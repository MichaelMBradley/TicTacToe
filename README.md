A simple tic-tac-toe project I made to show that I am capable of programming in C.
The AI is designed to be beatable, but not completely stupid.

The AI:
1. Checks to see if it can win in one move (and then does the move if it can)
2. If not, it sees if you can win in one move (and then tries to block you)
3. If no winning moves are found, it makes a move randomly

Even though it's not optimal, it's still capable of beating you if you don't pay attention just by getting a bit lucky.

Usage: `./ttt` to play the AI, or `./ttt [x]` where [x] is the number of players ({1, 2}).
