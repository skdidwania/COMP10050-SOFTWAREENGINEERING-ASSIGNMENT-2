/*Author1-Shri Krishna Dudwania
 Author2-Faisal Islam
 Created on 15 April*/
/*including the user defined header file
which contains definition of enums tokens,
players ,square and function prototype of
initialize_board and initialize_player*/
#include "game_init.h"//header file
#include <stdio.h>//including the header file for input output operations
/* header defines four variable types, several
 macros, and various functions for performing
 general functions.*/
#include <stdbool.h>//including the boolean header file
#include <stdlib.h>//library header file
void printLine();
/*function returns the first letter of the token
colour associated with it*/
/*100% provided by the professor available
 *  on BrightSpace*/
/*indentation is provided by me*/
square board[NUM_ROWS][NUM_COLUMNS];
char print_token(token *l)
{
 /*if token color is RED
  then return character 'R'*/
 if((*l).col== RED)
 {
  return 'R';
 }
 /*if token color is PINK
  then return character 'P'*/
 if((*l).col==PINK)
 {
  return 'P';
 }
 /*if token color is BLUE
  then return character 'B'*/
 if((*l).col== BLUE)
 {
  return 'B';
 }
 /*if token color is GREEN
  then return character 'G'*/
 if((*l).col== GREEN)
 {
  return 'G';
 }
 /*if token color is ORANGE
  then return character 'O'*/
 if((*l).col== ORANGE)
 {
  return 'O';
 }
 /*if token color is pink
  then return character 'Y'*/
 if((*l).col== YELLOW)
 {
  return 'Y';
 }
 return '\0';
}//end of print token function

/*function randomgeneration() generates
a random number between 0 and 5 and returns
the random number*/
int randomgeneartion()//function prototype
{
  int random;//variable to store the random number
  /*random number generation using the rand function*/
  random=(rand() %  (5 - 0 + 1)) + 0;
  /*returns the random function*/
  return (random);
}//end of randomgenearation
/*pushtoken function pushes a token color in the stack by passing the board
players and selectedsquare and is made use in tokenplacement
function*/
void pushtoken(player players[],int j,int selectedSquare)//function prototype
{
  int h=0;//constant to store value
  /*creation of size of token using malloc function*/
  board[selectedSquare][h].stack_top=(token*)malloc(sizeof(token));
  /*stores the token color on stack_top*/
  board[selectedSquare][h].stack_top->col=players[j].col;
  /*makes the next value as null*/
  board[selectedSquare][h].stack_top->next=NULL;
  /*increments the number of tokens*/
  board[selectedSquare][h].numTokens= board[selectedSquare][h].numTokens + 1;
}//end of pushtoken function
/*function to push a token on top of another token and is
 made use in place token function*/
void pushtokenabove(player players[],int j,int selectedSquare)//function prototype
{
  int h=0;//variable to store the constant value 0
  /*creation of size of token using malloc function*/
  token *q=(token*)malloc(sizeof(token));
  /*code to push a token color on top of another
   token*/
  q->next=board[selectedSquare][h].stack_top;
  q->col=players[j].col;//stores the color of the player
  board[selectedSquare][h].stack_top=q;
  /*increments the num of tokens by 1 when another 
  token is added to the stack*/
  board[selectedSquare][h].numTokens= board[selectedSquare][h].numTokens + 1;//incrementation
}//end of pushtokenabove function
/*function to count tokens and return the count of tokens
from the function*/
int counttokens(int selectedSquare)/*function prototype*/
{
  /*variable declarations are done*/
  int g=0;//variable to store the tokens
  int h=0;
  g=board[selectedSquare][h].numTokens;//stores the num of tokens in g
  return g;//returns g
}/*end of counttokens*/
  /*function to get the column in which
  token is present*/
