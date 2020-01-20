#pragma once
//---------------------------------------------------------------------------
#ifndef TextManagerH
#define TextManagerH
//---------------------------------------------------------------------------
#include <string>	// ��� ������������� std::string
#include <windows.h>	// ��� MessageBox
#pragma comment(lib,"User32.lib")	// ����� MessageBox �������� ��-��� windows forms
//---------------------------------------------------------------------------
// ����� ��� ������ � �������
//---------------------------------------------------------------------------
class TextManager
{
protected:

private:

public:
	TextManager(void);	// ����������� ������
	~TextManager();		// ���������� ������

	// ����������
//	std::string File;	// ���� � ����� � �����
	
	// �������
	std::string SystemStringToStdString(System::String^ Source);
	std::wstring SystemStringToStdWString(System::String^ Source);
	std::wstring StdStringToStdWString(std::string Source);

};
#endif
//---------------------------------------------------------------------------