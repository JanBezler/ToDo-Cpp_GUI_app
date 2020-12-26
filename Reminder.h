#pragma once
using namespace System;
#include "Event.h"

ref class Reminder :
    public Event
{ 
public:
    Reminder(DateTime^ datetime, String^ title, String^ description)
    {
        DateAndTime = datetime;
        Title = title;
        Description = description;
    }

    ~Reminder()
    {
    }

    virtual String^ GiveDateTime() override
    {
        return ((DateAndTime->Month).ToString() + "/" + (DateAndTime->Day).ToString() + "/" + (DateAndTime->Year).ToString() + " " + (DateAndTime->TimeOfDay).ToString());
    }

    virtual String^ GiveTitle() override
    {
        return ("R:" + Title);
    }

    virtual String^ GiveDescription() override
    {
        return (Description);
    }
};

