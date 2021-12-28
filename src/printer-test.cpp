#include "gtest/gtest.h"
#include "printer.hpp"

namespace
{
    TEST(AddTest, positiveNumber)
    {
        ASSERT_EQ(10, add(1, 9));
        ASSERT_EQ(-1, add(9, -10));
    }

    TEST(PrinterFoo, printIvalidInput_zero)
    {
        EXPECT_THROW(PrinterFoo printFoo(0), std::invalid_argument);
    }

    TEST(PrinterFoo, invalidInput_negativeNumber)
    {
        EXPECT_THROW(PrinterFoo printFoo(-1), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(-10), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(-100), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(-1000), std::invalid_argument);
    }
}