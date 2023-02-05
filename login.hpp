#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <wx-3.2/wx/frame.h>
#include <wx-3.2/wx/string.h>
#include <wx-3.2/wx/gdiobj.h>
#include <wx-3.2/wx/gdicmn.h>
#include <wx-3.2/wx/sizer.h>
#include <wx-3.2/wx/panel.h>
#include <wx-3.2/wx/stattext.h>
#include <wx-3.2/wx/textctrl.h>
#include <wx-3.2/wx/button.h>
#include <wx-3.2/wx/msgdlg.h>
#include <wx-3.2/wx/icon.h>

class LoginFrame : public wxFrame{
	public:
		LoginFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
		~LoginFrame(){};

	protected:
		wxBoxSizer* boxLoginPanel;
		wxBoxSizer* boxInput;
		wxGridSizer* boxButton;
		wxPanel* loginPanel;
		wxPanel* buttonPanel;
		wxButton* b_loginEnter;
		wxButton* b_registerEnter;
		wxStaticText* t_programName;
		wxStaticText* t_username;
		wxStaticText* t_password;
		wxStaticText* t_message;
		wxTextCtrl* m_userInput;
		wxTextCtrl* m_passInput;
		std::vector<std::string> userRegs;

	private:
		void OnButtonSign(wxCommandEvent& event);
		void OnButtonLogin(wxCommandEvent& event);
};

#endif 
