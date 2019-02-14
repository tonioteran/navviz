/**
 * @file testWrapper.hpp
 * @brief test glfw wrapper for encapsulating C API
 * @date Feb 13, 2019
 * @author Antonio Teran (teran@mit.edu)
 */

#include "navviz/GlfwWrapper.hpp"
#include "navviz/GlfwAppManager.hpp"

#include <cmath>

class ball : public vv::GlfwWrapper {
public:
	template<typename... ARGS>
	ball(ARGS&&... args) : vv::GlfwWrapper{ std::forward<ARGS>(args)... } , 
                         x_ball{ 0.0f },
                         y_ball{ 0.8f },
                         vx_ball{ 0.0f },
                         vy_ball{ 0.0f }
	{}

	virtual void onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods) override;

	virtual void glLoop() override;

private:
	float x_ball, y_ball;
	float vx_ball, vy_ball;
	const float gravity = 0.01;
	const float radius = 0.05f;

	void draw_ball();
};

void ball::onKeydown(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void ball::draw_ball()
{
	const float full_angle = 2.0f*3.141592654f;
	float x, y;

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);

	for (std::size_t i = 0; i < 20; ++i)
    {
      x = x_ball + radius*(std::cos(i*full_angle / 20.0f));
      y = y_ball + radius*(std::sin(i*full_angle / 20.0f));

      glVertex2f(x, y);
    }

	glEnd();
}

void ball::glLoop()
{
	float ratio = 800.0f / 600.0f;

	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);

	//Bounce on window bottom
	if (y_ball + radius <= radius)
		vy_ball = std::abs(vy_ball);
	else
		vy_ball -= gravity; //Apply gravity

	//Update ball coordinates
	x_ball += vx_ball;
	y_ball += vy_ball;

	//Lets draw the ball!
	draw_ball();
}

int main(void) {

  std::cout << "testing glfw wrappers" << std::endl;

  return (0);

}

