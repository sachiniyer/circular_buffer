cmake_minimum_required(VERSION 3.12)
project(hello VERSION 1.0.0 LANGUAGES CXX)
include(GNUInstallDirs)
add_library(${PROJECT_NAME} INTERFACE)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)
target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

find_package(Catch2 REQUIRED)
add_executable(circular_buffer_test test/test.cpp)
target_link_libraries(circular_buffer_test PRIVATE Catch2::Catch2)
target_include_directories(circular_buffer_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
include(CTest)
include(Catch)
catch_discover_tests(circular_buffer_test)
enable_testing()
