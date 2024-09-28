cmake_minimum_required(VERSION 3.5)

project(CellularAutomata)

set(CMAKE_BUILD_PARALLEL_LEVEL 16)

set(CMAKE_TOOLCHAIN_FILE
  "${PROJECT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(OpenGL_GL_PREFERENCE "GLVND")
set(CMP0072 "GLVND")

add_subdirectory(Main)

add_custom_target(${PROJECT_NAME})
add_dependencies(${PROJECT_NAME} Main)

