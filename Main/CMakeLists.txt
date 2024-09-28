project(Main)

set(CMAKE_BUILD_PARALLEL_LEVEL 16)

set(SOURCE_FILES ./Source_Files/main.cpp ./Source_Files/Automata1D.cpp ./Source_Files/Errors.cpp ./Source_Files/Automata2D.cpp ./Source_Files/SDLAutomata.cpp ./Source_Files/Random.cpp ./Source_Files/terminalAutomata.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)


target_include_directories(
  ${PROJECT_NAME}
  PUBLIC "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/Source_Files/"
  "${PROJECT_SOURCE_DIR}/Header_Files/")


target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES})

