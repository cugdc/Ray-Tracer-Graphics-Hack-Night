add_library(lib${PROJECT_NAME}
    "color.hpp"
    "image.hpp"
    "image.cpp"
    "ray.hpp")

target_include_directories(lib${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} lib${PROJECT_NAME})
