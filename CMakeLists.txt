cmake_minimum_required(VERSION 3.14)
project(Box_Capacity)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)
add_executable(Box_Capacity 
    src/sol.cpp 
    src/Box_Capacity.cpp
)
add_executable(test_Box_Capacity 
    test/test_main.cpp 
    test/test_Box_Capacity.cpp 
    src/Box_Capacity.cpp
)
target_link_libraries(test_Box_Capacity GTest::GTest GTest::Main)
target_include_directories(Box_Capacity PRIVATE include)
target_include_directories(test_Box_Capacity PRIVATE include)