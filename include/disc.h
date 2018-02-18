#ifndef DISC_H
#define DISC_H

#include "stdio.h"
#include <exception>

class Disc
{
  public:
/**
   Default contrustor: will assume colour is black
*/
   explicit Disc() { colour = false;}


/**
   Constructor: sets colour to variable c
*/
   explicit Disc(const bool c) {colour = c;}


/**
   Destructor:
*/
   virtual ~Disc() {}


/**
   Getter function: will return the value for colour
*/
   virtual bool getColour() {return colour;}
   
  private:
/**
   The colour is represented as a bool because it can only be
   one of two colours. For simplicity:

   ZERO/FALSE == BLACK
   ONE/TRUE == RED
 */
   bool colour;
};

#endif
