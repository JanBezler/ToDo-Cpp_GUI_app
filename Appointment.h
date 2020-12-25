#pragma once
using namespace System;
#include "Event.h"

ref class Appointment :
    public Event
{
private:
    int Duration;
public:
    Appointment(int minute, int hour, int day, int month, int year, int duration)
    {
        Minute = minute;
        Hour = hour;
        Day = day;
        Month = month;
        Year = year;
        Duration = duration;
    }

    ~Appointment()
    {
    }

    virtual String^ GiveDuration()
    {
        if (Duration < 60) return (Duration.ToString() + " min");
        else return (static_cast<int>((Duration / 60)).ToString() + " min and " + (Duration % 60).ToString() + " hr");
    }

    virtual String^ GiveTime() override
    {
        return (Hour.ToString() + ":" + Minute.ToString());
    }

    virtual String^ GiveDate() override
    {
        return (Day.ToString() + "." + Month.ToString() + "." + Year.ToString());
    }
};