int gettokenCol(int random)/*function prototype*/
{
  int moveCol=-1;
  int a=0;
  /*checks if positions have a token 
  or it is null*/
  /*usage of while loop to do the above job*/
  while(a<NUM_COLUMNS)
  {
    if(board[random][a].stack_top!=NULL)
    {
      moveCol = a;
    }
    a++;//incrementation of a
  }
  return moveCol;//returns the column with the the token
}//end of gettokenCol function
/*function containing the print statements of
of sidestepping*/
void printsidestepdetails()//function prototype
{
  /*printf statements*/
  /*asks the user to for the row to be sidestepped*/
  printf("\nEnter the row to be sidestepped ");
  /*asks the user to for the column to be sidestepped*/
  printf("\nEnter  column  to be sidestepped");
  /*asks the user to for the direction to be sidestepped*/
  printf("\nEnter the direction :0 for up and 1 for down:");
}//end of printsidestepdetails function
/*function to ask the user if he wants 
to sidestep or not containing the printf 
statements*/
void printsidestepchoice()//function prototype
{
  /*asks the user of his choice*/
  printf("\nDo you want to sidestep your piece");
  /*asks the user to press 1 for yes*/
  printf("\nPress 1 for Yes");
  /*asks the user to press 0 for no*/
  printf("\nPress 0 for No");
}//end of printsidestepchoice function
/*function provided by the professor 
to print the board on the screen using nested for
loops*/
void print_board()
{
  printf("                THE BOARD\n");
  int i;
  for(i =0;i<NUM_ROWS;i++)
  {
  //prints an horizontal line
   printLine();
   //prints the row number
   printf(" %d ", i);
   char c = '\0' ;
   //if the square (i,j) is occupied,
   //c is assigned the initial of the color of the token that occupies the square
   int j;
   for (j = 0; j < NUM_COLUMNS; j++)
   {
     if(board[i][j].stack_top != NULL){
     c = print_token(board[i][j].stack_top);
   }
   //if the square (i,j) is empty
   else
   {
   //c is assigned 'X' if the square represents an obstacle
     if(board[i][j].type == OBSTACLE)
      c = 'X';
      //c is assigned an empty space otherwise
     else c = ' ';
   }
       printf("| %c ", c);

  }
        printf ("|\n");
 }
    printLine();
    //prints the number of the columns at the end of the board
    printf("     0   1   2   3   4   5   6   7   8\n");
}
/*provided by the professor */
void printLine()
{
 printf("   -------------------------------------\n");
}//end of printline function

/*
 * Place tokens in the first column of the board
 *
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players
 */
/*function prototype and a part of function
 * provided by the professor */
/*function places token on the board squares
 *  according to the choice of the user and
 the rules of the game provided by the professor*/
void token_placement( player players[], int numPlayers)
{
  /*variable to store the minimum number of tokens*/
 int minNumOfTokens = 0;
 /*variable to stored the square selected by the user*/
 int squareselected = 0;
 int i;/*looping varibales*/
 int j;
 int h=0;
 /*variable to store the number of token of each player*/
 int eachtoken=4;
 /*nested for loop to place the tokens on board*/
 for(i=0;i<eachtoken;i++)
  {
      for(j=0;j<numPlayers;j++)
      { /*asks the user to select a square*/
        accepting :do
          {
            printf("\nPlayer %d please select a square to which u want ur token on: ",j+1);
            scanf("%d",&squareselected);
          }while(squareselected>5||squareselected<0);//inputs the squareselected
        /*checks if the top position is null then
        calls the pushtokens function and pushes the token
        color on top*/
        if(board[squareselected][h].stack_top==NULL)
        {
          pushtoken(players,j,squareselected);//push token function
        }
        /*if the above condition is not true then checks the condition below*/
        /*checks using counttokens function if its equal to minNumtokens and the color is not same*/
        else if(counttokens(squareselected)==minNumOfTokens && board[squareselected][0].stack_top->col!=players[j].col)
             {/*calls the pushtokenabove function */
               pushtokenabove(players,j,squareselected);
             }
        else
         {/*if the above conditions are not true then 
          prints on screen to enter again*/
           goto accepting;//accepts again
         }
         /*prints the board using print_board function*/
          print_board(board);
         if(((numPlayers*i)+j+1)%NUM_ROWS==0)
            minNumOfTokens=minNumOfTokens + 1;
        }
      }
  }//end of token_placement function
  /*pushnext function to replace the stack_top as stack_top next*/
  void pushnext(int sRow,int sCol)
  {
    board[sRow][sCol].stack_top = board[sRow][sCol].stack_top->next;
  }//end of pushnext function
  /*sidestepping moves using the switch case statements*/
  void sidestepmove(token *s,int sRow,int sCol,int dir)
  {
    /*switch statements with cases according to the direction
      specified by the user*/
    switch(dir)
     {
      case 0: s->next=board[sRow-1][sCol].stack_top;
              board[sRow-1][sCol].stack_top=s;
              break;
      case 1: s->next=board[sRow+1][sCol].stack_top;
              board[sRow+1][sCol].stack_top=s;
              break;
      default:printf("Nothing");
    }
  }
  void tokenassignment(int sRow,int sCol,token *e)
  {
    board[sRow][sCol].stack_top=e;
  }
