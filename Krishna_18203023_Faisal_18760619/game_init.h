/*Author1-Shri Krishna Dudwania 
 Author2-Faisal Islam
 Created on 15 April*/

/*defines the number of rows and columns on the 
board using macros in C*/
#define NUM_ROWS 6//defining the rows to 6
//number of columns of the board
#define NUM_COLUMNS 9//defines the columns to 9
/*defines the maximum player to 6 in accordance with the game rules 
and functioning*/

/*types of squares defined using enum namely
NORMAL & OBSTACLE squares required in the game*/
/*provided by the professor*/
enum stype
{
 NORMAL,OBSTACLE
};
/*types of colour declared using enum
namely red,blue,green,yello,pink and 
orange*/
/*provided by the professor*/
enum color
{
 RED, BLUE, GREEN, YELLOW, PINK, ORANGE
};
//defines a token.
/*Each token is connected with a color
which are defined above in the enum color
in the header file*/
/*provided by the professor*/
typedef struct token
{
 enum color col;
 struct token *next;
}token;

/*defines squares on the board
with the following properties*/
/*provided by the professor*/
typedef struct square
{/* a square can be either obstacle or normal
    and is defined using the enum stype */
 enum stype type;
     //the stack of tokens that can be placed on the board square (it will be top of the stack)
 token * stack_top;
 /*stores the number of tokens on the squares of the board
 for gaming*/    
 int numTokens;
}square;
/*struct player is stored with player name
color chosen by the player and the number of tokens
the player has in the last column*/
/*provided by the professor*/
typedef struct player
{
 char name[30];//name of the player
 enum color col;//color chosen by the player
 int numTokensLastCol;//number of tokens the player has in the last columns
}player;
/*initialization of board using nested for loop
and declaring all obstacle and normal squares
needed in the game for proper functioning of the game in
accordance of game rules done in the C file*/
/*function prototype provided by the professor*/
void initialize_board();
/*function initialize_players creates players
 and accepts the colour the player want to chose and the
 player's name and also returns the playercount and the 
 implementation is done in the C file*/
/*function  prototype provided by the professor*/
int initialize_players(player players[]);//initializes the players
//end of the header file
