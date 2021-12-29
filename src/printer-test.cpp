#include <climits>
#include "gtest/gtest.h"
#include "printer.hpp"

namespace
{
    TEST(PrinterFoo, printIvalidInput_zero)
    {
        EXPECT_THROW(PrinterFoo printFoo(0), std::invalid_argument);
    }

    TEST(PrinterFoo, invalidInput_negativeNumber)
    {
        EXPECT_THROW(PrinterFoo printFoo(-1), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(-10), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(-100), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(INT_MIN), std::invalid_argument);
    }

    TEST(PrinterFoo, invalidInput_greaterThan100)
    {
        EXPECT_THROW(PrinterFoo printFoo(101), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(102), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(INT_MAX), std::invalid_argument);
    }
}