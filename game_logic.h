/*Header file containing the definitions of the most important 
functions of printing the board ,placing the tokens and playing
 the game*/
/*places the tokens in the first column of the board
according to the user selection and the rules of the game
provided by the professor */
/*Input:  board - a six *nine array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players*/
/*fifty percent provided by the professor in the labs available on
 brightspace*/
void token_placement(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers);

/*function prototype print_board prints
 the board on the screen for playing the
  game*/
/*provided by the professor in the labs available on
 brightspace*/
void print_board(square board[NUM_ROWS][NUM_COLUMNS]);


 
/*plays the game according to the logic of the game
and upon user's choice to move the tokens keeping to
the rules of the game provided by the professor*/
/* Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players*/
/*Not provided by the professor*/
 void game_on(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers);