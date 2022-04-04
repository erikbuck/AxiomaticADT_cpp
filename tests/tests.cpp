#include "Stack.h"
#include <gtest/gtest.h>

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// TEST CASES and EXPECTED OUTCOMES for Stack ADT
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

/// \anchor AXIOMTStack0 Constructor \ref AXIOMStack0 "AXIOMS"
TEST(Stack, constructorStack)
{
    ASSERT_NO_FATAL_FAILURE(stack());
    GTEST_ASSERT_EQ(0, size(stack()));
}

/// \anchor AXIOMTPush0 Constructor \ref  AXIOMPush0 "push()"
TEST(Stack, constructorPush0)
{
    GTEST_ASSERT_EQ(true, 0 < size(push(stack(), 33)));
    GTEST_ASSERT_EQ(true, 0 < size(push(push(stack(), 42), 33)));
}

/// \anchor AXIOMTPush1 Constructor \ref AXIOMPush1 "push()"
TEST(Stack, constructorPush1)
{
    GTEST_ASSERT_EQ(true, equal(stack(), pop(push(stack(), 42))));
    GTEST_ASSERT_EQ(false, equal(push(stack(), 42), stack()));
    GTEST_ASSERT_EQ(
        false, equal(push(push(stack(), 42), 1), push(stack(), 42)));
}

/// \anchor AXIOMTPush2 Constructor \ref AXIOMPush2 "push()"
TEST(Stack, constructorPush2) { }

/// \anchor AXIOMTPush3 Constructor \ref AXIOMPush3 "push()"
TEST(Stack, constructorPush3) { GTEST_ASSERT_EQ(1, top(push(stack(), 1))); }

/// \anchor AXIOMTPush4 Constructor \ref AXIOMPush4 "push()"
TEST(Stack, constructorPush4)
{
    GTEST_ASSERT_EQ(11, top(push(push(stack(), 33), 11)));
}

// OBSERVER AXIOMS

/// \anchor AXIOMTPop0 Observer \ref AXIOMPop0 "pop()"
TEST(Stack, pop0) { GTEST_ASSERT_EQ(true, equal(pop(stack()), stack())); }

/// \anchor AXIOMTPop1 Observer \ref AXIOMPop0 "pop()"
TEST(Stack, pop1)
{
    GTEST_ASSERT_EQ(true, equal(pop(push(stack(), 1)), stack()));
    GTEST_ASSERT_EQ(
        true, equal(pop(push(push(stack(), 42), 1)), push(stack(), 42)));
}

/// \anchor AXIOMTTop0 Observer \ref AXIOMTop0 "top()"
TEST(Stack, top0) { EXPECT_ANY_THROW(top(stack())); }

/// \anchor AXIOMTTop1 Observer \ref AXIOMTop1 "top()"
TEST(Stack, top1)
{
    GTEST_ASSERT_EQ(1, top(push(stack(), 1)));
    GTEST_ASSERT_EQ(1, top(push(push(stack(), 99), 1)));
}

/// \anchor AXIOMTSize0 Observer \ref AXIOMSize0 "size()"
TEST(Stack, size0) { GTEST_ASSERT_EQ(0, size(stack())); }

/// \anchor AXIOMTSize1 Observer \ref AXIOMSize1 "size()"
TEST(Stack, size1)
{
    GTEST_ASSERT_EQ(size(push(stack(), 1)), 1 + size(stack()));
    GTEST_ASSERT_EQ(
        size(push(push(stack(), 2), 1)), 1 + size(push(stack(), 2)));
}

/// \anchor AXIOMTEqual0 Observer \ref AXIOMEqual0 "equal()"
TEST(Stack, equal0)
{
    GTEST_ASSERT_EQ(false, equal(stack(), push(stack(), 99)));
    GTEST_ASSERT_EQ(
        false, equal(push(stack(), 42), push(push(stack(), 42), 99)));
}

/// \anchor AXIOMTEqual1 Observer \ref AXIOMEqual1 "equal()"
TEST(Stack, equal1)
{
    GTEST_ASSERT_EQ(true, equal(push(stack(), 99), push(stack(), 99)));
    GTEST_ASSERT_EQ(false, equal(push(stack(), 99), push(stack(), 1)));
    GTEST_ASSERT_EQ(
        true, equal(push(push(stack(), 99), 98), push(push(stack(), 99), 98)));
    GTEST_ASSERT_EQ(
        false, equal(push(push(stack(), 99), 98), push(push(stack(), 99), 1)));
}

/// \anchor AXIOMTEqual2 Observer \ref AXIOMEqual2 "equal()"
TEST(Stack, equal2)
{
    auto a { stack() };
    GTEST_ASSERT_EQ(true, equal(a, a));
    auto b { push(stack(), 42) };
    GTEST_ASSERT_EQ(true, equal(b, b));
}

/// \anchor AXIOMTEqual3 Observer \ref AXIOMEqual3 "equal()"
TEST(Stack, equal3)
{
    auto a { stack() };
    auto b { stack() };
    GTEST_ASSERT_EQ(equal(a, b), equal(b, a));
    auto c { push(stack(), 1) };
    auto d { push(stack(), 1) };
    GTEST_ASSERT_EQ(equal(c, d), equal(d, c));
    auto e { push(stack(), 1) };
    auto f { push(stack(), 2) };
    GTEST_ASSERT_EQ(equal(e, f), equal(f, e));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}