/*game on function to play the game according to the rules of 
the game involoving sidestepping and moving forward*/
void game_on(player players[],int numPlayers)
{

  bool won=false;
  /*variable declarations to use in the function*/
  int i;
  int j;
  int k;
  int l;
  /*game continues until the game is won by any player*/
  while (!won)
  {
    /*for loop*/
    for(i=0;i<numPlayers;i++)
    {
      bool colFull=true;
      int rand;
      printf("\n\nPlayer %s turn with color %c.", players[i].name,colofplayer(players[i]));
      rand=randomgeneartion();//random number generation using randomgeneartion function
     /*the dice is rolled and a random number is generated*/
      printf("\nDice is rolled and the number is: %d\n",rand);
      int w=0;
      int sRow=-1;
      int sCol=-1;
      int dir=-1;
      /*print statements in the function*/
      printsidestepchoice();
      scanf("%d",&w);
      //if the choice is 1
      if(w==1)
      {
       printsidestepdetails();
       scanf("%d",&sRow);
       //validates the srow inputted by the user
        //checks if it is valid
       if(sRow<0 || sRow>5)
       {
        /*prints that wrong value
         and asks the user*/
         printf("wrong value..please enter again");
         scanf("%d",&sRow);
       }
       scanf("%d",&sCol);
       /*prints that wrong value
         and asks the user*/
       if(sCol<0 || sCol>5)
       {
         printf("wrong value..please enter again");
         scanf("%d",&sCol);
       }
       scanf("%d",&dir);
       /*prints that wrong value
         and asks the user*/
       if(dir<0|| dir>1)
       {
         printf("wrong direction..please enter again");
         scanf("%d",&dir);
       }
       //takes the token on top of stack
       token *st = board[sRow][sCol].stack_top;
       /*calls the function pushnext ,sidestepmove functions
       to do the operations*/
       pushnext(sRow,sCol);
       sidestepmove(st,sRow,sCol,dir);
        }
       else {
        printf("\nNo Sidestep took!\n");
      }

       int moveCol=-1;
       moveCol=gettokenCol(rand);
        
  
      if(board[rand][moveCol].type==NORMAL)
      {
        token *o = board[rand][moveCol].stack_top;
        pushnext(rand,moveCol);       
        moveCol=moveCol+1;
        tokenassignment(rand,moveCol,o);
        }
        /*if it is an obstacle then check if there are other tokens
        in the other rows*/
         else if(board[rand][moveCol].type==OBSTACLE)
         {
          for(l=0;l<NUM_ROWS;l++)
          {
           if(board[l][moveCol].stack_top==NULL)
           {
           	//makes colFull equal to false
            colFull=false;
            break;//break statement
           }
          }
          if(colFull==true)
          {
           token *t = board[rand][moveCol].stack_top;
           /*calls the pushnext function*/
           pushnext(rand,moveCol);
           t->next = NULL;
           /*moveCol is incremented*/
           moveCol=moveCol+1;
           /*token asssignment function is called*/
           tokenassignment(rand,moveCol,t);
          }
          /*if not then prints that obstacle square and cannot move*/
           else
           {
            printf("\nOBSTACLE FOUND ..TOKEN FROZEN!!!");

            }
        }
        /*printboard function is called to print the board*/
      print_board();
      int r;
      /*loop to check the number of tokens a player has in the last column of 
      the board*/
    for(r=0;r<6;r++)
      {
       if(board[r][5].stack_top!=NULL && board[r][5].stack_top->col==players[i].col)
       {
        players[i].numTokensLastCol= players[i].numTokensLastCol+1;//increments the tokens in last column
       }
      }
      /*if the tokens are greater than 2*/
       if(players[i].numTokensLastCol>2)
      {
        /*prints congratulations to the player and print the player name*/
       printf("\nCongratulations!!Player %s has won!!!!!",players[i].name);
       won=true;//makes won equals to true when player has won
       break;//break statement
      }

    }

  }


}//end of the code
