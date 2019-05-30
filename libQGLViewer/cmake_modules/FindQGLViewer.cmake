# FindQGLViewer.cmake - Findqglviewer
# quchao@seas.upenn.edu (Chao Qu)
# Modified from FindGlog.cmake by alexs.mac@gmail.com (Alex Stewart)
#
# FindQGLViewer.cmake - Find QGLViewer library.
#
# This module defines the following variables:
#
# QGLViewer_FOUND:        TRUE iff QGLViewer is found.
# QGLViewer_INCLUDE_DIRS: Include directories for QGLViewer.
# QGLViewer_LIBRARIES:    Libraries required to link QGLViewer.
#
# The following variables control the behaviour of this module:
#
# QGLViewer_INCLUDE_DIR_HINTS: List of additional directories in which to
#                              search for QGLViewer includes, e.g: /foo/include.
# QGLViewer_LIBRARY_DIR_HINTS: List of additional directories in which to
#                              search for QGLViewer libraries, e.g: /bar/lib.
#
# The following variables are also defined by this module, but in line with
# CMake recommended FindPackage() module style should NOT be referenced directly
# by callers (use the plural variables detailed above instead).  These variables
# do however affect the behaviour of the module via FIND_[PATH/LIBRARY]() which
# are NOT re-called (i.e. search for library is not repeated) if these variables
# are set with valid values _in the CMake cache_. This means that if these
# variables are set directly in the cache, either by the user in the CMake GUI,
# or by the user passing -DVAR=VALUE directives to CMake when called (which
# explicitly defines a cache variable), then they will be used verbatim,
# bypassing the HINTS variables and other hard-coded search locations.
#
# QGLViewer_INCLUDE_DIR: Include directory for QGLViewer, not including the
#                        include directory of any dependencies.
# QGLViewer_LIBRARY: QGLViewer library, not including the libraries of any
#                    dependencies.

# Called if we failed to find QGLViewer or any of it's required dependencies,
# unsets all public (designed to be used externally) variables and reports
# error message at priority depending upon [REQUIRED/QUIET/<NONE>] argument.
macro(QGLViewer_REPORT_NOT_FOUND REASON_MSG)
    unset(QGLViewer_FOUND)
    unset(QGLViewer_INCLUDE_DIRS)
    unset(QGLViewer_LIBRARIES)
    # Make results of search visible in the CMake GUI if QGLViewer has not
    # been found so that user does not have to toggle to advanced view.
    mark_as_advanced(CLEAR QGLViewer_INCLUDE_DIR QGLViewer_LIBRARY)
    # Note <package>_FIND_[REQUIRED/QUIETLY] variables defined by FindPackage()
    # use the camelcase library name, not uppercase.
    if(QGLViewer_FIND_QUIETLY)
        message(STATUS "Failed to find QGLViewer - " ${REASON_MSG} ${ARGN})
    elseif(Qglviewer_FIND_REQUIRED)
        message(FATAL_ERROR "Failed to find QGLViewer - " ${REASON_MSG} ${ARGN})
    else()
        # Neither QUIETLY nor REQUIRED, use no priority which emits a message
        # but continues configuration and allows generation.
        message("-- Failed to find QGLViewer - " ${REASON_MSG} ${ARGN})
    endif()
endmacro(QGLViewer_REPORT_NOT_FOUND)

# Search user-installed locations first, so that we prefer user installs
# to system installs where both exist.
list(APPEND QGLViewer_CHECK_INCLUDE_DIRS
    /usr/local/include
    /usr/local/homebrew/include # Mac OS X
    /opt/local/var/macports/software # Mac OS X.
    /opt/local/include
    /usr/include
    )
list(APPEND QGLViewer_CHECK_LIBRARY_DIRS
    /usr/local/lib
    /usr/local/homebrew/lib # Mac OS X.
    /opt/local/lib
    /usr/lib
    /usr/lib/x86_64-linux-gnu
    )

