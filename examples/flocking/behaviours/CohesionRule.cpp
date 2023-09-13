#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce;

  Vector2f centerOfMass = Vector2f(0, 0);

  //checks to make sure that there are neighbors
  if(!neighborhood.empty())
  {
    //Iterates through the neighborhood
    int i;
    for (i = 0; i < neighborhood.size(); i++)
    {
      // find center of mass
      centerOfMass += neighborhood[i]->getPosition(); //gets the center of mass of the neighbors
    }

    centerOfMass = centerOfMass / neighborhood.size();

    //DO NOT divide by re. It is already done in Mobagen.

    //find cohesionForce

    cohesionForce = centerOfMass - boid->getPosition();

    cohesionForce = cohesionForce.normalized();

  }

  return cohesionForce;
}