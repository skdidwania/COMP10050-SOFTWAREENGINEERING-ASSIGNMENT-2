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
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS])
{
  /*loop variable declaration for accessing the  two dimensional board
  positions to mark it as a obstacle or normal or null according to the
  rules provided by the professor*/
 int k=0;//variable declaration i with type int
 int m=0;//variable declaration j with type int
 /*using nested loop placing the obstacles and making
 normal squares by specifying the positions according
  to the game rule*/  
 char obs[ ]="OBSTACLE";
 char nor[ ]="NORMAL";
 for(k=0;i<NUM_ROWS;k++)//for loop with i 
 {
   for(m=0;j<NUM_COLUMNS;m++)//for loop with j
   {
     /*creation of obstacle squares on positions(0,3),(1,6),(2,4),(3,5),(4,2)&(5,7)
      as specified in the game rule provided by the professor*/
     if((k==0&&m==3)||(k==1&&m==6)||(k==2&&m==4)||(k==3&&m==5)||(k==4 && m==2)||(k==5 && m==7))//accessing the positions
     {
      /*making that position as an obstacle 
      on the board*/
       board[k][m].type=obs;//making it an obstacle on the board
      } 
       else
       {
         //else create a normal square on the board
         board[k][m].type=nor;//normal square
        }
      board[k][m].stack_top=NULL;/**/
  
     }
 
  }

}//end of initialize_board function

enum color selectcolor(int i)
{
  enum color col;
  switch(i)
  {
     case 0: col =  RED;
             break;
     case 1: col = BLUE;
             break;
     case 2: col = GREEN;
              break;
     case 3: col = YELLOW;
             break;
     case 4: col = PINK;
             break;
     case 5: col = ORANGE;
             break;
     default: break;
  }
  return col;
}
 /*function initialize_players creates players
 and accepts the colour the player want to chose and the
 player's name and also returns the playercount*/
int initialize_players(player players[])
{
 int PlayerCount;/*stores the player count provided by the user*/
 enum color col;//stores the color
 int l;//accepts the choice of color for the user
 int p;//stores the indexing for looping
 char nameofplayer[20];//stores the name of player as specified by the user
 /*asks the user to enter the number of players*/
 printf("\nPlease enter the number of players you want in the game between 2 and 6");
 scanf("%d",&PlayerCount);
 if(PlayerCount<2 && PlayerCount>6)
 {
  printf("Cannot accept..Please enter players between 2 and 6");
  scanf("%d",&PlayerCount);
 }
 for(p=0;p<PlayerCount;p++)
 {
   printf("\nDetails of player %d:",p+1);
   printf("\nName: ");
   scanf("%s",nameofplayer);
   printf("Enter the colour you want \n");
   printf("Press 0 for  RED,1 for blue 2 for green 3 for yellow 4 for pink 5 for orange\n");
   scanf("%d",&l);
   if(l<0|| l>6)
   {
    printf("Enter the correct value for l");
    scanf("%d",&l);
   }
   col=selectcolor(l);
   strcpy(players[i].name,nameofplayer);
   printf("Color %d\n", i);
   players[p].col = col;
 }
 return PlayerCount;

}//end of the code