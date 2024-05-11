cmake_minimum_required(VERSION 3.5) 

project(Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG HEAD
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_all tests/test_foo.cpp Point.cpp Edge.cpp Graph.cpp Parser.cpp)



add_executable(Nach main1.cpp Point.cpp Edge.cpp Graph.cpp Parser.cpp)
add_test(NAME MyTest COMMAND test_all)

target_link_libraries(Nach PRIVATE GTest::gtest_main)
target_link_libraries(test_all PRIVATE GTest::gtest_main)

