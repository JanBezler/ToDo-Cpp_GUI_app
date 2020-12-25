#pragma once
using namespace System;

ref class Event abstract
{
protected:
	int Hour, Minute;
	int Day, Month, Year;
public:
	virtual String^ GiveDate() = 0;
	virtual String^ GiveTime() = 0;

};


