#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <regex>
#include <type_traits>

#include <glm/common.hpp>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include "image.hpp"

template <class Dest, class Source> inline Dest bit_cast(const Source& source)
{
  static_assert(sizeof(Dest) == sizeof(Source),
                "bit_cast requires source and destination to be the same size");
  static_assert(std::is_trivially_copyable_v<Dest>,
                "bit_cast requires the destination type to be copyable");
  static_assert(std::is_trivially_copyable_v<Source>,
                "bit_cast requires the source type to be copyable");
  Dest dest;
  memcpy(&dest, &source, sizeof(dest));
  return dest;
}

constexpr auto float_color_to_byte(float color) -> std::byte
{
  return static_cast<std::byte>(static_cast<unsigned char>(255.99f * color));
}

Image::Image(size_t width, size_t height)
    : width_(width), height_(height), data_(width * height)
{
}

void Image::saveto(const std::string& filename) const
{
  std::regex png{R"(.*\.png$)"};
  if (!std::regex_match(filename, png)) {
    throw Unsupported_image_extension{filename.c_str()};
  }

  std::vector<std::byte> buffer;
  buffer.reserve(data_.size() * 3);
  for (auto i = data_.crbegin(), end = data_.crend(); i != end; ++i) {
    const auto color = glm::clamp(*i, Color{0, 0, 0}, Color{1, 1, 1});

    const auto red = float_color_to_byte(std::sqrt(color.r));
    const auto green = float_color_to_byte(std::sqrt(color.g));
    const auto blue = float_color_to_byte(std::sqrt(color.b));

    buffer.push_back(blue);
    buffer.push_back(green);
    buffer.push_back(red);
  }
  std::reverse(std::begin(buffer), std::end(buffer));

  stbi_write_png(filename.c_str(), int(width_), int(height_), 3,
                 bit_cast<void*>(buffer.data()), int(width_ * 3));
}
