#include "catch2/catch.hpp"
#include "ray.hpp"

TEST_CASE("Ray Test")
{
  GIVEN("A ray start at (1, 1, 1`) with direction (1, 0, 0)")
  {
    Ray r{glm::vec3{1, 1, 1}, glm::vec3{1, 0, 0}};
    WHEN("Invoke with t = 1")
    {
      THEN("The point is at (2, 1, 1)")
      {
        const auto p = r(1);
        REQUIRE(p.x == Approx(2));
        REQUIRE(p.y == Approx(1));
        REQUIRE(p.z == Approx(1));
      }
    }
  }
}
