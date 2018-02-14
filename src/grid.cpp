#include "grid.h"

Grid::Grid()
{
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
	 coord[i][j] = nullptr;
}

Grid::~Grid()
{
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
	 coord[i][j] = nullptr;
}

bool Grid::isEmpty(int i, int j)
{
   if (coord[i][j] == nullptr)
      return true;
   return false;
}

int Grid::getCoord(int i, int j)
{
   if (isEmpty(i,j))
      return 0;
   return coord[i][j]->getColour();
}
