#include <climits>
#include "gtest/gtest.h"
#include "printer.hpp"

namespace
{
    TEST(printerFoo, printIvalidInput_zero)
    {
        EXPECT_THROW(PrinterFoo printFoo(0), std::invalid_argument);
    }

    TEST(printerFoo, invalidInput_negativeNumber)
    {
        EXPECT_THROW(PrinterFoo printFoo(-1), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(-10), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(-100), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(INT_MIN), std::invalid_argument);
    }

    TEST(printerFoo, invalidInput_greaterThan100)
    {
        EXPECT_THROW(PrinterFoo printFoo(101), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(102), std::invalid_argument);
        EXPECT_THROW(PrinterFoo printFoo(INT_MAX), std::invalid_argument);
    }

    TEST(printerFoo, validInputValues)
    {
        constexpr int RANGE_START = 1;
        constexpr int RANGE_STOP = PrinterFoo::INPUT_RANGE_MAX / PrinterFoo::DEVIDER;

        for(auto i = RANGE_START; i <= RANGE_STOP; i++)
        {
            int diviableByThree = i * 3;
            PrinterFoo printFoo(diviableByThree);
            ASSERT_TRUE(printFoo.isConditionMet());
        }
    }
}