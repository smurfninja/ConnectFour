#ifndef GRID_H
#define GRID_H
#define HEIGHT 6
#define WIDTH 7

#include "disc.h"

class Grid
{
  public:
/**
   Default Constructor:
   Will generate a completely blank grid
*/
   explicit Grid();


/**
   Destructor:
*/
   virtual ~Grid();

   
/**
   Is Empty Function:
   Checks to see if the coordinates given is empty or not
   isEmpty() is TRUE when space is empty
   isEmpty() is FALSE when space is occupied
*/
   bool isEmpty(int i, int j);
/**
   Getter:
   Returns 0, 1, or 2
   0 - denotes empty spot, or nullptr found
   1 - denotes black disc
   2 - denotes red disc
*/
   int getCoord(int i, int j);
  private:
   Disc *coord[HEIGHT][WIDTH];
};
#endif
