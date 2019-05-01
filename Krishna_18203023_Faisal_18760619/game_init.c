/*Author1-Shri Krishna Dudwania 
 Author2-Faisal Islam
 Created on 15 April*/
#include"game_init.h"
#include<stdio.h>//including the header file for input output operations
/*including the string header file for string 
based operations*/
#include<string.h>//string header file
/*initialization of board using nested for loop
and declaring all obstacle and normal squares
needed in the game for proper functioning of the game in
accordance of game rules*/
/* function to accept the count of players from the user*/
square board[NUM_ROWS][NUM_COLUMNS];
int  acceptplayercount()
{
    int PlayerCount;//variable declaration PlayerCount
/*asks the user to enter the number of players*/
 printf("\nPlease enter the number of players you want in the game between 2 and 6");
 scanf("%d",&PlayerCount);/*accepts the playercount from the user*/
 return PlayerCount;/*returns the playercount*/
}
char colofplayer(player t)
{
  /*if player color is RED
  then return character 'R'*/
 if((t).col==RED)
 {
    return 'R';
 }
 /*if player color is PINK
  then return character 'P'*/
 if((t).col==PINK)
 {
    return 'P';
 }
 /*if token color is GREEN
  then return character 'G'*/
 if((t).col==GREEN)
 {
   return 'G';
 }
 /*if token color is BLUE
  then return character 'B'*/
 if((t).col==BLUE)
 {
  return 'B';
 }
 /*if token color is ORANGE
  then return character 'O'*/
 if((t).col==ORANGE)
 {
    return 'O';
 }
 /*if token color is YELLOW
  then return character 'Y'*/
 if((t).col== YELLOW) 
  {
    return 'Y';
  }
   return '\0';
}
void initialize_board()
{
  /*loop variable declaration for accessing the  two dimensional board
  positions to mark it as a obstacle or normal or null according to the
  rules provided by the professor*/
 int k=0;//variable declaration i with type int
 int m=0;//variable declaration j with type int
 /*using nested loop placing the obstacles and making
 normal squares by specifying the positions according
  to the game rule*/   
 /*100% provided by the professor*/
 int i,j;
 for (i =0; i< NUM_ROWS; i++){
        for(j =0; j < NUM_COLUMNS; j++){
            //creates an obstacle square at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)
            if((i == 0 && j==3) || (i == 1 && j == 6) || (i ==2 && j ==4)
                    || (i == 3 && j ==5) || (i==4 && j==2) || (i==5 && j==7)){
                board[i][j].type = OBSTACLE;
            } else{
                //creates a normal square otherwise
                board[i][j].type = NORMAL;
            }
            board[i][j].stack_top = NULL;
        }
  
     }
 
  }
/*end of initializeboard*/
enum color selectcolor(int i)
{
  enum color col;
  /*if i equals 0
   then store RED in col*/
  if(i==0)
  {
   col=RED;
  }
  /*if i equals 1
   then store BLUE in col*/
  if(i==1)
  {
   col=BLUE;
  }
  /*if i equals 2
   then store GREEN in col*/
  if(i==2)
  {
   col=GREEN;
  }
  /*if i equals 3
   then store YELLOW in col*/
  if(i==3)
  {
   col=YELLOW;
  }
  /*if i equals 4
   then store PINK in col*/
  if(i==4)
  {
   col=PINK;
  }
  /*if i equals 5
   then store ORANGE in col*/
    if(i==5)
  {
   col=ORANGE;
  }
  /*returns the colour from this function*/
  return col;
}//end of the function
 /*function initialize_players creates players
 and accepts the colour the player want to chose and the
 player's name and also returns the playercount*/
int initialize_players(player players[])
{
 
 enum color col;//stores the color
 int l;//accepts the choice of color for the user
 int p;//stores the indexing for looping
 char nameofplayer[20];//stores the name of player as specified by the user
 int totalplayers=0;
 /*invokes the function acceptplayercount to accept the
  number of players and storing it in the 
  variable totalplayers*/
 totalplayers=acceptplayercount();
 /*checks if the playerCount is less than 2 or greater than 6
 and if its true then prints that the game cannot accept
 that amount of players a s it would go against the
 *  rules of the game and asks the user to enter 
 the playerCount again*/
 if( totalplayers<2|| totalplayers>6)
 {
  /*prints that cannot accept players players
    which are not within the above range*/
  printf("Cannot accept..Please enter players between 2 and 6");
  scanf("%d",&totalplayers);/*takes the input again*/
 }
 /*for loop to accept the details of the players
  including name ,giving them the choice of colours*/
 for(p=0;p<totalplayers;p++)
 {
   printf("\nDetails of the igel argern game player %d:",p+1);
   printf("\nName: ");//prints on the screen to input the name of player
   /*accepts the name of the player*/
   scanf("%s",nameofplayer);
   /*asks the user to press the respective numbers for 
    the colour they want their token to be of*/
   printf("Enter the colour you want \n");
   printf("Press 0 for  RED,1 for blue 2 for green 3 for yellow 4 for pink 5 for orange\n");
   /*accepts the choice of colour*/
   scanf("%d",&l);
   /*checks if the choice of the user is valid or
    not and if not valid then asks the user
    to input the correct value again*/
   if(l<0|| l>6)
   {
   /*asks the user to enter the correct value for l */
    printf("Enter the correct value for l");
    scanf("%d",&l);//accepts the value for l again
   }
   /*calls the selectcolor function and passes the value l
    which gets the required color and stores it in col declared
    in the beginning of this function*/
   col=selectcolor(l);
   /*copies the nameofplayer to players*/
   strcpy(players[p].name,nameofplayer);
   printf("Color %d\n", l);
   players[p].col = col;
 }
 return totalplayers;//returns the total number of players

}//end of the code
