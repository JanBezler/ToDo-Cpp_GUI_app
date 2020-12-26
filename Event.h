#pragma once
#include "MainForm.h"
using namespace System;

ref class Event abstract
{
protected:
	DateTime^ DateAndTime;
	String^ Title;
	String^	Description;
	//friend void ToDoCppGUIapp::MainForm::SaveEventToFile(Event^ ie);

public:
	virtual String^ GiveDateTime() = 0;
	virtual String^ GiveTitle() = 0;
	virtual String^ GiveDescription() = 0;
	
	String^ operator+(int x) {

		return this + x.ToString();
	}

	String^ operator+(String^ x) {

		return this->ToString() + x;
	}

};


