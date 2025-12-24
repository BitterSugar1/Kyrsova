#pragma once

#include "Note.h"

namespace Planer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Форма для добавления/редактирования заметки
	/// </summary>
	public ref class AddNoteForm : public System::Windows::Forms::Form
	{
	public:
		// Конструктор для добавления новой заметки
		AddNoteForm(void) : _isEditMode(false), _noteToEdit(nullptr)
		{
			InitializeComponent();


			this->saveButton->Click += gcnew EventHandler(this, &AddNoteForm::OnSaveButtonClick);
			this->cancelButton->Click += gcnew EventHandler(this, &AddNoteForm::OnCancelButtonClick);
			this->deleteButton->Click += gcnew EventHandler(this, &AddNoteForm::OnDeleteButtonClick);
			this->Text = L"Добавить заметку";
			this->deleteButton->Visible = false;
		}

		// Конструктор для редактирования существующей заметки
		AddNoteForm(Note^ noteToEdit) : _isEditMode(true), _noteToEdit(noteToEdit)
		{
			InitializeComponent();

			this->saveButton->Click += gcnew EventHandler(this, &AddNoteForm::OnSaveButtonClick);
			this->cancelButton->Click += gcnew EventHandler(this, &AddNoteForm::OnCancelButtonClick);
			this->deleteButton->Click += gcnew EventHandler(this, &AddNoteForm::OnDeleteButtonClick);

			// Заполняем поля данными заметки
			titleTextBox->Text = noteToEdit->Title;
			descriptionTextBox->Text = noteToEdit->Description;
			dateTimePicker->Value = noteToEdit->DateTime;

			this->Text = L"Редактировать заметку";
			this->deleteButton->Visible = true;
		}

		// Свойства для доступа к данным формы
		property String^ NoteTitle {
			String^ get() { return titleTextBox->Text; }
		}

		property String^ NoteDescription {
			String^ get() { return descriptionTextBox->Text; }
		}

		property DateTime NoteDate {
			DateTime get() { return dateTimePicker->Value; }
		}

		// Свойство для режима редактирования
		property bool IsEditMode {
			bool get() { return _isEditMode; }
		}

		// Свойство для исходной заметки (в режиме редактирования)
		property Note^ OriginalNote {
			Note^ get() { return _noteToEdit; }
		}

		// Событие удаления заметки
		event EventHandler^ NoteDeleted;

	private:
		System::Windows::Forms::Label^ titleLabel;
		System::Windows::Forms::Label^ descriptionLabel;
		System::Windows::Forms::Label^ dateLabel;
		System::Windows::Forms::TextBox^ titleTextBox;
		System::Windows::Forms::TextBox^ descriptionTextBox;
		System::Windows::Forms::DateTimePicker^ dateTimePicker;
		System::Windows::Forms::Button^ saveButton;
		System::Windows::Forms::Button^ cancelButton;
		System::Windows::Forms::Button^ deleteButton;

		bool _isEditMode;
		Note^ _noteToEdit;

		void OnSaveButtonClick(Object^ sender, EventArgs^ e);
		void OnCancelButtonClick(Object^ sender, EventArgs^ e);
		void OnDeleteButtonClick(Object^ sender, EventArgs^ e);

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->descriptionLabel = (gcnew System::Windows::Forms::Label());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->titleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->descriptionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->Location = System::Drawing::Point(12, 15);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(61, 13);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"Название:";
			// 
			// descriptionLabel
			// 
			this->descriptionLabel->AutoSize = true;
			this->descriptionLabel->Location = System::Drawing::Point(12, 70);
			this->descriptionLabel->Name = L"descriptionLabel";
			this->descriptionLabel->Size = System::Drawing::Size(60, 13);
			this->descriptionLabel->TabIndex = 1;
			this->descriptionLabel->Text = L"Описание:";
			// 
			// dateLabel
			// 
			this->dateLabel->AutoSize = true;
			this->dateLabel->Location = System::Drawing::Point(12, 125);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(98, 13);
			this->dateLabel->TabIndex = 2;
			this->dateLabel->Text = L"Дата и время:";
			// 
			// titleTextBox
			// 
			this->titleTextBox->Location = System::Drawing::Point(12, 31);
			this->titleTextBox->Name = L"titleTextBox";
			this->titleTextBox->Size = System::Drawing::Size(310, 20);
			this->titleTextBox->TabIndex = 3;
			// 
			// descriptionTextBox
			// 
			this->descriptionTextBox->Location = System::Drawing::Point(12, 86);
			this->descriptionTextBox->Multiline = true;
			this->descriptionTextBox->Name = L"descriptionTextBox";
			this->descriptionTextBox->Size = System::Drawing::Size(310, 30);
			this->descriptionTextBox->TabIndex = 4;
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->CustomFormat = L"dd.MM.yyyy HH:mm";
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(12, 141);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->Size = System::Drawing::Size(310, 20);
			this->dateTimePicker->TabIndex = 5;
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(85, 180);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(75, 23);
			this->saveButton->TabIndex = 6;
			this->saveButton->Text = L"Сохранить";
			this->saveButton->UseVisualStyleBackColor = true;
			// 
			// cancelButton
			// 
			this->cancelButton->Location = System::Drawing::Point(247, 180);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 7;
			this->cancelButton->Text = L"Отмена";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// deleteButton
			// 
			this->deleteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)));
			this->deleteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteButton->Location = System::Drawing::Point(166, 180);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(75, 23);
			this->deleteButton->TabIndex = 8;
			this->deleteButton->Text = L"Удалить";
			this->deleteButton->UseVisualStyleBackColor = false;
			// 
			// AddNoteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 215);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->dateTimePicker);
			this->Controls->Add(this->descriptionTextBox);
			this->Controls->Add(this->titleTextBox);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->descriptionLabel);
			this->Controls->Add(this->titleLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddNoteForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавить заметку";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}