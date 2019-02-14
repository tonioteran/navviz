/**
 * @file Environment.cpp
 * @brief OpenGL wrapper for specifying viz environment
 * @date Feb 13, 2019
 * @author Antonio Teran (teran@mit.edu)
 */

#include "navviz/Environment.h"

namespace vv {

/* ************************************************************************** */
Environment::Environment() {}
Environment::Environment(const unsigned int scr_width,
    const unsigned int scr_height) : scr_width_(scr_width),
                                     scr_height_(scr_height) {
}

/* ************************************************************************** */
Environment::~Environment() {}



/* ************************************************************************** */
void Environment::initialize() {

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // create the window
  // std::shared_ptr<GLFWwindow> window = std::make_shared<GLFWwindow>(
  //             glfwCreateWindow(scr_width_, scr_height_, "World", NULL, NULL) );
  GLFWwindow* window = glfwCreateWindow(scr_width_, scr_height_,
                                        "World", NULL, NULL);
  if (window == NULL) {
    std::cout << "Environment::Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }
  
}




}// namespace
