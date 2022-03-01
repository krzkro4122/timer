#pragma once

#include <iostream>
#include <sstream>

namespace timer
{
    class Time
    {
    private:
        int timestamp;

    public:
        Time();
        Time(int timestamp);
        Time(int days, int hours, int minutes, int seconds);

        int getDays();
        int getHours();
        int getMinutes();
        int getSeconds();

        void setTime(int timestamp);
        void setTime(int days, int hour, int minute, int second);

        void up(int seconds);
        void down(int seconds);

        std::string toString();
        Time operator+ (const Time t);

        friend std::ostream& operator<< (std::ostream& stream, Time& time);
    };
}

