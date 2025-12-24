#include "WeeklyPlannerForm.h"

namespace Planer {

	void WeeklyPlannerForm::LoadExistingNotes()
	{
		try
		{
			// Путь к файлу заметок
			String^ filePath = System::IO::Path::Combine(
				System::Windows::Forms::Application::StartupPath,
				"notes.xml");

			System::Diagnostics::Debug::WriteLine("Пытаюсь загрузить заметки из: " + filePath);

			allNotes = NoteSerializer::LoadNotes(filePath);

			System::Diagnostics::Debug::WriteLine(
				String::Format("Загружено {0} заметок", allNotes->Count));
		}
		catch (Exception^ ex)
		{
			// Создаем новый список, если ошибка
			allNotes = gcnew List<Note^>();

			System::Windows::Forms::MessageBox::Show(
				"Не удалось загрузить заметки. Создан новый список.\n" + ex->Message,
				"Информация",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Information);
		}
	}

	void WeeklyPlannerForm::LoadWeekNotes()
	{
		// Очищаем таблицу от старых заметок
		for (int i = mainTableLayout->Controls->Count - 1; i >= 0; i--)
		{
			Control^ control = mainTableLayout->Controls[i];
			NoteControl^ noteControl = dynamic_cast<NoteControl^>(control);
			if (noteControl != nullptr)
			{
				mainTableLayout->Controls->RemoveAt(i);
			}
		}

		// Добавляем заметки текущей недели
		System::DateTime weekEnd = currentWeekStart.AddDays(7);

		int weekNoteCount = 0;
		for each (Note ^ note in allNotes)
		{
			System::DateTime noteDate = note->DateTime;
			if (noteDate >= currentWeekStart && noteDate < weekEnd)
			{
				AddNoteToTable(note);
				weekNoteCount++;
			}
		}

		// Обновляем отображение недели
		UpdateWeekDisplay();

		// Обновляем заголовок
		this->Text = String::Format(L"Еженедельный планировщик (Всего: {0}, На неделе: {1})",
			allNotes->Count, weekNoteCount);
	}

	void WeeklyPlannerForm::UpdateWeekDisplay()
	{
		// Обновляем заголовки дней недели с датами
		System::DateTime mondayDate = currentWeekStart;

		// Форматируем даты для заголовков
		mondayLabel->Text = String::Format(L"Понедельник\n{0:dd.MM}", mondayDate);
		tuesdayLabel->Text = String::Format(L"Вторник\n{0:dd.MM}", mondayDate.AddDays(1));
		wednesdayLabel->Text = String::Format(L"Среда\n{0:dd.MM}", mondayDate.AddDays(2));
		thursdayLabel->Text = String::Format(L"Четверг\n{0:dd.MM}", mondayDate.AddDays(3));
		fridayLabel->Text = String::Format(L"Пятница\n{0:dd.MM}", mondayDate.AddDays(4));
		saturdayLabel->Text = String::Format(L"Суббота\n{0:dd.MM}", mondayDate.AddDays(5));
		sundayLabel->Text = String::Format(L"Воскресенье\n{0:dd.MM}", mondayDate.AddDays(6));

		// Обновляем доступность кнопок навигации
		prevWeekButton->Enabled = IsWeekInRange(currentWeekStart.AddDays(-7));
		nextWeekButton->Enabled = IsWeekInRange(currentWeekStart.AddDays(7));
	}

	bool WeeklyPlannerForm::IsWeekInRange(System::DateTime weekStart)
	{
		// Определяем границы: текущая неделя, 1 назад, 7 вперед
		System::DateTime now = System::DateTime::Now;
		System::DateTime currentWeek = GetStartOfWeek(now);

		// Минимальная дата: неделя назад от текущей
		System::DateTime minDate = currentWeek.AddDays(-7);

		// Максимальная дата: 7 недель вперед от текущей
		System::DateTime maxDate = currentWeek.AddDays(7 * 7);

		return (weekStart >= minDate && weekStart <= maxDate);
	}

