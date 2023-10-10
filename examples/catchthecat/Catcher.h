#ifndef CATCHER_H
#define CATCHER_H

#include "Agent.h"
#include <vector>

class Catcher : public Agent {
public:
  explicit Catcher() : Agent(){};
  Point2D Move(World*) override;
  bool pointNotVisited(const std::vector<Point2D>& reached, const Point2D neighbor);
};

#endif  // CATCHER_H
