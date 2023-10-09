#include "Cat.h"
#include "World.h"
#include <queue>
#include <stdexcept>
#include <map>

Point2D Cat::Move(World* world) {

  Point2D catPos = world->getCat();

  //Get the closest exit position

  Point2D exitPoint;
  int i, j;
  for(i = -(world->getWorldSideSize() / 2); i < world->getWorldSideSize() / 2; i++)
  {
    for(j = -(world->getWorldSideSize() / 2); j < world->getWorldSideSize() / 2; j++)
    {
      //go through every point and detect if it is an end point
      //world->catWinsOnSpace()

    }
  }

  //Loop until it finds a point to move to

  std::queue<Point2D> frontier;
  std::vector<Point2D> reached;
  std::map<Point2D, Point2D> cameFrom;

  //TODO: insert the catPos into the cameFrom map for all of these

  frontier.push(world->E(catPos));

  frontier.push(world->SE(catPos));

  frontier.push(world->SW(catPos));

  frontier.push(world->W(catPos));

  frontier.push(world->NW(catPos));

  frontier.push(world->NE(catPos));

  while(!frontier.empty())
  {
    //Gets the neighbors:
    Point2D currentPos = frontier.back();
    frontier.pop();

    if(currentPos == exitPoint)
    {
      break;
    }
    //TODO: Insert all of these into the cameFrom map: (world->X(currentPos), currentPos) // x: the direction

    if(world->catCanMoveToPosition(world->E(currentPos)) && pointNotVisited(reached,world->E(currentPos)))
    {
      frontier.push(world->E(currentPos));
      reached.push_back(world->E(currentPos));
    }
    if(world->catCanMoveToPosition(world->SE(currentPos)) && pointNotVisited(reached,world->SE(currentPos)))
    {
      frontier.push(world->SE(currentPos));
      reached.push_back(world->SE(currentPos));
    }

    if(world->catCanMoveToPosition(world->SW(currentPos)) && pointNotVisited(reached,world->SW(currentPos)))
    {
      frontier.push(world->SW(currentPos));
      reached.push_back(world->SW(currentPos));
    }

    if(world->catCanMoveToPosition(world->W(currentPos)) && pointNotVisited(reached,world->W(currentPos)))
    {
      frontier.push(world->W(currentPos));
      reached.push_back(world->W(currentPos));
    }

    if(world->catCanMoveToPosition(world->NW(currentPos)) && pointNotVisited(reached,world->NW(currentPos)))
    {
      frontier.push(world->NW(currentPos));
      reached.push_back(world->NW(currentPos));
    }

    if(world->catCanMoveToPosition(world->NE(currentPos)) && pointNotVisited(reached,world->NE(currentPos)))
    {
      frontier.push(world->NE(catPos));
      reached.push_back(world->NE(currentPos));
    }


  }

  //Gets the point to move towards
  Point2D currentPos = exitPoint;
  while(currentPos != catPos)
  {
    //TODO: set the currentPos to the position where the exit point came from
    //currentPos = cameFrom.
  }

  return currentPos;

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
