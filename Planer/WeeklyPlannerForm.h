#pragma once

#include "NoteSerializer.h"
#include "Note.h"
#include "NoteControl.h"
#include "AddNoteForm.h"

namespace Planer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Форма недельного планировщика
	/// </summary>
	public ref class WeeklyPlannerForm : public System::Windows::Forms::Form
	{
	public:
		WeeklyPlannerForm(void)
		{
			InitializeComponent();
			allNotes = gcnew List<Note^>();
			currentWeekStart = GetStartOfWeek(System::DateTime::Now);

			// Назначаем обработчики событий
			this->addEventButton->Click += gcnew EventHandler(this, &WeeklyPlannerForm::OnAddEventButtonClick);
			this->prevWeekButton->Click += gcnew EventHandler(this, &WeeklyPlannerForm::OnPrevWeekButtonClick);
			this->nextWeekButton->Click += gcnew EventHandler(this, &WeeklyPlannerForm::OnNextWeekButtonClick);

			LoadExistingNotes();
			LoadWeekNotes();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~WeeklyPlannerForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::TableLayoutPanel^ mainTableLayout;
		System::Windows::Forms::Button^ prevWeekButton;
		System::Windows::Forms::Button^ nextWeekButton;
		System::Windows::Forms::Button^ addEventButton;

		// Заголовки дней недели
	private: System::Windows::Forms::Label^ mondayLabel;
	private: System::Windows::Forms::Label^ tuesdayLabel;
	private: System::Windows::Forms::Label^ wednesdayLabel;
	private: System::Windows::Forms::Label^ thursdayLabel;
	private: System::Windows::Forms::Label^ fridayLabel;
	private: System::Windows::Forms::Label^ saturdayLabel;
	private: System::Windows::Forms::Label^ sundayLabel;

		   // Метки времени (12 пар по 2 часа)
	private: System::Windows::Forms::Label^ timeSlot1Label;
	private: System::Windows::Forms::Label^ timeSlot2Label;
	private: System::Windows::Forms::Label^ timeSlot3Label;
	private: System::Windows::Forms::Label^ timeSlot4Label;
	private: System::Windows::Forms::Label^ timeSlot5Label;
	private: System::Windows::Forms::Label^ timeSlot6Label;
	private: System::Windows::Forms::Label^ timeSlot7Label;
	private: System::Windows::Forms::Label^ timeSlot8Label;
	private: System::Windows::Forms::Label^ timeSlot9Label;
	private: System::Windows::Forms::Label^ timeSlot10Label;
	private: System::Windows::Forms::Label^ timeSlot11Label;
	private: System::Windows::Forms::Label^ timeSlot12Label;

	private:
		List<Note^>^ allNotes;
		System::DateTime currentWeekStart;

		// Методы
		System::DateTime GetStartOfWeek(System::DateTime date)
		{
			int diff = (int)date.DayOfWeek - (int)System::DayOfWeek::Monday;
			if (diff < 0)
				diff += 7;
			return date.AddDays(-diff).Date;
		}

		void LoadExistingNotes();
		void LoadWeekNotes();
		void UpdateWeekDisplay();
		void AddNoteToTable(Note^ note);
		void SaveNotesToFile();
		bool IsWeekInRange(System::DateTime weekStart);
		bool IsCellOccupied(System::DateTime dateTime); // Проверка на занятость ячейки
		void OnAddEventButtonClick(Object^ sender, EventArgs^ e);
		void OnNoteControlClicked(Object^ sender, EventArgs^ e);
		void OnNoteEditButtonClicked(Object^ sender, EventArgs^ e);
		void OnNoteDeleted(Object^ sender, EventArgs^ e);
		void OnPrevWeekButtonClick(Object^ sender, EventArgs^ e);
		void OnNextWeekButtonClick(Object^ sender, EventArgs^ e);

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->mainTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->mondayLabel = (gcnew System::Windows::Forms::Label());
			this->tuesdayLabel = (gcnew System::Windows::Forms::Label());
			this->wednesdayLabel = (gcnew System::Windows::Forms::Label());
			this->thursdayLabel = (gcnew System::Windows::Forms::Label());
			this->fridayLabel = (gcnew System::Windows::Forms::Label());
			this->saturdayLabel = (gcnew System::Windows::Forms::Label());
			this->sundayLabel = (gcnew System::Windows::Forms::Label());
			this->addEventButton = (gcnew System::Windows::Forms::Button());
			this->timeSlot1Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot2Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot3Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot4Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot5Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot6Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot7Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot8Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot9Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot10Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot11Label = (gcnew System::Windows::Forms::Label());
			this->timeSlot12Label = (gcnew System::Windows::Forms::Label());
			this->prevWeekButton = (gcnew System::Windows::Forms::Button());
			this->nextWeekButton = (gcnew System::Windows::Forms::Button());
			this->mainTableLayout->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainTableLayout
			// 
			this->mainTableLayout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainTableLayout->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->mainTableLayout->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->mainTableLayout->ColumnCount = 8;
			this->mainTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10.0866F)));
			this->mainTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.73559F)));
			this->mainTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->mainTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->mainTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->mainTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->mainTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->mainTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->mainTableLayout->Controls->Add(this->mondayLabel, 1, 0);
			this->mainTableLayout->Controls->Add(this->tuesdayLabel, 2, 0);
			this->mainTableLayout->Controls->Add(this->wednesdayLabel, 3, 0);
			this->mainTableLayout->Controls->Add(this->thursdayLabel, 4, 0);
			this->mainTableLayout->Controls->Add(this->fridayLabel, 5, 0);
			this->mainTableLayout->Controls->Add(this->saturdayLabel, 6, 0);
			this->mainTableLayout->Controls->Add(this->sundayLabel, 7, 0);
			this->mainTableLayout->Controls->Add(this->addEventButton, 0, 0);
			this->mainTableLayout->Controls->Add(this->timeSlot1Label, 0, 1);
			this->mainTableLayout->Controls->Add(this->timeSlot2Label, 0, 2);
			this->mainTableLayout->Controls->Add(this->timeSlot3Label, 0, 3);
			this->mainTableLayout->Controls->Add(this->timeSlot4Label, 0, 4);
			this->mainTableLayout->Controls->Add(this->timeSlot5Label, 0, 5);
			this->mainTableLayout->Controls->Add(this->timeSlot6Label, 0, 6);
			this->mainTableLayout->Controls->Add(this->timeSlot7Label, 0, 7);
			this->mainTableLayout->Controls->Add(this->timeSlot8Label, 0, 8);
			this->mainTableLayout->Controls->Add(this->timeSlot9Label, 0, 9);
			this->mainTableLayout->Controls->Add(this->timeSlot10Label, 0, 10);
			this->mainTableLayout->Controls->Add(this->timeSlot11Label, 0, 11);
			this->mainTableLayout->Controls->Add(this->timeSlot12Label, 0, 12);
			this->mainTableLayout->Location = System::Drawing::Point(18, 19);
			this->mainTableLayout->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->mainTableLayout->Name = L"mainTableLayout";
			this->mainTableLayout->RowCount = 13;
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.888123F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.517189F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.508609F)));
			this->mainTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->mainTableLayout->Size = System::Drawing::Size(1578, 891);
			this->mainTableLayout->TabIndex = 0;
			// 
			// mondayLabel
			// 
			this->mondayLabel->BackColor = System::Drawing::Color::LightSteelBlue;
			this->mondayLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mondayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->mondayLabel->Location = System::Drawing::Point(160, 1);
			this->mondayLabel->Margin = System::Windows::Forms::Padding(0);
			this->mondayLabel->Name = L"mondayLabel";
			this->mondayLabel->Size = System::Drawing::Size(199, 86);
			this->mondayLabel->TabIndex = 0;
			this->mondayLabel->Text = L"Понедельник";
			this->mondayLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tuesdayLabel
			// 
			this->tuesdayLabel->BackColor = System::Drawing::Color::LightSteelBlue;
			this->tuesdayLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tuesdayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->tuesdayLabel->Location = System::Drawing::Point(360, 1);
			this->tuesdayLabel->Margin = System::Windows::Forms::Padding(0);
			this->tuesdayLabel->Name = L"tuesdayLabel";
			this->tuesdayLabel->Size = System::Drawing::Size(201, 86);
			this->tuesdayLabel->TabIndex = 1;
			this->tuesdayLabel->Text = L"Вторник";
			this->tuesdayLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// wednesdayLabel
			// 
			this->wednesdayLabel->BackColor = System::Drawing::Color::LightSteelBlue;
			this->wednesdayLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->wednesdayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->wednesdayLabel->Location = System::Drawing::Point(562, 1);
			this->wednesdayLabel->Margin = System::Windows::Forms::Padding(0);
			this->wednesdayLabel->Name = L"wednesdayLabel";
			this->wednesdayLabel->Size = System::Drawing::Size(201, 86);
			this->wednesdayLabel->TabIndex = 2;
			this->wednesdayLabel->Text = L"Среда";
			this->wednesdayLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// thursdayLabel
			// 
			this->thursdayLabel->BackColor = System::Drawing::Color::LightSteelBlue;
			this->thursdayLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->thursdayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->thursdayLabel->Location = System::Drawing::Point(764, 1);
			this->thursdayLabel->Margin = System::Windows::Forms::Padding(0);
			this->thursdayLabel->Name = L"thursdayLabel";
			this->thursdayLabel->Size = System::Drawing::Size(201, 86);
			this->thursdayLabel->TabIndex = 3;
			this->thursdayLabel->Text = L"Четверг";
			this->thursdayLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// fridayLabel
			// 
			this->fridayLabel->BackColor = System::Drawing::Color::LightSteelBlue;
			this->fridayLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->fridayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->fridayLabel->Location = System::Drawing::Point(966, 1);
			this->fridayLabel->Margin = System::Windows::Forms::Padding(0);
			this->fridayLabel->Name = L"fridayLabel";
			this->fridayLabel->Size = System::Drawing::Size(201, 86);
			this->fridayLabel->TabIndex = 4;
			this->fridayLabel->Text = L"Пятница";
			this->fridayLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// saturdayLabel
			// 
			this->saturdayLabel->BackColor = System::Drawing::Color::LightSteelBlue;
			this->saturdayLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->saturdayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->saturdayLabel->Location = System::Drawing::Point(1168, 1);
			this->saturdayLabel->Margin = System::Windows::Forms::Padding(0);
			this->saturdayLabel->Name = L"saturdayLabel";
			this->saturdayLabel->Size = System::Drawing::Size(201, 86);
			this->saturdayLabel->TabIndex = 5;
			this->saturdayLabel->Text = L"Суббота";
			this->saturdayLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// sundayLabel
			// 
			this->sundayLabel->BackColor = System::Drawing::Color::LightSteelBlue;
			this->sundayLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sundayLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->sundayLabel->Location = System::Drawing::Point(1370, 1);
			this->sundayLabel->Margin = System::Windows::Forms::Padding(0);
			this->sundayLabel->Name = L"sundayLabel";
			this->sundayLabel->Size = System::Drawing::Size(207, 86);
			this->sundayLabel->TabIndex = 6;
			this->sundayLabel->Text = L"Воскресенье";
			this->sundayLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// addEventButton
			// 
			this->addEventButton->BackColor = System::Drawing::Color::LightGreen;
			this->addEventButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addEventButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addEventButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->addEventButton->Location = System::Drawing::Point(1, 1);
			this->addEventButton->Margin = System::Windows::Forms::Padding(0);
			this->addEventButton->Name = L"addEventButton";
			this->addEventButton->Size = System::Drawing::Size(158, 86);
			this->addEventButton->TabIndex = 7;
			this->addEventButton->Text = L"+";
			this->addEventButton->UseVisualStyleBackColor = false;
			// 
			// timeSlot1Label
			// 
			this->timeSlot1Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot1Label->AutoSize = true;
			this->timeSlot1Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot1Label->Location = System::Drawing::Point(1, 88);
			this->timeSlot1Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot1Label->Name = L"timeSlot1Label";
			this->timeSlot1Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot1Label->TabIndex = 8;
			this->timeSlot1Label->Text = L"00:00 - 01:59";
			this->timeSlot1Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot2Label
			// 
			this->timeSlot2Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot2Label->AutoSize = true;
			this->timeSlot2Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot2Label->Location = System::Drawing::Point(1, 154);
			this->timeSlot2Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot2Label->Name = L"timeSlot2Label";
			this->timeSlot2Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot2Label->TabIndex = 9;
			this->timeSlot2Label->Text = L"02:00 - 03:59";
			this->timeSlot2Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot3Label
			// 
			this->timeSlot3Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot3Label->AutoSize = true;
			this->timeSlot3Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot3Label->Location = System::Drawing::Point(1, 220);
			this->timeSlot3Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot3Label->Name = L"timeSlot3Label";
			this->timeSlot3Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot3Label->TabIndex = 10;
			this->timeSlot3Label->Text = L"04:00 - 05:59";
			this->timeSlot3Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot4Label
			// 
			this->timeSlot4Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot4Label->AutoSize = true;
			this->timeSlot4Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot4Label->Location = System::Drawing::Point(1, 286);
			this->timeSlot4Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot4Label->Name = L"timeSlot4Label";
			this->timeSlot4Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot4Label->TabIndex = 11;
			this->timeSlot4Label->Text = L"06:00 - 07:59";
			this->timeSlot4Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot5Label
			// 
			this->timeSlot5Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot5Label->AutoSize = true;
			this->timeSlot5Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot5Label->Location = System::Drawing::Point(1, 352);
			this->timeSlot5Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot5Label->Name = L"timeSlot5Label";
			this->timeSlot5Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot5Label->TabIndex = 12;
			this->timeSlot5Label->Text = L"08:00 - 09:59";
			this->timeSlot5Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot6Label
			// 
			this->timeSlot6Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot6Label->AutoSize = true;
			this->timeSlot6Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot6Label->Location = System::Drawing::Point(1, 418);
			this->timeSlot6Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot6Label->Name = L"timeSlot6Label";
			this->timeSlot6Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot6Label->TabIndex = 13;
			this->timeSlot6Label->Text = L"10:00 - 11:59";
			this->timeSlot6Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot7Label
			// 
			this->timeSlot7Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot7Label->AutoSize = true;
			this->timeSlot7Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot7Label->Location = System::Drawing::Point(1, 484);
			this->timeSlot7Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot7Label->Name = L"timeSlot7Label";
			this->timeSlot7Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot7Label->TabIndex = 14;
			this->timeSlot7Label->Text = L"12:00 - 13:59";
			this->timeSlot7Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot8Label
			// 
			this->timeSlot8Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot8Label->AutoSize = true;
			this->timeSlot8Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot8Label->Location = System::Drawing::Point(1, 550);
			this->timeSlot8Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot8Label->Name = L"timeSlot8Label";
			this->timeSlot8Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot8Label->TabIndex = 15;
			this->timeSlot8Label->Text = L"14:00 - 15:59";
			this->timeSlot8Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot9Label
			// 
			this->timeSlot9Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot9Label->AutoSize = true;
			this->timeSlot9Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot9Label->Location = System::Drawing::Point(1, 616);
			this->timeSlot9Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot9Label->Name = L"timeSlot9Label";
			this->timeSlot9Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot9Label->TabIndex = 16;
			this->timeSlot9Label->Text = L"16:00 - 17:59";
			this->timeSlot9Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot10Label
			// 
			this->timeSlot10Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot10Label->AutoSize = true;
			this->timeSlot10Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot10Label->Location = System::Drawing::Point(1, 682);
			this->timeSlot10Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot10Label->Name = L"timeSlot10Label";
			this->timeSlot10Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot10Label->TabIndex = 17;
			this->timeSlot10Label->Text = L"18:00 - 19:59";
			this->timeSlot10Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot11Label
			// 
			this->timeSlot11Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot11Label->AutoSize = true;
			this->timeSlot11Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot11Label->Location = System::Drawing::Point(1, 748);
			this->timeSlot11Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot11Label->Name = L"timeSlot11Label";
			this->timeSlot11Label->Size = System::Drawing::Size(158, 65);
			this->timeSlot11Label->TabIndex = 18;
			this->timeSlot11Label->Text = L"20:00 - 21:59";
			this->timeSlot11Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeSlot12Label
			// 
			this->timeSlot12Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->timeSlot12Label->AutoSize = true;
			this->timeSlot12Label->BackColor = System::Drawing::SystemColors::Control;
			this->timeSlot12Label->Location = System::Drawing::Point(1, 814);
			this->timeSlot12Label->Margin = System::Windows::Forms::Padding(0);
			this->timeSlot12Label->Name = L"timeSlot12Label";
			this->timeSlot12Label->Size = System::Drawing::Size(158, 76);
			this->timeSlot12Label->TabIndex = 19;
			this->timeSlot12Label->Text = L"22:00 - 23:59";
			this->timeSlot12Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// prevWeekButton
			// 
			this->prevWeekButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->prevWeekButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->prevWeekButton->Location = System::Drawing::Point(18, 948);
			this->prevWeekButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->prevWeekButton->Name = L"prevWeekButton";
			this->prevWeekButton->Size = System::Drawing::Size(60, 60);
			this->prevWeekButton->TabIndex = 1;
			this->prevWeekButton->Text = L"<";
			this->prevWeekButton->UseVisualStyleBackColor = true;
			// 
			// nextWeekButton
			// 
			this->nextWeekButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->nextWeekButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->nextWeekButton->Location = System::Drawing::Point(1555, 948);
			this->nextWeekButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->nextWeekButton->Name = L"nextWeekButton";
			this->nextWeekButton->Size = System::Drawing::Size(60, 60);
			this->nextWeekButton->TabIndex = 2;
			this->nextWeekButton->Text = L">";
			this->nextWeekButton->UseVisualStyleBackColor = true;
			// 
			// WeeklyPlannerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1628, 1033);
			this->Controls->Add(this->nextWeekButton);
			this->Controls->Add(this->prevWeekButton);
			this->Controls->Add(this->mainTableLayout);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"WeeklyPlannerForm";
			this->Text = L"Еженедельный планировщик";
			this->mainTableLayout->ResumeLayout(false);
			this->mainTableLayout->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}