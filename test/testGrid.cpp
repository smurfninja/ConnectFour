#ifndef TESTDISC_CPP
#define TESTDISC_CPP

#include "../src/grid.cpp"
#include "gtest/gtest.h"

TEST(GridTest, GridDefaultConstructor)
{
   Grid g;
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
      {
	 EXPECT_EQ(g.getCoord(i,j), 0);	 
      }
}

TEST(GridTest, GridContructor)
{
   Grid *g = new Grid(0,0,1);
   EXPECT_EQ(g->getCoord(0,0),2);
   EXPECT_EQ(g->getCoord(0,1),0);
   delete g;
}

TEST(GridTest, GridDrop)
{
   Grid g;
}

#endif
