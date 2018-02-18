#ifndef VIEW_H
#define VIEW_H

#include "grid.h"
#include "stdio.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cassert>

class View
{
  public:
   virtual int getChoice(int p);
   virtual int getPlayers();
   virtual void viewDisc(int x);
   virtual void viewGrid(Grid &g);
};

#endif
