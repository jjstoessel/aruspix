/////////////////////////////////////////////////////////////////////////////
// Name:        optionsdlg.cpp
// Author:      Laurent Pugin
// Created:     2004
// Copyright (c) Laurent Pugin. All rights reserved.   
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && ! defined(__APPLE__)
    #pragma implementation "axoptionsdlg.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "wx/valgen.h"
#include "wx/fontdlg.h"
#include "wx/fontutil.h"

//#include "wx/datetime.h"

#include "axoptionsdlg.h"
#include "aximage.h"
#include "axapp.h"
#include "wg/wgfile.h"
#include "wg/iowwg.h"

#ifdef AX_SUPERIMPOSITION
	#include "superimposition/sup.h"
#endif

#ifdef AX_RECOGNITION
	#include "recognition/rec.h"
	#include "im/imoperator.h"
#endif

//----------------------------------------------------------------------------
// OptionsDlg
//----------------------------------------------------------------------------

// WDR: event table for OptionsDlg

BEGIN_EVENT_TABLE(OptionsDlg,wxDialog)
    EVT_BUTTON( wxID_OK, OptionsDlg::OnOk )
    EVT_BUTTON( wxID_CANCEL, OptionsDlg::OnCancel )
    EVT_COMBOBOX( ID_CB_LANGUAGE_OPS, OptionsDlg::OnChangeLanguage )
    EVT_BUTTON( ID_BROWSE_WORKING_DIR, OptionsDlg::OnBrowseWorkDir )
	EVT_BUTTON( ID_BROWSE_DOCUMENTS_DIR, OptionsDlg::OnBrowseDocDir )
    EVT_BUTTON( ID_CHOOSE_FONT, OptionsDlg::OnChooseFont )
    EVT_SPIN( ID_SC_WG_OFFSET, OptionsDlg::OnSpinCtrl )
	EVT_TEXT( ID_SC_WG_OFFSET, OptionsDlg::OnSpinCtrlText )
    EVT_SPIN( ID_SC_WG_SIZE, OptionsDlg::OnSpinCtrl )
	EVT_TEXT( ID_SC_WG_SIZE, OptionsDlg::OnSpinCtrlText )
#ifdef AX_SUPERIMPOSITION
#endif	
#ifdef AX_RECOGNITION
	EVT_BUTTON( ID4_PRE_DEFAULT, OptionsDlg::OnPreDefault )
    EVT_BUTTON( ID4_REC_BT_MUS_MODELS, OptionsDlg::OnBrowse4 )
    EVT_BUTTON( ID4_REC_BT_TYP_MODELS, OptionsDlg::OnBrowse4 )
#endif
END_EVENT_TABLE()

OptionsDlg::OptionsDlg( wxWindow *parent, wxWindowID id, const wxString &title,
    const wxPoint &position, const wxSize& size, long style ) :
    wxDialog( parent, id, title, position, size, style )
{
    m_changeLanguage = false;
    m_changeFont = false;
	
	
	this->SetAutoLayout( true );

    this->SetExtraStyle(wxWS_EX_VALIDATE_RECURSIVELY);
		
    //OptionsDlgFunc( this, TRUE ); do it manually to allow conditionnal adds
    wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );
    wxNotebook *notebook = new wxNotebook( this, ID_NOTEBOOK_OP, wxDefaultPosition, wxSize(50,50) );//, 0 );
	m_min_size.Set( 0, 0 );

	// Standard tabs
	this->OptionsDlgStandard( notebook );	
	
	// Superimposition tabs
	this->OptionsDlgSuperimposition( notebook );	
	
	// Recognition tabs
	this->OptionsDlgRecognition( notebook );	

	// Notebook and Buttons
	// Layout 'a la main' .... pffff
	notebook->SetMinSize( notebook->CalcSizeFromPage( m_min_size ) );
    item0->Add( notebook, 0, wxALIGN_CENTER|wxALL, 5 );
    wxBoxSizer *item5 = new wxBoxSizer( wxHORIZONTAL );
    wxButton *item6 = new wxButton( this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    item5->Add( item6, 0, wxALIGN_CENTER|wxALL, 5 );
    wxButton *item7 = new wxButton( this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    item5->Add( item7, 0, wxALIGN_CENTER|wxALL, 5 );
    item0->Add( item5, 0, wxALIGN_CENTER|wxALL, 0 );


	item0->Layout();
	this->SetSizer( item0 );
	item0->Fit( this );
	item0->SetSizeHints( this );

    m_wgWinPtr = new OptionsWgWindow( GetWgPanel(), -1, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL|wxNO_BORDER );
	m_wgWinPtr->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU)  );
    m_wgWinPtr->Resize( );
}


