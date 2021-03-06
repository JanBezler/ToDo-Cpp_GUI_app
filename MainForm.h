#pragma once

#include "Event.h"
#include "Reminder.h"
#include "RepeatingReminder.h"
#include "Appointment.h"

namespace ToDoCppGUIapp {

	using namespace System;
	using namespace std;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		int EventOption;
		String^ ChoosenDayName;
		int ChoosenDuration;
		String^ Title;
		String^ Description;
		List<Event^> EventsList;
		DateTime ChoosenDate;

		void SaveEventToFile(Event^);
		void ReadEventFromFile();
		void ClearEventsInFile();
		void ReloadEvents();
		void AddItemToListEvents(Event^);


	public:
		MainForm(void)
		{
			EventOption = 0;
			InitializeComponent();
			ReadEventFromFile();
			SetOption();

			for each (Event ^ e in EventsList)
			{
				AddItemToListEvents(e);
			}

		}

	protected:
		~MainForm()
		{
			if (components)
				delete components;
		}

#pragma region Set Option method

		void SetOption()
		{
			switch (EventOption)
			{
			default:
				this->buttonAppointment->Visible = true;
				this->buttonReminder->Visible = true;
				this->buttonRepeat->Visible = false;
				this->inputTitle->Visible = false;
				this->dateTimePicker->Visible = false;
				this->inputDescription->Visible = false;
				this->chooseDuration->Visible = false;
				this->labelDuration->Visible = false;
				this->labelRepeat->Visible = false;
				this->chooseRepeat->Visible = false;
				this->chooseHour->Visible = false;
				this->chooseMinute->Visible = false;
				this->label1->Visible = false;
				this->label2->Visible = false;
				this->label3->Visible = false;
				this->label4->Visible = false;
				this->label5->Visible = false;
				this->buttonCreate->Visible = false;
				break;

			case 1:
				this->buttonAppointment->Visible = true;
				this->buttonReminder->Visible = true;
				this->buttonRepeat->Visible = false;
				this->inputTitle->Visible = true;
				this->dateTimePicker->Visible = true;
				this->inputDescription->Visible = true;
				this->chooseDuration->Visible = true;
				this->labelDuration->Visible = true;
				this->labelRepeat->Visible = false;
				this->chooseRepeat->Visible = false;
				this->chooseHour->Visible = true;
				this->chooseMinute->Visible = true;
				this->label1->Visible = true;
				this->label2->Visible = true;
				this->label3->Visible = true;
				this->label4->Visible = true;
				this->label5->Visible = true;
				this->buttonCreate->Visible = true;
				break;

			case 2:
				this->buttonAppointment->Visible = true;
				this->buttonReminder->Visible = true;
				this->buttonRepeat->Visible = true;
				this->inputTitle->Visible = true;
				this->dateTimePicker->Visible = true;
				this->inputDescription->Visible = true;
				this->chooseDuration->Visible = false;
				this->labelDuration->Visible = false;
				this->labelRepeat->Visible = false;
				this->chooseRepeat->Visible = false;
				this->chooseHour->Visible = true;
				this->chooseMinute->Visible = true;
				this->label1->Visible = true;
				this->label2->Visible = true;
				this->label3->Visible = true;
				this->label4->Visible = true;
				this->label5->Visible = true;
				this->buttonCreate->Visible = true;
				break;

			case 3:
				this->buttonAppointment->Visible = true;
				this->buttonReminder->Visible = true;
				this->buttonRepeat->Visible = true;
				this->inputTitle->Visible = true;
				this->dateTimePicker->Visible = false;
				this->inputDescription->Visible = true;
				this->chooseDuration->Visible = false;
				this->labelDuration->Visible = false;
				this->labelRepeat->Visible = true;
				this->chooseRepeat->Visible = true;
				this->chooseHour->Visible = true;
				this->chooseMinute->Visible = true;
				this->label1->Visible = false;
				this->label2->Visible = true;
				this->label3->Visible = true;
				this->label4->Visible = true;
				this->label5->Visible = true;
				this->buttonCreate->Visible = true;
				break;
			}
		}
#pragma endregion

#pragma region Windows Form Designer generated code

