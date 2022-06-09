#include "MyForm.h"
#include <Windows.h>


using namespace System;
using namespace System::Windows::Forms;

/* Функция входа main() */
[STAThreadAttribute]
void main() {

    Application::EnableVisualStyles(); // Задаем параметры отрисовки приложения
    Application::SetCompatibleTextRenderingDefault(false); // Задаем параметры отрисовки приложения


    Project54::MyForm form;
    Application::Run(% form);  // Запускаем главную форму

}