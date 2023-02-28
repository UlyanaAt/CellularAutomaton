#pragma once

namespace CellularAutomaton {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ buttonSS;
	private: System::Windows::Forms::NumericUpDown^ numRule;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSS = (gcnew System::Windows::Forms::Button());
			this->numRule = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numRule))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonSS);
			this->groupBox1->Controls->Add(this->numRule);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 10));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(278, 178);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Enter rule";
			// 
			// buttonSS
			// 
			this->buttonSS->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonSS->Font = (gcnew System::Drawing::Font(L"MS Gothic", 16));
			this->buttonSS->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->buttonSS->Location = System::Drawing::Point(22, 90);
			this->buttonSS->Name = L"buttonSS";
			this->buttonSS->Size = System::Drawing::Size(200, 63);
			this->buttonSS->TabIndex = 2;
			this->buttonSS->Text = L"Start/Stop";
			this->buttonSS->UseVisualStyleBackColor = false;
			this->buttonSS->Click += gcnew System::EventHandler(this, &MyForm::buttonSS_Click);
			// 
			// numRule
			// 
			this->numRule->Font = (gcnew System::Drawing::Font(L"MS Gothic", 16));
			this->numRule->Location = System::Drawing::Point(102, 38);
			this->numRule->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 256, 0, 0, 0 });
			this->numRule->Name = L"numRule";
			this->numRule->Size = System::Drawing::Size(120, 34);
			this->numRule->TabIndex = 1;
			this->numRule->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 213, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 16));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(17, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 27);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Rule";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(314, 22);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1506, 840);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1832, 874);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numRule))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonSS_Click(System::Object^ sender, System::EventArgs^ e);
};
}
