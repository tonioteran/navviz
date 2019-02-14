/**
 * @file GlfwWrapper.hpp
 * @brief glfw wrapper for encapsulating C API
 * @date Feb 13, 2019
 * @author Antonio Teran (teran@mit.edu)
 * Taken from http://www.cplusplus.com/articles/NvCRko23/
 *   all credit goes to Manu Sanchez!
 */

#ifndef GLFWWRAPPER_HPP
#define GLFWWRAPPER_HPP

#include <GLFW/glfw3.h>
#include <iostream>

namespace vv {

class GlfwWrapper {

 public:

  GLFWwindow* window_;
  
  // constructors, destructors
  GlfwWrapper(const std::string &scr_title, int scr_width, int scr_height);
  virtual ~GlfwWrapper();

  void start();

  virtual void onKeydown(GLFWwindow* window, int key, int code, int a, int mod);
  virtual void onError(int error, const char* desc);
  virtual void onResize(GLFWwindow* window, int width, int height);
  virtual void glLoop() = 0;

  GLFWwindow* window() const;

};

} // namespace vv

#endif
