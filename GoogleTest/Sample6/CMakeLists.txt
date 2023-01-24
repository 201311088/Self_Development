cmake_minimum_required(VERSION 3.14) # cmake 최소 버전
project(my_project) # project description 없으면 warning

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14) # CXX version setting googletest C++14

include(FetchContent) # https://snowdeer.github.io/c++/2022/01/11/cpp-cmake-fetchcontent/
FetchContent_Declare( # 외부 라이브러리 사용 선언
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # 캐시 앤트리세팅 https://cmake.org/cmake/help/latest/command/set.html
FetchContent_MakeAvailable(googletest) # FetchContent_Declare 연장

# google test keyword in cmake -- study
enable_testing()

# 실행파일 만드는 cmake keyword -- study
add_executable( 
  sample6_unittest # Param1 : 생성할 파일명
  sample6_unittest.cc # Param 2~ : 소스 파일
  prime_tables.h
)
# message(${CMAKE_SOURCE_DIR})
# target_include_directories(sample1_unittest PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Link 할 라이브러리 목록
target_link_libraries( 
  sample6_unittest # param1 : 타겟
  GTest::gtest_main # param 2~ : Link할 라이브러리 (이름만 입력)  

)

# https://cmake.org/cmake/help/latest/command/include.html
include(GoogleTest)
# https://runebook.dev/ko/docs/cmake/module/googletest
gtest_discover_tests(sample6_unittest)  # 실행 파일에 테스트 열거. initGoogleTest 역할
