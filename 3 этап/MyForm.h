#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;
#include <cmath> 
#include <msclr/marshal.h>
#include <iostream>
using namespace msclr::interop;

namespace Project54 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	int _n = 1;
	double h = 0.1;
	double a, b;
	double n;
	long double* a_n;
	long double* b_n;
	long double* result;
	long double SimpsonIntegral(int, double, double, double, double, double(*)(double, int, double));
	double f1(double, int, double);
	double f2(double, int, double);
	double f3(double, int, double);
	double f4(double, int, double);
	double fa1(double, int, double);
	double fb1(double, int, double);
	char* uravnenie = new char[255];
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBox6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"y=x", L"y=sin(x)", L"y=5x+2", L"y=sin(x)+cos(x)" });
			this->comboBox4->Location = System::Drawing::Point(104, 63);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(134, 21);
			this->comboBox4->TabIndex = 0;
			this->comboBox4->Text = L"y=x";
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox4_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(112, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Выберите уравнение";
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"0.1", L"0.01", L"0.001" });
			this->comboBox5->Location = System::Drawing::Point(324, 63);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(121, 21);
			this->comboBox5->TabIndex = 2;
			this->comboBox5->Text = L"0.1";
			this->comboBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox5_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(373, 47);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Шаг";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(603, 46);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(144, 13);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Кол-во членов разложения";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"5", L"10" });
			this->comboBox6->Location = System::Drawing::Point(615, 63);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(121, 21);
			this->comboBox6->TabIndex = 5;
			this->comboBox6->Text = L"1";
			this->comboBox6->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox6_SelectedIndexChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(464, 586);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Расчитать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(49, 110);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(405, 444);
			this->dataGridView2->TabIndex = 7;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick);
			// 
			// chart2
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart2->Legends->Add(legend1);
			this->chart2->Location = System::Drawing::Point(594, 178);
			this->chart2->Name = L"chart2";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"фурье";
			this->chart2->Series->Add(series1);
			this->chart2->Size = System::Drawing::Size(300, 300);
			this->chart2->TabIndex = 8;
			this->chart2->Text = L"chart2";
			this->chart2->Click += gcnew System::EventHandler(this, &MyForm::chart2_Click);
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(1059, 661);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox4);
			this->Name = L"MyForm";
			this->Text = L"Ряды Фурье";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
	   


	   
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	marshal_context^ marshal = gcnew marshal_context();
	a = -M_PI;
	b = M_PI;
	
	if (comboBox5->Text != "") h = atof(marshal->marshal_as<const char*>(comboBox5->Text));
	std::cout << h<<'\n';
	n = (b - a) / h;
	if (comboBox6->Text != "") _n = atof(marshal->marshal_as<const char*>(comboBox6->Text));
	std::cout << _n << '\n';
	a_n = new long double[_n];
	
	b_n = new long double[_n];
	result = new long double[n];
	for (int i = 0; i < n; i++) {
		result[i] = 0;
	}
	if (comboBox4->Text == L"y=x") {
		a_n[0] = ((1 / b) * SimpsonIntegral(0, a, b, h, n, f1)) / 2;
		result[0] = a_n[0];
		for (int i = 1; i < _n; i++) {
			a_n[i] = ((1 / M_PI) * SimpsonIntegral(i, a, b, h, n, fa1));
			


		}
		for (int i = 1; i < _n; i++) {
			b_n[i] = ((1 / M_PI) * SimpsonIntegral(i, a, b, h, n, fb1));

		}
		double x = a;
		for (int j = 1; j < _n; j++) {
			for (int i = 1; i < n; i++) {
				result[i] += (a_n[j] * cos(j * x) + b_n[j] * sin(j * x));
				std::cout << result[i]<<'\n';
				//result = b_n[1] * sin(1 * x) + b_n[2] * sin(2 * x) + b_n[3] * sin(3 * x) + b_n[4] * sin(4 * x) + b_n[5] * sin(5 * x);
				//result = 2 * sin(x) - sin(2 * x) + (2 * sin(3 * x)) / 3 - sin(4 * x) / 2 + (2 * sin(5 * x)) / 5; // ряд y=x из 5 членов

				x += h;
			}
			x = a;

		}
	}
	if (comboBox4->Text == L"y=sin(x)") {
		a_n[0] = ((1 / b) * SimpsonIntegral(0, a, b, h, n, f2))/2;
		for (int i = 1; i < _n; i++) {
			a_n[i] = ((1 / M_PI) * SimpsonIntegral(i, a, b, h, n, fa1));


		}
		for (int i = 1; i < _n; i++) {
			b_n[i] = ((1 / M_PI) * SimpsonIntegral(i, a, b, h, n, fb1));

		}
		double x = a;
		for (int j = 1; j < _n; j++) {
			for (int i = 1; i < n; i++) {
				result[i] += (a_n[j] * cos(j * x) + b_n[j] * sin(j * x));
				//result = b_n[1] * sin(1 * x) + b_n[2] * sin(2 * x) + b_n[3] * sin(3 * x) + b_n[4] * sin(4 * x) + b_n[5] * sin(5 * x);
				//result = 2 * sin(x) - sin(2 * x) + (2 * sin(3 * x)) / 3 - sin(4 * x) / 2 + (2 * sin(5 * x)) / 5; // ряд y=x из 5 членов

				x += h;
			}
			x = a;

		}
	}
	if (comboBox4->Text == L"y=5x+2") {
		a_n[0] = ((1 / b) * SimpsonIntegral(0, a, b, h, n, f3)) / 2;
		for (int i = 1; i < _n; i++) {
			a_n[i] = ((1 / M_PI) * SimpsonIntegral(i, a, b, h, n, fa1));


		}
		for (int i = 1; i < _n; i++) {
			b_n[i] = ((1 / M_PI) * SimpsonIntegral(i, a, b, h, n, fb1));

		}
		double x = a;
		for (int j = 1; j < _n; j++) {
			for (int i = 1; i < n; i++) {
				result[i] += (a_n[j] * cos(j * x) + b_n[j] * sin(j * x));
				//result = b_n[1] * sin(1 * x) + b_n[2] * sin(2 * x) + b_n[3] * sin(3 * x) + b_n[4] * sin(4 * x) + b_n[5] * sin(5 * x);
				//result = 2 * sin(x) - sin(2 * x) + (2 * sin(3 * x)) / 3 - sin(4 * x) / 2 + (2 * sin(5 * x)) / 5; // ряд y=x из 5 членов

				x += h;
			}
			x = a;

		}
	}
	if (comboBox4->Text == L"y=sin(x)+cos(x)") {
		a_n[0] = ((1 / b) * SimpsonIntegral(0, a, b, h, n, f4)) / 2;
		for (int i = 1; i < _n; i++) {
			a_n[i] = ((1 / M_PI) * SimpsonIntegral(i, a, b, h, n, fa1));


		}
		for (int i = 1; i < _n; i++) {
			b_n[i] = ((1 / M_PI) * SimpsonIntegral(i, a, b, h, n, fb1));

		}
		double x = a;
		for (int j = 1; j < _n; j++) {
			for (int i = 1; i < n; i++) {
				result[i] += (a_n[j] * cos(j * x) + b_n[j] * sin(j * x));
				//result = b_n[1] * sin(1 * x) + b_n[2] * sin(2 * x) + b_n[3] * sin(3 * x) + b_n[4] * sin(4 * x) + b_n[5] * sin(5 * x);
				//result = 2 * sin(x) - sin(2 * x) + (2 * sin(3 * x)) / 3 - sin(4 * x) / 2 + (2 * sin(5 * x)) / 5; // ряд y=x из 5 членов

				x += h;
			}
			x = a;
			
			}
		}
	a = -M_PI;
	double x1=a;
	dataGridView2->RowCount = 2000;
	dataGridView2->ColumnCount = 3;
	for (int i = 0; i < 2000; i++) {
		dataGridView2->Rows[i]->Cells[0]->Value =x1;
		dataGridView2->Rows[i]->Cells[1]->Value = result[i];
		
		x1 += h;
	}
	double x2 = a;
	chart2->Series["фурье"]->Points->Clear();
	for (int i = 0; i < n; i++) {

		chart2->Series["фурье"]->Points->AddXY(x2, result[i]);
		
		x2 += h;
	}
}

private: System::Void comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox6_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void chart2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
	///////////////

	
	


	double f1(double x, int, double) {
		return x;

	}
	double f2(double x, int, double) {
		return sin(x);

	}
	double f3(double x, int, double) {
		return 5*x + 2;

	}
	double f4(double x, int, double) {
		return sin(x) + cos(x);

	}
	double fa1(double x, int n, double b) {
		return (x * cos(n * x));

	}
	double fb1(double x, int n, double b) {
		return (x * sin(n * x));

	}


	long double SimpsonIntegral(int _n, double a, double b, double h, double n, double(*f)(double, int, double)) {

		long double result = h * (f(a, _n, b) + f(b, _n, b)) / 6.0;

		for (int i = 1; i <= n; i++)
			result = result + 4.0 / 6.0 * h * f(a + h * (i - 0.5), _n, b);

		for (int i = 1; i <= n - 1; i++)
			result = result + 2.0 / 6.0 * h * f(a + h * i, _n, b);

		return result;

	}


}
