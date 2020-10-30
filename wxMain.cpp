

#include <wx/wx.h>
#include <wx/xrc/xmlres.h>

#include "MainFrame.h"

class wxMain: public wxApp
{
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(wxMain)

bool wxMain::OnInit()
{

	//As this is the main frame therefore it has no parent window
	MainFrame *mainFrame = new MainFrame((wxWindow* )NULL);
	mainFrame->Show(TRUE);
	//Frame set as Top window will delete its child window by itself, no need to call delete explicitly here
	SetTopWindow(mainFrame);


   return TRUE;

}
