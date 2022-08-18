project(ErrorCombination)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_CPPLINT "cpplint")


include_directories(.)



FILE(GLOB TEST_PROGRAMS ${CMAKE_SOURCE_DIR}/tests/*.cxx)

foreach(TEST_PROGRAM ${TEST_PROGRAMS})
   message(STATUS "Building ${TEST_PROGRAM}")
   get_filename_component(PROGRAM_NAME ${TEST_PROGRAM} NAME_WE)
   foreach(TEST_STANDARD 11 14 17 20)
      add_executable(${PROGRAM_NAME}_cxx${TEST_STANDARD} ${TEST_PROGRAM})

      set_property(TARGET ${PROGRAM_NAME}_cxx${TEST_STANDARD} PROPERTY CXX_STANDARD ${TEST_STANDARD})

      if(MSVC)
         target_compile_options(${PROGRAM_NAME}_cxx${TEST_STANDARD} PRIVATE /W4 /WX)
      else()
         target_compile_options(${PROGRAM_NAME}_cxx${TEST_STANDARD} PRIVATE -Wall -Wextra -Wpedantic -Werror)
      endif()
   endforeach()
endforeach()



