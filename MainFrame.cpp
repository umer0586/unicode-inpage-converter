/*
 * MainFrame.cpp
 * Author: Umer Farooq
 */

#include "MainFrame.h"
#include <string>
#include <wx/xrc/xmlres.h>


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(XRCID("ConvertButton"), MainFrame::OnConvert)
	EVT_MENU(XRCID("MenuItemITU"), MainFrame::OnMenuItemITUSelect)
	EVT_MENU(XRCID("MenuItemUTI"), MainFrame::OnMenuItemUTISelect)
	EVT_MENU(XRCID("MenuItemAbout") , MainFrame::OnAbout)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(wxWindow* parent)
{

	// Load XRC into memory
	wxXmlResource::Get()->InitAllHandlers();
	// If XRC failed to load than close application by showing error
	if( !wxXmlResource::Get()->LoadFile( wxFileName("./xrc/MainFrame.xrc") )  )
		wxLogFatalError("Unable to Load MainFrame.xrc");

	// Load Frame from XRC and assign newly created Frame to this object
	if( !wxXmlResource::Get()->LoadFrame(this, parent, "MainFrame"))
		wxLogFatalError("Unable to load Application's main Frame");



	// Pointers to MenuItems
	MenuItemITU = GetMenuBar()->FindItem(XRCID("MenuItemITU"));
	MenuItemUTI = GetMenuBar()->FindItem(XRCID("MenuItemUTI"));

	// Input Text control where user will Enter text
	TextControl = XRCCTRL(*this, "TextControl", wxTextCtrl);

	if(!TextControl)
		wxLogFatalError("Unable to Locate TextControl");


	// Statusbar fields can't be create in XRC file so we have to dynamically create fields
	const int STATUSBAR_FIELD_WIDTHS[4] = {50,-1,-1,-1};
	// statubs bar is divided into 4 fields
	SetStatusWidths(4, STATUSBAR_FIELD_WIDTHS);

	TextControl->Bind(wxEVT_COMMAND_TEXT_UPDATED, [this](wxCommandEvent event)->void{

		this->SetStatusText(wxString::Format("Character Count : %d", this->TextControl->GetValue().length() ), 3);

	});

	//Default Convertion mode
	SetConvertionMode(INPAGE_TO_URDU_UNICODE);
	MenuItemITU->Check(true);


	SetStatusText("Mode : ", 0);
	SetStatusText(" InPage to Urdu Unicode ", 1);
	SetStatusText(wxString::Format("Characters Limit : %d",(int)CHARACTER_LIMIT),2);
	SetStatusText("Character Count : 0",3);

	// Set max and min size equal to disable window resize
	SetMinSize(wxSize(700,400));
	SetMaxSize(GetMinSize());
	Maximize(true);
	SetPosition(wxDefaultPosition);



}

void MainFrame::SetConvertionMode(const size_t& ConvertionMode)
{
	this->ConvertionMode = ConvertionMode;
}

size_t MainFrame::GetConvertionMode() const
{
	return ConvertionMode;
}

//When a convert button is clicked
void MainFrame::OnConvert(wxCommandEvent& event)
{

	wxString InputText = TextControl->GetValue();

	if( InputText.IsEmpty() )
	{
		wxMessageDialog(this,"Please Enter Text","No Text Entered",wxICON_WARNING).ShowModal();
		return;
	}

	if( InputText.Length() > CHARACTER_LIMIT )
	{
		wxLogWarning("Characters Limit Exeed");
		return;
	}

	if( GetConvertionMode() == INPAGE_TO_URDU_UNICODE)
	{
		std::wstring InpageText = InputText.ToStdWstring();
		std::wstring UrduUnicodeText = converter.inpageToUnicode(InpageText);

		TextControl->SetValue(UrduUnicodeText);
	}

	if( GetConvertionMode() == URDU_UNICODE_TO_INPAGE )
	{

		std::wstring UrduUnicodeText = InputText.ToStdWstring();
		std::wstring InpageText = converter.unicodeToInpage(UrduUnicodeText);

		TextControl->SetValue(InpageText);

	}


}


// When menu item "Inpage to Urdu Unicode" is selected
void MainFrame::OnMenuItemITUSelect(wxCommandEvent& event)
{

	SetConvertionMode(INPAGE_TO_URDU_UNICODE);
	SetStatusText(" InPage to Urdu Unicode ", 1);
	MenuItemITU->Check(true);


	if(MenuItemUTI->IsChecked())
		MenuItemUTI->Check(false);


}

// When menu Item "Urdu Unicode to Inpage" is selected
void MainFrame::OnMenuItemUTISelect(wxCommandEvent& event)
{

	SetConvertionMode(URDU_UNICODE_TO_INPAGE);
	SetStatusText(" Urdu Unicode to InPage", 1);
	MenuItemUTI->Check(true);

	if(MenuItemITU->IsChecked())
		MenuItemITU->Check(false);


}

void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageDialog(this, "Downloaded from\nhttps://github.com/umer0586/unicode-inpage-converter\nDeveloped By Umer Farooq \numerfarooq2383@gmail.com", "About", wxICON_INFORMATION).ShowModal();
}
