#include "MyForm.h"
using namespace CellularAutomaton;
using namespace System::Windows::Forms;

// Application entry point
[STAThreadAttribute]
void main(array<String^>^ args) {
    // Initial Application Parameters:
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    CellularAutomaton::MyForm form;
    Application::Run(% form);
}

System::Void CellularAutomaton::MyForm::buttonSS_Click(System::Object^ sender, System::EventArgs^ e)
{
   

    BCount += 1;
    if (BCount % 2 != 0)
    {
        timer1->Start();
    }
    else
    {
        timer1->Stop();
    }
    
}

System::Void CellularAutomaton::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
    
}

System::Void CellularAutomaton::MyForm::dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor = BackColor.Black;
}

System::Void CellularAutomaton::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    for (int i = 0; i < 29; i++)
    {
        dataGridView1->Rows->Add();
    }
}


