#ifndef TESTDISC_CPP
#define TESTDISC_CPP

#include "../include/disc.h"
#include "gtest/gtest.h"

TEST(DiscTest, DiscDefaultConstructor)
{
   Disc *d = new Disc();
   EXPECT_FALSE(d->getColour());
   delete d;
}

TEST(DiscTest, DiscConstructor)
{
   Disc T = Disc(true);
   Disc F = Disc(false);
   Disc error = Disc(3);
   Disc neg = Disc(-1);
   Disc zero = Disc(0);

   EXPECT_FALSE(zero.getColour());
   EXPECT_NE(neg.getColour(), false);
   EXPECT_NE(error.getColour(), false);
   EXPECT_TRUE(T.getColour());
   EXPECT_FALSE(F.getColour());  
}

#endif
