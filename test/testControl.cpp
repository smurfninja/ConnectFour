#ifndef TESTCONTROL_CPP
#define TESTCONTROL_CPP

#include "mockGrid.cpp"
#include "../include/control.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
using ::testing::AtLeast;

TEST(TestControl, TestPlay)
{
   Grid *g = new MockGrid();
   Controller *c = new Controller(*g);
}


#endif
