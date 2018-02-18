#include "gmock/gmock.h"
#include "../include/grid.h"

class MockGrid : public Grid
{
public:
   MOCK_METHOD2(isEmpty, bool(int i, int j));
   MOCK_METHOD0(isFull, bool());
   MOCK_METHOD0(isFinished, bool());
   MOCK_METHOD2(getCoord, int(int i, int j));
   MOCK_METHOD3(addDisc, void(int x, int y, bool c));
   MOCK_METHOD3(moveDisc, void(int i, int j, bool c));
   MOCK_METHOD3(dropDisc, void(int i, int j, bool c));
   MOCK_METHOD2(removeDisc, void(int i, int j));
   MOCK_METHOD2(play, void(int x, bool c));
};
