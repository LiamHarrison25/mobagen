#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2f AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to match the heading of neighbors = Average velocity
  Vector2f averageVelocity = Vector2f::zero();

  //checks to make sure that there are neighbors
  if(!neighborhood.empty())
  {
    float x = 0, y = 0;
    int i;
    for(i = 0; i < neighborhood.size(); i++) //iterate over the neighborhood
    {

      //get the average velocity of the group
      x += neighborhood[i]->getVelocity().x;
      y += neighborhood[i]->getVelocity().y;
    }

    averageVelocity = Vector2f(x, y);
    averageVelocity = averageVelocity / neighborhood.size();

  }

  return Vector2f::normalized(averageVelocity);
}

