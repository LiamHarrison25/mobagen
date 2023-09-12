#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce;

  // todo: add your code here to make a force towards the center of mass
  // hint: iterate over the neighborhood

  Vector2f centerOfMass = Vector2f(0, 0);


  if(!neighborhood.empty())
  {
    // find center of mass
    int i;
    for (i = 0; i < neighborhood.size(); i++)
    {
      centerOfMass += neighborhood[i]->getPosition();
    }

    centerOfMass = centerOfMass / neighborhood.size();

    //find cohesionForce

    //DO NOT divide by re. It is already done in Mobagen.

    //TODO: calculate the cohesion force

    cohesionForce = centerOfMass - boid->getPosition();

    //cohesionForce = boid->getPosition() - centerOfMass;
  }




  return cohesionForce;
}