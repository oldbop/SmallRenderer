cmake_minimum_required(VERSION 3.22)
project(SmallRenderer)

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(deps/glfw/)
add_subdirectory(deps/glad/)

include_directories(deps/glfw/deps)

file(GLOB SOURCES CONFIGURE_DEPENDS
  ${PROJECT_SOURCE_DIR}/src/*.hpp
  ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable("${CMAKE_PROJECT_NAME}" ${SOURCES}) 

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES 
  DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)

target_link_libraries(${CMAKE_PROJECT_NAME} glfw)
target_link_libraries(${CMAKE_PROJECT_NAME} glad)
