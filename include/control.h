#ifndef CONTROL_CPP
#define CONTROL_CPP

#include "view.h"

class Controller
{
  public:
   Controller(Grid &g);
   void play();
  private:
   const Grid *game;
};


#endif
