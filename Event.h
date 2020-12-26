#pragma once
#include "MainForm.h"
using namespace System;

ref class Event abstract
{
protected:
	DateTime^ DateAndTime;
	String^ Title;
	String^	Description;

public:
	virtual String^ GiveDateTime() = 0;
	virtual String^ GiveTitle() = 0;
	virtual String^ GiveDescription() = 0;
	
};