	bool WeeklyPlannerForm::IsCellOccupied(System::DateTime dateTime)
	{
		// Проверяем, есть ли уже заметка в этой временной ячейке
		System::DateTime weekStart = GetStartOfWeek(dateTime);

		// Если дата не относится к текущей отображаемой неделе, не проверяем
		if (weekStart != currentWeekStart)
			return false;

		// Определяем позицию в таблице
		int dayOfWeek = (int)dateTime.DayOfWeek;
		int column = dayOfWeek == 0 ? 6 : dayOfWeek - 1;
		column += 1; // +1 потому что первый столбец - время

		int hour = dateTime.Hour;
		int row = (hour / 2) + 1; // +1 потому что первая строка - заголовки

		// Проверяем все контролы в этой ячейке
		for each (Control ^ control in mainTableLayout->Controls)
		{
			if (mainTableLayout->GetRow(control) == row &&
				mainTableLayout->GetColumn(control) == column)
			{
				NoteControl^ noteControl = dynamic_cast<NoteControl^>(control);
				if (noteControl != nullptr)
				{
					return true;
				}
			}
		}
		return false;
	}

	void WeeklyPlannerForm::AddNoteToTable(Note^ note)
	{
		// Определяем день недели заметки
		System::DateTime noteDate = note->DateTime;
		System::DateTime weekStart = GetStartOfWeek(noteDate);

		// Проверяем, что заметка в текущей отображаемой неделе
		if (weekStart != currentWeekStart)
			return;

		// Определяем столбец (день недели)
		int dayOfWeek = (int)noteDate.DayOfWeek;
		// Конвертируем DayOfWeek (0=Sunday) в наш формат (0=Monday)
		int column = dayOfWeek == 0 ? 6 : dayOfWeek - 1;
		column += 1; // +1 потому что первый столбец - время

		// Определяем строку (время)
		int hour = noteDate.Hour;
		int row = (hour / 2) + 1; // +1 потому что первая строка - заголовки

		// Проверяем границы
		if (row < 1 || row > 12 || column < 1 || column > 7)
		{
			System::Diagnostics::Debug::WriteLine(
				String::Format("Заметка вне границ таблицы: день={0}, час={1}, row={2}, column={3}",
					dayOfWeek, hour, row, column));
			return;
		}

		// Проверяем, не занята ли ячейка
		if (IsCellOccupied(note->DateTime))
		{
			System::Windows::Forms::MessageBox::Show(
				"В это время уже есть заметка",
				"Ошибка",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Warning);
			return;
		}

		// Создаем NoteControl
		NoteControl^ noteControl = gcnew NoteControl();
		noteControl->NoteTitle = note->Title;
		noteControl->IsCompleted = note->IsCompleted;
		noteControl->NoteDescription = note->Description;
		noteControl->NoteTime = note->DateTime;

		// Сохраняем ссылку на Note в Tag для связи
		noteControl->Tag = note;

		// Назначаем обработчики клика
		noteControl->NoteClicked += gcnew NoteClickedEventHandler(this, &WeeklyPlannerForm::OnNoteControlClicked);
		noteControl->NoteEditButtonClick += gcnew NoteEditButtonClickEventHandler(this, &WeeklyPlannerForm::OnNoteEditButtonClicked);

		// Добавляем в таблицу
		mainTableLayout->Controls->Add(noteControl, column, row);
	}

