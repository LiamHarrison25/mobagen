#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {

  //(0,0) is the top left of the grid

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
        else if (numNeighbors >= 4)
        {
          world.SetNext(currentPoint, false); //turns off the point
        }
        else if(numNeighbors == 2 || numNeighbors == 3)
        {
          world.SetNext(currentPoint, true); //keeps the point on
        }
      }
      else
      {
        if(numNeighbors == 3)
        {
          world.SetNext(currentPoint, true); //turns on the point
        }
      }
    }
  }
}

int JohnConway::CountNeighbors(World& w, Point2D p) {
  return
      w.Get(p.Up().Left())+
      w.Get(p.Up()) +
      w.Get(p.Up().Right()) +
      w.Get(p.Left()) +
      w.Get(p.Right()) +
      w.Get(p.Down().Left()) +
      w.Get(p.Down()) +
      w.Get(p.Down().Right());
}
