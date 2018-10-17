#include <catch2/catch.hpp>

#include <glm/glm.hpp>

#include <cmath>

#include "ray.hpp"

constexpr float pi = 3.1415926f;

constexpr auto deg_to_rad(float deg) -> float { return deg / 180.0f * pi; }

class Camera {
public:
  Camera(glm::vec3 eye, glm::vec3 direction, glm::vec3 up, float fov)
      : eye_{eye}, direction_{glm::normalize(direction)},
        horizontal_{glm::normalize(glm::cross(direction_, up))},
        up_{glm::cross(direction_, horizontal_)}, fov_{fov}
  {
  }

  auto direction() const -> glm::vec3 { return direction_; }

  auto horizontal() const -> glm::vec3 { return horizontal_; }

  auto up() const -> glm::vec3 { return up_; }

  auto eye() const -> glm::vec3 { return eye_; }

private:
  glm::vec3 eye_;

  glm::vec3 direction_;
  glm::vec3 horizontal_;
  glm::vec3 up_;

  float fov_;
};

TEST_CASE("Radian to degree")
{
  GIVEN("90 degree")
  {
    THEN("equal to pi / 2 radian") { REQUIRE(deg_to_rad(90) == pi / 2); }
  }
}

TEST_CASE("Camera test")
{
  GIVEN("A camera at (1,1,1) with direction (1, 1, 1)"
        "and up direction (0, 1, 0) fov 45 degree")
  {
    Camera c{{1, 1, 1}, {1, 1, 1}, {0, 1, 0}, deg_to_rad(45)};

    THEN("Camera is at (1,1,1)")
    {
      const auto eye = c.eye();
      REQUIRE(eye.x == Approx(1));
      REQUIRE(eye.y == Approx(1));
      REQUIRE(eye.z == Approx(1));
    }

    THEN("Direction is at (1,1,1) / sqrt(3)")
    {
      const auto d = c.direction();
      REQUIRE(d.x == Approx(1 / sqrt(3)));
      REQUIRE(d.y == Approx(1 / sqrt(3)));
      REQUIRE(d.z == Approx(1 / sqrt(3)));
    }

    THEN("Vectors are orthogonal")
    {
      REQUIRE(glm::dot(c.direction(), c.horizontal()) == Approx(0));
      REQUIRE(glm::dot(c.direction(), c.up()) == Approx(0));
      REQUIRE(glm::dot(c.up(), c.horizontal()) == Approx(0));
    }
  }
}
