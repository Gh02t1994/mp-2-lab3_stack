add_executable(test_tstack
    test_main.cpp
    test_tstack.cpp
)

target_link_libraries(test_tstack PRIVATE gtest ${MP2_LIBRARY})

add_test(NAME TestStack COMMAND test_tstack)


add_executable(test_tarithmeticexpression
    test_main.cpp
    test_tarithmeticexpression.cpp
)

target_link_libraries(test_tarithmeticexpression
    PRIVATE
    gtest
    ${MP2_LIBRARY}
)

add_test(NAME TestArithmeticExpression COMMAND test_tarithmeticexpression)
