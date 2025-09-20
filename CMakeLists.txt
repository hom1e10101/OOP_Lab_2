cmake_minimum_required(VERSION 3.14)
project(Three)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)
add_executable(Three
    src/sol.cpp
    src/MyVector.cpp
    src/Three.cpp
)
add_executable(test_Three
    test/test_main.cpp 
    test/test_Three.cpp 
    src/Three.cpp
    src/MyVector.cpp
)
target_link_libraries(test_Three GTest::GTest GTest::Main)
target_include_directories(Three PRIVATE include)
target_include_directories(test_Three PRIVATE include)