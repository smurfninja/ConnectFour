#include "view.h"

void View::viewDisc(int x)
{
   switch (x)
   {
      case 0:
	 printf("| [ ] |");
	 break;
      case 1:
	 printf("|  *  |");
	 break;
      case 2:
	 printf("|  \e[91m*  \e[00m|");
	 break;
   }
}

void View::viewGrid(Grid &g) 
{
   system("clear");
   printf("|  1  ||  2  ||  3  ||  4  ||  5  ||  6  ||  7  | \n");
   
   for(int i = HEIGHT-1; i >= 0 ; i--)
   {
       for(int j = 0; j < WIDTH; j++)
    	  viewDisc(g.getCoord(i,j));
       printf("\n");
   }	  
}

int View::getChoice(int p)
{
   int x;
   if (p == 2)
      printf("RED: Please Enter Your Next Move:\n");
   if (p == 1)
      printf("BLACK: Please Enter Your Next Move:\n");
   try
   {
      std::cin >> x;
      if (x < 1 || x > 7)
	 throw 90;
   }catch(int)
   {
      printf("\nPlease enter a valid move:\n");
      x = getChoice(p);
   }
   return x;
}

int View::getPlayers()
{
   int x;
   try
   {
      printf("Which colour will you be playing?\nEnter 1 for BLACK\nEnter 2 for RED\n");
      std::cin >> x;
      if(x != 1 && x != 2)
	 throw 20;
   }catch (int)
   {
      printf("\nPlease enter a valid Player number\n\n");
      x = getPlayers();
   }
   return x;
   
}
