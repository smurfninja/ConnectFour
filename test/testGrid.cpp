#ifndef TESTDISC_CPP
#define TESTDISC_CPP

#include "../src/grid.cpp"
#include "gtest/gtest.h"

TEST(GridTest, GridDefaultConstructor)
{
   Grid g = Grid();
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
      {
	 EXPECT_EQ(g.getCoord(i,j), 0);	 
      }
}

#endif