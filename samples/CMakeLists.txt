add_executable(sample_stack sample_stack.cpp)

target_link_libraries(sample_stack PRIVATE ${MP2_LIBRARY})


add_executable(sample_arithmeticexpression sample_arithmeticexpression.cpp)

target_link_libraries(sample_arithmeticexpression PRIVATE ${MP2_LIBRARY})
