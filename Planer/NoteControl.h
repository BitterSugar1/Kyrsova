#pragma once

#include <Windows.h>

namespace Planer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public delegate void NoteClickedEventHandler(Object^ sender, EventArgs^ e);
	public delegate void NoteEditButtonClickEventHandler(Object^ sender, EventArgs^ e);

	/// <summary>
	/// Пользовательский элемент управления для отображения заметки
	/// </summary>
	public ref class NoteControl : public System::Windows::Forms::UserControl
	{
	public:
		NoteControl(void)
		{
			InitializeComponent();

			// Назначаем обработчик клика на весь контрол
			this->Click += gcnew EventHandler(this, &NoteControl::OnControlClick);

			// Кнопка редактирования - используем MouseDown
			this->editButton->Click += gcnew EventHandler(this, &NoteControl::OnEditButtonClick);

			toolTip = gcnew ToolTip();
			toolTip->AutoPopDelay = 5000;
			toolTip->InitialDelay = 500;
			toolTip->ReshowDelay = 100;
			toolTip->ShowAlways = true;

			this->MouseEnter += gcnew EventHandler(this, &NoteControl::OnMouseEnterControl);
			this->MouseLeave += gcnew EventHandler(this, &NoteControl::OnMouseLeaveControl);
			this->titleLabel->MouseEnter += gcnew EventHandler(this, &NoteControl::OnMouseEnterControl);
			this->titleLabel->MouseLeave += gcnew EventHandler(this, &NoteControl::OnMouseLeaveControl);
		}

		// Событие клика на заметку
		event NoteClickedEventHandler^ NoteClicked;
		// Событие нажатия кнопки редактирования
		event NoteEditButtonClickEventHandler^ NoteEditButtonClick;

		// Свойства
		property String^ NoteTitle{
			String ^ get() { return titleLabel->Text; }
			void set(String ^ value) {
				titleLabel->Text = value;
				UpdateToolTip();
			}
		}

			property bool IsCompleted{
				bool get() { return _isCompleted; }
				void set(bool value) {
					_isCompleted = value;
					// Обновляем внешний вид при изменении состояния
					UpdateAppearance();
				}
		}

			property String^ NoteDescription{
				String ^ get() { return _description; }
				void set(String ^ value) {
					_description = value;
					// Обновляем ToolTip
					UpdateToolTip();
				}
		}

			property DateTime NoteTime{
				DateTime get() { return _noteTime; }
				void set(DateTime value) {
					_noteTime = value;
					// Обновляем ToolTip
					UpdateToolTip();
				}
		}

	private:
		System::Windows::Forms::Label^ titleLabel;
		System::Windows::Forms::Button^ editButton;
		System::Windows::Forms::ToolTip^ toolTip;
		System::ComponentModel::Container^ components;
		String^ _description;
		DateTime _noteTime;
		bool _isCompleted;
		static long long _lastEditClickTime;

		void UpdateToolTip()
		{
			String^ timeStr = _noteTime.ToString("HH:mm");
			String^ dateStr = _noteTime.ToString("dd.MM.yyyy");

			if (!String::IsNullOrEmpty(_description))
			{
				String^ tooltipText = String::Format(L"{0}\nВремя: {1} ({2})\n\nОписание:\n{3}",
					titleLabel->Text, timeStr, dateStr, _description);
				toolTip->SetToolTip(this, tooltipText);
				toolTip->SetToolTip(titleLabel, tooltipText);
				toolTip->SetToolTip(editButton, tooltipText);
			}
			else
			{
				String^ tooltipText = String::Format(L"{0}\nВремя: {1} ({2})",
					titleLabel->Text, timeStr, dateStr);
				toolTip->SetToolTip(this, tooltipText);
				toolTip->SetToolTip(titleLabel, tooltipText);
				toolTip->SetToolTip(editButton, tooltipText);
			}
		}

		void UpdateAppearance()
		{
			if (_isCompleted)
			{
				// Выполненная задача - зеленый фон, перечеркнутый текст
				titleLabel->BackColor = Color::LightGreen;
				titleLabel->Font = gcnew Drawing::Font(
					titleLabel->Font,
					Drawing::FontStyle::Strikeout | Drawing::FontStyle::Regular);
			}
			else
			{
				// Невыполненная задача - желтый фон, обычный текст
				titleLabel->BackColor = Color::LightYellow;
				titleLabel->Font = gcnew Drawing::Font(
					titleLabel->Font,
					Drawing::FontStyle::Regular);
			}
		}

		void OnControlClick(Object^ sender, EventArgs^ e)
		{
			// Меняем состояние при клике
			IsCompleted = !IsCompleted;
			NoteClicked(this, e);
		}

		void OnEditButtonClick(Object^ sender, EventArgs^ e)
		{
			// Проверяем время последнего клика
			long long currentTicks = System::DateTime::Now.Ticks;
			long long ticksBetweenCalls = currentTicks - _lastEditClickTime;

			// Если прошло меньше 1 секунды - игнорируем
			if (ticksBetweenCalls < 10000000 && _lastEditClickTime != 0) // 1 секунда = 10,000,000 ticks
			{
				return;
			}

			_lastEditClickTime = currentTicks;

			// Генерируем событие редактирования
			NoteEditButtonClick(this, e);
		}

		void OnMouseEnterControl(Object^ sender, EventArgs^ e)
		{
			this->Cursor = Cursors::Hand;
			// Подсветка при наведении
			titleLabel->BackColor = Color::LightBlue;
		}

		void OnMouseLeaveControl(Object^ sender, EventArgs^ e)
		{
			this->Cursor = Cursors::Default;
			// Возвращаем обычный цвет
			UpdateAppearance();
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->editButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->AutoEllipsis = true;
			this->titleLabel->BackColor = System::Drawing::Color::LightYellow;
			this->titleLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->titleLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->titleLabel->Location = System::Drawing::Point(0, 0);
			this->titleLabel->Margin = System::Windows::Forms::Padding(0);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Padding = System::Windows::Forms::Padding(10, 0, 10, 0); // Уменьшил правый padding
			this->titleLabel->Size = System::Drawing::Size(2356, 1061);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"Название заметки";
			this->titleLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->titleLabel->Click += gcnew System::EventHandler(this, &NoteControl::OnControlClick);
			// 
			// editButton
			// 
			this->editButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->editButton->Dock = System::Windows::Forms::DockStyle::Right; // Изменено с Anchor на Dock
			this->editButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8)); // Увеличил шрифт
			this->editButton->Margin = System::Windows::Forms::Padding(0);
			this->editButton->Name = L"editButton";
			this->editButton->Size = System::Drawing::Size(60, 1061); // Фиксированная ширина
			this->editButton->TabIndex = 1;
			this->editButton->Text = L"✏️";
			this->editButton->UseVisualStyleBackColor = false;
			this->editButton->Click += gcnew System::EventHandler(this, &NoteControl::OnEditButtonClick);
			// 
			// NoteControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Transparent;
			this->Controls->Add(this->editButton);
			this->Controls->Add(this->titleLabel);
			this->Margin = System::Windows::Forms::Padding(0);
			this->Name = L"NoteControl";
			this->Size = System::Drawing::Size(2416, 1061); // Увеличил ширину на 60 пикселей для кнопки
			this->ResumeLayout(false);
		}
#pragma endregion
	};
}