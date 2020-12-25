#pragma once
using namespace System;
#include "Reminder.h"

ref class RepeatingReminder :
    public Reminder
{
private:
    int Repeat;
public:
    RepeatingReminder(int minute, int hour, int day, int month, int year, int repeat) :
        Reminder(minute, hour, day, month, year)
    {
        Minute = minute;
        Hour = hour;
        Day = day;
        Month = month;
        Year = year;
        Repeat = repeat;
    }

    ~RepeatingReminder()
    {
    }

    virtual String^ GiveRepeat()
    {
        return ("Repeating every " + Repeat.ToString() + " days");
    }

};

