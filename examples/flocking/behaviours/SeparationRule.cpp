#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to avoid boids too close
  Vector2f separatingForce = Vector2f::zero();

      float desiredDistance = desiredMinimalDistance;
  //
  //    //checks to make sure that there are neighbors
        if (!neighborhood.empty()) {

            int countCloseFlockmates = 0;

            Vector2f Acc = Vector2f(0, 0);

            //iterate through the neighborhood and only move away the neighbors that are less than the separation radius
            int i;
            for (i = 0; i < neighborhood.size(); i++)
            {
              //gets the direction of a neighbor
              Vector2f differenceVector = boid->getPosition() - neighborhood[i]->getPosition();

              //gets the distance of the neighbor
              float distance = differenceVector.getMagnitude();

              if(distance < desiredDistance && distance > 0) //checks if the neighbor is in the radius
              {
                countCloseFlockmates++;
                Vector2f hat = differenceVector.normalized();
                Vector2f force = hat / (distance / desiredDistance);
                Acc += force; //adds to the accumulative force
              }

              if(countCloseFlockmates > 0)
              {
                separatingForce = (Acc / countCloseFlockmates); //gets the separating force
              }
            }
        }
  separatingForce = Vector2f::normalized(separatingForce);

  return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
  ImGui::SetCurrentContext(world->engine->window->imGuiContext);
  bool valusHasChanged = false;

  if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
    valusHasChanged = true;
  }

  return valusHasChanged;
}
