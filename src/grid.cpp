#include "grid.h"

/**
   CONSTRUCTORS
   **************************************************
   DEFAULT
*/
Grid::Grid()
{
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
	 coord[i][j] = nullptr;
}

/**
   IMPLICIT DECLARED ONE SPACE

   Grid(x,y,TRUE) == (x,y)->RED
   Grid(x,y,FALSE) == (x,y)->BLACK
*/
Grid::Grid(int x, int y, bool c)
{
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
	 coord[i][j] = nullptr;
   coord[x][y] = new Disc(c);
}
/**
   COPY CONSTRUCTOR
 */
Grid::Grid(Grid& g)
{
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
	 coord[i][j] = nullptr;
   
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
      {
	 if (!g.isEmpty(i,j))
	    coord[i][j] = new Disc(g.getCoord(i,j)-1);
	 else
	    coord[i][j] = nullptr;
      }
	     
}
/**
   DESTRUCTOR
   **************************************************
 */
Grid::~Grid()
{
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
	 coord[i][j] = nullptr;
}
/**
   OVERLOADED OPERATORS
   **************************************************
   ASSIGNMENT
 */
Grid& Grid::operator=(const Grid &rhs)
{
   if (this != &rhs)
   {
      for(int i = 0; i < HEIGHT; i++)
	 for(int j = 0; j < WIDTH; j++)
	 {
	    if (!rhs.isEmpty(i,j))
	       coord[i][j] = new Disc(rhs.getCoord(i,j)-1);
	    else
	       coord[i][j] = nullptr;
	 }
   }
   return *this;
}
/**
   EQUALITY
*/
bool Grid::operator==(const Grid &other) const
{
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
      {
	 if (getCoord(i,j) != other.getCoord(i,j))
	    return false;
      }
   return true;
}


/**
   INEQUALITY
*/
bool Grid::operator!=(const Grid &other) const
{
   return !(*this == other);
}

/**
   BOOLEAN MEMBER FUNCTIONS
   **************************************************
   EMPTY CHECK - CHECKS IF SINGLE SPACE  IS EMPTY
 */
bool Grid::isEmpty(int i, int j) const 
{
   if (coord[i][j] == nullptr)
      return true;
   return false;
}

/**
   IS FULL - CHECKS IF GRID IS FULL
 */
bool Grid::isFull()
{
    for(int i = 0; i < HEIGHT; i++)
       for(int j = 0; j < WIDTH; j++)
	 if (isEmpty(i,j))
	    return false;
    return true;
}

/**
   IS FINISHED FUNCTION - RuNS THROUGH  ALL END GAME CONDITIONS
 */
bool Grid::isFinished()
{
   
   return false;
}

/**
   IS ROW FUNCTION - DETERMINES ROW IS MADE IN A HORIZONTAL LINE
 */
bool Grid::isRow(int i, int j)
{
   int count = 1;
   if (isEmpty(i,j))
      return false;
   bool colour = getCoord(i,j);
   if (getCoord(i,j+1) == colour)
   {
      count++;
      if(getCoord(i, j+2) == colour)
      {
	 count++;
	 if(getCoord(i, j+3) == colour)
	    count++;
      }
   }
   if (getCoord(i,j-1) == colour)
   {
      count++;
      if(getCoord(i, j-2) == colour)
      {
	 count++;
	 if(getCoord(i, j-3) == colour)
	    count++;
      }
   }
   if (count > 3)
      return true;
   return false;
}

/**
   INTEGER MEMBER FUNCTIONS
   **************************************************
   GETTER FOR DISC AT COORDINATES - (i,j)
 */
int Grid::getCoord(int i, int j) const
{
   try
   {
      if (i < 0 || j < 0 || i > HEIGHT || j > HEIGHT)
	 throw 20;
   }catch (int)
   {
      return 0;
   }
   if (isEmpty(i,j))
      return 0;
   return coord[i][j]->getColour()+1;
}

/**
   VOID MEMBER FUNCTIONS
   **************************************************
   ADDER FOR NEW DISC AT COORDINATES - (x,y)
*/
void Grid::addDisc(int x, int y, bool c)
{
   coord[x][y] = new Disc(c);
}

/**
   MOVER FOR DISC AT (i,j) TO (x,y)
*/
void Grid::moveDisc(int i, int j, int x, int y)
{
   coord[x][y] = new Disc(getCoord(i,j)-1);
   removeDisc(i,j);
}

/**
   DROP - MAKES SURE DISCS FOLLOW RULES OF GRAVITY
*/

void Grid::dropDisc(int i, int j, bool c)
{
   if (i == 0)
      return;

   if (isEmpty(i-1, j))
   {
      moveDisc(i, j, i-1, j);
      dropDisc(i-1, j, c);
   }

   return;
}

/**
   REMOVE - REMOVES DISC FROM GRID
*/
void Grid::removeDisc(int i, int j)
{
   
   delete coord[i][j];
   coord[i][j] = nullptr;
}

/**
   PlAY - FORCES PLAYERS TO FOLLOW RULES
*/
void Grid::play(int x, bool c)
{
   addDisc(HEIGHT, x, c);
   dropDisc(HEIGHT, x, c);
}

