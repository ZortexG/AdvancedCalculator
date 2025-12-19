#include "mainframe.h"
#include <wx/wx.h>
#include <iostream>
#include <string>

using namespace std;


namespace {
	bool waitingForSecond = false; 
	char pendingOp = 0;            
	bool justCalculated = false;   
}


mainframe::mainframe(const wxString& title, double v1, double v2, double v3)
	: wxFrame(nullptr, wxID_ANY, title), tradArth(v1, v2, v3)
{
	maincalc();
}

void mainframe::maincalc()
{
	panel = new wxPanel(this);

	inputfield = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 10), wxSize(280, 40));

	butt1 = new wxButton(panel, wxID_ANY, "1", wxPoint(10, 60), wxSize(50, 50));
	butt2 = new wxButton(panel, wxID_ANY, "2", wxPoint(70, 60), wxSize(50, 50));
	butt3 = new wxButton(panel, wxID_ANY, "3", wxPoint(130, 60), wxSize(50, 50));
	butt4 = new wxButton(panel, wxID_ANY, "4", wxPoint(10, 120), wxSize(50, 50));
	butt5 = new wxButton(panel, wxID_ANY, "5", wxPoint(70, 120), wxSize(50, 50));
	butt6 = new wxButton(panel, wxID_ANY, "6", wxPoint(130, 120), wxSize(50, 50));
	butt7 = new wxButton(panel, wxID_ANY, "7", wxPoint(10, 180), wxSize(50, 50));
	butt8 = new wxButton(panel, wxID_ANY, "8", wxPoint(70, 180), wxSize(50, 50));
	butt9 = new wxButton(panel, wxID_ANY, "9", wxPoint(130, 180), wxSize(50, 50));
	butt0 = new wxButton(panel, wxID_ANY, "0", wxPoint(70, 240), wxSize(50, 50));
	buttdec = new wxButton(panel, wxID_ANY, ".", wxPoint(10, 240), wxSize(50, 50));

	buttadd = new wxButton(panel, wxID_ANY, "+", wxPoint(200, 60), wxSize(50, 50));
	buttsub = new wxButton(panel, wxID_ANY, "-", wxPoint(200, 120), wxSize(50, 50));
	buttmul = new wxButton(panel, wxID_ANY, "*", wxPoint(200, 180), wxSize(50, 50));
	buttdiv = new wxButton(panel, wxID_ANY, "/", wxPoint(200, 240), wxSize(50, 50));
	buttequal = new wxButton(panel, wxID_ANY, "=", wxPoint(130, 240), wxSize(50, 50));

	buttclear = new wxButton(panel, wxID_ANY, "C", wxPoint(260, 60), wxSize(50, 50));

	bindevents();
	CreateStatusBar();
}

void mainframe::bindevents() {
	panel->Bind(wxEVT_LEFT_DOWN, &mainframe::mouseclickering, this); // testing


	buttadd->Bind(wxEVT_BUTTON, &mainframe::onadd, this);
	buttsub->Bind(wxEVT_BUTTON, &mainframe::onsub, this);
	buttmul->Bind(wxEVT_BUTTON, &mainframe::onmul, this);
	buttdiv->Bind(wxEVT_BUTTON, &mainframe::ondiv, this);

	buttequal->Bind(wxEVT_BUTTON, &mainframe::onequal, this);
	buttclear->Bind(wxEVT_BUTTON, &mainframe::onclear, this);

	
	auto onDigit = [this](wxCommandEvent& ev) {
		wxButton* b = dynamic_cast<wxButton*>(ev.GetEventObject());
		if (!b) return;
		wxString label = b->GetLabel();

		
		if (justCalculated) {
			inputfield->SetValue("");
			justCalculated = false;
			pendingOp = 0;
			waitingForSecond = false;
			
		}

		
		if (waitingForSecond) {
			inputfield->SetValue("");
			waitingForSecond = false;
		}

		wxString cur = inputfield->GetValue();
		
		if (cur == "0" && label != ".") cur = "";

		if (label == "." && cur.Contains(".")) return;

		cur += label;
		inputfield->SetValue(cur);
		inputfield->SetFocus();
	};

	butt0->Bind(wxEVT_BUTTON, onDigit);
	butt1->Bind(wxEVT_BUTTON, onDigit);
	butt2->Bind(wxEVT_BUTTON, onDigit);
	butt3->Bind(wxEVT_BUTTON, onDigit);
	butt4->Bind(wxEVT_BUTTON, onDigit);
	butt5->Bind(wxEVT_BUTTON, onDigit);
	butt6->Bind(wxEVT_BUTTON, onDigit);
	butt7->Bind(wxEVT_BUTTON, onDigit);
	butt8->Bind(wxEVT_BUTTON, onDigit);
	butt9->Bind(wxEVT_BUTTON, onDigit);
	buttdec->Bind(wxEVT_BUTTON, onDigit);
}

