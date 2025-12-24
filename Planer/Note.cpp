#include "Note.h"

namespace Planer {
	long long _lastEditClickTime = 0;

	// Конструктор по умолчанию
	Note::Note()
	{
		_title = String::Empty;
		_description = String::Empty;
		_dateTime = System::DateTime::Now;
		_isCompleted = false;  // По умолчанию не выполнена
	}

	// Конструктор с параметрами
	Note::Note(String^ title, String^ description, System::DateTime dateTime)
	{
		_title = title;
		_description = description;
		_dateTime = dateTime;
		_isCompleted = false;  // По умолчанию не выполнена
	}
}