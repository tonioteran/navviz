cmake_minimum_required(VERSION 3.11)

# find_package(OpenGL REQUIRED)
# find_package(Qt5 REQUIRED QtGui QtOpenGL QtXml)

# To look for libQGLViewer cmake file
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5 COMPONENTS Core Xml)
find_package(OpenGL REQUIRED) # required by QGLViewer
find_package(QGLViewer REQUIRED)

add_executable(simpleViewer main.cpp simpleViewer.cpp)
target_link_libraries(simpleViewer Qt5::Xml Qt5::OpenGL OpenGL QGLViewer)
