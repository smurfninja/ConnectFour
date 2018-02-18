#ifndef MOCKVIEW_CPP
#define MOCKVIEW_CPP

#include "view.h"
#include "gmock/gmock.h"

class MockView : public View
{
public:
   MOCK_METHOD1(getChoice, int(int p));
   MOCK_METHOD0(getPlayers, int());
   MOCK_METHOD1(viewDisc, void(int x));
   MOCK_METHOD1(viewGrid, void(Grid &g));
};

#endif
