//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "stdafx.h"		// Для правильной линковки
#include "TextManager.h"
//---------------------------------------------------------------------------
TextManager::TextManager(void)
{
	// Конструктор класса
	
}
//---------------------------------------------------------------------------
TextManager::~TextManager()
{
	// Деструктор класса
	
}
//---------------------------------------------------------------------------
std::string TextManager::SystemStringToStdString(System::String^ Source) {
	// Преобразование System::String в std::String
using namespace System::Runtime::InteropServices;
const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(Source)).ToPointer();
std::string Dest = chars;
Marshal::FreeHGlobal(System::IntPtr((void*)chars));
return Dest;
}
//---------------------------------------------------------------------------
std::wstring TextManager::SystemStringToStdWString(System::String^ Source) {
	// Преобразование System::String в std::String
using namespace System::Runtime::InteropServices;
const wchar_t* chars = (const wchar_t*)(Marshal::StringToHGlobalUni(Source)).ToPointer();
std::wstring Dest = chars;
Marshal::FreeHGlobal(System::IntPtr((void*)chars));
return Dest;
}
//---------------------------------------------------------------------------
std::wstring TextManager::StdStringToStdWString(std::string Source) {
int len;
int slength = (int)Source.length() + 1;
len = MultiByteToWideChar(CP_ACP, 0, Source.c_str(), slength, 0, 0); 
std::wstring r(len, L'\0');
MultiByteToWideChar(CP_ACP, 0, Source.c_str(), slength, &r[0], len);
return r;
}
//---------------------------------------------------------------------------