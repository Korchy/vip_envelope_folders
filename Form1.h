#pragma once


namespace TCMPluginDir {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(268, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::textBox1_KeyDown);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(191, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(89, 25);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Создать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 71);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Создание директории";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			// Входной параметр (вторым параметром должна передаваться директория, в которой будут выполнены действия)
			using namespace System;
			using namespace System::IO;
			array<String^>^ arguments = Environment::GetCommandLineArgs();
			String^ Dest = "";
			// Т.к. Total Commander разбивает путь к директории, если есть пробелы в названиях - собрать строку целиком
			for(int i=1; i < arguments->Length; i++) {
				Dest = Dest->Concat(Dest, " ", arguments[i]);
			}
			// Если нет завершающего слеша - добавить
			if(Dest->Substring(Dest->Length - 1) != "\\") {
				Dest = Dest->Concat(Dest, "\\");
			}
/*				// Создание директории
			Dest = Dest->Concat(Dest,"\\",this->textBox1->Text);
			Directory::CreateDirectory(Dest);
			// Создание файлов (копированием из исходного Doc1.doc)
			String^ FileName = FileName->Concat(Dest,"\\",this->textBox1->Text,".doc");;
			String^ FileName2 = FileName2->Concat(Dest,"\\","Приложение ",this->textBox1->Text,".doc");
			// Копируем шаблонный файл word из текущей директории
			// Если ругается на error C2039: GetCurrentDirectoryW: не является членом "System::IO::Directory"
			// вставить в stdafx.h указание #undef GetCurrentDirectory
			String^ CurrentPath = CurrentPath->Concat(Directory::GetCurrentDirectory(),"\\","Doc1.doc");
			File::Copy(CurrentPath,FileName);
			File::Copy(CurrentPath,FileName2);
*/
/*			TextManager* TManager = new TextManager();
			std::wstring BaseDir = TManager->SystemStringToStdWString(Dest);
			std::wstring OurRef = TManager->SystemStringToStdWString(this->textBox1->Text);
*/
			// Создать директории по OurRef
			VipBase* VBase = new VipBase();
			bool rez = VBase->CreateBaseDir(Dest, this->textBox1->Text);
/*
			// Скопировать файл STOP.doc
			Dest = Dest->Concat(Dest,"\\",this->textBox1->Text);
			String^ FileName = FileName->Concat(Dest,"\\","END",".doc");
//			String^ Dir = Directory::GetCurrentDirectory();
			String^ Dir = "C:";
			String^ CurrentPath = CurrentPath->Concat(Dir,"\\","END.doc");
			File::Copy(CurrentPath,FileName);
*/
/*
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result;
			MessageBox::Show( this, CurrentPath, caption, buttons );
*/
			// Закрыть окно
			if(rez == true) {
				Close();
			}
			
			 }

	private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 // По нажатию Enter - нажимать на кнопку
				 if(e->KeyCode == Keys::Enter) button1_Click(sender,e);
				 // Esc - закрыть
				 if(e->KeyCode == Keys::Escape) Close();
			 }
	};
}