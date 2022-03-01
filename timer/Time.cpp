#include <iostream>
#include <assert.h>
#include "Time.h"

namespace timer
{
    Time::Time()
        : timestamp(0)
    {
    }

    Time::Time(int timestamp)
        : timestamp(timestamp)
    {
    }

    Time::Time(int days, int hours, int minutes, int seconds)
    {
        setTime(days, hours, minutes, seconds);
    }

    int Time::getDays()
    {
        return this->timestamp / 86400;
    }

    int Time::getHours()
    {
        return this->timestamp % 86400 / 3600;
    }

    int Time::getMinutes()
    {
        return this->timestamp % 3600 / 60;
    }

    int Time::getSeconds()
    {
        return this->timestamp % 3600 % 60;
    }

    void Time::setTime(int timestamp)
    {
        this->timestamp = timestamp;
    }

    void Time::setTime(int days, int hours, int minutes, int seconds)
    {
        this->timestamp = days * 86400 + hours * 3600 + minutes * 60 + seconds;
    }

    void Time::up(int seconds)
    {
        this->timestamp += seconds;
    }

    void Time::down(int seconds)
    {
        if (timestamp > 0)
            this->timestamp -= seconds;
    }

    std::string Time::toString()
    {
        std::stringstream ss;

        if (this->getDays() != 0)
            ss << this->getDays() << "d ";

        ss << this->getHours() << ":"
            << this->getMinutes() << ":"
            << this->getSeconds();

        return ss.str();
    }

    Time Time::operator+(const Time t)
    {
        return Time(this->timestamp + t.timestamp);
    }

    std::ostream& operator<<(std::ostream& stream, Time& time)
    {
        stream << time.toString();
        return stream;
    }    
}