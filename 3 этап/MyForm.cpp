#include "MyForm.h"
#include <Windows.h>


using namespace System;
using namespace System::Windows::Forms;

/* ������� ����� main() */
[STAThreadAttribute]
void main() {

    Application::EnableVisualStyles(); // ������ ��������� ��������� ����������
    Application::SetCompatibleTextRenderingDefault(false); // ������ ��������� ��������� ����������


    Project54::MyForm form;
    Application::Run(% form);  // ��������� ������� �����

}