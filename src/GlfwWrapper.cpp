/**
 * @file GlfwWrapper.cpp
 * @brief glfw wrapper for encapsulating C API
 * @date Feb 13, 2019
 * @author Antonio Teran (teran@mit.edu)
 * Taken from http://www.cplusplus.com/articles/NvCRko23/
 *   all credit goes to Manu Sanchez!
 */

#include "navviz/GlfwWrapper.hpp"

namespace vv {

/* ************************************************************************** */
GlfwWrapper::GlfwWrapper(const std::string &scr_title, int scr_width,
                         int scr_height) {
  if (!glfwInit()) {
    throw std::runtime_error ("Unable to initialize glfw");
  }

  window_ = glfwCreateWindow(scr_width, scr_height,
                             scr_title.c_str(), NULL, NULL);
  if (!window_) {
    throw std::runtime_error ("Unable to initialize glfw window");
  }
  glfwMakeContextCurrent(window_);
  glfwSwapInterval(1); // TODO: find out what this does exactly?
}

/* ************************************************************************** */
GlfwWrapper::~GlfwWrapper() {
  glfwDestroyWindow(window_); // TODO: find out what this does exactly?
  glfwTerminate();
}

/* ************************************************************************** */
void GlfwWrapper::onKeydown(GLFWwindow* window, int key, int code, int a, int mod) {
  // Does nothing by default. Override to customize
}
  
/* ************************************************************************** */
void GlfwWrapper::onError(int error, const char* desc) {
  // Does nothing by default
}

/* ************************************************************************** */
void GlfwWrapper::onResize(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

/* ************************************************************************** */
void GlfwWrapper::start() {
  glfwLoop();
}

/* ************************************************************************** */
void GlfwWrapper::glfwLoop() {
  this->glLoop();

  glfwSwapBuffers(window_);
  glfwPollEvents();
  std::cout << "reach the end of glfwLoop" << std::endl;
}


} // namespace vv
