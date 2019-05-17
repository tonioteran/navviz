cmake_minimum_required(VERSION 3.11)

find_package(OpenGL REQUIRED)
find_package(Qt5 REQUIRED QtGui QtOpenGL QtXml)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)



find_package(QGLViewer REQUIRED)



add_executable(simpleViewer main.cpp)
