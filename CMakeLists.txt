cmake_minimum_required(VERSION 3.12)
project(NavigationVisualizationLib VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-W -Wall -Wextra -Wpedantic)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Eigen REQUIRED)

set(GLAD_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/glad/includes/")
add_library("glad" "${CMAKE_CURRENT_SOURCE_DIR}/extern/glad/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_INCLUDE_DIR}")

set(STB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/stb/")

add_library(navviz
  )
target_include_directories(navviz
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE src)
target_link_libraries(navviz
  PUBLIC Eigen3::Eigen3 OpenGL glad glfw "${STB_INCLUDE_DIR}")

# set(NAVVIZ_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes/")
# set(STB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/extern/stb/")
# add_definitions( -DREPO_DIR_PATH=${CMAKE_CURRENT_SOURCE_DIR} )

add_subdirectory(apps)
add_subdirectory(tests)





