#
#  CMakeLists.txt
#
#  The MIT License
#
#  Copyright (C) 2016 Shota Matsuda
#
#  Permission is hereby granted, free of charge, to any person obtaining a
#  copy of this software and associated documentation files (the "Software"),
#  to deal in the Software without restriction, including without limitation
#  the rights to use, copy, modify, merge, publish, distribute, sublicense,
#  and/or sell copies of the Software, and to permit persons to whom the
#  Software is furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in
#  all copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
#  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
#  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
#  DEALINGS IN THE SOFTWARE.
#

# Project settings
cmake_minimum_required(VERSION 2.8)
project(takram_nanovg CXX C)

# Configuration types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "configs" FORCE)
if (DEFINED CMAKE_BUILD_TYPE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})
endif()

# Compiler flags
set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS "-std=c++1y -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -DNDEBUG")
message(STATUS "")
message(STATUS "Configuration: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ flags (Release): ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ flags (Debug): ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C flags (Release): ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "C flags (Debug): ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "")

# Run path
set(CMAKE_MACOSX_RPATH ON)
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Include directories
include_directories("${${PROJECT_NAME}_SOURCE_DIR}/src")
include_directories("${${PROJECT_NAME}_SOURCE_DIR}/lib/nanovg/src")

# Library
find_library(OPENGL_FRAMEWORK NAMES OpenGL)
foreach(GL IN ITEMS gl2 gl3)
  file(GLOB_RECURSE SOURCES "src/takram/nanovg.cc" "src/takram/nanovg/${GL}.cc" "lib/nanovg/src/*.c")
  add_library("${PROJECT_NAME}_${GL}_static" STATIC ${SOURCES})
  add_library("${PROJECT_NAME}_${GL}_shared" SHARED ${SOURCES})
  set_target_properties("${PROJECT_NAME}_${GL}_static" PROPERTIES OUTPUT_NAME "${PROJECT_NAME}_${GL}")
  set_target_properties("${PROJECT_NAME}_${GL}_shared" PROPERTIES OUTPUT_NAME "${PROJECT_NAME}_${GL}")
  target_link_libraries("${PROJECT_NAME}_${GL}_static" ${OPENGL_FRAMEWORK})
  target_link_libraries("${PROJECT_NAME}_${GL}_shared" ${OPENGL_FRAMEWORK})
endforeach()

# Unit test
file(GLOB_RECURSE TESTS "test/*.cc")
list(LENGTH TESTS TEST_COUNT)
if (TEST_COUNT)
  enable_testing()
  add_subdirectory("lib/googletest/googletest")
  include_directories("lib/googletest/googletest/include")
  add_executable("${PROJECT_NAME}_test" ${TESTS})
  target_link_libraries("${PROJECT_NAME}_test" "gtest" "gtest_main")
  target_link_libraries("${PROJECT_NAME}_test" "${PROJECT_NAME}_gl3_shared")
  add_test("${PROJECT_NAME}" "${PROJECT_NAME}_test")
endif()

# Install settings
foreach(GL IN ITEMS gl2 gl3)
  install(TARGETS "${PROJECT_NAME}_${GL}_static" DESTINATION "lib")
endforeach()
install(DIRECTORY "src/takram" DESTINATION "include" FILES_MATCHING PATTERN "*.h")
