cmake_minimum_required(VERSION 3.12)

set(MY_TESTS
  drawTriangles;
  drawTrianglesShader;
  texturesDemo;
  transformDemo;
  projectionDemo;
  cameraDemo;
  maxVertexAttribs)

foreach(my_test IN LISTS MY_TESTS)
  add_executable("${my_test}" "${my_test}.cpp")
  target_link_libraries("${my_test}" PUBLIC OpenGL glad glfw)
  target_include_directories("${my_test}" PUBLIC "${GLAD_INCLUDE_DIR}"
    "${NAVVIZ_INCLUDE_DIR}" "${STB_INCLUDE_DIR}")
endforeach(my_test)

# add_executable(drawTriangles drawTriangles.cpp)
# target_link_libraries(drawTriangles PUBLIC OpenGL glad glfw)
# target_include_directories(drawTriangles PUBLIC "${GLAD_INCLUDE_DIR}")
