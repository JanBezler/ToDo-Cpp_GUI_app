#pragma once
using namespace System;
#include "Event.h"

ref class Reminder :
    public Event
{ 
public:
    Reminder(int minute, int hour, int day, int month, int year)
    {
        Minute = minute;
        Hour = hour;
        Day = day;
        Month = month;
        Year = year;
    }

    ~Reminder()
    {
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

