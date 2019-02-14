/**
 * @file Environment.h
 * @brief OpenGL wrapper for specifying viz environment
 * @date Feb 13, 2019
 * @author Antonio Teran (teran@mit.edu)
 */

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

namespace vv {

class Environment {

 private:

  // screen settings
  const unsigned int scr_width_  = 800;
  const unsigned int scr_height_ = 600;

 public:

  // constructors, destructors
  Environment();
  Environment(const unsigned int scr_width, const unsigned int scr_height);
  virtual ~Environment();

  void initialize();

};


} // namespace vv

#endif
