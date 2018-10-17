add_executable(${PROJECT_NAME}Test "main.cpp" "image_test.cpp" "ray_test.cpp" "camera_test.cpp")

target_link_libraries(${PROJECT_NAME}Test lib${PROJECT_NAME})
