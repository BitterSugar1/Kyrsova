#pragma once

namespace Planer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ project
	/// </summary>
	public ref class project : public System::Windows::Forms::Form
	{
	public:
		project(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòðóêòîðà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~project()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox17;
	private: System::Windows::Forms::TextBox^ textBox18;
	private: System::Windows::Forms::TextBox^ textBox19;
	private: System::Windows::Forms::TextBox^ textBox20;
	private: System::Windows::Forms::TextBox^ textBox21;
	private: System::Windows::Forms::TextBox^ textBox22;
	private: System::Windows::Forms::TextBox^ textBox23;
	private: System::Windows::Forms::TextBox^ textBox24;
	private: System::Windows::Forms::TextBox^ textBox25;
	private: System::Windows::Forms::TextBox^ textBox26;
	private: System::Windows::Forms::TextBox^ textBox27;
	private: System::Windows::Forms::TextBox^ textBox29;
	private: System::Windows::Forms::TextBox^ textBox28;
	private: System::Windows::Forms::TextBox^ textBox30;
	private: System::Windows::Forms::TextBox^ textBox31;
	private: System::Windows::Forms::TextBox^ textBox32;
	private: System::Windows::Forms::Button^ button3;

	protected:

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->tableLayoutPanel1->ColumnCount = 8;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10.0866F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.73559F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.86297F)));
			this->tableLayoutPanel1->Controls->Add(this->textBox2, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox3, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox4, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox5, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox6, 6, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox7, 7, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox8, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox9, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox10, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox12, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->textBox11, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->textBox13, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->textBox14, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->textBox15, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->textBox16, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->textBox17, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->textBox18, 0, 11);
			this->tableLayoutPanel1->Controls->Add(this->textBox19, 0, 12);
			this->tableLayoutPanel1->Controls->Add(this->textBox20, 0, 13);
			this->tableLayoutPanel1->Controls->Add(this->textBox21, 0, 14);
			this->tableLayoutPanel1->Controls->Add(this->textBox22, 0, 15);
			this->tableLayoutPanel1->Controls->Add(this->textBox23, 0, 16);
			this->tableLayoutPanel1->Controls->Add(this->textBox24, 0, 17);
			this->tableLayoutPanel1->Controls->Add(this->textBox25, 0, 18);
			this->tableLayoutPanel1->Controls->Add(this->textBox26, 0, 19);
			this->tableLayoutPanel1->Controls->Add(this->textBox27, 0, 20);
			this->tableLayoutPanel1->Controls->Add(this->textBox29, 0, 21);
			this->tableLayoutPanel1->Controls->Add(this->textBox30, 0, 23);
			this->tableLayoutPanel1->Controls->Add(this->textBox28, 0, 22);
			this->tableLayoutPanel1->Controls->Add(this->textBox31, 0, 24);
			this->tableLayoutPanel1->Controls->Add(this->textBox32, 0, 25);
			this->tableLayoutPanel1->Controls->Add(this->button3, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 26;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5.003373F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.803685F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.799343F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.803685F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.803685F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1065, 590);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &project::tableLayoutPanel1_Paint);
			// 
			// textBox2
			// 
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox2->Location = System::Drawing::Point(245, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(130, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"Вторник";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox3
			// 
			this->textBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox3->Location = System::Drawing::Point(381, 3);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(130, 22);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"Среда";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox4
			// 
			this->textBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox4->Location = System::Drawing::Point(517, 3);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(130, 22);
			this->textBox4->TabIndex = 3;
			this->textBox4->Text = L"Четверг";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox5
			// 
			this->textBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox5->Location = System::Drawing::Point(653, 3);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(130, 22);
			this->textBox5->TabIndex = 4;
			this->textBox5->Text = L"Пятница";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox6
			// 
			this->textBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox6->Location = System::Drawing::Point(789, 3);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(130, 22);
			this->textBox6->TabIndex = 5;
			this->textBox6->Text = L"Суббота";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox7
			// 
			this->textBox7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox7->Location = System::Drawing::Point(925, 3);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(137, 22);
			this->textBox7->TabIndex = 6;
			this->textBox7->Text = L"Воскресенье";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(110, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(129, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Понедельник";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &project::textBox1_TextChanged);
			// 
			// textBox8
			// 
			this->textBox8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox8->Enabled = false;
			this->textBox8->Location = System::Drawing::Point(3, 32);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(101, 22);
			this->textBox8->TabIndex = 7;
			this->textBox8->Text = L"00:00";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &project::textBox8_TextChanged);
			// 
			// textBox9
			// 
			this->textBox9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox9->Enabled = false;
			this->textBox9->Location = System::Drawing::Point(3, 54);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(101, 22);
			this->textBox9->TabIndex = 8;
			this->textBox9->Text = L"01:00";
			this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &project::textBox9_TextChanged);
			// 
			// textBox10
			// 
			this->textBox10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox10->Enabled = false;
			this->textBox10->Location = System::Drawing::Point(3, 76);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(101, 22);
			this->textBox10->TabIndex = 9;
			this->textBox10->Text = L"02:00";
			this->textBox10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox12
			// 
			this->textBox12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox12->Enabled = false;
			this->textBox12->Location = System::Drawing::Point(3, 98);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(101, 22);
			this->textBox12->TabIndex = 11;
			this->textBox12->Text = L"03:00";
			this->textBox12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox11
			// 
			this->textBox11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox11->Enabled = false;
			this->textBox11->Location = System::Drawing::Point(3, 120);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(101, 22);
			this->textBox11->TabIndex = 10;
			this->textBox11->Text = L"04:00";
			this->textBox11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox13
			// 
			this->textBox13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox13->Enabled = false;
			this->textBox13->Location = System::Drawing::Point(3, 142);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(101, 22);
			this->textBox13->TabIndex = 12;
			this->textBox13->Text = L"05:00";
			this->textBox13->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox14
			// 
			this->textBox14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox14->Enabled = false;
			this->textBox14->Location = System::Drawing::Point(3, 164);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(101, 22);
			this->textBox14->TabIndex = 13;
			this->textBox14->Text = L"06:00";
			this->textBox14->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox15
			// 
			this->textBox15->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox15->Enabled = false;
			this->textBox15->Location = System::Drawing::Point(3, 186);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(101, 22);
			this->textBox15->TabIndex = 14;
			this->textBox15->Text = L"07:00";
			this->textBox15->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox16
			// 
			this->textBox16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox16->Enabled = false;
			this->textBox16->Location = System::Drawing::Point(3, 208);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(101, 22);
			this->textBox16->TabIndex = 15;
			this->textBox16->Text = L"08:00";
			this->textBox16->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox17
			// 
			this->textBox17->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox17->Enabled = false;
			this->textBox17->Location = System::Drawing::Point(3, 230);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(101, 22);
			this->textBox17->TabIndex = 16;
			this->textBox17->Text = L"09:00";
			this->textBox17->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox18
			// 
			this->textBox18->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox18->Enabled = false;
			this->textBox18->Location = System::Drawing::Point(3, 252);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(101, 22);
			this->textBox18->TabIndex = 17;
			this->textBox18->Text = L"10:00";
			this->textBox18->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox19
			// 
			this->textBox19->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox19->Enabled = false;
			this->textBox19->Location = System::Drawing::Point(3, 274);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(101, 22);
			this->textBox19->TabIndex = 18;
			this->textBox19->Text = L"11:00";
			this->textBox19->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox20
			// 
			this->textBox20->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox20->Enabled = false;
			this->textBox20->Location = System::Drawing::Point(3, 296);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(101, 22);
			this->textBox20->TabIndex = 19;
			this->textBox20->Text = L"12:00";
			this->textBox20->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox21
			// 
			this->textBox21->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox21->Enabled = false;
			this->textBox21->Location = System::Drawing::Point(3, 318);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(101, 22);
			this->textBox21->TabIndex = 20;
			this->textBox21->Text = L"13:00";
			this->textBox21->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox22
			// 
			this->textBox22->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox22->Enabled = false;
			this->textBox22->Location = System::Drawing::Point(3, 340);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(101, 22);
			this->textBox22->TabIndex = 21;
			this->textBox22->Text = L"14:00";
			this->textBox22->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox23
			// 
			this->textBox23->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox23->Enabled = false;
			this->textBox23->Location = System::Drawing::Point(3, 362);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(101, 22);
			this->textBox23->TabIndex = 22;
			this->textBox23->Text = L"15:00";
			this->textBox23->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox24
			// 
			this->textBox24->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox24->Enabled = false;
			this->textBox24->Location = System::Drawing::Point(3, 384);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(101, 22);
			this->textBox24->TabIndex = 23;
			this->textBox24->Text = L"16:00";
			this->textBox24->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox25
			// 
			this->textBox25->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox25->Enabled = false;
			this->textBox25->Location = System::Drawing::Point(3, 406);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(101, 22);
			this->textBox25->TabIndex = 24;
			this->textBox25->Text = L"17:00";
			this->textBox25->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox26
			// 
			this->textBox26->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox26->Enabled = false;
			this->textBox26->Location = System::Drawing::Point(3, 428);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(101, 22);
			this->textBox26->TabIndex = 25;
			this->textBox26->Text = L"18:00";
			this->textBox26->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox27
			// 
			this->textBox27->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox27->Enabled = false;
			this->textBox27->Location = System::Drawing::Point(3, 450);
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(101, 22);
			this->textBox27->TabIndex = 26;
			this->textBox27->Text = L"19:00";
			this->textBox27->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox29
			// 
			this->textBox29->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox29->Enabled = false;
			this->textBox29->Location = System::Drawing::Point(3, 472);
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(101, 22);
			this->textBox29->TabIndex = 28;
			this->textBox29->Text = L"20:00";
			this->textBox29->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox30
			// 
			this->textBox30->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox30->Enabled = false;
			this->textBox30->Location = System::Drawing::Point(3, 516);
			this->textBox30->Name = L"textBox30";
			this->textBox30->Size = System::Drawing::Size(101, 22);
			this->textBox30->TabIndex = 29;
			this->textBox30->Text = L"22:00";
			this->textBox30->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox28
			// 
			this->textBox28->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox28->Enabled = false;
			this->textBox28->Location = System::Drawing::Point(3, 494);
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(101, 22);
			this->textBox28->TabIndex = 27;
			this->textBox28->Text = L"21:00";
			this->textBox28->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox31
			// 
			this->textBox31->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox31->Enabled = false;
			this->textBox31->Location = System::Drawing::Point(3, 538);
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(101, 22);
			this->textBox31->TabIndex = 30;
			this->textBox31->Text = L"23:00";
			this->textBox31->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox32
			// 
			this->textBox32->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox32->Enabled = false;
			this->textBox32->Location = System::Drawing::Point(3, 560);
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(101, 22);
			this->textBox32->TabIndex = 31;
			this->textBox32->Text = L"24:00";
			this->textBox32->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button3->Location = System::Drawing::Point(3, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 23);
			this->button3->TabIndex = 32;
			this->button3->Text = L"+";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->Location = System::Drawing::Point(12, 608);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"<";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &project::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(1002, 608);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L">";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// project
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1085, 642);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"project";
			this->Text = L"project";
			this->Load += gcnew System::EventHandler(this, &project::project_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void project_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}