void OptionsDlg::OptionsDlgStandard( wxNotebook *notebook )
{
    wxPanel *item1 = new wxPanel( notebook, -1 );
    wxSize size = System1DlgFunc( item1, false )->GetMinSize();
	m_min_size.Set( max( m_min_size.GetWidth(), size.GetWidth() ), max( m_min_size.GetHeight(), size.GetHeight() ) );
    notebook->AddPage( item1, _("General") );

    // Various
    this->GetCbLanguageOps()->SetValidator(
        wxGenericValidator(&wxGetApp().m_language));
    this->GetDocDir()->SetValidator(
        wxTextValidator(wxFILTER_NONE,&wxGetApp().m_docDir));
    this->GetWorkingDir()->SetValidator(
        wxTextValidator(wxFILTER_NONE,&wxGetApp().m_workingDir));
		
	// Music Font
    this->GetFontName()->SetLabel(wxGetApp().m_musicFontName);
	m_ignoreSpinEvent = true;
    this->GetScWgOffset()->SetValidator(
        wxGenericValidator(&wxGetApp().m_fontPosCorrection));
    this->GetScWgSize()->SetValidator(
        wxGenericValidator(&wxGetApp().m_fontSizeCorrection));
	m_previousFontPosCorrection = wxGetApp().m_fontPosCorrection; // keep if canceled
	m_previousFontSizeCorrection = wxGetApp().m_fontSizeCorrection;
	m_ignoreSpinEvent = false;
	
	// Images
    this->GetCbGrayOpi()->SetValidator(
        wxGenericValidator(&AxImage::s_gray));
    this->GetCbReduceOpi()->SetValidator(
        wxGenericValidator(&AxImage::s_reduceBigImages));
    m_imageSizeToReduceStr = wxString::Format("%d",AxImage::s_imageSizeToReduce);
    this->GetTcMaxsizeOpi()->SetValidator(
        wxTextValidator(wxFILTER_NUMERIC,&m_imageSizeToReduceStr));
	this->GetCbNegativeOpi()->SetValidator(
        wxGenericValidator(&AxImage::s_checkIfNegative));
}

void OptionsDlg::OptionsDlgSuperimposition( wxNotebook *notebook )
{
#ifdef AX_SUPERIMPOSITION	
    wxPanel *item1 = new wxPanel( notebook, -1 );
    wxSize size = Sup1DlgFunc( item1, false )->GetMinSize();
	m_min_size.Set( max( m_min_size.GetWidth(), size.GetWidth() ), max( m_min_size.GetHeight(), size.GetHeight() ) );
    notebook->AddPage( item1, _("Superimposition") );

    m_sizeStr = wxString::Format("%d",SupEnv::s_segmentSize);
    this->GetTcSizeOps1()->SetValidator(
        wxTextValidator(wxFILTER_NUMERIC,&m_sizeStr));
    switch (SupEnv::s_interpolation)
    {
    case 0: m_interpolation_index = 0; break;
    case 2: m_interpolation_index = 1; break;
    case 3: m_interpolation_index = 2; break;
    default: m_interpolation_index = 0;
    }
    this->GetCcInterpOps1()->SetValidator(
        wxGenericValidator(&m_interpolation_index));

    this->GetScSplitxOps1()->SetValidator(
        wxGenericValidator(&SupEnv::s_split_x));
    this->GetScSplityOps1()->SetValidator(
        wxGenericValidator(&SupEnv::s_split_y));
    this->GetScCorrxOps1()->SetValidator(
        wxGenericValidator(&SupEnv::s_corr_x));
    this->GetScCorryOps1()->SetValidator(
        wxGenericValidator(&SupEnv::s_corr_y));
    this->GetChFilter1Ops1()->SetValidator(
        wxGenericValidator(&SupEnv::s_filter1));
    this->GetChFilter2Ops1()->SetValidator(
        wxGenericValidator(&SupEnv::s_filter2));
#endif
}

