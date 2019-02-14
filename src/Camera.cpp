/**
 * @file Camera.cpp
 * @brief Camera object to move around in OpenGL
 * @date Feb 13, 2019
 * @author Antonio Teran (teran@mit.edu)
 * taken from:
 * https://learnopengl.com/code_viewer_gh.php?code=includes/learnopengl/camera.h
 * all credit goes to them!
 */

#include "navviz/Camera.h"

namespace vv {

/* ************************************************************************** */
Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) :
      Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED),
      MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
  Position = position;
  WorldUp  = up;
  Yaw      = yaw;
  Pitch    = pitch;
  updateCameraVectors();
}

/* ************************************************************************** */
Camera::~Camera() {}

} // namespace vv

