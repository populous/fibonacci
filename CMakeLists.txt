cmake_minimum_required(VERSION 3.16)
project(hello_cmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# GoogleTest는 MSVC에서 CRT 설정 충돌을 피하기 위해 이 옵션을 자주 사용합니다.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(fibonacci_lib INTERFACE)
target_include_directories(fibonacci_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(hello main.cpp)
target_link_libraries(hello PRIVATE fibonacci_lib)

enable_testing()

add_executable(hello_test test.cpp)
target_link_libraries(hello_test PRIVATE fibonacci_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(hello_test)