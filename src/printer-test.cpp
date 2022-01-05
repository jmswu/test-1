#include <climits>
#include "gtest/gtest.h"
#include "printer.hpp"

namespace
{
    TEST(dummy, test)
    {
        ASSERT_EQ(add(1, 2), 3);
    }

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

    TEST(printerFoo, correctOutputString)
    {
        PrinterFoo printerFoo(3);
        ASSERT_EQ(printerFoo.getString(), std::string("Foo"));
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

    TEST(printerBar, correctOutputString)
    {
        PrinterBar printerBar(5);
        ASSERT_EQ(printerBar.getString(), std::string("Bar"));
    }

    TEST(printerFooBar, validInputValues_andCondtionMet)
    {
        for(auto inputvalue = PrinterFooBar::INPUT_RANGE_MIN; inputvalue <= PrinterFooBar::INPUT_RANGE_MAX; inputvalue++)
        {
            // skip if the value cannot be devided by divider
            if (((inputvalue % PrinterFooBar::PrinterFoo::DEVIDER) != 0) ||
                ((inputvalue % PrinterFooBar::PrinterBar::DEVIDER) != 0))
                continue;

            PrinterFooBar printerFooBar(inputvalue);
            ASSERT_TRUE(printerFooBar.isConditionMet());
        }
    }

    TEST(printerFooBar, validInputValues_andCondtionNotMet)
    {
        for(auto inputvalue = PrinterFooBar::INPUT_RANGE_MIN; inputvalue <= PrinterFooBar::INPUT_RANGE_MAX; inputvalue++)
        {
            // skip if the value can be devided by divider
            if (((inputvalue % PrinterFooBar::PrinterFoo::DEVIDER) == 0) &&
                ((inputvalue % PrinterFooBar::PrinterBar::DEVIDER) == 0))
                continue;

            PrinterFooBar printerFooBar(inputvalue);
            ASSERT_FALSE(printerFooBar.isConditionMet());
        }
    }

    TEST(printerFooBar, correctOutputString)
    {
        PrinterFooBar printerFooBar(15);
        ASSERT_EQ(printerFooBar.getString(), std::string("FooBar"));
    }

    TEST(printerNumber, validInputValues_andConditionMet)
    {
        for(auto inputvalue = PrinterNumber::INPUT_RANGE_MIN; inputvalue <= PrinterNumber::INPUT_RANGE_MAX; inputvalue++)
        {
            // skip if the value cannot be devided by divider
            // condition true
            if (((inputvalue % PrinterNumber::PrinterFoo::DEVIDER) != 0) &&
                ((inputvalue % PrinterNumber::PrinterBar::DEVIDER) != 0))
            {
                PrinterNumber printerNumber(inputvalue);
                ASSERT_TRUE(printerNumber.isConditionMet());
            }
        } 
    }

    TEST(printerNumber, validInputValues_andConditionNotMet)
    {
        for(auto inputvalue = PrinterNumber::INPUT_RANGE_MIN; inputvalue <= PrinterNumber::INPUT_RANGE_MAX; inputvalue++)
        {
            // skip if the value can be devided by divider
            // condition false
            if (((inputvalue % PrinterNumber::PrinterFoo::DEVIDER) == 0) &&
                ((inputvalue % PrinterNumber::PrinterBar::DEVIDER) == 0))
            {
                PrinterNumber printerNumber(inputvalue);
                ASSERT_FALSE(printerNumber.isConditionMet());
            }
        } 
    }

    TEST(printerNumber, correctOutputString)
    {
        const int dataArrayCannotDivideByThreeOrFive[] = {1, 2, 4, 7};
        for(const auto &val: dataArrayCannotDivideByThreeOrFive)
        {
            PrinterNumber printerNumber(val);
            ASSERT_EQ(printerNumber.getString(), std::to_string(val));
        }
    }

    TEST(printerAll, showAllValues)
    {
        for(auto inputValue = PrinterBase::INPUT_RANGE_MIN; inputValue <= PrinterBase::INPUT_RANGE_MAX; inputValue++)
        {
            PrinterFoo      foo(inputValue);        myPrint(inputValue, foo);
            PrinterBar      bar(inputValue);        myPrint(inputValue, bar);
            PrinterFooBar   foobar(inputValue);     myPrint(inputValue, foobar);
            PrinterNumber   number(inputValue);     myPrint(inputValue, number);
        }
    }

}