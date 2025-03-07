cmake_minimum_required(VERSION 3.5)
project(ConsoleStream LANGUAGES CXX)

add_library(ConsoleStream INTERFACE)

target_include_directories(ConsoleStream INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# test
if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    set(CMAKE_CXX_STANDARD 98)
    add_executable(Test test/main.cpp)
    target_link_libraries(Test PRIVATE ConsoleStream)
endif()
