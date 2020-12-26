#pragma once

#include "Event.h"
#include "Reminder.h"
#include "RepeatingReminder.h"
#include "Appointment.h"

namespace ToDoCppGUIapp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
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
		DateTime ChoosenDate;
		int ChoosenHour, ChoosenMinute;

		void SaveEventToFile(Event^);

	public:
		MainForm(void)
		{
			EventOption = 0;

			InitializeComponent();
			SetOption();

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
				this->listEvents->Visible = true;
				this->vScrollBar->Visible = true;
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
				this->listEvents->Visible = true;
				this->vScrollBar->Visible = true;
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
				this->listEvents->Visible = true;
				this->vScrollBar->Visible = true;
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
				this->listEvents->Visible = true;
				this->vScrollBar->Visible = true;
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
	private: System::Windows::Forms::CheckedListBox^ listEvents;
	private: System::Windows::Forms::VScrollBar^ vScrollBar;
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
	private:System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ chooseMinute;
	private: System::Windows::Forms::NumericUpDown^ chooseHour;


		void InitializeComponent(void)
		{
			this->buttonAppointment = (gcnew System::Windows::Forms::Button());
			this->buttonReminder = (gcnew System::Windows::Forms::Button());
			this->listEvents = (gcnew System::Windows::Forms::CheckedListBox());
			this->vScrollBar = (gcnew System::Windows::Forms::VScrollBar());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseDuration))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseMinute))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseHour))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonAppointment
			// 
			this->buttonAppointment->Location = System::Drawing::Point(12, 12);
			this->buttonAppointment->Name = L"buttonAppointment";
			this->buttonAppointment->Size = System::Drawing::Size(75, 54);
			this->buttonAppointment->TabIndex = 0;
			this->buttonAppointment->Text = L"New Appointment";
			this->buttonAppointment->UseVisualStyleBackColor = true;
			this->buttonAppointment->Click += gcnew System::EventHandler(this, &MainForm::buttonAppointment_Click);
			// 
			// buttonReminder
			// 
			this->buttonReminder->Location = System::Drawing::Point(93, 12);
			this->buttonReminder->Name = L"buttonReminder";
			this->buttonReminder->Size = System::Drawing::Size(75, 54);
			this->buttonReminder->TabIndex = 1;
			this->buttonReminder->Text = L"New Reminder";
			this->buttonReminder->UseVisualStyleBackColor = true;
			this->buttonReminder->Click += gcnew System::EventHandler(this, &MainForm::buttonReminder_Click);
			// 
			// listEvents
			// 
			this->listEvents->FormattingEnabled = true;
			this->listEvents->Location = System::Drawing::Point(295, 4);
			this->listEvents->Name = L"listEvents";
			this->listEvents->Size = System::Drawing::Size(224, 454);
			this->listEvents->TabIndex = 3;
			// 
			// vScrollBar
			// 
			this->vScrollBar->Location = System::Drawing::Point(522, 4);
			this->vScrollBar->Name = L"vScrollBar";
			this->vScrollBar->Size = System::Drawing::Size(17, 454);
			this->vScrollBar->TabIndex = 4;
			// 
			// buttonRepeat
			// 
			this->buttonRepeat->AutoSize = true;
			this->buttonRepeat->Location = System::Drawing::Point(174, 49);
			this->buttonRepeat->Name = L"buttonRepeat";
			this->buttonRepeat->Size = System::Drawing::Size(61, 17);
			this->buttonRepeat->TabIndex = 5;
			this->buttonRepeat->Text = L"Repeat";
			this->buttonRepeat->UseVisualStyleBackColor = true;
			this->buttonRepeat->CheckedChanged += gcnew System::EventHandler(this, &MainForm::buttonRepeat_CheckedChanged);
			// 
			// inputTitle
			// 
			this->inputTitle->Location = System::Drawing::Point(12, 87);
			this->inputTitle->Name = L"inputTitle";
			this->inputTitle->Size = System::Drawing::Size(227, 20);
			this->inputTitle->TabIndex = 6;
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->Location = System::Drawing::Point(12, 278);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(227, 20);
			this->dateTimePicker->TabIndex = 7;
			// 
			// inputDescription
			// 
			this->inputDescription->Location = System::Drawing::Point(12, 126);
			this->inputDescription->Multiline = true;
			this->inputDescription->Name = L"inputDescription";
			this->inputDescription->Size = System::Drawing::Size(227, 133);
			this->inputDescription->TabIndex = 8;
			// 
			// chooseDuration
			// 
			this->chooseDuration->Location = System::Drawing::Point(136, 345);
			this->chooseDuration->Name = L"chooseDuration";
			this->chooseDuration->Size = System::Drawing::Size(75, 20);
			this->chooseDuration->TabIndex = 9;
			// 
			// labelDuration
			// 
			this->labelDuration->AutoSize = true;
			this->labelDuration->Location = System::Drawing::Point(35, 347);
			this->labelDuration->Name = L"labelDuration";
			this->labelDuration->Size = System::Drawing::Size(95, 13);
			this->labelDuration->TabIndex = 10;
			this->labelDuration->Text = L"Duration (minutes):";
			// 
			// labelRepeat
			// 
			this->labelRepeat->AutoSize = true;
			this->labelRepeat->Location = System::Drawing::Point(54, 280);
			this->labelRepeat->Name = L"labelRepeat";
			this->labelRepeat->Size = System::Drawing::Size(45, 13);
			this->labelRepeat->TabIndex = 11;
			this->labelRepeat->Text = L"Repeat:";
			// 
			// chooseRepeat
			// 
			this->chooseRepeat->Items->Add(L"Monday");
			this->chooseRepeat->Items->Add(L"Tuesday");
			this->chooseRepeat->Items->Add(L"Wednesday");
			this->chooseRepeat->Items->Add(L"Thursday");
			this->chooseRepeat->Items->Add(L"Friday");
			this->chooseRepeat->Items->Add(L"Saturday");
			this->chooseRepeat->Items->Add(L"Sunday");
			this->chooseRepeat->Location = System::Drawing::Point(105, 278);
			this->chooseRepeat->Name = L"chooseRepeat";
			this->chooseRepeat->ReadOnly = true;
			this->chooseRepeat->Size = System::Drawing::Size(96, 20);
			this->chooseRepeat->TabIndex = 12;
			this->chooseRepeat->Text = L"Monday";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Title:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Description:";
			// 
			// buttonCreate
			// 
			this->buttonCreate->Location = System::Drawing::Point(12, 383);
			this->buttonCreate->Name = L"buttonCreate";
			this->buttonCreate->Size = System::Drawing::Size(223, 69);
			this->buttonCreate->TabIndex = 15;
			this->buttonCreate->Text = L"Create";
			this->buttonCreate->UseVisualStyleBackColor = true;
			this->buttonCreate->Click += gcnew System::EventHandler(this, &MainForm::buttonCreate_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 262);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Date:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(35, 311);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Time:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(120, 311);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(10, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L":";
			// 
			// chooseMinute
			// 
			this->chooseMinute->Location = System::Drawing::Point(136, 309);
			this->chooseMinute->Name = L"chooseMinute";
			this->chooseMinute->Size = System::Drawing::Size(39, 20);
			this->chooseMinute->TabIndex = 19;
			// 
			// chooseHour
			// 
			this->chooseHour->Location = System::Drawing::Point(75, 309);
			this->chooseHour->Name = L"chooseHour";
			this->chooseHour->Size = System::Drawing::Size(39, 20);
			this->chooseHour->TabIndex = 20;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 464);
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
			this->Controls->Add(this->vScrollBar);
			this->Controls->Add(this->listEvents);
			this->Controls->Add(this->buttonReminder);
			this->Controls->Add(this->buttonAppointment);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
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

		Title = inputTitle->Text;
		Description = inputDescription->Text;

		//DateTime Now;
		//Now = Now.Now;
		ChoosenDate = dateTimePicker->Value.Date;
		
		//ChoosenDate.AddHours(-Now.Hour);
		//ChoosenDate.AddMinutes(-Now.Minute);

		DateTime^ DateAndTime = gcnew DateTime(ChoosenDate.Year, ChoosenDate.Month, ChoosenDate.Day, static_cast<int>(chooseHour->Value), static_cast<int>(chooseMinute->Value),0);

		
		if (EventOption == 1) 
		{
			ChoosenDuration = static_cast<int>(chooseDuration->Value);
			newEvent = gcnew Appointment(DateAndTime,ChoosenDuration,Title,Description);
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
		
		

	} 


};
}
