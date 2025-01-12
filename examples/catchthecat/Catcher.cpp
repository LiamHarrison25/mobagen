#include "Catcher.h"
#include "World.h"
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>

Point2D Catcher::Move(World* world) {

  Point2D catPos = world->getCat();
  int worldSize = world->getWorldSideSize();

  //TODO: Implement these new unordered maps and unordered sets
  std::queue<Point2D> frontier; //queue used to store the next points to visit
  std::unordered_set<Point2D> frontierSet; //used to store the points that are in the frontier
  std::unordered_map<int, Point2D> cameFrom; //map used to store the location from where a point came. The key is an int which is a 1d representation of a point2D.
  std::unordered_map<bool, Point2D> visited; //map used to store the points that have been visited

  Point2D exitPoint = Point2D(0, 0);

  frontier.push(catPos);
  frontierSet.insert(catPos);

  //Loop until there are not more points to check
  while(!frontier.empty())
  {
    Point2D currentPos = frontier.front(); //gets the next point from the frontier
    frontier.pop();
    frontierSet.erase(currentPos); //removes the currentPoint from the frontier set

    //check if the point is -side / 2 or side /2
    //if it is, it is going to be an end point

    if(worldSize * currentPos.y + currentPos.x == worldSize / 2 || worldSize * currentPos.y + currentPos.x == -worldSize / 2 && world->isValidPosition(currentPos) && world->getContent(currentPos) == 0) //if it finds the exit point, exit early
    {
      //found an end point
      exitPoint = currentPos;
      break;
    }

    //TODO: make a loop that goes through each of the neighbors and checks if they are valid points, if they are not blocked, if they are not in the frontierSet, and if they are not in the visited

    //loops through each of the neighbors
    int i;
    for(i = 0; i < 5; i++)
    {
      //check if the neighbor is valid, if it is not blocked, if it is not in the frontierSet, and if it is not in visited
    }

    //These check whether the point can be moved to and if they have already been reached.

//    if(world->getContent(world->E(currentPos)) == 0 && pointNotVisited(reached,world->E(currentPos)))
//    {
//      if(world->isValidPosition(world->E(currentPos)))
//          {
//            frontier.push(world->E(currentPos)); //adds it to the frontier
//            reached.push_back(world->E(currentPos)); //adds it to the reached
//            cameFrom.emplace(worldSize * world->E(currentPos).x + world->E(currentPos).y, currentPos); //stores where it came from.
//          }
//    }
//
//    if(world->getContent(world->SE(currentPos)) == 0 && pointNotVisited(reached,world->SE(currentPos)))
//    {
//          if(world->isValidPosition(world->SE(currentPos)))
//          {
//            frontier.push(world->SE(currentPos));
//            reached.push_back(world->SE(currentPos));
//            cameFrom.emplace(worldSize * world->SE(currentPos).x + world->SE(currentPos).y, currentPos);
//          }
//    }
//
//    if(world->getContent(world->SW(currentPos)) == 0 && pointNotVisited(reached,world->SW(currentPos)))
//    {
//          if(world->isValidPosition(world->SW(currentPos)))
//          {
//            frontier.push(world->SW(currentPos));
//            reached.push_back(world->SW(currentPos));
//            cameFrom.emplace(worldSize * world->SW(currentPos).x + world->SW(currentPos).y, currentPos);
//          }
//    }
//
//    if(world->getContent(world->W(currentPos)) == 0 && pointNotVisited(reached,world->W(currentPos)))
//    {
//          if(world->isValidPosition(world->W(currentPos)))
//          {
//            frontier.push(world->W(currentPos));
//            reached.push_back(world->W(currentPos));
//            cameFrom.emplace(worldSize * world->W(currentPos).x + world->W(currentPos).y, currentPos);
//          }
//    }
//
//    if(world->getContent(world->NW(currentPos)) == 0 && pointNotVisited(reached,world->NW(currentPos)))
//    {
//          if(world->isValidPosition(world->NW(currentPos)))
//          {
//            frontier.push(world->NW(currentPos));
//            reached.push_back(world->NW(currentPos));
//            cameFrom.emplace(worldSize * world->NW(currentPos).x + world->NW(currentPos).y, currentPos);
//          }
//    }
//
//    if(world->getContent(world->NE(currentPos)) == 0 && pointNotVisited(reached,world->NE(currentPos)))
//    {
//          if(world->isValidPosition(world->NE(currentPos)))
//          {
//            frontier.push(world->NE(catPos));
//            reached.push_back(world->NE(currentPos));
//            cameFrom.emplace(worldSize * world->NE(currentPos).x + world->NE(currentPos).y, currentPos);
//          }
//    }

  }

  if(exitPoint == Point2D(0, 0))
  {
    //TODO: Add a condition for if there are no exits. If there are paths to exit, move randomly

    bool validPoint = false;
    std::vector<Point2D> randomPoints;

    //TODO: randomize the position of the points in the vector and then loop through the vector, checking if the point is valid. If the vector gets to the end, there are no moves left so just move to an invalid point
    auto rand = Random::Range(0, 5);
    auto pos = world->getCat();

    while(!validPoint)
    {
          switch (rand) {
            case 0:
              if(!world->getContent(World::NE(pos)) && world->isValidPosition(World::NE(pos)))
                return World::NE(pos);
                break;
            case 1:
              if(!world->getContent(World::NW(pos)) && world->isValidPosition(World::NW(pos)))
                return World::NW(pos);
                break;
            case 2:
              if(!world->getContent(World::E(pos)) && world->isValidPosition(World::E(pos)))
                return World::E(pos);
                break;
            case 3:
              if(!world->getContent(World::W(pos)) && world->isValidPosition(World::W(pos)))
                return World::W(pos);
                break;
            case 4:
              if(!world->getContent(World::SW(pos)) && world->isValidPosition(World::SW(pos)))
                return World::SW(pos);
                break;
            case 5:
              if(!world->getContent(World::SE(pos)) && world->isValidPosition(World::SE(pos)))
                return World::SE(pos);
                break;
            default:
              return World::SW(pos);
          }
    }
  }

  //Gets the point to move towards
  Point2D currentPos = exitPoint;
  std::vector<Point2D> path;

  while(currentPos != catPos) //loops through to make the path
  {
    currentPos = cameFrom[worldSize * currentPos.x + currentPos.y]; //gets the pos where it came from
    path.push_back(currentPos);
  }

  //clears everything
  reached.clear();
  cameFrom.clear();

  return path[1];

}

bool Catcher::pointNotVisited(const std::vector<Point2D>& reached, const Point2D neighbor)
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
