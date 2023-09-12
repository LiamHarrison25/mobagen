#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include "engine/Engine.h"

Vector2f SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  // Try to avoid boids too close
  Vector2f separatingForce = Vector2f::zero();

      float desiredDistance = desiredMinimalDistance;
  //
  //    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
        if (!neighborhood.empty()) {
            Vector2f position = boid->transform.position;
            int countCloseFlockmates = 0;

  //        // todo: find and apply force only on the closest mates

            //iterate through the neighborhood and only move away the neighbors that are less than the separation radius
            Vector2f Acc = Vector2f(0, 0);
            int i;
            for (i = 0; i < neighborhood.size(); i++)
            {

              //gets the direction of a neighbor
              Vector2f differenceVector = neighborhood[i]->getPosition() - boid->getPosition();

              //gets the distance of the neighbor
              float distance = differenceVector.getMagnitude();

              if(distance < desiredDistance && distance > 0)
              {
                countCloseFlockmates++;
                //Hat = Diff Vector.Normalized
                Vector2f hat = differenceVector.normalized();
                Vector2f force = hat / distance;
                Acc += force;
              }

              if(countCloseFlockmates > 0)
              {
                separatingForce = (Acc / countCloseFlockmates);
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
