#pragma once
#include "Note.h"

namespace Planer {

	using namespace System;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Класс для сохранения и загрузки заметок
	/// </summary>
	public ref class NoteSerializer abstract sealed
	{
	public:
		// Сохранить список заметок в файл
		static void SaveNotes(List<Note^>^ notes, String^ filePath);

		// Загрузить список заметок из файла
		static List<Note^>^ LoadNotes(String^ filePath);
	};
}