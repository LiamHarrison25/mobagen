#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2f AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to match the heading of neighbors = Average velocity
  Vector2f averageVelocity = Vector2f::zero();

  // todo: add your code here to align each boid in a neighborhood
  // hint: iterate over the neighborhood

  if(!neighborhood.empty())
  {
    float x = 0, y = 0;
    int i;
    for(i = 0; i < neighborhood.size(); i++) //iterate over the neighborhood
    {
      //do math here to alignment

      //get the average velocity of the group
      x += neighborhood[i]->getVelocity().x;
      y += neighborhood[i]->getVelocity().y;

      //boid->getDetectionRadius()
    }

    averageVelocity = Vector2f(x, y);
    averageVelocity = averageVelocity / neighborhood.size();

    //averageVelocity = {x/neighborhood.size(), y/neighborhood.size()};
  }

  return Vector2f::normalized(averageVelocity);
}

