#include "MainForm.h"
//#include "Event.h"
//#include "Reminder.h"
//#include "RepeatingReminder.h"
//#include "Appointment.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);
	ToDoCppGUIapp::MainForm form;
	Application::Run(% form);
}