set (SOURCES
  application.cc
  driver/Driver.cpp  # has main()
  driver/Platform.cpp
)

add_executable(${CMAKE_PROJECT_NAME} WIN32
  ${SOURCES}
  qml.qrc
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
  lldb
  Qt5::Qml
  Qt5::Quick
  ${CMAKE_THREAD_LIBS_INIT}
)

target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
  QT_USE_QSTRINGBUILDER
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
  ${LLDB_INCLUDE_PATH}
)

set_property(TARGET ${CMAKE_PROJECT_NAME}
  PROPERTY CXX_STANDARD 14)

set_property(TARGET ${CMAKE_PROJECT_NAME} APPEND_STRING
  PROPERTY COMPILE_FLAGS -Wall)

add_dependencies(${CMAKE_PROJECT_NAME} llvm)

if (APPLE)
  # https://llvm.org/svn/llvm-project/lldb/trunk/docs/code-signing.txt
  add_custom_command(TARGET ${CMAKE_PROJECT_NAME}
    POST_BUILD
    COMMAND codesign -f -s lldb_codesign ${CMAKE_CURRENT_BINARY_DIR}/qlldb)
endif()
