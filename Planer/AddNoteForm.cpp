#include "AddNoteForm.h"

namespace Planer {

	void AddNoteForm::OnSaveButtonClick(Object^ sender, EventArgs^ e)
	{
		String^ title = titleTextBox->Text->Trim();

		if (String::IsNullOrWhiteSpace(title))
		{
			System::Windows::Forms::MessageBox::Show(
				"Введите название заметки",
				"Ошибка",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Warning);

			// Устанавливаем фокус на поле ввода
			titleTextBox->Focus();
			titleTextBox->SelectAll();
			return;
		}

		// Также проверяем дату (она не должна быть в прошлом, или любая другая логика)
		if (dateTimePicker->Value < DateTime::Now.AddMinutes(-5)) // Допускаем 5 минут в прошлом
		{
			System::Windows::Forms::MessageBox::Show(
				"Дата не должна быть в прошлом",
				"Ошибка",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Warning);

			return;
		}

		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	void AddNoteForm::OnCancelButtonClick(Object^ sender, EventArgs^ e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}

	void AddNoteForm::OnDeleteButtonClick(Object^ sender, EventArgs^ e)
	{
		System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(
			"Вы уверены, что хотите удалить эту заметку?",
			"Подтверждение удаления",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Question);

		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			// Генерируем событие удаления
			NoteDeleted(this, EventArgs::Empty);
			this->DialogResult = System::Windows::Forms::DialogResult::Abort; // Используем Abort для обозначения удаления
			this->Close();
		}
	}
}