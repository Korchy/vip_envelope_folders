//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "stdafx.h"		// ��� ���������� ��������
#include "VipBase.h"
//---------------------------------------------------------------------------
VipBase::VipBase(void)
{
	// ����������� ������
	
}
//---------------------------------------------------------------------------
VipBase::~VipBase()
{
	// ���������� ������
	
}
//---------------------------------------------------------------------------
//void VipBase::CreateBaseDir(std::wstring BaseDir, std::wstring OurRef)
void VipBase::CreateBaseDir(System::String^ BaseDir, System::String^ OurRef) {
	// �������� ���������� � ����������� �� ���� ���� (���������� �� OurRef
	// ������� �������� ����������
	System::String^ Dest = BaseDir+OurRef;
	System::IO::Directory::CreateDirectory(Dest);

	// ���������� �� ���������
// ������� ���������� �� �����
	// ��� ����
	System::IO::Directory::CreateDirectory(Dest+"\\"+"����");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"�� CL");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"to CL");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"���");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"���������� �������");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"���������� �� ����");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"���������� ���������");
	System::IO::Directory::CreateDirectory(Dest+"\\"+"POA");
	// �� �����
//	System::String^ Base = Dest->Substring(3,2);
	// ��������� �� ������ ����������
	if(BaseDir->Contains("\\03\\")) {
	System::IO::Directory::CreateDirectory(Dest+"\\"+"��������");
		System::IO::Directory::CreateDirectory(Dest+"\\"+"��");
	}
	if(BaseDir->Contains("\\39\\")) {
		System::IO::Directory::CreateDirectory(Dest+"\\"+"��������");
	}
}
//---------------------------------------------------------------------------
