#pragma once
using namespace System;
#include "Event.h"

ref class Appointment :
    public Event
{
private:
    int Duration;
public:
    Appointment(DateTime^ datetime, int duration, String^ title, String^ description)
    {
        DateAndTime = datetime;
        Duration = duration;
        Title = title;
        Description = description;
    }

    ~Appointment()
    {
    }

    virtual String^ GiveDateTime() override
    {
        return ((DateAndTime->Month).ToString() + "/" + (DateAndTime->Day).ToString() + "/" + (DateAndTime->Year).ToString() + " " + (DateAndTime->TimeOfDay).ToString());
    }

    virtual String^ GiveTitle() override
    {
        return ("A:" + Title);
    }

    virtual String^ GiveDescription() override
    {
        DateTime^ DateAndTimeWithDuration = DateAndTime->AddMinutes(Duration);
        return ("Ends at " + (DateAndTimeWithDuration->TimeOfDay).ToString() + " - " + Description);
    }


};

