#ifndef TESTDISC_CPP
#define TESTDISC_CPP

#include "../src/disc.h"
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

   EXPECT_TRUE(T.getColour());
   EXPECT_FALSE(F.getColour());  
}

#endif
