if(EXISTS "/mnt/c/Users/iakwon/gTest_samples/Sample7/build/sample7_unittest[1]_tests.cmake")
  include("/mnt/c/Users/iakwon/gTest_samples/Sample7/build/sample7_unittest[1]_tests.cmake")
else()
  add_test(sample7_unittest_NOT_BUILT sample7_unittest_NOT_BUILT)
endif()