cmake_minimum_required(VERSION 2.8.11)

project(qlldb)

include(ExternalProject)

set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Qml Quick)

ExternalProject_Add(llvm
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third_party/llvm"
  CMAKE_ARGS
    "-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}"
    "-DLLVM_EXTERNAL_LLDB_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}/third_party/lldb"
    "-DLLVM_EXTERNAL_CLANG_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}/third_party/clang"
)

add_library(lldb SHARED IMPORTED)
set_target_properties(lldb PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/lib/liblldb.dylib)
set(LLDB_INCLUDE_PATH ${CMAKE_CURRENT_BINARY_DIR}/include)

add_subdirectory(src)
