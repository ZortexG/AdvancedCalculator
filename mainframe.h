#pragma once
#include <wx/wx.h>
#include "tradArth.h"

class mainframe : public wxFrame, public tradArth
{
public:
	mainframe(const wxString& title, double v1 = 0, double v2 = 0, double v3 = 0);


	void maincalc();
	void bindevents();


	void onadd(wxCommandEvent& event);
	void onsub(wxCommandEvent& event);
	void onmul(wxCommandEvent& event);
	void ondiv(wxCommandEvent& event);
	void onequal(wxCommandEvent& event);
	void onclear(wxCommandEvent& event);
	void mouseclickering(wxMouseEvent& evnt);

private:
	
	wxPanel* panel = nullptr;
	wxTextCtrl* inputfield = nullptr;

	wxButton* butt1 = nullptr;
	wxButton* butt2 = nullptr;
	wxButton* butt3 = nullptr;
	wxButton* butt4 = nullptr;
	wxButton* butt5 = nullptr;
	wxButton* butt6 = nullptr;
	wxButton* butt7 = nullptr;
	wxButton* butt8 = nullptr;
	wxButton* butt9 = nullptr;
	wxButton* butt0 = nullptr;
	wxButton* buttdec = nullptr;

	wxButton* buttadd = nullptr;
	wxButton* buttsub = nullptr;
	wxButton* buttmul = nullptr;
	wxButton* buttdiv = nullptr;

	wxButton* buttequal = nullptr;
	wxButton* buttclear = nullptr;
};

