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


	public:
		MainForm(void)
		{
			InitializeComponent();
			EventOption = 0;

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
				this->label2->Visible = false;
				this->label3->Visible = false;
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
				this->label2->Visible = true;
				this->label3->Visible = true;
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
				this->label2->Visible = true;
				this->label3->Visible = true;
				this->buttonCreate->Visible = true;
				break;

			case 3:
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
				this->labelRepeat->Visible = true;
				this->chooseRepeat->Visible = true;
				this->label2->Visible = true;
				this->label3->Visible = true;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chooseDuration))->BeginInit();
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
			this->dateTimePicker->Location = System::Drawing::Point(12, 271);
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
			this->chooseDuration->Location = System::Drawing::Point(137, 297);
			this->chooseDuration->Name = L"chooseDuration";
			this->chooseDuration->Size = System::Drawing::Size(75, 20);
			this->chooseDuration->TabIndex = 9;
			// 
			// labelDuration
			// 
			this->labelDuration->AutoSize = true;
			this->labelDuration->Location = System::Drawing::Point(36, 299);
			this->labelDuration->Name = L"labelDuration";
			this->labelDuration->Size = System::Drawing::Size(95, 13);
			this->labelDuration->TabIndex = 10;
			this->labelDuration->Text = L"Duration (minutes):";
			// 
			// labelRepeat
			// 
			this->labelRepeat->AutoSize = true;
			this->labelRepeat->Location = System::Drawing::Point(42, 325);
			this->labelRepeat->Name = L"labelRepeat";
			this->labelRepeat->Size = System::Drawing::Size(45, 13);
			this->labelRepeat->TabIndex = 11;
			this->labelRepeat->Text = L"Repeat:";
			// 
			// chooseRepeat
			// 
			this->chooseRepeat->Location = System::Drawing::Point(93, 323);
			this->chooseRepeat->Name = L"chooseRepeat";
			this->chooseRepeat->Size = System::Drawing::Size(120, 20);
			this->chooseRepeat->TabIndex = 12;
			this->chooseRepeat->Text = L"domainUpDown1";
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
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 464);
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


		    


};
}