	void WeeklyPlannerForm::OnAddEventButtonClick(Object^ sender, EventArgs^ e)
	{
		// Открываем форму добавления заметки
		AddNoteForm^ addForm = gcnew AddNoteForm();
		if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ title = addForm->NoteTitle->Trim();

			// Дополнительная проверка
			if (String::IsNullOrWhiteSpace(title))
			{
				System::Windows::Forms::MessageBox::Show(
					"Заметка без названия не может быть сохранена",
					"Ошибка",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);
				return;
			}

			// Проверяем, не занята ли ячейка
			if (IsCellOccupied(addForm->NoteDate))
			{
				System::Windows::Forms::MessageBox::Show(
					"В это время уже есть заметка",
					"Ошибка",
					System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Warning);
				return;
			}

			// Создаем новую заметку
			Note^ newNote = gcnew Note(
				title,
				addForm->NoteDescription,
				addForm->NoteDate);

			// Добавляем в общий список
			allNotes->Add(newNote);

			// Добавляем в таблицу (если заметка на текущей неделе)
			AddNoteToTable(newNote);

			// Сохраняем в файл
			SaveNotesToFile();

			// Пересчитываем статистику
			int weekNoteCount = 0;
			System::DateTime weekEnd = currentWeekStart.AddDays(7);
			for each (Note ^ note in allNotes)
			{
				if (note->DateTime >= currentWeekStart && note->DateTime < weekEnd)
					weekNoteCount++;
			}

			// Обновляем заголовок
			this->Text = String::Format(L"Еженедельный планировщик (Всего: {0}, На неделе: {1})",
				allNotes->Count, weekNoteCount);
		}
	}

	void WeeklyPlannerForm::SaveNotesToFile()
	{
		try
		{
			String^ filePath = System::IO::Path::Combine(
				System::Windows::Forms::Application::StartupPath,
				"notes.xml");

			// Создаем директорию, если её нет
			String^ directory = System::IO::Path::GetDirectoryName(filePath);
			if (!System::IO::Directory::Exists(directory))
			{
				System::IO::Directory::CreateDirectory(directory);
			}

			NoteSerializer::SaveNotes(allNotes, filePath);
		}
		catch (Exception^ ex)
		{
			System::Windows::Forms::MessageBox::Show(
				"Ошибка сохранения заметок: " + ex->Message,
				"Ошибка",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Error);
		}
	}

	void WeeklyPlannerForm::OnNoteControlClicked(Object^ sender, EventArgs^ e)
	{
		NoteControl^ clickedNote = safe_cast<NoteControl^>(sender);

		// Находим соответствующую заметку в списке и обновляем её
		if (clickedNote->Tag != nullptr)
		{
			Note^ note = safe_cast<Note^>(clickedNote->Tag);
			note->IsCompleted = clickedNote->IsCompleted;

			// Сохраняем изменения
			SaveNotesToFile();
		}
	}

	void WeeklyPlannerForm::OnNoteEditButtonClicked(Object^ sender, EventArgs^ e)
	{
		// Защита от двойного вызова
		static long long lastCallTicks = 0;
		long long currentTicks = System::DateTime::Now.Ticks;
		long long ticksBetweenCalls = currentTicks - lastCallTicks;

		// Если предыдущий вызов был менее 500 мс назад - игнорируем
		// 1 tick = 100 nanoseconds, so 500 ms = 5,000,000 ticks
		if (ticksBetweenCalls < 5000000 && lastCallTicks != 0)
		{
			return;
		}

		lastCallTicks = currentTicks;

		NoteControl^ clickedNote = safe_cast<NoteControl^>(sender);

		if (clickedNote->Tag != nullptr)
		{
			Note^ noteToEdit = safe_cast<Note^>(clickedNote->Tag);

			// Открываем форму редактирования
			AddNoteForm^ editForm = gcnew AddNoteForm(noteToEdit);

			// Подписываемся на событие удаления
			editForm->NoteDeleted += gcnew EventHandler(this, &WeeklyPlannerForm::OnNoteDeleted);

			System::Windows::Forms::DialogResult dialogResult = editForm->ShowDialog();

			if (dialogResult == System::Windows::Forms::DialogResult::OK)
			{
				// Обновляем данные заметки
				noteToEdit->Title = editForm->NoteTitle;
				noteToEdit->Description = editForm->NoteDescription;
				noteToEdit->DateTime = editForm->NoteDate;

				// Если дата изменилась, проверяем не занята ли новая ячейка
				System::DateTime originalDateTime = safe_cast<Note^>(clickedNote->Tag)->DateTime;
				if (noteToEdit->DateTime != originalDateTime)
				{
					// Проверяем, не пытаемся ли переместить в ту же ячейку (что разрешено)
					// Но сначала проверяем, не занята ли ячейка другим элементом
					bool isSameCell = (GetStartOfWeek(noteToEdit->DateTime) == GetStartOfWeek(originalDateTime)) &&
						(noteToEdit->DateTime.Hour / 2 == originalDateTime.Hour / 2) &&
						(noteToEdit->DateTime.DayOfWeek == originalDateTime.DayOfWeek);

					if (!isSameCell && IsCellOccupied(noteToEdit->DateTime))
					{
						System::Windows::Forms::MessageBox::Show(
							"В это время уже есть заметка",
							"Ошибка",
							System::Windows::Forms::MessageBoxButtons::OK,
							System::Windows::Forms::MessageBoxIcon::Warning);
						return;
					}
				}

				// Обновляем отображение
				clickedNote->NoteTitle = noteToEdit->Title;
				clickedNote->NoteDescription = noteToEdit->Description;
				clickedNote->NoteTime = noteToEdit->DateTime;

				// Если дата изменилась, нужно переразместить заметку
				if (noteToEdit->DateTime != originalDateTime)
				{
					// Удаляем старый контрол
					mainTableLayout->Controls->Remove(clickedNote);

					// Добавляем заметку заново (в новую позицию)
					AddNoteToTable(noteToEdit);
				}

				// Сохраняем изменения
				SaveNotesToFile();

				// Перезагружаем неделю для обновления статистики
				LoadWeekNotes();
			}
			else if (dialogResult == System::Windows::Forms::DialogResult::Abort)
			{
				// Заметка была удалена в форме редактирования
				// Обработка удаления уже выполнена в OnNoteDeleted
			}
		}
	}

	void WeeklyPlannerForm::OnNoteDeleted(Object^ sender, EventArgs^ e)
	{
		AddNoteForm^ editForm = safe_cast<AddNoteForm^>(sender);
		Note^ noteToDelete = editForm->OriginalNote;

		if (noteToDelete != nullptr)
		{
			// Удаляем заметку из списка
			allNotes->Remove(noteToDelete);

			// Удаляем контрол из таблицы
			for each (Control ^ control in mainTableLayout->Controls)
			{
				NoteControl^ noteControl = dynamic_cast<NoteControl^>(control);
				if (noteControl != nullptr && noteControl->Tag != nullptr)
				{
					Note^ note = safe_cast<Note^>(noteControl->Tag);
					if (note == noteToDelete)
					{
						mainTableLayout->Controls->Remove(control);
						break;
					}
				}
			}

			// Сохраняем изменения
			SaveNotesToFile();

			// Перезагружаем неделю для обновления статистики
			LoadWeekNotes();

			System::Windows::Forms::MessageBox::Show(
				"Заметка удалена",
				"Информация",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Information);
		}
	}

	void WeeklyPlannerForm::OnPrevWeekButtonClick(Object^ sender, EventArgs^ e)
	{
		// Переходим на предыдущую неделю, если она в пределах диапазона
		System::DateTime prevWeek = currentWeekStart.AddDays(-7);
		if (IsWeekInRange(prevWeek))
		{
			currentWeekStart = prevWeek;
			LoadWeekNotes();
		}
		else
		{
			System::Windows::Forms::MessageBox::Show(
				"Достигнут предел просмотра недель. Можно просматривать только:\n- Текущую неделю\n- 1 неделю назад\n- 7 недель вперед",
				"Ограничение",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Information);
		}
	}

	void WeeklyPlannerForm::OnNextWeekButtonClick(Object^ sender, EventArgs^ e)
	{
		// Переходим на следующую неделю, если она в пределах диапазона
		System::DateTime nextWeek = currentWeekStart.AddDays(7);
		if (IsWeekInRange(nextWeek))
		{
			currentWeekStart = nextWeek;
			LoadWeekNotes();
		}
		else
		{
			System::Windows::Forms::MessageBox::Show(
				"Достигнут предел просмотра недель. Можно просматривать только:\n- Текущую неделю\n- 1 неделю назад\n- 7 недель вперед",
				"Ограничение",
				System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Information);
		}
	}
}