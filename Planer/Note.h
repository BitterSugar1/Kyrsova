#pragma once

namespace Planer {

	using namespace System;

	/// <summary>
	/// Класс заметки
	/// </summary>
	public ref class Note
	{
	private:
		String^ _title;
		String^ _description;
		System::DateTime _dateTime;
		bool _isCompleted;

	public:
		// Конструкторы
		Note();
		Note(String^ title, String^ description, System::DateTime dateTime);

		// Свойства для XML сериализации (должны быть public)
		property String^ Title {
			String^ get() { return _title; }
			void set(String^ value) { _title = value; }
		}

		property String^ Description {
			String^ get() { return _description; }
			void set(String^ value) { _description = value; }
		}

		property System::DateTime DateTime {
			System::DateTime get() { return _dateTime; }
			void set(System::DateTime value) { _dateTime = value; }
		}

		property bool IsCompleted {
			bool get() { return _isCompleted; }
			void set(bool value) { _isCompleted = value; }
		}

		// Дополнительные методы для удобства (если нужны)
		String^ GetTitle() { return _title; }
		void SetTitle(String^ value) { _title = value; }

		String^ GetDescription() { return _description; }
		void SetDescription(String^ value) { _description = value; }

		System::DateTime GetDateTime() { return _dateTime; }
		void SetDateTime(System::DateTime value) { _dateTime = value; }

		bool GetIsCompleted() { return _isCompleted; }
		void SetIsCompleted(bool value) { _isCompleted = value; }
	};
}