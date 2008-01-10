/////////////////////////////////////////////////////////////////////////////
// Name:        axgotodlg.h
// Author:      Laurent Pugin
// Created:     2004
// Copyright (c) Laurent Pugin. All rights reserved.   
/////////////////////////////////////////////////////////////////////////////

#ifndef __axgotodlg_H__
#define __axgotodlg_H__

#if defined(__GNUG__) && ! defined(__APPLE__)
    #pragma interface "axgotodlg.h"
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "axapp_wdr.h"

// WDR: class declarations

//----------------------------------------------------------------------------
// AxGotoDlg
//----------------------------------------------------------------------------

class AxGotoDlg: public wxDialog
{
public:
    // constructors and destructors
    AxGotoDlg( wxWindow *parent, wxWindowID id, const wxString &title,
        int nbOfPages, int currentPage,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE );
    
    // WDR: method declarations for AxGotoDlg
	int GetPage() { return m_pageNo -1; }
    wxSpinCtrl* GetScNoGoto()  { return (wxSpinCtrl*) FindWindow( ID_SC_NO_GOTO ); }
    wxRadioButton* GetRbNoGoto()  { return (wxRadioButton*) FindWindow( ID_RB_NO_GOTO ); }
    wxRadioButton* GetRbLastGoto()  { return (wxRadioButton*) FindWindow( ID_RB_LAST_GOTO ); }
    wxRadioButton* GetRbFirstGoto()  { return (wxRadioButton*) FindWindow( ID_RB_FIRST_GOTO ); }
    
private:
    // WDR: member variable declarations for AxGotoDlg
    int m_nbOfPages;
    int m_pageNo;
    
private:
    // WDR: handler declarations for AxGotoDlg
	void OnSpinCtrl( wxSpinEvent &event );
	void OnSpinCtrlText( wxCommandEvent &event );
    void OnOk( wxCommandEvent &event );
    void OnCancel( wxCommandEvent &event );

private:
    DECLARE_EVENT_TABLE()
};

#endif
