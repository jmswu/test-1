#include "gtest/gtest.h"
#include "printer.hpp"

namespace
{
    TEST(AddTest, positiveNumber)
    {
        ASSERT_EQ(10, add(1, 9));
        ASSERT_EQ(-1, add(9, -10));
    }
}