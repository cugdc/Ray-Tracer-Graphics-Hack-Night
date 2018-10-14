#include <cstdio>

#include "image.hpp"

int main()
{
  Image image{800, 600};
  for (auto y = std::size_t{0}; y < 10; ++y) {
    for (auto x = std::size_t{0}; x < 10; ++x) {
      image.color_at(x, y) = Color{1, 0, 0};
    }
  }
  image.saveto("output.png");
  std::puts("Done!");
}