# Check general hints
if(QGLViewer_HINTS AND EXISTS ${QGLViewer_HINTS})
    set(QGLViewer_INCLUDE_DIR_HINTS ${QGLViewer_HINTS}/include)
    set(QGLViewer_LIBRARY_DIR_HINTS ${QGLViewer_HINTS}/lib)
endif()

find_package(Qt4 COMPONENTS QtCore QtXml QtOpenGL QtGui)
include(${QT_USE_FILE})

set(QGLViewer_INCLUDE_FILE QGLViewer/config.h)
# Search supplied hint directories first if supplied.
find_path(QGLViewer_INCLUDE_DIR
    NAMES ${QGLViewer_INCLUDE_FILE}
    PATHS ${QGLViewer_INCLUDE_DIR_HINTS}
          ${QGLViewer_CHECK_INCLUDE_DIRS}
    NO_DEFAULT_PATH)
if(NOT QGLViewer_INCLUDE_DIR OR NOT EXISTS ${QGLViewer_INCLUDE_DIR})
QGLViewer_REPORT_NOT_FOUND("Could not find QGLViewer include directory, "
    "set QGLViewer_INCLUDE_DIR to directory containing QGLViewer/config.h")
endif()

find_library(QGLViewer_LIBRARY
    NAMES libQGLViewer.so
    PATHS ${QGLViewer_LIBRARY_DIR_HINTS}
          ${QGLViewer_CHECK_LIBRARY_DIRS}
    NO_DEFAULT_PATH)
if(NOT QGLViewer_LIBRARY OR NOT EXISTS ${QGLViewer_LIBRARY})
QGLViewer_REPORT_NOT_FOUND("Could not find QGLViewer library, "
    "set QGLViewer_LIBRARY to full path to libQGLViewer.so.")
endif()

# Mark internally as found, then verify. QGLViewer_REPORT_NOT_FOUND() unsets
# if called.
set(QGLViewer_FOUND TRUE)

# Catch case when caller has set QGLViewer_INCLUDE_DIR in the cache / GUI and
# thus FIND_[PATH/LIBRARY] are not called, but specified locations are
# invalid, otherwise we would report the library as found.
if(QGLViewer_INCLUDE_DIR AND NOT EXISTS ${QGLViewer_INCLUDE_DIR}/${QGLViewer_INCLUDE_FILE})
QGLViewer_REPORT_NOT_FOUND("Caller defined QGLViewer_INCLUDE_DIR:"
    " ${QGLViewer_INCLUDE_DIR} does not contain QGLViewer/config.h header.")
endif()

# TODO: This regex for QGLViewer library is pretty primitive, we use lowercase
#       for comparison to handle Windows using CamelCase library names, could
#       this check be better?
string(TOLOWER "${QGLViewer_LIBRARY}" LOWERCASE_QGLViewer_LIBRARY)
if(QGLViewer_LIBRARY AND NOT "${LOWERCASE_QGLViewer_LIBRARY}" MATCHES ".*qglviewer[^/]*")
QGLViewer_REPORT_NOT_FOUND("Caller defined QGLViewer_LIBRARY: "
    "${QGLViewer_LIBRARY} does not match QGLViewer.")
endif()

# Set standard CMake FindPackage variables if found.
if(QGLViewer_FOUND)
    list(APPEND QGLViewer_INCLUDE_DIRS ${QGLViewer_INCLUDE_DIR} ${QT_INCLUDES})
    list(APPEND QGLViewer_LIBRARIES ${QGLViewer_LIBRARY} ${QT_LIBRARIES} GL glut GLU)
endif()

# Handle REQUIRED / QUIET optional arguments.
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Qglviewer DEFAULT_MSG
    QGLViewer_INCLUDE_DIRS QGLViewer_LIBRARIES)

# Only mark internal variables as advanced if we found QGLViewer, otherwise
# leave them visible in the standard GUI for the user to set manually.
if(QGLViewer_FOUND)
    mark_as_advanced(FORCE QGLViewer_INCLUDE_DIR QGLViewer_LIBRARY)
endif()
