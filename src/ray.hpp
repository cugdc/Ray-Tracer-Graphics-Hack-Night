#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>

// ray
struct Ray {
  glm::vec3 origin;
  glm::vec3 direction;

  auto operator()(float t) -> glm::vec3 { return origin + direction * t; }
};


#endif // RAY_HPP
