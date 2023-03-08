#include "MyForm.h"
#include <iostream>
#include <map>

using namespace CellularAutomaton;
using namespace System::Windows::Forms;

// Application entry point
[STAThreadAttribute]
void main(cli::array<String^>^ args) {
    // Initial Application Parameters:
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    CellularAutomaton::MyForm form;
    Application::Run(% form);
}

bool ValArray[54] = { 0 };
bool interimValArray[54] = { 0 };
bool* pointerVA{ ValArray };
bool* pointerTrans;
bool* pointerIntVA{ interimValArray };
string binRuleNumber;

std::map <string, int> mRule = { {"000", 0}, {"001", 0}, {"010", 0}, {"011", 0}, {"100", 0}, {"101", 0},
        {"110", 0}, {"111", 0} };

Void CellularAutomaton::MyForm::Rule()
{
    int b;
    
    RuleNumber = (int)numRule->Value;
    binRuleNumber = dec2bin(RuleNumber);
    int i = 0;
        for (auto it = mRule.begin(); it != mRule.end(); ++it)
        {
            b = binRuleNumber[i];
            it->second = binRuleNumber[i] - '0';
            i++;
        }

}

string CellularAutomaton::MyForm::dec2bin(int num)
{
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return binRuleNumber = to_string(bin);
}

Void CellularAutomaton::MyForm::Draw(bool* pointer)
{
    string smth;
    for (int i = 0; i < 54; i++)
    {
        if (i == 0)
        {
            smth = to_string(*(pointer+53)) + to_string(*(pointer+i)) + to_string(*(pointer+i + 1));
            *(pointerIntVA+i) = mRule[smth];
        }
        else if (i == 53)
        {
            smth = to_string(*(pointer + i - 1)) + to_string(*(pointer + i)) + to_string(*(pointer));
            *(pointerIntVA + i) = mRule[smth];
        }
        else
        {
            smth = to_string(*(pointer + i - 1)) + to_string(*(pointer + i)) + to_string(*(pointer + i + 1));
            *(pointerIntVA + i) = mRule[smth];
        }
    }

    for (int i = 1; i < 29; i++)
    {
        for (int j = 0; j < 54; j++)
        {
            if (*(pointerIntVA + j) == 1)
            {
                dataGridView1->Rows[i]->Cells[j]->Style->BackColor = BackColor.Black;
            }
        }
    }

    pointerTrans = pointerVA;
    pointerVA = pointerIntVA;
    pointerIntVA = pointerTrans;
}



System::Void CellularAutomaton::MyForm::buttonSS_Click(System::Object^ sender, System::EventArgs^ e)
{
   

    BCount += 1;
    if (BCount % 2 != 0)
    {
        //timer1->Start();
        Rule();
        Draw(pointerVA);
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
    //Draw(ValArray);
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


