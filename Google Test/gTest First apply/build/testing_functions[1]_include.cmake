if(EXISTS "/mnt/c/Users/iakwon/Desktop/gTEST_Drill/build/testing_functions[1]_tests.cmake")
  include("/mnt/c/Users/iakwon/Desktop/gTEST_Drill/build/testing_functions[1]_tests.cmake")
else()
  add_test(testing_functions_NOT_BUILT testing_functions_NOT_BUILT)
endif()