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

//! Class for encapsulating GLFW's C API
/*!
  Provides generic templates for the API's callbacks to be customized through
  polymorfism. It hides OpenGL's configuration boilerplate code from the user.
 */
class GlfwWrapper {

public:
  GLFWwindow *window_;

  //! Constructor: initializes GLFW, creates window, and sets as curr context
  GlfwWrapper(const std::string &scr_title, int scr_width, int scr_height);

  //! Destructor: destroys window object and terminates GLFW
  virtual ~GlfwWrapper();

  //! Calls glfwLoop
  void start();

  //! Executes main render loop, swaps buffers and polls for external inputs
  void glfwLoop();

  //! Main render loop, to be implemented by child class. Called in glfwLoop
  virtual void glLoop() = 0;

  // Callbacks:
  virtual void onKeydown(GLFWwindow *window, int key, int code, int a,
                         int mod) = 0;
  virtual void onError(int error, const char *desc) = 0;
  virtual void onResize(GLFWwindow *window, int width, int height);

  // Getters:
  GLFWwindow *window() const { return window_; };
};

} // namespace vv

#endif
