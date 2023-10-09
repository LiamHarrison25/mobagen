#ifndef CAT_H
#define CAT_H

#include "Agent.h"
#include <vector>

class Cat : public Agent {
public:
  explicit Cat() : Agent(){};
  Point2D Move(World*) override;
  bool pointNotVisited(const std::vector<Point2D>& reached, const Point2D neighbor);
};

#endif  // CAT_H
