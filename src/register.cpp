#include <regex>
#include "register.hpp"

RegisterFrame::RegisterFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(nullptr, wxID_ANY, title, pos, size){
	
	//Icon
	wxBitmap icnbtm("user.png");
	wxIcon icn;
	icn.CopyFromBitmap(icnbtm);
	SetIcon(icn);

	boxRegisterPanel = new wxBoxSizer(wxVERTICAL);
	registerPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1));
	
	this->SetSizer(boxRegisterPanel);
	boxRegisterPanel->Add(registerPanel, 1, wxEXPAND, 5);

	boxInputRegs = new wxBoxSizer(wxVERTICAL);
	registerPanel->SetSizer(boxInputRegs);

	t_nameFrame = new wxStaticText(registerPanel, wxID_ANY, "Register User", wxDefaultPosition, wxSize(-1,-1));
	t_username = new wxStaticText(registerPanel, wxID_ANY, "Username", wxDefaultPosition, wxSize(-1,-1));
	t_password = new wxStaticText(registerPanel, wxID_ANY, "Password", wxDefaultPosition, wxSize(-1,-1));
	t_email = new wxStaticText(registerPanel, wxID_ANY, "Email", wxDefaultPosition, wxSize(-1,-1));
	t_message = new wxStaticText(registerPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1));
	m_userInput = new wxTextCtrl(registerPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);
	m_passInput = new wxTextCtrl(registerPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), wxTE_PASSWORD);
	m_emailInput = new wxTextCtrl(registerPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1,-1), 0);

	boxInputRegs->Add(t_nameFrame, 0, wxALIGN_CENTER, 5);

	boxInputRegs->Add(t_username, 0, wxRIGHT | wxLEFT | wxTOP, 5);
	boxInputRegs->Add(m_userInput, 0, wxALL | wxEXPAND, 5);

	boxInputRegs->Add(t_email, 0, wxRIGHT | wxLEFT | wxTOP, 5);
	boxInputRegs->Add(m_emailInput, 0, wxALL | wxEXPAND, 5);

	boxInputRegs->Add(t_password, 0, wxRIGHT | wxLEFT | wxTOP, 5);
	boxInputRegs->Add(m_passInput, 0, wxALL | wxEXPAND, 5);

	boxInputRegs->Add(t_message, 0, wxALL, 5);

	// Buttons
	buttonsPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1));		
	boxButtons = new wxGridSizer(0,2,0,0);
	buttonsPanel->SetSizer(boxButtons);

	boxRegisterPanel->Add(buttonsPanel, 0, wxEXPAND, 5);

	b_registerUser = new wxButton(buttonsPanel, wxID_OK, "Register User", wxDefaultPosition, wxSize(-1,-1), 0);
	b_cancelRegister = new wxButton(buttonsPanel, wxID_CANCEL, "Cancel", wxDefaultPosition, wxSize(-1,-1), 0);

	boxButtons->Add(b_cancelRegister, 0, wxALL | wxEXPAND, 5);
	boxButtons->Add(b_registerUser, 0, wxALL | wxEXPAND, 5);

	//Bind
	b_registerUser->Bind(wxEVT_BUTTON, &RegisterFrame::OnButtonRegister, this);
	b_cancelRegister->Bind(wxEVT_BUTTON, &RegisterFrame::OnButtonCancel, this);
}

void RegisterFrame::OnButtonRegister(wxCommandEvent& event){
	const std::string userInput = m_userInput->GetValue().ToStdString();
	const std::string emailInput = m_emailInput->GetValue().ToStdString();
	const std::string passInput = m_passInput->GetValue().ToStdString();

	std::ifstream f_readFile;
	std::ofstream f_writeFile;
	f_readFile.open("UsersRegistred.txt");
	f_writeFile.open("UsersRegistred.txt", std::fstream::app);

	if(!(f_readFile.is_open() && f_writeFile.is_open())){
		wxMessageBox("Banco de dados inexistente!", "Alerta");
	}else if(!verifyEmailInput(emailInput)){
		m_emailInput->Clear();
		t_message->SetLabel("Sintaxe de email invalido!");
	}else{
		std::string line;
		bool found = false;
		while(getline(f_readFile, line)){
			userRegs = passDelimetedString(line);
			if(userRegs.at(0) == userInput || userRegs.at(1) == emailInput){
				t_message->SetLabel("Ja existe um cadastro com esse usuario ou email!");
				found = true;	
			}
		}
		if(!found){
			f_writeFile << userInput << ',' << emailInput << ',' << passInput << '\n';

			m_userInput->Clear(); m_passInput->Clear(); m_emailInput->Clear();
			t_message->SetLabel(wxEmptyString);

			wxMessageBox("Usuario registrado!", "Success");	
		}
	}
	f_writeFile.close();
	f_readFile.close();
}

void RegisterFrame::OnButtonCancel(wxCommandEvent& event){
	Close();
}

bool RegisterFrame::verifyEmailInput(const std::string emailInput){
	const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	
	return std::regex_match(emailInput, pattern);
}