	private: System::Windows::Forms::Button^ buttonAppointment;
	private: System::Windows::Forms::Button^ buttonReminder;
	private: System::Windows::Forms::ListBox^ listEvents;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::CheckBox^ buttonRepeat;
	private: System::Windows::Forms::TextBox^ inputTitle;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::TextBox^ inputDescription;
	private: System::Windows::Forms::NumericUpDown^ chooseDuration;
	private: System::Windows::Forms::Label^ labelDuration;
	private: System::Windows::Forms::Label^ labelRepeat;
	private: System::Windows::Forms::DomainUpDown^ chooseRepeat;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonCreate;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ chooseMinute;
	private: System::Windows::Forms::NumericUpDown^ chooseHour;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Button^ buttonRemoveSelected;



		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			   this->buttonAppointment = (gcnew System::Windows::Forms::Button());
			   this->buttonReminder = (gcnew System::Windows::Forms::Button());
			   this->buttonRepeat = (gcnew System::Windows::Forms::CheckBox());
			   this->inputTitle = (gcnew System::Windows::Forms::TextBox());
			   this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			   this->inputDescription = (gcnew System::Windows::Forms::TextBox());
			   this->chooseDuration = (gcnew System::Windows::Forms::NumericUpDown());
			   this->labelDuration = (gcnew System::Windows::Forms::Label());
			   this->labelRepeat = (gcnew System::Windows::Forms::Label());
			   this->chooseRepeat = (gcnew System::Windows::Forms::DomainUpDown());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->buttonCreate = (gcnew System::Windows::Forms::Button());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->chooseMinute = (gcnew System::Windows::Forms::NumericUpDown());
			   this->chooseHour = (gcnew System::Windows::Forms::NumericUpDown());
			   this->listEvents = (gcnew System::Windows::Forms::ListBox());
			   this->buttonClear = (gcnew System::Windows::Forms::Button());
			   this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->buttonRemoveSelected = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseDuration))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseMinute))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseHour))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // buttonAppointment
			   // 
			   resources->ApplyResources(this->buttonAppointment, L"buttonAppointment");
			   this->buttonAppointment->Name = L"buttonAppointment";
			   this->buttonAppointment->UseVisualStyleBackColor = true;
			   this->buttonAppointment->Click += gcnew System::EventHandler(this, &MainForm::buttonAppointment_Click);
			   // 
			   // buttonReminder
			   // 
			   resources->ApplyResources(this->buttonReminder, L"buttonReminder");
			   this->buttonReminder->Name = L"buttonReminder";
			   this->buttonReminder->UseVisualStyleBackColor = true;
			   this->buttonReminder->Click += gcnew System::EventHandler(this, &MainForm::buttonReminder_Click);
			   // 
			   // buttonRepeat
			   // 
			   resources->ApplyResources(this->buttonRepeat, L"buttonRepeat");
			   this->buttonRepeat->Name = L"buttonRepeat";
			   this->buttonRepeat->UseVisualStyleBackColor = true;
			   this->buttonRepeat->CheckedChanged += gcnew System::EventHandler(this, &MainForm::buttonRepeat_CheckedChanged);
			   // 
			   // inputTitle
			   // 
			   resources->ApplyResources(this->inputTitle, L"inputTitle");
			   this->inputTitle->Name = L"inputTitle";
			   // 
			   // dateTimePicker
			   // 
			   resources->ApplyResources(this->dateTimePicker, L"dateTimePicker");
			   this->dateTimePicker->Name = L"dateTimePicker";
			   // 
			   // inputDescription
			   // 
			   resources->ApplyResources(this->inputDescription, L"inputDescription");
			   this->inputDescription->Name = L"inputDescription";
			   // 
			   // chooseDuration
			   // 
			   resources->ApplyResources(this->chooseDuration, L"chooseDuration");
			   this->chooseDuration->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10080, 0, 0, 0 });
			   this->chooseDuration->Name = L"chooseDuration";
			   // 
			   // labelDuration
			   // 
			   resources->ApplyResources(this->labelDuration, L"labelDuration");
			   this->labelDuration->Name = L"labelDuration";
			   // 
			   // labelRepeat
			   // 
			   resources->ApplyResources(this->labelRepeat, L"labelRepeat");
			   this->labelRepeat->Name = L"labelRepeat";
			   // 
			   // chooseRepeat
			   // 
			   this->chooseRepeat->Items->Add(resources->GetString(L"chooseRepeat.Items"));
			   this->chooseRepeat->Items->Add(resources->GetString(L"chooseRepeat.Items1"));
			   this->chooseRepeat->Items->Add(resources->GetString(L"chooseRepeat.Items2"));
			   this->chooseRepeat->Items->Add(resources->GetString(L"chooseRepeat.Items3"));
			   this->chooseRepeat->Items->Add(resources->GetString(L"chooseRepeat.Items4"));
			   this->chooseRepeat->Items->Add(resources->GetString(L"chooseRepeat.Items5"));
			   this->chooseRepeat->Items->Add(resources->GetString(L"chooseRepeat.Items6"));
			   resources->ApplyResources(this->chooseRepeat, L"chooseRepeat");
			   this->chooseRepeat->Name = L"chooseRepeat";
			   this->chooseRepeat->ReadOnly = true;
			   // 
			   // label2
			   // 
			   resources->ApplyResources(this->label2, L"label2");
			   this->label2->Name = L"label2";
			   // 
			   // label3
			   // 
			   resources->ApplyResources(this->label3, L"label3");
			   this->label3->Name = L"label3";
			   // 
			   // buttonCreate
			   // 
			   resources->ApplyResources(this->buttonCreate, L"buttonCreate");
			   this->buttonCreate->Name = L"buttonCreate";
			   this->buttonCreate->UseVisualStyleBackColor = true;
			   this->buttonCreate->Click += gcnew System::EventHandler(this, &MainForm::buttonCreate_Click);
			   // 
			   // label1
			   // 
			   resources->ApplyResources(this->label1, L"label1");
			   this->label1->Name = L"label1";
			   // 
			   // label4
			   // 
			   resources->ApplyResources(this->label4, L"label4");
			   this->label4->Name = L"label4";
			   // 
			   // label5
			   // 
			   resources->ApplyResources(this->label5, L"label5");
			   this->label5->Name = L"label5";
			   // 
			   // chooseMinute
			   // 
			   resources->ApplyResources(this->chooseMinute, L"chooseMinute");
			   this->chooseMinute->Name = L"chooseMinute";
			   // 
			   // chooseHour
			   // 
			   resources->ApplyResources(this->chooseHour, L"chooseHour");
			   this->chooseHour->Name = L"chooseHour";
			   // 
			   // listEvents
			   // 
			   resources->ApplyResources(this->listEvents, L"listEvents");
			   this->listEvents->FormattingEnabled = true;
			   this->listEvents->Name = L"listEvents";
			   this->listEvents->Click += gcnew System::EventHandler(this, &MainForm::listEvents_Click);
			   // 
			   // buttonClear
			   // 
			   resources->ApplyResources(this->buttonClear, L"buttonClear");
			   this->buttonClear->Name = L"buttonClear";
			   this->buttonClear->UseVisualStyleBackColor = true;
			   this->buttonClear->Click += gcnew System::EventHandler(this, &MainForm::buttonClear_Click);
			   // 
			   // timer
			   // 
			   this->timer->Enabled = true;
			   this->timer->Interval = 60000;
			   this->timer->Tick += gcnew System::EventHandler(this, &MainForm::timer_Tick);
			   // 
			   // buttonRemoveSelected
			   // 
			   resources->ApplyResources(this->buttonRemoveSelected, L"buttonRemoveSelected");
			   this->buttonRemoveSelected->Name = L"buttonRemoveSelected";
			   this->buttonRemoveSelected->UseVisualStyleBackColor = true;
			   this->buttonRemoveSelected->Click += gcnew System::EventHandler(this, &MainForm::buttonRemoveSelected_Click);
			   // 
			   // MainForm
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   resources->ApplyResources(this, L"$this");
			   this->Controls->Add(this->buttonRemoveSelected);
			   this->Controls->Add(this->buttonClear);
			   this->Controls->Add(this->listEvents);
			   this->Controls->Add(this->chooseHour);
			   this->Controls->Add(this->chooseMinute);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->buttonCreate);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->chooseRepeat);
			   this->Controls->Add(this->labelRepeat);
			   this->Controls->Add(this->labelDuration);
			   this->Controls->Add(this->chooseDuration);
			   this->Controls->Add(this->inputDescription);
			   this->Controls->Add(this->dateTimePicker);
			   this->Controls->Add(this->inputTitle);
			   this->Controls->Add(this->buttonRepeat);
			   this->Controls->Add(this->buttonReminder);
			   this->Controls->Add(this->buttonAppointment);
			   this->Name = L"MainForm";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseDuration))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseMinute))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseHour))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion


	private: System::Void buttonAppointment_Click(System::Object^ sender, System::EventArgs^ e) {
		EventOption = 1;
		SetOption();
	}

	private: System::Void buttonReminder_Click(System::Object^ sender, System::EventArgs^ e) {
		if ((EventOption < 2) && (buttonRepeat->Checked))  EventOption = 3;
		else EventOption = 2;
		SetOption();
	}

	private: System::Void buttonRepeat_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (buttonRepeat->Checked)
		{
			EventOption = 3;
			SetOption();
		}
		else
		{
			EventOption = 2;
			SetOption();
		}
	}

	private: System::Void buttonCreate_Click(System::Object^ sender, System::EventArgs^ e) {
		Event^ newEvent;


		if ((inputTitle->Text != "") && (static_cast<int>(chooseHour->Value) < 24) && (static_cast<int>(chooseMinute->Value) < 60))  Title = inputTitle->Text;
		else
		{
			MessageBox::Show("Title or time was not entered properly!", "error", MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button2);
			return;
		}
		Description = inputDescription->Text;
		ChoosenDate = dateTimePicker->Value.Date;

		DateTime^ DateAndTime = gcnew DateTime(ChoosenDate.Year, ChoosenDate.Month, ChoosenDate.Day, static_cast<int>(chooseHour->Value), static_cast<int>(chooseMinute->Value), 0);


		if (EventOption == 1)
		{
			ChoosenDuration = static_cast<int>(chooseDuration->Value);
			newEvent = gcnew Appointment(DateAndTime, ChoosenDuration, Title, Description);
		}
		else if (EventOption == 2)
		{
			newEvent = gcnew Reminder(DateAndTime, Title, Description);
		}
		else if (EventOption == 3)
		{
			ChoosenDayName = chooseRepeat->Text;
			newEvent = gcnew RepeatingReminder(DateAndTime, ChoosenDayName, Title, Description);
		}

		SaveEventToFile(newEvent);

		AddItemToListEvents(newEvent);
		EventsList.Add(newEvent);
	}

	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
		listEvents->Items->Clear();
		EventsList.Clear();
		ClearEventsInFile();
	}

	private: System::Void listEvents_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			Event^ SelectedEvent = EventsList[listEvents->SelectedIndex];
			buttonRemoveSelected->Enabled = true;
			MessageBox::Show("Description: " + SelectedEvent->GiveDescription(), SelectedEvent->GiveTitle(), MessageBoxButtons::OK, MessageBoxIcon::Information, MessageBoxDefaultButton::Button2);
		}
		catch (const System::ArgumentOutOfRangeException^)
		{
			MessageBox::Show("Choose element from the list!", "error", MessageBoxButtons::OK, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button2);
		}


	}

	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {

		DateTime^ CurrentTime = gcnew DateTime();
		CurrentTime = CurrentTime->Now;
		CurrentTime = DateTime(CurrentTime->Year, CurrentTime->Month, CurrentTime->Day, CurrentTime->Hour, CurrentTime->Minute, 0, 0);

		for each (Event ^ e in EventsList)
		{
			if (e->ToString() == "RepeatingReminder")
			{
				if ((e->GiveRepeat() == CurrentTime->DayOfWeek.ToString()) && (e->GiveDateTimeAsDateTime()->TimeOfDay == CurrentTime->TimeOfDay))
				{
					MessageBox::Show("Description: " + e->GiveDescription(), e->GiveTitle(), MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				}
			}
			else if (e->ToString() == "Reminder")
			{
				if ((e->GiveDateTimeAsDateTime()->TimeOfDay == CurrentTime->TimeOfDay) && (e->GiveDateTimeAsDateTime()->Date == CurrentTime->Date))
				{
					MessageBox::Show("Description: " + e->GiveDescription(), e->GiveTitle(), MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
					EventsList.Remove(e);
				}
			}
			else if (e->ToString() == "Appointment")
			{
				DateTime^ earlier = gcnew DateTime();
				earlier = CurrentTime->AddMinutes(10);
				if ((e->GiveDateTimeAsDateTime()->TimeOfDay == earlier->TimeOfDay) && (e->GiveDateTimeAsDateTime()->Date == earlier->Date))
				{
					MessageBox::Show("[Starts in 10 minutes!] Description: " + e->GiveDescription(), e->GiveTitle(), MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				}
				if ((e->GiveDateTimeAsDateTime()->TimeOfDay == CurrentTime->TimeOfDay) && (e->GiveDateTimeAsDateTime()->Date == CurrentTime->Date))
				{
					EventsList.Remove(e);
				}
			}
		}
		void ReloadEvents();

	}

	private: System::Void buttonRemoveSelected_Click(System::Object^ sender, System::EventArgs^ e) {
		EventsList.Remove(EventsList[listEvents->SelectedIndex]);
		ReloadEvents();
		buttonRemoveSelected->Enabled = false;
	}
};
}
