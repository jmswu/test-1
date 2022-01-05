#pragma once

#include <cstdbool>
#include <stdexcept>

int add(int a, int b);

class PrinterBase
{
    protected:
        int number = INPUT_RANGE_MIN;

    public:
        static constexpr int INPUT_RANGE_MIN = 1;
        static constexpr int INPUT_RANGE_MAX = 100;

        PrinterBase(void) = delete;
        PrinterBase(int number): number(number)
        {
            if (isInputValid() == false) 
            {
                throw std::invalid_argument("Invalid input argument");
            }
        };
        
        bool isInputValid(void) const
        {
            if (number < INPUT_RANGE_MIN) return false;
            if (number > INPUT_RANGE_MAX) return false;

            return true;
        }

        virtual bool isConditionMet(void) const = 0;
        virtual void print(void) const = 0;
};

class PrinterFoo : public PrinterBase
{
    public:
        static constexpr int DEVIDER = 3;

        PrinterFoo(void) = delete;
        PrinterFoo(int number) : PrinterBase(number){}

        bool isConditionMet(void) const override
        {
            return (number % DEVIDER == 0) ? true : false;
        }

        void print(void) const override
        {
            if (isConditionMet()) std::printf("Foo");
        }
};

class PrinterBar : public PrinterBase
{
    public:
        static constexpr int DEVIDER = 5;

        PrinterBar(void) = delete;
        PrinterBar(int number) : PrinterBase(number){}

        bool isConditionMet(void) const override
        {
            return (number % DEVIDER == 0) ? true : false;
        }

        void print(void) const override
        {
            if (isConditionMet()) std::printf("Bar");
        }
};

class PrinterFooBar: public PrinterFoo, public PrinterBar
{   
    public:
        PrinterFooBar(void) = delete;
        PrinterFooBar(int number): PrinterFoo(number), PrinterBar(number) {}

        bool isConditionMet(void) const override
        {
            return PrinterFoo::isConditionMet() && PrinterBar::isConditionMet();
        }

        void print(void) const override
        {
            if (isConditionMet()) 
            {
                PrinterFoo::print();
                PrinterBar::print();
            }
        }
};

class PrinterNumber: public PrinterFoo, public PrinterBar
{
    public:
        PrinterNumber(void) = delete;
        PrinterNumber(int number): PrinterFoo(number), PrinterBar(number) {}

        bool isConditionMet(void) const override
        {
            return (PrinterFoo::isConditionMet() == false) && (PrinterBar::isConditionMet() == false);
        }

        void print(void) const override
        {
            if (isConditionMet())
            {
                std::printf("%d", PrinterFoo::number);
            }
        }
};