#pragma once

#include <cstdbool>
#include <stdexcept>

int add(int a, int b);

class PrinterBase
{
    protected:
        static constexpr int INPUT_RANGE_MIN = 1;
        static constexpr int INPUT_RANGE_MAX = 100;

        int number = INPUT_RANGE_MIN;
    public:
        PrinterBase(void) = delete;
        PrinterBase(int number): number(number)
        {
            if (isInputValid() == false) 
            {
                throw std::invalid_argument("Invalid input argument");
            }
        };
        
        bool isInputValid(void)
        {
            if (number < INPUT_RANGE_MIN) return false;
            if (number > INPUT_RANGE_MAX) return false;

            return true;
        }

        virtual bool isConditionMet(void) = 0;
        virtual void print(void) = 0;
};

class PrinterFoo : public PrinterBase
{
    public:
        PrinterFoo(int number) : PrinterBase(number){}

        bool isConditionMet(void)
        {
            return (number % 3 == 0) ? true : false;
        }

        void print(void)
        {
            if (isConditionMet()) std::printf("Foo");
        }
};