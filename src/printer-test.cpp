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

    TEST(printerFoo, validInputValues_andCondtionMet)
    {
        constexpr int RANGE_START = 1;
        constexpr int RANGE_STOP = PrinterFoo::INPUT_RANGE_MAX / PrinterFoo::DEVIDER;

        for(auto i = RANGE_START; i <= RANGE_STOP; i++)
        {
            int diviableByThree = i * PrinterFoo::DEVIDER;
            PrinterFoo printFoo(diviableByThree);
            ASSERT_TRUE(printFoo.isConditionMet());
        }
    }

    TEST(printerFoo, validInputsValues_butConditionNotmet)
    {
        for(auto inputValue = PrinterFoo::INPUT_RANGE_MIN; inputValue <= PrinterFoo::INPUT_RANGE_MAX; inputValue++)
        {
            // skip if the value can be devided by divider
            if ((inputValue % PrinterFoo::DEVIDER) == 0) continue;

            PrinterFoo printerFoo(inputValue);
            ASSERT_FALSE(printerFoo.isConditionMet());
        }
    }

    TEST(printerBar, validInputValues_andCondtionMet)
    {
        constexpr int RANGE_START = 1;
        constexpr int RANGE_STOP = PrinterBar::INPUT_RANGE_MAX / PrinterBar::DEVIDER;

        for(auto i = RANGE_START; i <= RANGE_STOP; i++)
        {
            int diviableByFive = i * PrinterBar::DEVIDER;
            PrinterBar printBar(diviableByFive);
            ASSERT_TRUE(printBar.isConditionMet());
        }
    }

    TEST(printerBar, validInputValues_andCondtionNotMet)
    {
        for(auto inputValue = PrinterBar::INPUT_RANGE_MIN; inputValue <= PrinterBar::INPUT_RANGE_MAX; inputValue++)
        {
            // skip if the value can be devided by divider
            if ((inputValue % PrinterBar::DEVIDER) == 0) continue;

            PrinterBar printerBar(inputValue);
            ASSERT_FALSE(printerBar.isConditionMet());
        }
    }

    TEST(printerFooBar, validInputValues_andCondtionNotMet)
    {
        for(auto inputvalue = 1; inputvalue <= 100; inputvalue++)
        {

            // skip if the value can be devided by divider
            if (((inputvalue % PrinterFooBar::PrinterFoo::DEVIDER) == 0) &&
                ((inputvalue % PrinterFooBar::PrinterBar::DEVIDER) == 0))
                continue;

            PrinterFooBar printerFooBar(inputvalue);
            ASSERT_FALSE(printerFooBar.isConditionMet());
        }
    }
}