void mainframe::onadd(wxCommandEvent& event)
{

	wxString s = inputfield->GetValue();
	double current = wxAtof(s);
	if (pendingOp == 0) {
		
		this->val2 = current;
	} else {
	
		this->val1 = current;
		this->doOperation(pendingOp);
	}
	pendingOp = '+';
	waitingForSecond = true;
	justCalculated = false;
	inputfield->SetValue(wxString::Format("%g", this->val2));
	inputfield->SetFocus();
}

void mainframe::onsub(wxCommandEvent& event)
{
	wxString s = inputfield->GetValue();
	double current = wxAtof(s);
	if (pendingOp == 0) {
		this->val2 = current;
	} else {
		this->val1 = current;
		this->doOperation(pendingOp);
	}
	pendingOp = '-';
	waitingForSecond = true;
	justCalculated = false;
	inputfield->SetValue(wxString::Format("%g", this->val2));
	inputfield->SetFocus();
}

void mainframe::onmul(wxCommandEvent& event)
{
	wxString s = inputfield->GetValue();
	double current = wxAtof(s);
	if (pendingOp == 0) {
		this->val2 = current;
	} else {
		this->val1 = current;
		this->doOperation(pendingOp);
	}
	pendingOp = '*';
	waitingForSecond = true;
	justCalculated = false;
	inputfield->SetValue(wxString::Format("%g", this->val2));
	inputfield->SetFocus();
}

void mainframe::ondiv(wxCommandEvent& event)
{
	wxString s = inputfield->GetValue();
	double current = wxAtof(s);
	if (pendingOp == 0) {
		this->val2 = current;
	} else {
		this->val1 = current;
		this->doOperation(pendingOp);
	}
	pendingOp = '/';
	waitingForSecond = true;
	justCalculated = false;
	inputfield->SetValue(wxString::Format("%g", this->val2));
	inputfield->SetFocus();
}

void mainframe::onequal(wxCommandEvent& event)
{
	
	if (pendingOp != 0) {
		wxString s = inputfield->GetValue();
		double current = wxAtof(s);
		this->val1 = current;
		this->doOperation(pendingOp);
		
		inputfield->SetValue(wxString::Format("%g", this->val2));
		pendingOp = 0;
		waitingForSecond = false;
		justCalculated = true;
		inputfield->SetFocus();
	}
}

void mainframe::onclear(wxCommandEvent& event)
{
	inputfield->SetValue("");
	this->clear();
	pendingOp = 0;
	waitingForSecond = false;
	justCalculated = false;
	inputfield->SetFocus();
}

void mainframe::mouseclickering(wxMouseEvent& evnt)
{
	wxPoint mousepos = evnt.GetPosition();
	wxString msg = wxString::Format("Mouse Event! (x=%d y=%d)", mousepos.x, mousepos.y);
	wxLogStatus(msg);
}
