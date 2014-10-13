//------------------------------------------------------------------------------
// Source code generated by wxDesigner from file: rec.wdr
// Do not modify this file, all changes will be lost!
//------------------------------------------------------------------------------

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma implementation "rec_wdr.h"
#endif

// For compilers that support precompilation
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// Include private header
#include "rec_wdr.h"

#include <wx/intl.h>

// Euro sign hack of the year
#if wxUSE_UNICODE
    #define __WDR_EURO__ wxT("\u20ac")
#else
    #if defined(__WXMAC__)
        #define __WDR_EURO__ wxT("\xdb")
    #elif defined(__WXMSW__)
        #define __WDR_EURO__ wxT("\x80")
    #else
        #define __WDR_EURO__ wxT("\xa4")
    #endif
#endif

// Custom source
#include "recognition/rec.h"
#include "recognition/recmus.h"
#include "recognition/recim.h"
#include "recognition/recbookctrl.h"
#include "mus/mustoolpanel.h"

// Implement window functions

wxSizer *WindowFunc4( wxWindow *parent, bool call_fit, bool set_sizer )
{
    wxFlexGridSizer *item0 = new wxFlexGridSizer( 1, 0, 0 );
    item0->AddGrowableCol( 0 );
    item0->AddGrowableRow( 0 );

    RecSplitterWindow *item1 = new RecSplitterWindow( parent, ID4_SPLITTER1, wxDefaultPosition, wxDefaultSize, 0 );
    item0->Add( item1, 0, wxGROW|wxALL, 0 );

    if (set_sizer)
    {
        parent->SetSizer( item0 );
        if (call_fit)
            item0->SetSizeHints( parent );
    }
    
    return item0;
}

wxSizer *MusOutputFunc4( wxWindow *parent, bool call_fit, bool set_sizer )
{
    wxFlexGridSizer *item0 = new wxFlexGridSizer( 1, 0, 0 );
    item0->AddGrowableCol( 0 );
    item0->AddGrowableRow( 1 );

    MusToolPanel *item1 = new MusToolPanel( parent, ID4_TOOLPANEL, wxDefaultPosition, wxSize(10,10), 0 );
    item0->Add( item1, 0, wxGROW, 0 );

    RecMusController *item2 = new RecMusController( parent, ID4_MUSPANEL, wxDefaultPosition, wxSize(200,160), wxSUNKEN_BORDER );
    item0->Add( item2, 0, wxGROW|wxALL, 0 );

    if (set_sizer)
    {
        parent->SetSizer( item0 );
        if (call_fit)
            item0->SetSizeHints( parent );
    }
    
    return item0;
}

