#ifndef TESTDISC_CPP
#define TESTDISC_CPP

#include "../include/grid.h"
#include "gtest/gtest.h"

/**
   Creates new grid g
   runs through every coordinate created
   expects that nullptr is found in
   every possible location
 */
TEST(GridTest, GridDefaultConstructor)
{
   Grid g;
   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
      {
	 EXPECT_EQ(g.getCoord(i,j), 0);	 
      }
}


/**
   Does virtually the same thing as the
   default constructor but adds one disc
   to the specified location
   This function was added for the sake
   of making testing easier.
   NOTE
   g is created with a 1 at (0,0)
   this constructor is actually taking
   a boolean value 1 not an integer.
   So the disc created for that space
   will be passed a 1 as well.
   Which means the disc will be RED
   our expected value should be that
   it returns RED

   Grid(x,y,TRUE) == (x,y)->RED
   Grid(x,y,FALSE) == (x,y)->BLACK
 */
TEST(GridTest, GridContructor)
{
   Grid g(0,0,1);
   EXPECT_EQ(g.getCoord(0,0),2);
   EXPECT_EQ(g.getCoord(0,1),0);
}

/**
   Copy Constructor first initializes
   all variables to nullptr.
   Then for each non empty space in g
   it creates a new disc with same value
   for the same space in h.
   Expected values should both be equal
 */
TEST(GridTest, GridCopy)
{
   Grid *g = new Grid(0, 0, 1);
   Grid h(*g);
   EXPECT_EQ(g->getCoord(0,0), 2);
   EXPECT_EQ(g->getCoord(5,5), 0);
   EXPECT_EQ(g->getCoord(3,3), 0);
   EXPECT_EQ(h.getCoord(0,0), 2);
   EXPECT_EQ(h.getCoord(5,5), 0);
   EXPECT_EQ(h.getCoord(3,3), 0);
   delete g;
}

/**
   Assignment operator is the exact same
   as copy construtor execpt that it
   doesn't need to initialize all values
   to nullptr because the default
   constructor already did that
 */
TEST(GridTest, GridAssignmentOperator)
{
   Grid g(1,1,1);
   Grid h;
   h = g;
   EXPECT_EQ(g.getCoord(0,0), 0);
   EXPECT_EQ(g.getCoord(1,1), 2);
   EXPECT_EQ(g.getCoord(0,1), 0);
   EXPECT_EQ(g.getCoord(1,0), 0);
   EXPECT_EQ(h.getCoord(0,1), 0);
   EXPECT_EQ(h.getCoord(1,0), 0);
   EXPECT_EQ(h.getCoord(0,0), 0);
   EXPECT_EQ(h.getCoord(1,1), 2);
}

/**
   Equality operator: Runs through every
   space on the grid. If the two values
   are not equal ever, it immediately
   returns false. If it gets to the end of
   the loop, it returns true
*/
TEST(GridTest, GridEquality)
{
   Grid g(0,0,0);
   Grid f(0,0,1); 
   EXPECT_FALSE(f == g);

   Grid x(0,0,0);
   Grid y(0,0,1);
   Grid z;

   EXPECT_TRUE(g == x);
   EXPECT_EQ(x.getCoord(0,0), 1);
   EXPECT_EQ(g.getCoord(0,0), 1);
   EXPECT_TRUE(f == y);
   EXPECT_FALSE(x == y);
   EXPECT_EQ(x.getCoord(0,0), 1);
   EXPECT_EQ(y.getCoord(0,0), 2);
   EXPECT_FALSE(x == z);
   EXPECT_FALSE(y == z);
   EXPECT_FALSE(g == y);
   EXPECT_FALSE(g == z);
   EXPECT_FALSE(g == f);
   EXPECT_FALSE(f == z);
   
}


/**
   Inequality: simply calls the inverse
   of the equality operator should
   work flawlessly. Still will be tested.
 */
