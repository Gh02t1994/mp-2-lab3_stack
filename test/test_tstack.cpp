#include "tstack.h"

#include <gtest.h>

TEST(TStack, create_empty_stack)
{
    Stack<int> st(5);

    EXPECT_TRUE(st.IsEmpty());
    EXPECT_FALSE(st.IsFull());
}

TEST(TStack, push_element)
{
    Stack<int> st(3);

    st.push(10);

    EXPECT_FALSE(st.IsEmpty());
    EXPECT_EQ(st.get(), 10);
}

TEST(TStack, push_multiple_elements)
{
    Stack<int> st(3);

    st.push(10);
    st.push(20);
    st.push(30);

    EXPECT_TRUE(st.IsFull());
    EXPECT_EQ(st.get(), 30);
}

TEST(TStack, pop_element)
{
    Stack<int> st(3);

    st.push(10);
    st.push(20);

    st.pop();

    EXPECT_EQ(st.get(), 10);
}

TEST(TStack, pop_all_elements)
{
    Stack<int> st(2);

    st.push(10);
    st.push(20);

    st.pop();
    st.pop();

    EXPECT_TRUE(st.IsEmpty());
}

TEST(TStack, push_to_full_stack)
{
    Stack<int> st(2);

    st.push(10);
    st.push(20);

    EXPECT_THROW(st.push(30), out_of_range);
}

TEST(TStack, get_from_empty_stack)
{
    Stack<int> st(3);

    EXPECT_THROW(st.get(), out_of_range);
}

TEST(TStack, pop_from_empty_stack)
{
    Stack<int> st(3);

    EXPECT_THROW(st.pop(), out_of_range);
}

TEST(TStack, copy_constructor)
{
    Stack<int> st1(3);

    st1.push(10);
    st1.push(20);

    Stack<int> st2(st1);

    EXPECT_EQ(st2.get(), 20);

    st2.pop();

    EXPECT_EQ(st2.get(), 10);
    EXPECT_EQ(st1.get(), 20);
}

TEST(TStack, move_constructor)
{
    Stack<int> st1(3);

    st1.push(10);
    st1.push(20);

    Stack<int> st2(std::move(st1));

    EXPECT_EQ(st2.get(), 20);
    EXPECT_FALSE(st2.IsEmpty());

    EXPECT_TRUE(st1.IsEmpty());
}

TEST(TStack, work_with_double)
{
    Stack<double> st(2);

    st.push(3.14);
    st.push(2.71);

    EXPECT_DOUBLE_EQ(st.get(), 2.71);
}