void OptionsDlg::OptionsDlgRecognition( wxNotebook *notebook )
{
#ifdef AX_RECOGNITION	
    wxPanel *item1 = new wxPanel( notebook, -1 );
    wxSize size = Rec1DlgFunc( item1, false )->GetMinSize();
	m_min_size.Set( max( m_min_size.GetWidth(), size.GetWidth() ), max( m_min_size.GetHeight(), size.GetHeight() ) );
    notebook->AddPage( item1, _("Recognition") );
	
	// pre-processing
    this->GetChTextOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_find_text));
    this->GetChBordersPosOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_find_borders));
    this->GetChTextInitOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_find_ornate_letters));
    this->GetChStavesSegOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_find_text_in_staves));
	// margins
	this->GetScMarginTopOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_pre_margin_top));
	this->GetScMarginBottomOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_pre_margin_bottom));
	this->GetScMarginLeftOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_pre_margin_left));
	this->GetScMarginRightOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_pre_margin_right));
	// binarization
	this->GetRbBinResOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_pre_threshold_method_resize));
	this->GetRbBinOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_pre_threshold_method));
	this->GetScBinSizeOps3()->SetValidator(
        wxGenericValidator(&RecEnv::s_pre_threshold_region_size));

    // typographic model
    this->GetTypModel()->SetValidator(
        wxTextValidator(wxFILTER_NONE,&RecEnv::s_rec_typ_model));

	// music model
    this->GetMusModel()->SetValidator(
        wxTextValidator(wxFILTER_NONE,&RecEnv::s_rec_mus_model));

    m_lmScalingStr = wxString::Format("%.02f",RecEnv::s_rec_lm_scaling);
    this->GetLMScaling()->SetValidator(
        wxTextValidator(wxFILTER_NUMERIC,&m_lmScalingStr));
    this->GetDelayed()->SetValidator(
        wxGenericValidator(&RecEnv::s_rec_delayed));
    this->GetLMOrder()->SetValidator(
        wxGenericValidator(&RecEnv::s_rec_lm_order));
#endif
}


void OptionsDlg::UpdateFontCorrections( int eventID )
{
	if ( !m_wgWinPtr )
		return ;

	if ( !this->IsShown() || m_ignoreSpinEvent )
		return;

	wxGetApp().m_fontPosCorrection = GetScWgOffset()->GetValue();
	wxGetApp().m_fontSizeCorrection = GetScWgSize()->GetValue();
	m_wgWinPtr->UpdatePageValues();
	if ( eventID == ID_SC_WG_SIZE)
		m_wgWinPtr->UpdateZoomValues();
    m_wgWinPtr->Resize( );
}

// WDR: handler implementations for OptionsDlg

#ifdef AX_RECOGNITION
void OptionsDlg::OnBrowse4( wxCommandEvent &event )
{
    if ( event.GetId() == ID4_REC_BT_TYP_MODELS )
	{
		wxString filename = wxFileSelector( _("Select a typographic model"), wxGetApp().m_lastDirTypModel_in, this->GetTypModel()->GetValue(), NULL, "Typographic models|*.axtyp", wxOPEN);
		if ( filename.IsEmpty() )
			return;

		wxGetApp().m_lastDirTypModel_in = wxPathOnly( filename );
        this->GetTypModel()->SetValue( filename );
	}
    if ( event.GetId() == ID4_REC_BT_MUS_MODELS )
	{
		wxString filename = wxFileSelector( _("Select a music model"), wxGetApp().m_lastDirMusModel_in, this->GetMusModel()->GetValue(), NULL, "Music models|*.axmus", wxOPEN);
		if ( filename.IsEmpty() )
			return;

		wxGetApp().m_lastDirMusModel_in = wxPathOnly( filename );
        this->GetMusModel()->SetValue( filename );
	}
}
#endif


