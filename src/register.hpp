#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <wx-3.2/wx/frame.h>
#include <wx-3.2/wx/string.h>
#include <wx-3.2/wx/sizer.h>
#include <wx-3.2/wx/gdicmn.h>
#include <wx-3.2/wx/panel.h>
#include <wx-3.2/wx/textctrl.h>
#include <wx-3.2/wx/button.h>
#include <wx-3.2/wx/stattext.h>
#include <wx-3.2/wx/msgdlg.h>
#include "file.hpp"

class RegisterFrame : public wxFrame{
	public:
		RegisterFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
		~RegisterFrame(){}

	protected:
		wxBoxSizer* boxRegisterPanel;
		wxBoxSizer* boxInputRegs;
		wxGridSizer* boxButtons;
		wxPanel* registerPanel; 
		wxPanel* buttonsPanel;
		wxStaticText* t_username;
		wxStaticText* t_password;
		wxStaticText* t_email;
		wxStaticText* t_nameFrame;
		wxStaticText* t_message;
		wxTextCtrl* m_userInput;
		wxTextCtrl* m_passInput;
		wxTextCtrl* m_emailInput;
		wxButton* b_registerUser;
		wxButton* b_cancelRegister;
		std::vector<std::string> userRegs;

	private:
		void OnButtonRegister(wxCommandEvent& event);
		void OnButtonCancel(wxCommandEvent& event);
		bool verifyEmailInput(const std::string emailInput);
};

#endif // !REGISTER_HPP
