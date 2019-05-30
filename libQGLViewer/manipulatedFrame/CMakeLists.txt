add_executable(manipulatedFrame main.cpp manipulatedFrame.cpp)
target_link_libraries(manipulatedFrame Qt5::Xml Qt5::OpenGL OpenGL ${QGLVIEWER_LIBRARY})
