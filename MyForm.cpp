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
    return System::Void();
}