void OptionsDlg::OnSpinCtrlText( wxCommandEvent &event )
{
	UpdateFontCorrections( event.GetId() );
}

void OptionsDlg::OnSpinCtrl( wxSpinEvent &event )
{
	UpdateFontCorrections( event.GetId() );
}


#ifdef __WXMAC__
// -------------------------------------------------------------
#include "wx/fontenum.h"

class MyFontEnumerator : public wxFontEnumerator
{
public:
    bool GotAny() const
        { return !m_facenames.IsEmpty(); }

    const wxArrayString& GetFacenames() const
        { return m_facenames; }

protected:
    virtual bool OnFacename(const wxString& facename)
    {
        m_facenames.Add(facename);
        return true;
    }

    private:
        wxArrayString m_facenames;
} fontEnumerator;

#endif


void OptionsDlg::OnChooseFont( wxCommandEvent &event )
{

#ifdef __WXMAC__ && !wxCHECK_VERSION(2,8,3)
    MyFontEnumerator fontEnumerator;
	wxString facename;
    fontEnumerator.EnumerateFacenames( wxFONTENCODING_CP1252 );
	//fontEnumerator.EnumerateFacenames( wxFONTENCODING_SYSTEM );
    if ( fontEnumerator.GotAny() )
    {
        int nFacenames = fontEnumerator.GetFacenames().GetCount();
        wxString *facenames = new wxString[nFacenames];
		int n;
		for ( n = 0; n < nFacenames; n++ )
			facenames[n] = fontEnumerator.GetFacenames().Item(n);
            
		n = wxGetSingleChoiceIndex( _("Choose a facename"), wxGetApp().GetAppName(),
                                       nFacenames, facenames, this);

		if ( n != -1 )
            facename = facenames[n];
        delete [] facenames;
        
        if ( facename.empty() )
			return;
    }
	else
    {
        wxLogWarning(_("No font found"));
		return;
    }
	//wxFont::SetDefaultEncoding( wxFONTENCODING_CP1252 );
	wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false, facename, wxFONTENCODING_CP1252);
	//wxFont font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
	//	wxFONTWEIGHT_NORMAL, false, "Leipzig 4.4", wxFONTENCODING_CP1252);
#else
    wxFont font = wxGetFontFromUser( this );
    if ( !font.Ok() )
        return;
#endif
    m_font = font;
    m_changeFont = true;
    this->GetFontName()->SetLabel( m_font.GetFaceName() );
}

void OptionsDlg::OnPreDefault( wxCommandEvent &event )
{
    this->GetChTextOps3()->SetValue( true );
    this->GetChBordersPosOps3()->SetValue( true );
    this->GetChTextInitOps3()->SetValue( true );
    this->GetChStavesSegOps3()->SetValue( true );
	// margins
	this->GetScMarginTopOps3()->SetValue( 150 );
	this->GetScMarginBottomOps3()->SetValue( 120 );
	this->GetScMarginLeftOps3()->SetValue( 30 );
	this->GetScMarginRightOps3()->SetValue( 20 );
	// binarization
	this->GetRbBinResOps3()->SetSelection( IM_BINARIZATION_OTSU );
	this->GetRbBinOps3()->SetSelection( PRE_BINARIZATION_BRINK );
	this->GetScBinSizeOps3()->SetValue( 15 );
}

void OptionsDlg::OnBrowseDocDir( wxCommandEvent &event )
{
    wxString input = wxDirSelector( _("Documents folder"), wxGetApp().m_docDir );
    if ( input.empty() )
        return;

    this->GetDocDir()->SetValue(input);
}

void OptionsDlg::OnBrowseWorkDir( wxCommandEvent &event )
{
    wxString input = wxDirSelector( _("Working folder"), wxGetApp().m_workingDir );
    if ( input.empty() )
        return;

    this->GetWorkingDir()->SetValue(input);
}

