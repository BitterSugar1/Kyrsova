#include "NoteSerializer.h"
#include "Note.h"

#include <vcclr.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;
using namespace System::IO;

namespace Planer {

	void NoteSerializer::SaveNotes(List<Note^>^ notes, String^ filePath)
	{
		try
		{
			XmlSerializer^ serializer = gcnew XmlSerializer(List<Note^>::typeid);
			StreamWriter^ writer = gcnew StreamWriter(filePath);
			serializer->Serialize(writer, notes);
			writer->Close();
		}
		catch (Exception^ ex)
		{
			throw gcnew Exception("Ошибка сохранения: " + ex->Message);
		}
	}

	List<Note^>^ NoteSerializer::LoadNotes(String^ filePath)
	{
		try
		{
			if (!System::IO::File::Exists(filePath))
			{
				System::Diagnostics::Debug::WriteLine("Файл заметок не найден: " + filePath);
				return gcnew List<Note^>();
			}

			XmlSerializer^ serializer = gcnew XmlSerializer(List<Note^>::typeid);

			StreamReader^ reader = gcnew StreamReader(filePath, System::Text::Encoding::UTF8);

			List<Note^>^ notes = safe_cast<List<Note^>^>(serializer->Deserialize(reader));
			reader->Close();

			System::Diagnostics::Debug::WriteLine(
				String::Format("Успешно загружено {0} заметок", notes->Count));

			return notes;
		}
		catch (System::Exception^ ex)
		{
			System::Diagnostics::Debug::WriteLine(
				"Ошибка загрузки заметок: " + ex->Message);

			return gcnew List<Note^>();
		}
	}
}