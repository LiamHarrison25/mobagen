#include "Cat.h"
#include "World.h"
#include <queue>
#include <stdexcept>
#include <map>

Point2D Cat::Move(World* world) {

  Point2D catPos = world->getCat();
  int worldSize = world->getWorldSideSize();

  //Get the closest exit position

  Point2D exitPoint = Point2D(3, 3); //TODO: change
  int i, j;
  for(i = -(world->getWorldSideSize() / 2); i < worldSize / 2; i++)
  {
    for(j = -(world->getWorldSideSize() / 2); j < worldSize / 2; j++)
    {
      //go through every point and detect if it is an end point
      //TODO: Find the nearest exit
      //world->catWinsOnSpace()

    }
  }

  std::queue<Point2D> frontier; //queue used to store the next points to visit
  std::vector<Point2D> reached; //vector used to store the points that have been reached already
  std::map<int, Point2D> cameFrom; //map used to store the location from where a point came. The key is an int which is a 1d representation of a point2D.

  //Gets the initial neighbors

  if(world->catCanMoveToPosition(world->E(catPos)))
  {
    frontier.push(world->E(catPos));
    cameFrom.emplace(worldSize * world->E(catPos).x + world->E(catPos).y, catPos);
  }

  if(world->catCanMoveToPosition(world->SE(catPos)))
  {
    frontier.push(world->SE(catPos));
    cameFrom.emplace(worldSize * world->SE(catPos).x + world->SE(catPos).y, catPos);
  }

  if(world->catCanMoveToPosition(world->SW(catPos)))
  {
    frontier.push(world->SW(catPos));
    cameFrom.emplace(worldSize * world->SW(catPos).x + world->SW(catPos).y, catPos);
  }

  if(world->catCanMoveToPosition(world->W(catPos)))
  {
    frontier.push(world->W(catPos));
    cameFrom.emplace(worldSize * world->W(catPos).x + world->W(catPos).y, catPos);
  }

  if(world->catCanMoveToPosition(world->NW(catPos)))
  {
    frontier.push(world->NW(catPos));
    cameFrom.emplace(worldSize * world->NW(catPos).x + world->NW(catPos).y, catPos);
  }

  if(world->catCanMoveToPosition(world->NE(catPos)))
  {
    frontier.push(world->NE(catPos));
    cameFrom.emplace(worldSize * world->NE(catPos).x + world->NE(catPos).y, catPos);
  }

  //Loop until there are not more points to check
  while(!frontier.empty())
  {
    Point2D currentPos = frontier.front(); //gets the next point from the frontier
    frontier.pop();

    if(currentPos == exitPoint) //if it finds the exit point, exit early
    {
      break;
    }

    //These check whether the point can be moved to and if they have already been reached.

    if(world->catCanMoveToPosition(world->E(currentPos)) && pointNotVisited(reached,world->E(currentPos)))
    {
      frontier.push(world->E(currentPos)); //adds it to the frontier
      reached.push_back(world->E(currentPos)); //adds it to the reached
      cameFrom.emplace(worldSize * world->E(currentPos).x + world->E(currentPos).y, currentPos); //stores where it came from.
    }
    if(world->catCanMoveToPosition(world->SE(currentPos)) && pointNotVisited(reached,world->SE(currentPos)))
    {
      frontier.push(world->SE(currentPos));
      reached.push_back(world->SE(currentPos));
      cameFrom.emplace(worldSize * world->SE(currentPos).x + world->SE(currentPos).y, currentPos);
    }

    if(world->catCanMoveToPosition(world->SW(currentPos)) && pointNotVisited(reached,world->SW(currentPos)))
    {
      frontier.push(world->SW(currentPos));
      reached.push_back(world->SW(currentPos));
      cameFrom.emplace(worldSize * world->SW(currentPos).x + world->SW(currentPos).y, currentPos);
    }

    if(world->catCanMoveToPosition(world->W(currentPos)) && pointNotVisited(reached,world->W(currentPos)))
    {
      frontier.push(world->W(currentPos));
      reached.push_back(world->W(currentPos));
      cameFrom.emplace(worldSize * world->W(currentPos).x + world->W(currentPos).y, currentPos);
    }

    if(world->catCanMoveToPosition(world->NW(currentPos)) && pointNotVisited(reached,world->NW(currentPos)))
    {
      frontier.push(world->NW(currentPos));
      reached.push_back(world->NW(currentPos));
      cameFrom.emplace(worldSize * world->NW(currentPos).x + world->NW(currentPos).y, currentPos);
    }

    if(world->catCanMoveToPosition(world->NE(currentPos)) && pointNotVisited(reached,world->NE(currentPos)))
    {
      frontier.push(world->NE(catPos));
      reached.push_back(world->NE(currentPos));
      cameFrom.emplace(worldSize * world->NE(currentPos).x + world->NE(currentPos).y, currentPos);
    }

  }

  //Gets the point to move towards
  Point2D currentPos = exitPoint;
  Point2D previousPos;
  while(currentPos != catPos) //loops through to make the path
  {
    previousPos = currentPos;
    currentPos = cameFrom[worldSize * currentPos.x + currentPos.y]; //gets the pos where it came from
  }

  return previousPos;

}

bool Cat::pointNotVisited(const std::vector<Point2D>& reached, const Point2D neighbor)
{
  int j;
  for(j = 0; j < reached.size(); j++)
  {
    if(neighbor == reached[j])
    {
      return false;
    }
  }

  return true; //returns that this is a new point
}
