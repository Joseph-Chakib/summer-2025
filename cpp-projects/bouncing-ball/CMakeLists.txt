cmake_minimum_required(VERSION 3.10)
project(bouncing_ball)

set(CMAKE_CXX_STANDARD 17)

# Tell CMake where to find the correct SFMLConfig.cmake
set(CMAKE_MODULE_PATH "/opt/homebrew/opt/sfml/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(bouncing_ball main.cpp)
target_link_libraries(bouncing_ball sfml-graphics sfml-window sfml-system)

