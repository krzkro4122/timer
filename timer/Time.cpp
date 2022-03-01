#include <iostream>
#include <assert.h>
#include "Time.h"

namespace timer
{
    Time::Time()
        : timestamp(0)
    {
    }

    Time::Time(unsigned int timestamp)
        : timestamp(timestamp)
    {
    }

    Time::Time(unsigned int days, unsigned int hours, unsigned int minutes, unsigned int seconds)
    {
        setTime(days, hours, minutes, seconds);
    }

    unsigned int Time::getDays()
    {
        return this->timestamp / 86400;
    }

    unsigned int Time::getHours()
    {
        return this->timestamp % 86400 / 3600;
    }

    unsigned Time::getMinutes()
    {
        return this->timestamp % 3600 / 60;
    }

    unsigned int Time::getSeconds()
    {
        return this->timestamp % 3600 % 60;
    }

    void Time::setTime(unsigned int timestamp)
    {
        this->timestamp = timestamp;
    }

    void Time::setTime(unsigned int days, unsigned int hours, unsigned int minutes, unsigned int seconds)
    {
        this->timestamp = days * 86400 + hours * 3600 + minutes * 60 + seconds;
    }

    void Time::up(unsigned int seconds)
    {
        this->timestamp += seconds;
    }

    void Time::down(unsigned int seconds)
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