void OptionsDlg::OnChangeLanguage( wxCommandEvent &event )
{
    m_changeLanguage = true;
}

void OptionsDlg::OnOk(wxCommandEvent &event)
{
    if ( Validate() && TransferDataFromWindow() )
    {   
        AxImage::s_imageSizeToReduce = atoi(m_imageSizeToReduceStr);
        if ( m_changeLanguage )
            wxMessageBox(_("You must restart the program to change the language"), wxGetApp().GetAppName() ,
                             wxICON_INFORMATION );

        if ( m_changeFont )
        {
            const wxNativeFontInfo *info = m_font.GetNativeFontInfo();
            wxString infos = info->ToString();
            wxGetApp().m_musicFontDesc = infos;
            wxGetApp().m_musicFontName = m_font.GetFaceName();
        }
		
	#ifdef AX_SUPERIMPOSITION
		switch (m_interpolation_index)
        {
        case 0: SupEnv::s_interpolation = 0; break;
        case 1: SupEnv::s_interpolation = 2; break;
        case 2: SupEnv::s_interpolation = 3; break;
        default: SupEnv::s_interpolation = 0;
        }
        SupEnv::s_segmentSize= atoi(m_sizeStr);
	#endif
		
	#ifdef AX_RECOGNITION
		//RecEnv::s_rec_phone_pen = atof(m_phonePenStr);
        //RecEnv::s_rec_end_prune = atof(m_endPruneStr);
        //RecEnv::s_rec_word_pen = atof(m_wordPenStr);
        RecEnv::s_rec_lm_scaling = atof(m_lmScalingStr);
	#endif
	
        event.Skip();
    }
}

void OptionsDlg::OnCancel(wxCommandEvent &event)
{
	// reset previous values;
	wxGetApp().m_fontPosCorrection = m_previousFontPosCorrection;
	wxGetApp().m_fontSizeCorrection = m_previousFontSizeCorrection;
    event.Skip();
}



//----------------------------------------------------------------------------
// OptionsWgWindow
//----------------------------------------------------------------------------

IMPLEMENT_CLASS(OptionsWgWindow, WgWindow)

// WDR: event table for OptionsWgWindow

BEGIN_EVENT_TABLE(OptionsWgWindow,WgWindow)
    EVT_MOUSE_EVENTS( OptionsWgWindow::OnMouse )
END_EVENT_TABLE()

OptionsWgWindow::OptionsWgWindow( wxWindow *parent, wxWindowID id,
    const wxPoint &position, const wxSize& size, long style, bool center ) :
    WgWindow( parent, id, position, size, style, center )
{
    m_filePtr = NULL;
    m_filePtr = new WgFile();
    m_filePtr->m_fheader.param.pageFormatHor = 20;
    m_filePtr->m_fheader.param.pageFormatVer = 20;
    m_filePtr->m_fheader.param.MargeGAUCHEIMPAIRE = 0;
    m_filePtr->m_fheader.param.MargeGAUCHEPAIRE = 0;

    WgPage *page = new WgPage();
    page->defin = 20;
    page->lrg_lign = 20;
    
    WgStaff *staff = new WgStaff();
    staff->ecart = 4;
    
    WgSymbole *clef = new WgSymbole();
    clef->flag = CLE;
    clef->code = UT3;
    clef->xrel = 95;
    
    staff->m_elements.Add( clef );
    page->m_staves.Add( staff );
    m_filePtr->m_pages.Add( page );
    m_filePtr->CheckIntegrity();

    /*m_filePtr->m_fheader.filesize = 0;
    WwgOutput *wwgoutput = new WwgOutput( m_filePtr, "D:/test.wwg" );
    wwgoutput->ExportFile();
    delete wwgoutput;*/

	this->SetFile( m_filePtr );
	//this->Resize();
}

OptionsWgWindow::OptionsWgWindow()
{
}

OptionsWgWindow::~OptionsWgWindow()
{
    if (m_filePtr)
        delete m_filePtr;
}

// WDR: handler implementations for OptionsWgWindow

void OptionsWgWindow::OnMouse(wxMouseEvent &event)
{
}