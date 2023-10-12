#include "Cat.h"
#include "World.h"
#include <queue>
#include <stdexcept>
#include <map>

Point2D Cat::Move(World* world) {

  Point2D catPos = world->getCat();
  int worldSize = world->getWorldSideSize();

  std::queue<Point2D> frontier; //queue used to store the next points to visit
  std::vector<Point2D> reached; //vector used to store the points that have been reached already //TODO: remove this and check using the cameFrom
  std::map<int, Point2D> cameFrom; //map used to store the location from where a point came. The key is an int which is a 1d representation of a point2D.

  Point2D exitPoint = Point2D(0, 0);

  frontier.push(catPos);
  reached.push_back(catPos);

  //Loop until there are not more points to check
  while(!frontier.empty())
  {
    Point2D currentPos = frontier.front(); //gets the next point from the frontier
    frontier.pop();

    //check if the point is -side / 2 or side /2
    //if it is, it is going to be an end point

    if(worldSize * currentPos.y + currentPos.x == worldSize / 2 || worldSize * currentPos.y + currentPos.x == -worldSize / 2) //if it finds the exit point, exit early
    {
      //found an end point
      exitPoint = currentPos;
      break;
    }

    //These check whether the point can be moved to and if they have already been reached.

    if(world->getContent(world->E(currentPos)) == 0 && pointNotVisited(reached,world->E(currentPos)))
    {
      frontier.push(world->E(currentPos)); //adds it to the frontier
      reached.push_back(world->E(currentPos)); //adds it to the reached
      cameFrom.emplace(worldSize * world->E(currentPos).x + world->E(currentPos).y, currentPos); //stores where it came from.
    }

    if(world->getContent(world->SE(currentPos)) == 0 && pointNotVisited(reached,world->SE(currentPos)))
    {
      frontier.push(world->SE(currentPos));
      reached.push_back(world->SE(currentPos));
      cameFrom.emplace(worldSize * world->SE(currentPos).x + world->SE(currentPos).y, currentPos);
    }

    if(world->getContent(world->SW(currentPos)) == 0 && pointNotVisited(reached,world->SW(currentPos)))
    {
      frontier.push(world->SW(currentPos));
      reached.push_back(world->SW(currentPos));
      cameFrom.emplace(worldSize * world->SW(currentPos).x + world->SW(currentPos).y, currentPos);
    }

    if(world->getContent(world->W(currentPos)) == 0 && pointNotVisited(reached,world->W(currentPos)))
    {
      frontier.push(world->W(currentPos));
      reached.push_back(world->W(currentPos));
      cameFrom.emplace(worldSize * world->W(currentPos).x + world->W(currentPos).y, currentPos);
    }

    if(world->getContent(world->NW(currentPos)) == 0 && pointNotVisited(reached,world->NW(currentPos)))
    {
      frontier.push(world->NW(currentPos));
      reached.push_back(world->NW(currentPos));
      cameFrom.emplace(worldSize * world->NW(currentPos).x + world->NW(currentPos).y, currentPos);
    }

    if(world->getContent(world->NE(currentPos)) == 0 && pointNotVisited(reached,world->NE(currentPos)))
    {
      frontier.push(world->NE(catPos));
      reached.push_back(world->NE(currentPos));
      cameFrom.emplace(worldSize * world->NE(currentPos).x + world->NE(currentPos).y, currentPos);
    }

  }

  if(exitPoint == Point2D(0, 0))
  {
    auto rand = Random::Range(0, 5);
    auto pos = world->getCat();
    switch (rand) {
      case 0:
        return World::NE(pos);
      case 1:
        return World::NW(pos);
      case 2:
        return World::E(pos);
      case 3:
        return World::W(pos);
      case 4:
        return World::SW(pos);
      case 5:
        return World::SE(pos);
      default:
        throw "random out of range";

  }

  //Gets the point to move towards
  Point2D currentPos = exitPoint;
  std::vector<Point2D> path;

  while(currentPos != catPos) //loops through to make the path
  {
    currentPos = cameFrom[worldSize * currentPos.x + currentPos.y]; //gets the pos where it came from
    path.push_back(currentPos);
  }

  return path[path.size() - 2];

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
