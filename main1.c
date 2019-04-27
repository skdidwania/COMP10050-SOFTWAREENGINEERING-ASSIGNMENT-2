/*Author1-Shri Krishna Dudwania 
 Author2-Faisal Islam
 Created on 15 April*/
/*the program below has main function
which calls the function defined in the other peices of code
namely initialize_board ,display_gameboard,initialize_players
token_placement and game_on thus playing the game*/

#include "game_init.h"
/*including the game_logic header file which has the 
function prototype defined within it*/
#include "game_logic.h"
#include <stdio.h>//including the header file for input output operations
#include <stdlib.h> //including the stdlib header file
#include<time.h> //including the time library file for random function
int main(int argc, char** argv)
{
  srand(time(NULL)); 
 /*board is initialized and defined as a two dimensional
  array of square boxes to play the igel argern game*/
  /*provided by the professor*/
 square board[NUM_ROWS][NUM_COLUMNS];
  /*players array declaration  with type player 
   which can contain a maximum of 6 players to play
   the game */
 /*provided by the professor
 player players[6];
  /*variable declaration numPlayers to store the number of players 
  in the game as specified by the user*/
 /*provided by the profesor*/
 int PlayerCount=0;
  /*board creation is done calling the initialize 
    board function and passing the board as a parameter 
    to the function*/
 /*provided by the professor*/
 initialize_board(board);
 /*displays the board on the screen calling the
   display_gameboard function and passing board as
    a parameter to it*/
 display_gameboard(board);
 /*player creation is done by calling the function
   initialize_players which returns the number of players
   specified by the user in the starting of the game when
   the players array defined above is passed to it*/
  PlayerCount = initialize_players(players);
    /*asks the user to place the tokens on the first 
    column of the board initially to play the game 
    according the rules of the game */
  token_placement(board, players,  PlayerCount);
    /*prints on the screen that game starts */
  printf("\n------------Starting the game----------\n ");
    /*game is started when the function game_on is called 
    and the board ,players,numPlayers is passed to it
    and then at the end the winner is identified and displayed*/
  game_on(board, players,  PlayerCount);
  return 0;
}/*end of the code of the game when the winner is declared*/