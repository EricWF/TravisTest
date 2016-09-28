cmake_minimum_required (VERSION 2.8.11)
project (travis_test)

find_package(Threads REQUIRED)

macro(add_flags target)
  get_target_property(TEMP_FLAGS ${target} COMPILE_FLAGS)
  if (TEMP_FLAGS STREQUAL "TEMP_FLAGS-NOTFOUND")
    set(TEMP_FLAGS "")
  endif()
  foreach(value ${ARGN})
    set(TEMP_FLAGS "${TEMP_FLAGS} ${value}")
  endforeach()
  set_target_properties(${target} PROPERTIES COMPILE_FLAGS ${TEMP_FLAGS})
endmacro()

macro(add_version_target lang)
  add_executable(version_info_${lang} version_info.cpp)
  target_link_libraries(version_info_${lang} ${CMAKE_THREAD_LIBS_INIT})
  add_flags(version_info_${lang} -std=c++${lang})
  add_custom_target(print_version_info_${lang} ALL
          COMMAND version_info_${lang}
          WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
          COMMENT "Run and print the version information for C++${lang}"
          SOURCES version_info.cpp)
endmacro()

add_version_target(98)
add_version_target(03)
add_version_target(11)
add_version_target(14)
add_version_target(1z)
