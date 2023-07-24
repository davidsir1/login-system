#include <wx-3.2/wx/app.h>
#include "login.hpp"

class SystemLogin : public wxApp{
	public:
		virtual bool OnInit();
};

bool SystemLogin::OnInit(){
	LoginFrame* mainFrame = new LoginFrame("System Login", wxDefaultPosition, wxSize(300,300));
	mainFrame->SetMinSize(wxSize(200,250));	
	mainFrame->Show(true);
	SetTopWindow(mainFrame);
	return true;
}

wxIMPLEMENT_APP(SystemLogin);
