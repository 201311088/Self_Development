if(EXISTS "/mnt/c/Users/iakwon/gTest_samples/Sample2/build/sample2_unittest[1]_tests.cmake")
  include("/mnt/c/Users/iakwon/gTest_samples/Sample2/build/sample2_unittest[1]_tests.cmake")
else()
  add_test(sample2_unittest_NOT_BUILT sample2_unittest_NOT_BUILT)
endif()