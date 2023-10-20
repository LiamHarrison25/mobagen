#include "../World.h"
#include "Random.h"
#include "RecursiveBacktrackerExample.h"
#include <climits>


Color32 color1;

bool RecursiveBacktrackerExample::Step(World* w) {

  //dfs steps:
  //detect which tiles are visitable
  //if none are visitable, pull from the stack and go to that
  //else:
  //Go to a random visitable tile
  //add that tile to the stack

  Point2D nextPoint;

  Point2D p;

  if(stack.empty())
  {

  }

  std::vector visitables = getVisitables(w, p); //gets a vector that stores all the visitable points


  if(visitables.empty() && !stack.empty())
  {
    //take a point from the stack and move there

    //Treat the vector as a stack by using in reverse

    nextPoint = stack.back();
    //stack.erase(stack.back());

    //TODO: Move to the next point
    //visited.insert(p)
    color1.Dark();
    w->SetNodeColor(p, Color::Blue); //sets the new color

    //TODO: Insert the node into the visitables map
    //visitables.insert(p, )

  }
  else if(stack.empty() && visitables.empty())
  {
    return true;
  }
  else
  {
    int upperRange = visitables.size();

    //go to a random visitable tile
    int random = 0;

    //TODO: set random to a random number between 0 and upperRange

    nextPoint = visitables[random];

    //add that tile into the stack
    //stack.insert(stack.front(), nextPoint)
  }


}

void RecursiveBacktrackerExample::Clear(World* world) {
  visited.clear();
  stack.clear();
  auto sideOver2 = world->GetSize() / 2;

  for (int i = -sideOver2; i <= sideOver2; i++) {
    for (int j = -sideOver2; j <= sideOver2; j++) {
      visited[i][j] = false;
    }
  }
}
Point2D RecursiveBacktrackerExample::randomStartPoint(World* world) {
  auto sideOver2 = world->GetSize() / 2;

  // todo: change this if you want
  for (int y = -sideOver2; y <= sideOver2; y++)
    for (int x = -sideOver2; x <= sideOver2; x++)
      if (!visited[y][x]) return {x, y};
  return {INT_MAX, INT_MAX};
}

std::vector<Point2D> RecursiveBacktrackerExample::getVisitables(World* w, const Point2D& p) {
  auto sideOver2 = w->GetSize() / 2;
  std::vector<Point2D> visitables;

  //TODO: Get the visitables

  return visitables;
}
