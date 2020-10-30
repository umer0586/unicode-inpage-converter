/*
 * MainFrame.h
 * Author : Umer Farooq
 */

#ifndef MAINFRAME_H_
#define MAINFRAME_H_

#include <wx/wx.h>
#include <wx/xrc/xmlres.h>
#include "Converter.h"

/*
 * This class controls all the interactions for UI contained in xrc/MainFrame.xrc
 * it is a controller class for xrc/MainFrame.xrc
*/

class MainFrame: public wxFrame {

public:
	MainFrame(wxWindow* parent);

//Must be protected
protected:
	wxButton* ConvertButton;
	wxTextCtrl* TextControl;
	wxMenuItem* MenuItemITU; //MenuItem Inpage To Unicode
	wxMenuItem* MenuItemUTI; //MenuItem Unicode to Inpage

private:
	const size_t INPAGE_TO_URDU_UNICODE = 1;
	const size_t URDU_UNICODE_TO_INPAGE = 2;
	size_t ConvertionMode;
	void SetConvertionMode(const size_t&);
	size_t GetConvertionMode() const;
	Converter converter;

	const size_t CHARACTER_LIMIT = 10000;



private:
	// Event handlers (these functions should _not_ be virtual)
	void OnConvert(wxCommandEvent& event);
	void OnMenuItemITUSelect(wxCommandEvent& event);
	void OnMenuItemUTISelect(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	// Any class wishing to process wxWidgets events must use this macro
	wxDECLARE_EVENT_TABLE();
};

#endif /* MAINFRAME_H_ */
