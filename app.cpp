#include <wx/wx.h>
#include "mainframe.h"


class CalcApp : public wxApp
{
public:
    virtual bool OnInit() override
    {
        mainframe* frame = new mainframe("ZorteXCalc", 0.0, 0.0, 0.0);
        frame->Show(true);
		frame->SetClientSize(800, 600);
		frame->Center();
        return true;
    }
};

wxIMPLEMENT_APP(CalcApp);