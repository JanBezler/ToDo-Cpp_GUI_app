#include "MainForm.h"
#include "Event.h"
#include "Reminder.h"
#include "RepeatingReminder.h"
#include "Appointment.h"
#include <fstream>
#include <string>


using namespace std;
using namespace System;
using namespace System::Configuration;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

[STAThread]
void Main()
{
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);
	ToDoCppGUIapp::MainForm form;
	Application::Run(% form);
}


void MarshalString(String^ s, string& os) {
	
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}


void ToDoCppGUIapp::MainForm::SaveEventToFile(Event^ ie)
{
	string output;
	MarshalString(ie->GiveOutputToFile(), output);

	ofstream fout("events_data.txt", std::ofstream::app);
	fout << output;
	fout.close();
}


void ToDoCppGUIapp::MainForm::ReadEventFromFile()
{
	List<Event^> ReadedEvents;
	string line;

	ifstream fin("events_data.txt");
	if (fin.is_open())
	{
		int event_type;
		String^ title;
		String^ desc;
		int duration;
		String^ date;
		String^ repeat;
		String^ time;

		int lineNum = 0;
		while (getline(fin, line))
		{
			
			switch (lineNum)
			{
			case 0:
				title = gcnew String(line.c_str()); 
				break;
			case 1:
				desc = gcnew String(line.c_str()); 
				break;
			case 2:
				if (line[0] != NULL) 
				{ 
					event_type = 1; 
					duration = stoi(line);
				}
				else { event_type = 0; }
				break;
			case 3:
				date = gcnew String(line.c_str());
				break;
			case 4:
				repeat = gcnew String(line.c_str());
				if ((repeat->Length == 0)&&(event_type==0)) { event_type = 2; }
				else if (event_type == 0) { event_type = 3; }
				break;
			case 5:
				time = gcnew String(line.c_str());
				break;
			}

			lineNum++;

			if (lineNum > 5)
			{
				lineNum = 0;
				Event^ newEvent;
				DateTime datetime;
				datetime = datetime.Parse(date + " " + time);
				

				switch (event_type)
				{
				case 1:
					newEvent = gcnew Appointment(datetime, duration, title, desc);
					break;
				case 2:
					newEvent = gcnew Reminder(datetime, title, desc);
					break;
				case 3:
					newEvent = gcnew RepeatingReminder(datetime, repeat, title, desc);
					break;
				}

				ReadedEvents.Add(newEvent);
			}
		}

		fin.close();
		
		for each (Event^ e in ReadedEvents)
		{
			EventsList.Add(e); 
		}
	}
}

void ToDoCppGUIapp::MainForm::ClearEventsInFile()
{
	ofstream fcls("events_data.txt", std::ofstream::trunc);
	fcls.close();
}


void ToDoCppGUIapp::MainForm::ReloadEvents()
{

	ofstream fout("events_data.txt", std::ofstream::trunc);

	string output;

	listEvents->Items->Clear();

	for each (Event ^ e in EventsList)
	{
		AddItemToListEvents(e);
		MarshalString(e->GiveOutputToFile(), output);
		fout << output;
	}

	fout.close();

}


void ToDoCppGUIapp::MainForm::AddItemToListEvents(Event^ e)
{
	listEvents->Items->Add(e->GiveDateTime() + "   " + e->GiveTitle());
}