wxSizer *RecBookFunc4( wxWindow *parent, bool call_fit, bool set_sizer )
{
    wxFlexGridSizer *item0 = new wxFlexGridSizer( 1, 0, 0 );
    item0->AddGrowableCol( 0 );
    item0->AddGrowableRow( 0 );

    RecBookCtrl *item1 = new RecBookCtrl( parent, ID4_TREEBOOK, wxDefaultPosition, wxSize(120,160), wxTR_HAS_BUTTONS|wxTR_LINES_AT_ROOT|wxSUNKEN_BORDER );
    item0->Add( item1, 0, wxGROW|wxALL, 5 );

    wxStaticLine *item2 = new wxStaticLine( parent, ID4_LINE2, wxDefaultPosition, wxSize(20,-1), wxLI_HORIZONTAL );
    item0->Add( item2, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxStaticBitmap *item3 = new wxStaticBitmap( parent, ID4_PREVIEW, BitmapsFunc4( 0 ), wxDefaultPosition, wxSize(200,200) );
    item0->Add( item3, 0, wxALIGN_CENTER|wxALL, 5 );

    wxCheckBox *item4 = new wxCheckBox( parent, ID4_CB_PREVIEW, _("Preview"), wxDefaultPosition, wxDefaultSize, 0 );
    item0->Add( item4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    if (set_sizer)
    {
        parent->SetSizer( item0 );
        if (call_fit)
            item0->SetSizeHints( parent );
    }
    
    return item0;
}

wxSizer *RecBookDataFunc4( wxWindow *parent, bool call_fit, bool set_sizer )
{
    wxFlexGridSizer *item0 = new wxFlexGridSizer( 1, 0, 0 );
    item0->AddGrowableCol( 0 );
    item0->AddGrowableCol( 1 );
    item0->AddGrowableRow( 0 );

    wxStaticBox *item2 = new wxStaticBox( parent, -1, _("Book information") );
    wxStaticBoxSizer *item1 = new wxStaticBoxSizer( item2, wxVERTICAL );

    wxFlexGridSizer *item3 = new wxFlexGridSizer( 2, 0, 0 );

    wxStaticText *item4 = new wxStaticText( parent, ID4_TEXT, _("RISM"), wxDefaultPosition, wxDefaultSize, 0 );
    item3->Add( item4, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxTextCtrl *item5 = new wxTextCtrl( parent, ID4_RISM, wxT(""), wxDefaultPosition, wxSize(300,-1), 0 );
    item3->Add( item5, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item6 = new wxStaticText( parent, ID4_TEXT, _("Composer"), wxDefaultPosition, wxDefaultSize, 0 );
    item3->Add( item6, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxTextCtrl *item7 = new wxTextCtrl( parent, ID4_COMPOSER, wxT(""), wxDefaultPosition, wxSize(300,-1), 0 );
    item3->Add( item7, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item8 = new wxStaticText( parent, ID4_TEXT, _("Title"), wxDefaultPosition, wxDefaultSize, 0 );
    item3->Add( item8, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxTextCtrl *item9 = new wxTextCtrl( parent, ID4_TITLE, wxT(""), wxDefaultPosition, wxSize(300,-1), 0 );
    item3->Add( item9, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item10 = new wxStaticText( parent, ID4_TEXT, _("Printer"), wxDefaultPosition, wxDefaultSize, 0 );
    item3->Add( item10, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxTextCtrl *item11 = new wxTextCtrl( parent, ID4_PRINTER, wxT(""), wxDefaultPosition, wxSize(300,-1), 0 );
    item3->Add( item11, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item12 = new wxStaticText( parent, ID4_TEXT, _("Year"), wxDefaultPosition, wxDefaultSize, 0 );
    item3->Add( item12, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxTextCtrl *item13 = new wxTextCtrl( parent, ID4_YEAR, wxT(""), wxDefaultPosition, wxSize(300,-1), 0 );
    item3->Add( item13, 0, wxALIGN_CENTER|wxALL, 5 );

    wxStaticText *item14 = new wxStaticText( parent, ID4_TEXT, _("Library"), wxDefaultPosition, wxDefaultSize, 0 );
    item3->Add( item14, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxTextCtrl *item15 = new wxTextCtrl( parent, ID4_LIBRARY, wxT(""), wxDefaultPosition, wxSize(300,-1), 0 );
    item3->Add( item15, 0, wxALIGN_CENTER|wxALL, 5 );

    item1->Add( item3, 0, wxALIGN_CENTER, 5 );

    item0->Add( item1, 0, wxGROW|wxALL, 5 );

    wxStaticBox *item17 = new wxStaticBox( parent, -1, _("File directories") );
    wxStaticBoxSizer *item16 = new wxStaticBoxSizer( item17, wxVERTICAL );

    wxStaticText *item18 = new wxStaticText( parent, ID4_TEXT, _("Images"), wxDefaultPosition, wxDefaultSize, 0 );
    item16->Add( item18, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5 );

    wxFlexGridSizer *item19 = new wxFlexGridSizer( 2, 0, 0 );

    wxBoxSizer *item20 = new wxBoxSizer( wxHORIZONTAL );

    wxTextCtrl *item21 = new wxTextCtrl( parent, ID4_BOOK_IMAGES, wxT(""), wxDefaultPosition, wxSize(300,-1), 0 );
    item20->Add( item21, 0, wxALIGN_CENTER|wxALL, 5 );

    wxButton *item22 = new wxButton( parent, ID4_ON_BOOK_IMAGES, _("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
    item20->Add( item22, 0, wxALIGN_CENTER|wxALL, 5 );

    item19->Add( item20, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0 );

    item16->Add( item19, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0 );

    wxStaticText *item23 = new wxStaticText( parent, ID4_TEXT, _("Aruspix files"), wxDefaultPosition, wxDefaultSize, 0 );
    item16->Add( item23, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxTOP, 5 );

    wxFlexGridSizer *item24 = new wxFlexGridSizer( 2, 0, 0 );

    wxBoxSizer *item25 = new wxBoxSizer( wxHORIZONTAL );

    wxTextCtrl *item26 = new wxTextCtrl( parent, ID4_BOOK_AXFILES, wxT(""), wxDefaultPosition, wxSize(300,-1), 0 );
    item25->Add( item26, 0, wxALIGN_CENTER|wxALL, 5 );

    wxButton *item27 = new wxButton( parent, ID4_ON_BOOK_AXFILES, _("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
    item25->Add( item27, 0, wxALIGN_CENTER|wxALL, 5 );

    item24->Add( item25, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0 );

    item16->Add( item24, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 0 );

    item0->Add( item16, 0, wxGROW|wxALL, 5 );

    wxStaticBox *item29 = new wxStaticBox( parent, -1, _("Binarization") );
    wxStaticBoxSizer *item28 = new wxStaticBoxSizer( item29, wxVERTICAL );

    wxFlexGridSizer *item30 = new wxFlexGridSizer( 2, 0, 0 );

    wxStaticText *item31 = new wxStaticText( parent, ID4_TEXT, _("Document condition"), wxDefaultPosition, wxDefaultSize, 0 );
    item30->Add( item31, 0, wxALIGN_CENTER|wxALL, 5 );

    wxString strs32[] = 
    {
        _("Brink (2 Classes)"), 
        _("Sauvola"), 
        _("Brink (3 Classes)")
    };
    wxChoice *item32 = new wxChoice( parent, ID4_PAGE_BIN_CHOICE, wxDefaultPosition, wxSize(140,-1), 3, strs32, 0 );
    item30->Add( item32, 0, wxALIGN_CENTER|wxALL, 5 );

    item28->Add( item30, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );

    wxBoxSizer *item33 = new wxBoxSizer( wxHORIZONTAL );

    wxStaticText *item34 = new wxStaticText( parent, ID4_TEXT, _("Region size (uneven lighting)"), wxDefaultPosition, wxDefaultSize, 0 );
    item33->Add( item34, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxSpinCtrl *item35 = new wxSpinCtrl( parent, ID4_RGN_SIZE_SPINCTRL, wxT("0"), wxDefaultPosition, wxSize(55,-1), 0, 0, 100, 0 );
    item33->Add( item35, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    item28->Add( item33, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );

    wxBoxSizer *item36 = new wxBoxSizer( wxHORIZONTAL );

    wxCheckBox *item37 = new wxCheckBox( parent, ID4_BIN_SELECT_CHECKBOX, _("Allow algorithm selection when processing individual images"), wxDefaultPosition, wxDefaultSize, 0 );
    item36->Add( item37, 0, wxALIGN_CENTER|wxALL, 5 );

    item28->Add( item36, 0, wxALIGN_CENTER|wxALL, 5 );

    item0->Add( item28, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxBoxSizer *item38 = new wxBoxSizer( wxHORIZONTAL );

    wxButton *item39 = new wxButton( parent, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    item38->Add( item39, 0, wxALIGN_CENTER|wxALL, 5 );

    wxButton *item40 = new wxButton( parent, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    item38->Add( item40, 0, wxALIGN_CENTER|wxALL, 5 );

    item0->Add( item38, 0, wxALIGN_CENTER|wxALL, 5 );

    if (set_sizer)
    {
        parent->SetSizer( item0 );
        if (call_fit)
            item0->SetSizeHints( parent );
    }
    
    return item0;
}

wxSizer *RecBinSelectDlgFunc( wxWindow *parent, bool call_fit, bool set_sizer )
{
    wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );

    wxFlexGridSizer *item1 = new wxFlexGridSizer( 2, 0, 0 );

    wxStaticText *item2 = new wxStaticText( parent, ID4_TEXTPgBin, _("Document condition"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item2, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxString strs3[] = 
    {
        _("Brink (2 Classes)"), 
        _("Sauvola"), 
        _("Brink (3 Classes)")
    };
    wxChoice *item3 = new wxChoice( parent, ID4_BIN_CHOICE, wxDefaultPosition, wxSize(140,-1), 3, strs3, 0 );
    item1->Add( item3, 0, wxALIGN_CENTER|wxALL, 5 );

    item0->Add( item1, 0, wxLEFT|wxRIGHT, 5 );

    wxBoxSizer *item4 = new wxBoxSizer( wxHORIZONTAL );

    wxStaticText *item5 = new wxStaticText( parent, ID4_TEXTRgnSize, _("Region Size (uneven lighting)"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
    item4->Add( item5, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxSpinCtrl *item6 = new wxSpinCtrl( parent, ID4_RGN_SIZE_SPINCTRL, wxT("15"), wxDefaultPosition, wxSize(55,-1), 0, 3, 50, 15 );
    item4->Add( item6, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );

    item0->Add( item4, 0, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );

    wxStaticLine *item7 = new wxStaticLine( parent, ID4_LINE1, wxDefaultPosition, wxSize(300,-1), wxLI_HORIZONTAL );
    item0->Add( item7, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxCheckBox *item8 = new wxCheckBox( parent, ID4_DEACTIVATE_DIALOG_CHECKBOX, _("Deactivate this dialog"), wxDefaultPosition, wxDefaultSize, 0 );
    item0->Add( item8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxButton *item9 = new wxButton( parent, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    item9->SetDefault();
    item0->Add( item9, 0, wxALIGN_CENTER|wxALL, 5 );

    if (set_sizer)
    {
        parent->SetSizer( item0 );
        if (call_fit)
            item0->SetSizeHints( parent );
    }
    
    return item0;
}

// Implement menubar functions

wxMenuBar *MenuBarFunc4()
{
    wxMenuBar *item0 = new wxMenuBar;
    
    wxMenu* item1 = new wxMenu;
    item1->AppendSeparator();
    item1->Append( ID4_NEW_BOOK, _("N&ew book"), _("Create a new book") );
    item1->Append( ID4_OPEN_BOOK, _("Open &book"), _("Open a book") );
    item1->Append( ID4_CLOSE_BOOK, _("C&lose book"), _("Close the book") );
    item1->Append( ID4_SAVE_BOOK, _("Sa&ve book"), _("Close the book") );
    item1->Append( ID4_SAVE_AS_BOOK, _("Save boo&k as"), _("Close the book") );
    item1->AppendSeparator();
    item1->Append( ID4_IMPORT_MEI, _("Import MEI"), _("Import MEI file") );
    item1->AppendSeparator();
    item1->Append( ID4_EXPORT_MEI, _("Export to MEI"), _("Export file as a MEI file") );
    item1->Append( ID4_EXPORT_MUSICXML, _("Export to MusicXML"), _("Save music part as a MusicXML file") );
    item0->Append( item1, _("commun1") );
    
    wxMenu* item2 = new wxMenu;
    item2->AppendSeparator();
    item2->Append( ID4_PROCESS, _("&Run"), _("Process current page") );
    item2->Append( ID4_CANCEL_REC, _("Un&do recognition"), _("Undo the recognition step") );
    item0->Append( item2, _("commun2") );
    
    wxMenu* item3 = new wxMenu;
    item3->Append( ID4_BOOK_EDIT, _("Edit"), _("Edit the book informations") );
    item3->Append( ID4_BOOK_LOAD, _("Reload files"), _("Reload images and Aruspix files into the book") );
    item3->AppendSeparator();
    item3->Append( ID4_BOOK_PRE, _("Batch preprocessing"), _("Preprocess active pages of the book") );
    item3->Append( ID4_BOOK_REC, _("Batch recognition"), _("Run recognition on remaining pages of the book") );
    item3->Append( ID4_BOOK_FULL, _("Batch (full process)"), _("Run preprocessing and recognition on active pages of a book") );
    item3->AppendSeparator();
    item3->Append( ID4_BOOK_ADAPT, _("Optimize"), _("Perform full optimization on recognized pages of the book") );
    item3->Append( ID4_BOOK_RESET_ADAPT, _("Reset optimization"), _("Reset optimization") );
    item3->AppendSeparator();
    item3->Append( ID4_BOOK_EXPORT_MODELS, _("Export models"), _("Export the Aruspix typographic model of the book") );
    
    wxMenu* item4 = new wxMenu;
    item4->Append( ID4_BOOK_EXPORT_MEI, _("MEI"), _("Export pages of the books as MEI files") );
    item3->Append( ID4_MENU, _("Export pages"), item4 );

    item3->Append( ID4_BOOK_IMPORT_MODELS, _("Import models"), _("Import an Aruspix typographic and music model to be used for this book") );
    item0->Append( item3, _("&Book") );
    
    wxMenu* item5 = new wxMenu;
    item5->Append( ID4_ZOOM_OUT, _("Zoom out\t-"), _("Zoom out") );
    item5->Append( ID4_ZOOM_IN, _("Zoom in\t+"), _("Zoom in") );
    item5->Append( ID4_ADJUST, _("Adjust"), _("Adjust to fit the window"), wxITEM_CHECK );
    item5->Append( ID4_ADJUST_V, _("Adjust vertically"), _("Adjust to fit the window vertically"), wxITEM_CHECK );
    item5->Append( ID4_ADJUST_H, _("Adjust horizontally"), _("Adjust to fit the window horizontally"), wxITEM_CHECK );
    item0->Append( item5, _("&Page") );
    
    wxMenu* item6 = new wxMenu;
    item6->Append( ID4_SHOW_STAFF_BMP, _("Staff correspondence"), _("Show staff correspondence on image"), wxITEM_CHECK );
    item6->AppendSeparator();
    item6->Append( ID4_INSERT_MODE, _("&Insertion"), wxT(""), wxITEM_CHECK );
    item6->Append( ID4_NOTES, _("&Notes and rests"), wxT("") );
    item6->Append( ID4_KEYS, _("&Keys"), wxT("") );
    item6->Append( ID4_SIGNS, _("&Propostions"), wxT("") );
    item6->Append( ID4_SYMBOLES, _("&Symboles"), wxT("") );
    item0->Append( item6, _("&Tools") );
    
    return item0;
}

// Implement toolbar functions

// Implement bitmap functions

wxBitmap BitmapsFunc4( size_t index )
{
    if (index == 0)
    {
        /* XPM */
        static const char *xpm_data[] = {
        /* columns rows colors chars-per-pixel */
        "16 15 1 1",
        "  c None",
        /* pixels */
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                ",
        "                "
        };
        wxBitmap bitmap( xpm_data );
        return bitmap;
    }
    return wxNullBitmap;
}

wxBitmap BitmapsFuncClassification( size_t index )
{
    if (index == 0)
    {
        /* XPM */
        static const char *xpm_data[] = {
        /* columns rows colors chars-per-pixel */
        "16 16 2 1",
        "  c None",
        "a c Black",
        /* pixels */
        "                ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        "                "
        };
        wxBitmap bitmap( xpm_data );
        return bitmap;
    }
    if (index == 1)
    {
        /* XPM */
        static const char *xpm_data[] = {
        /* columns rows colors chars-per-pixel */
        "16 16 2 1",
        "  c None",
        "a c #FFFF00",
        /* pixels */
        "                ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        "                "
        };
        wxBitmap bitmap( xpm_data );
        return bitmap;
    }
    if (index == 2)
    {
        /* XPM */
        static const char *xpm_data[] = {
        /* columns rows colors chars-per-pixel */
        "16 16 2 1",
        "  c None",
        "b c #FF8000",
        /* pixels */
        "                ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        "                "
        };
        wxBitmap bitmap( xpm_data );
        return bitmap;
    }
    if (index == 3)
    {
        /* XPM */
        static const char *xpm_data[] = {
        /* columns rows colors chars-per-pixel */
        "16 16 2 1",
        "  c None",
        "b c #007F00",
        /* pixels */
        "                ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        "                "
        };
        wxBitmap bitmap( xpm_data );
        return bitmap;
    }
    if (index == 4)
    {
        /* XPM */
        static const char *xpm_data[] = {
        /* columns rows colors chars-per-pixel */
        "16 16 2 1",
        "  c None",
        "b c #00FF00",
        /* pixels */
        "                ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        " bbbbbbbbbbbbbb ",
        "                "
        };
        wxBitmap bitmap( xpm_data );
        return bitmap;
    }
    if (index == 5)
    {
        /* XPM */
        static const char *xpm_data[] = {
        /* columns rows colors chars-per-pixel */
        "16 16 2 1",
        "  c None",
        "a c #E4E4E4",
        /* pixels */
        "                ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        " aaaaaaaaaaaaaa ",
        "                "
        };
        wxBitmap bitmap( xpm_data );
        return bitmap;
    }
    return wxNullBitmap;
}


// End of generated file
