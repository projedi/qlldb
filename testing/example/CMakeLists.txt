cmake_minimum_required(VERSION 2.8.11)

project(example)

set (SOURCES
  main.cc
)

add_executable(${CMAKE_PROJECT_NAME} WIN32
  ${SOURCES}
)

set_property(TARGET ${CMAKE_PROJECT_NAME}
  PROPERTY CXX_STANDARD 14)

set_property(TARGET ${CMAKE_PROJECT_NAME} APPEND_STRING
  PROPERTY COMPILE_FLAGS -Wall)

install(TARGETS example
  RUNTIME DESTINATION bin
)
