cmake_minimum_required(VERSION 3.14) # cmake 최소 버전
# 프로젝트 정보
project(
  FUNCTIONS
  VERSION 0.1
  DESCRIPTION "테스트 적용 연습"
  LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)  #######  FOR the GTEST
FetchContent_Declare( 
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  #######  FOR the GTEST
FetchContent_MakeAvailable(googletest) 

enable_testing()  #######  FOR the GTEST

add_executable(
  testing_functions
  CFunction_unittest.cc
  CFunctions.cpp
  CFunctions.h
) 

target_link_libraries(    #######  FOR the GTEST : Link to Virtual Main() 
  testing_functions
  GTest::gtest_main 
)

include(GoogleTest)

gtest_discover_tests(testing_functions)

