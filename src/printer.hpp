#pragma once

#include <cstdbool>
#include <stdexcept>

int add(int a, int b);

class PrinterBase
{
    protected:
        static constexpr int INPUT_RANGE_MIN = 1;
        static constexpr int INPUT_RANGE_MAX = 100;
        int number = 0;
    public:
        PrinterBase(int number): number(number)
        {
            if (isNumberValid() == false) 
            {
                throw std::invalid_argument("Invalid input argument");
            }
        };
        
        bool isNumberValid(void)
        {
            if (number < INPUT_RANGE_MIN) return false;
            if (number > INPUT_RANGE_MAX) return false;

            return true;
        }

        virtual bool isConditionMet(void) = 0;
        virtual void print(void) = 0;
};