#include "login.hpp"
#include "register.hpp"

LoginFrame::LoginFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size){
	
	// Icon
	wxBitmap icnbtm("user.png");
	wxIcon icn;
	icn.CopyFromBitmap(icnbtm);
	SetIcon(icn);
	
	
	boxLoginPanel = new wxBoxSizer(wxVERTICAL);
	loginPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1));

	this->SetSizer(boxLoginPanel);
	boxLoginPanel->Add(loginPanel, 1, wxEXPAND, 5);

	boxInput = new wxBoxSizer(wxVERTICAL);
	loginPanel->SetSizer(boxInput);

	t_programName = new wxStaticText(loginPanel, wxID_ANY, "System Login", wxDefaultPosition, wxSize(-1,-1));
	t_username = new wxStaticText(loginPanel, wxID_ANY, "Username/Email", wxDefaultPosition, wxSize(-1,-1));
	t_password = new wxStaticText(loginPanel, wxID_ANY, "Password", wxDefaultPosition, wxSize(-1,-1));
	t_message = new wxStaticText(loginPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1));	
	m_userInput = new wxTextCtrl(loginPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
	m_passInput = new wxTextCtrl(loginPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), wxTE_PASSWORD);

	boxInput->Add(t_programName, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	boxInput->Add(t_username, 0, wxLEFT | wxRIGHT | wxTOP, 5);
	boxInput->Add(m_userInput, 0, wxEXPAND | wxALL, 5);

	boxInput->Add(t_password, 0, wxLEFT | wxRIGHT | wxTOP, 5);
	boxInput->Add(m_passInput, 0, wxEXPAND | wxALL, 5);

	boxInput->Add(t_message, 0, wxRIGHT | wxALL, 5);

	// Buttons
	buttonPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1));
	boxButton = new wxGridSizer(0, 2, 0, 0);
	buttonPanel->SetSizer(boxButton);

	boxLoginPanel->Add(buttonPanel, 0, wxEXPAND, 5);

	b_loginEnter = new wxButton(buttonPanel, wxID_OK, "Login", wxDefaultPosition, wxSize(-1,-1), 0);
	b_registerEnter = new wxButton(buttonPanel, wxID_OK, "Sign In", wxDefaultPosition, wxSize(-1,-1), 0);

	boxButton->Add(b_loginEnter, 0, wxALL | wxEXPAND ,5);
	boxButton->Add(b_registerEnter, 0, wxALL | wxEXPAND , 5);

	// Bind
	b_loginEnter->Bind(wxEVT_BUTTON, &LoginFrame::OnButtonLogin, this);
	b_registerEnter->Bind(wxEVT_BUTTON, &LoginFrame::OnButtonSign, this);
}

// Events
void LoginFrame::OnButtonLogin(wxCommandEvent& event){
	const std::string userInput = m_userInput->GetValue().ToStdString();
	const std::string passInput = m_passInput->GetValue().ToStdString();
	
	std::ifstream f_readFile;	
	f_readFile.open("UsersRegistred.txt");
	bool found = false;

	if(!f_readFile.is_open()){
		wxMessageBox("Banco de dados inexistente!", "Alerta");
	}else if(!(userInput == "" || passInput == "")){
		std::string line;
		while(getline(f_readFile, line)){
			userRegs = passDelimetedString(line);
			if((userRegs.at(0) == userInput || userRegs.at(1) == userInput) && userRegs.at(2) == passInput){
				t_message->SetLabel("Logado");
				found = true;
			}
		}	
		if(found == false){
			t_message->SetLabel("Usuario/Email ou senha incorretos!");	
		}
	}
	f_readFile.close();
}

void LoginFrame::OnButtonSign(wxCommandEvent& event){
	RegisterFrame* regiserFrame = new RegisterFrame("Register User", wxDefaultPosition, wxSize(380,325));

	regiserFrame->SetMinSize(wxSize(365,315));
	regiserFrame->Show();
}
