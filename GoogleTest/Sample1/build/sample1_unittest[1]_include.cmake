if(EXISTS "/mnt/c/Users/iakwon/gTest_samples/Sample1/build/sample1_unittest[1]_tests.cmake")
  include("/mnt/c/Users/iakwon/gTest_samples/Sample1/build/sample1_unittest[1]_tests.cmake")
else()
  add_test(sample1_unittest_NOT_BUILT sample1_unittest_NOT_BUILT)
endif()
