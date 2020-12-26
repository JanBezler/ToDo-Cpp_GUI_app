#include "MainForm.h"
//#include "Event.h"
//#include "Reminder.h"
//#include "RepeatingReminder.h"
//#include "Appointment.h"
#include <fstream>

using namespace std;
using namespace System;
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
	using namespace std;
	
	string title, desc, datetime;
	MarshalString(ie->GiveTitle(), title);
	MarshalString(ie->GiveDescription(), desc);
	MarshalString(ie->GiveDateTime(), datetime);


	ofstream fout("dane.txt", std::ofstream::app);

	fout << "\n";
	fout << title + "\n";
	fout << desc + "\n";
	fout << datetime + "\n";

	fout.close();
}
 
