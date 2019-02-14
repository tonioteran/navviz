cmake_minimum_required(VERSION 3.12)

set(MY_APPS
  cameraDemo)

foreach(my_app IN LISTS MY_APPS)
  add_executable("${my_app}" "${my_app}.cpp")
  target_link_libraries("${my_app}" PUBLIC navviz)
  target_include_directories("${my_app}" PUBLIC "${GLAD_INCLUDE_DIR}"
    "${NAVVIZ_INCLUDE_DIR}" "${STB_INCLUDE_DIR}")
endforeach(my_app)

# add_executable(drawTriangles drawTriangles.cpp)
# target_link_libraries(drawTriangles PUBLIC OpenGL glad glfw)
# target_include_directories(drawTriangles PUBLIC "${GLAD_INCLUDE_DIR}")
