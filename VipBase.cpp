//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "stdafx.h"		// Для правильной линковки
#include "VipBase.h"
//---------------------------------------------------------------------------
VipBase::VipBase(void)
{
	// Конструктор класса
	
}
//---------------------------------------------------------------------------
VipBase::~VipBase()
{
	// Деструктор класса
	
}
//---------------------------------------------------------------------------
//void VipBase::CreateBaseDir(std::wstring BaseDir, std::wstring OurRef)
void VipBase::CreateBaseDir(System::String^ BaseDir, System::String^ OurRef) {
	// Создание директорий в зависимости от типа базы (определяем по OurRef
	// Создать основную директорию
	System::String^ Dest = BaseDir+OurRef;
	System::IO::Directory::CreateDirectory(Dest);

	// Директории не создавать
// Создать директории по базам
	// Для всех
	System::IO::Directory::CreateDirectory(Dest+"\\"+"ОТ CL");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"ДЛЯ CL");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"ВиП");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"ИНСТРУКЦИЯ КЛИЕНТА");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"ФИНАНСОВЫЕ ДОКУМЕНТЫ");
	// По базам
//	System::String^ Base = Dest->Substring(3,2);
	// Проверяем из полной директории
	if(BaseDir->Contains("\\03\\")) {
		System::IO::Directory::CreateDirectory(Dest+"\\"+"ФИПС");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"ПУБЛИКАЦИЯ НА ФИПС");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"ПЕРЕЧЕНЬ");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"ТЗ");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"POA");
	}
	if(BaseDir->Contains("\\07\\")) {
		System::IO::Directory::CreateDirectory(Dest+"\\"+"ФИПС");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"POA");
	}
	if(BaseDir->Contains("\\08\\")) {
		System::IO::Directory::CreateDirectory(Dest+"\\"+"ФИПС");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"POA");
	}
	if(BaseDir->Contains("\\09\\")) {
		System::IO::Directory::CreateDirectory(Dest+"\\"+"ФИПС");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"POA");
	}
	if(BaseDir->Contains("\\11\\")) {
		System::IO::Directory::CreateDirectory(Dest+"\\"+"СУД");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"POA");
	}
	if(BaseDir->Contains("\\20\\")) {
		System::IO::Directory::CreateDirectory(Dest+"\\"+"СУД");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"POA");
	}
	if(BaseDir->Contains("\\39\\")) {
		System::IO::Directory::CreateDirectory(Dest+"\\"+"ТЗ");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"ПРОВЕРКА");
	}
	if(BaseDir->Contains("\\44\\")) {
		System::IO::Directory::CreateDirectory(Dest+"\\"+"СУД");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"POA");
	}
}
//---------------------------------------------------------------------------
