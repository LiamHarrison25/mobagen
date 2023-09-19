//
// Created by atolstenko on 2/9/2023.
//

#include "HexagonGameOfLife.h"
void HexagonGameOfLife::Step(World& world) {

  int i, j;
  for(i = 0; i < world.SideSize(); i++)
  {
    for(j = 0; j < world.SideSize(); j++)
    {
      Point2D currentPoint = Point2D(i, j);
      bool isAlive = world.Get(currentPoint);
      int numNeighbors = CountNeighbors(world, currentPoint);

      if(isAlive)
      {
        if (numNeighbors <= 1)
        {
          world.SetNext(currentPoint, false); //turns off the point
        }
        else if (numNeighbors >= 3)
        {
          world.SetNext(currentPoint, false); //turns off the point
        }
        else if(numNeighbors == 2)
        {
          world.SetNext(currentPoint, true); //keeps the point on
        }
      }
      else
      {
        if(numNeighbors == 2)
        {
          world.SetNext(currentPoint, true); //turns on the point
        }
      }
    }
  }

}
int HexagonGameOfLife::CountNeighbors(World& w, Point2D p) {
if(p.y %2 == 0) //if even row
  {
    return
        w.Get(p + Point2D(-1, -1)) + //Top Left
        w.Get(p + Point2D(0, -1)) + //Top Right
        w.Get(p + Point2D(-1, 0)) + //Left
        w.Get(p + Point2D(1, 0)) +
        w.Get(p + Point2D(-1, 1)) +
        w.Get(p + Point2D(0, 1));
  }
  else
  {
    return
        w.Get(p + Point2D(0, -1)) + //Top Left
        w.Get(p + Point2D(1, -1)) + //Top Right
        w.Get(p + Point2D(-1, 0)) + //Left
        w.Get(p + Point2D(1, 0)) +
        w.Get(p + Point2D(0, 1)) +
        w.Get(p + Point2D(1, 1));
  }

}

