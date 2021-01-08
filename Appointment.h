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
        return (DateAndTime->Month + "/" + DateAndTime->Day + "/" + DateAndTime->Year + ", " + DateAndTime->TimeOfDay);
    }

    virtual String^ GiveTitle() override
    {
        return ("A: " + Title);
    }

    virtual String^ GiveDescription() override
    {
        DateTime^ DateAndTimeWithDuration = DateAndTime->AddMinutes(Duration);
        return ("Ends at " + (DateAndTimeWithDuration->TimeOfDay).ToString() + " - " + Description);
    }

    virtual String^ GiveOutputToFile() override
    {
        DateTime^ DateAndTimeWithDuration = DateAndTime->AddMinutes(Duration);
        return(
            Title + "\n" +
            Description + "\n" +
            Duration + "\n" +
            DateAndTime->Month + "/" + DateAndTime->Day + "/" + DateAndTime->Year + "\n" + 
            "\n" +
            DateAndTime->TimeOfDay + "\n"
            );
    }

    virtual DateTime^ GiveDateTimeAsDateTime() override
    {
        return DateAndTime;
    }

    String^ GiveRepeat() override
    {
        return "NULL";
    }
};

