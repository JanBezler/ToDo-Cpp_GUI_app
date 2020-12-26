#pragma once
using namespace System;
#include "Reminder.h"

ref class RepeatingReminder :
    public Reminder
{
private:
    String^ Repeat;
public:
    RepeatingReminder(DateTime^ datetime, String^ repeat, String^ title, String^ description) :
        Reminder(datetime, title, description)
    {
        DateAndTime = datetime;
        Repeat = repeat;
        Title = title;
        Description = description;
    }

    ~RepeatingReminder()
    {
    }

    virtual String^ GiveDateTime() override
    {
        return (Repeat + " " + DateAndTime->TimeOfDay);
    }

};

