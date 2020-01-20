#pragma once
//---------------------------------------------------------------------------
#ifndef TextManagerH
#define TextManagerH
//---------------------------------------------------------------------------
#include <string>	// Для использования std::string
#include <windows.h>	// Для MessageBox
#pragma comment(lib,"User32.lib")	// Чтобы MessageBox вызывать из-под windows forms
//---------------------------------------------------------------------------
// Класс для работы с текстом
//---------------------------------------------------------------------------
class TextManager
{
protected:

private:

public:
	TextManager(void);	// Конструктор класса
	~TextManager();		// Деструктор класса

	// Переменные
//	std::string File;	// Путь к файлу с логом
	
	// Функции
	std::string SystemStringToStdString(System::String^ Source);
	std::wstring SystemStringToStdWString(System::String^ Source);
	std::wstring StdStringToStdWString(std::string Source);

};
#endif
//---------------------------------------------------------------------------