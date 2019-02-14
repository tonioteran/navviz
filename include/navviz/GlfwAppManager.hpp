/**
 * @file GlfwAppManager.hpp
 * @brief glfw wrapper for encapsulating Callback API
 * @date Feb 13, 2019
 * @author Antonio Teran (teran@mit.edu)
 * Taken from http://www.cplusplus.com/articles/NvCRko23/
 *   all credit goes to Manu Sanchez!
 */

#ifndef GLFWAPPMANAGER_HPP
#define GLFWAPPMANAGER_HPP

#include <GLFW/glfw3.h>
#include <iostream>

#include "navviz/GlfwWrapper.hpp"

namespace vv {

class GlfwAppManager {

 private:

  static GlfwWrapper *app_;

  static void onKeydown(GLFWwindow *window, int key, int code, int a, int mod) {
    if (app_) app_->onKeydown(window, key, code, a, mod);
  }
  static void onError(int error, const char* desc) {
    if (app_) app_->onError(error, desc);
  }
  static void onResize(GLFWwindow *window, int width, int height) {
    if (app_) app_->onResize(window, width, height);
  }

 public:

  static void startApp(GlfwWrapper *app) {
    app_ = app;

    glfwSetKeyCallback(app->window(), onKeydown);
    glfwSetFramebufferSizeCallback(app->window(), onResize);
    glfwSetErrorCallback(onError);
  }

};

} // namespace vv

#endif
