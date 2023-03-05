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

bool ValArray[54] = { 0 };

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
        for (int i = 0; i < 29; i++)
        {
            for (int j = 0; j < 54; j++)
            {
                dataGridView1->Rows[i]->Cells[j]->Style->BackColor = BackColor.White;
            }
        }
            
    }
    
}

System::Void CellularAutomaton::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
    
}

System::Void CellularAutomaton::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    for (int i = 0; i < 29; i++)
    {
        dataGridView1->Rows->Add();
    }
}

System::Void CellularAutomaton::MyForm::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    dataGridView1->Rows[0]->Cells[e->ColumnIndex]->Style->BackColor = BackColor.Black;
    ValArray[e->ColumnIndex] = 1;
}