TEST(GridTest, GridInEquality)
{
   Grid a(0,0,0);
   Grid b(0,0,1);
   Grid c;

   EXPECT_TRUE(a != b);
   EXPECT_TRUE(a != c);
   EXPECT_TRUE(b != c);

   c = a;

   EXPECT_FALSE(c != a);
   EXPECT_EQ(c.getCoord(0,0), 1);
   EXPECT_EQ(c.getCoord(0,1), 0);
   EXPECT_EQ(c.getCoord(1,0), 0);
   EXPECT_EQ(c.getCoord(1,1), 0);
   EXPECT_EQ(a.getCoord(0,0), 1);
}

TEST(GridTest, GridDiscAdd)
{
   Grid a(0,0,0);
   ASSERT_EQ(a.getCoord(0,0), 1);
   ASSERT_EQ(a.getCoord(5,5), 0);

   a.addDisc(5,5,1);

   EXPECT_EQ(a.getCoord(0,0), 1);
   EXPECT_EQ(a.getCoord(5,5), 2);
}

TEST(GridTest, GridMove)
{
   Grid a(0,0,0);
   ASSERT_EQ(a.getCoord(0,0), 1);

   a.moveDisc(0,0, 5,5);

   EXPECT_EQ(a.getCoord(0,0), 0);
   EXPECT_EQ(a.getCoord(5,5), 1);
}

TEST(GridTest, GridDrop)
{
   Grid a(0,0,0);
   ASSERT_EQ(a.getCoord(0,0), 1);
   ASSERT_EQ(a.getCoord(5,1), 0);
   ASSERT_EQ(a.getCoord(4,1), 0);
   ASSERT_EQ(a.getCoord(3,1), 0);
   ASSERT_EQ(a.getCoord(2,1), 0);
   ASSERT_EQ(a.getCoord(1,1), 0);
   ASSERT_EQ(a.getCoord(0,1), 0);

   a.addDisc(5,1,0);
   a.dropDisc(5, 1, 0);

   EXPECT_EQ(a.getCoord(0,0), 1);
   EXPECT_EQ(a.getCoord(5,1), 0);
   EXPECT_EQ(a.getCoord(4,1), 0);
   EXPECT_EQ(a.getCoord(3,1), 0);
   EXPECT_EQ(a.getCoord(2,1), 0);
   EXPECT_EQ(a.getCoord(1,1), 0);
   EXPECT_EQ(a.getCoord(0,1), 1);
}

TEST(GridTest, GridRemove)
{
   Grid a(0,0,0);
   ASSERT_EQ(a.getCoord(0,0),1);

   a.removeDisc(0,0);

   EXPECT_EQ(a.getCoord(0,0),0);
}

TEST(GridTest, GridPlay)
{
   Grid a;
   a.play(0, true);
   a.play(4, false);
   a.play(6, true);
   a.play(4, true);

   EXPECT_EQ(a.getCoord(0,0), 2);
   EXPECT_EQ(a.getCoord(0,4), 1);
   EXPECT_EQ(a.getCoord(1,4), 2);
   EXPECT_EQ(a.getCoord(0,6), 2);
}

TEST(GridTest, GridEmpty)
{
   Grid a(0,0,1);
   Grid b;

   for(int i = 0; i < HEIGHT; i++)
      for(int j = 0; j < WIDTH; j++)
      {
	 b.play(j, true);
      }

   EXPECT_FALSE(a.isFull());
   EXPECT_TRUE(b.isFull());
}

TEST(GridTest, GridRow)
{
   Grid a;
   
   EXPECT_FALSE(a.isRow(0,2));
   
   a.play(1, true);
   a.play(2, true);
   a.play(3, true);
   a.play(4, true);

   EXPECT_FALSE(a.isEmpty(0,3));
   EXPECT_TRUE(a.isRow(0,3));
   EXPECT_EQ(a.getCoord(0,1), 2);
   EXPECT_EQ(a.getCoord(0,2), 2);
   EXPECT_EQ(a.getCoord(0,3), 2);
   EXPECT_EQ(a.getCoord(0,4), 2);
   EXPECT_EQ(a.getCoord(0,0), 0);
   EXPECT_EQ(a.getCoord(0,5), 0);
   EXPECT_EQ(a.getCoord(0,6), 0);
}

TEST(GridTest, GridScore)
{
   Grid a;
   a.play(0,true);
   a.play(0,true);
   a.play(0,true);
   a.play(0,true);

   EXPECT_TRUE(a.isFinished());
}
#endif
