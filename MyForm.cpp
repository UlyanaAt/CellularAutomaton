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

string CellularAutomaton::MyForm::dec2bin(int num)
{
    int bin = 0, k = 1;
    int number = num;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    if (number <= 1)
    {
        return binRuleNumber = "0000000" + to_string(bin);
    }
    else if (3 >= number && number > 1)
    {
        return binRuleNumber = "000000" + to_string(bin);
    }
    else if (7 >= number && number > 3)
    {
        return binRuleNumber = "00000" + to_string(bin);
    }
    else if (15 >= number && number > 7)
    {
        return binRuleNumber = "0000" + to_string(bin);
    }
    else if (31 >= number && number > 15)
    {
        return binRuleNumber = "000" + to_string(bin);
    }
    else if (63 >= number && number > 31)
    {
        return binRuleNumber = "00" + to_string(bin);
    }
    else if (127 >= number && number > 63)
    {
        return binRuleNumber = "0" + to_string(bin);
    }
    else
    {
        return binRuleNumber = to_string(bin);
    }
}

Void CellularAutomaton::MyForm::Rule()
{
    RuleNumber = (int)numRule->Value;
    binRuleNumber = dec2bin(RuleNumber);
    int i = 0;
        for (auto it = mRule.begin(); it != mRule.end(); ++it)
        {
            it->second = binRuleNumber[i] - '0';
            i++;
        }
}

Void CellularAutomaton::MyForm::Draw(bool* pointer, bool* pointerT)
{
    string smth;
    for (int i = 1; i < 29; i++) 
    {
        for (int j = 0; j < 54; j++)
        {
            if (j == 0)
            {
                smth = to_string(*(pointer + 53)) + to_string(*(pointer + j)) + to_string(*(pointer + j + 1));
                *(pointerT + j) = mRule[smth];
            }
            else if (j == 53)
            {
                smth = to_string(*(pointer + j - 1)) + to_string(*(pointer + j)) + to_string(*(pointer));
                *(pointerT + j) = mRule[smth];
            }
            else
            {
                smth = to_string(*(pointer + j - 1)) + to_string(*(pointer + j)) + to_string(*(pointer + j + 1));
                *(pointerT + j) = mRule[smth];
            }
        }

        for (int j = 0; j < 54; j++)
        {
            if (*(pointerT + j) == 1)
            {
                dataGridView1->Rows[i]->Cells[j]->Style->BackColor = BackColor.Black;
            }
        }

        pointerTrans = pointer;
        pointer = pointerT;
        pointerT = pointerTrans;
    }
}

System::Void CellularAutomaton::MyForm::buttonSS_Click(System::Object^ sender, System::EventArgs^ e)
{
    BCount += 1;
    if (BCount % 2 != 0)
    {
        Rule();
        Draw(pointerVA, pointerIntVA);
    }
    else
    {
        for (int i = 0; i < 29; i++)
        {
            for (int j = 0; j < 54; j++)
            {
                dataGridView1->Rows[i]->Cells[j]->Style->BackColor = BackColor.White;
            }
        }

        for (int j = 0; j < 54; j++)
        {
            ValArray[j] = 0;
            interimValArray[j] = 0;
        }   
    }
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


