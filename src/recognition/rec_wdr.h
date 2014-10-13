//------------------------------------------------------------------------------
// Header generated by wxDesigner from file: rec.wdr
// Do not modify this file, all changes will be lost!
//------------------------------------------------------------------------------

#ifndef __WDR_rec_H__
#define __WDR_rec_H__

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma interface "rec_wdr.h"
#endif

// Include wxWidgets' headers

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/image.h>
#include <wx/statline.h>
#include <wx/spinbutt.h>
#include <wx/spinctrl.h>
#include <wx/splitter.h>
#include <wx/listctrl.h>
#include <wx/treectrl.h>
#include <wx/notebook.h>
#include <wx/grid.h>
#include <wx/toolbar.h>
#include <wx/tglbtn.h>

// Declare window functions

const int ID4_SPLITTER1 = 14000;
wxSizer *WindowFunc4( wxWindow *parent, bool call_fit = TRUE, bool set_sizer = TRUE );

const int ID4_TOOLPANEL = 14001;
const int ID4_MUSPANEL = 14002;
wxSizer *MusOutputFunc4( wxWindow *parent, bool call_fit = TRUE, bool set_sizer = TRUE );

const int ID4_TREEBOOK = 14003;
const int ID4_LINE2 = 14004;
const int ID4_PREVIEW = 14005;
const int ID4_CB_PREVIEW = 14006;
wxSizer *RecBookFunc4( wxWindow *parent, bool call_fit = TRUE, bool set_sizer = TRUE );

const int ID4_TEXT = 14007;
const int ID4_RISM = 14008;
const int ID4_COMPOSER = 14009;
const int ID4_TITLE = 14010;
const int ID4_PRINTER = 14011;
const int ID4_YEAR = 14012;
const int ID4_LIBRARY = 14013;
const int ID4_BOOK_IMAGES = 14014;
const int ID4_ON_BOOK_IMAGES = 14015;
const int ID4_BOOK_AXFILES = 14016;
const int ID4_ON_BOOK_AXFILES = 14017;
const int ID4_PAGE_BIN_CHOICE = 14018;
const int ID4_RGN_SIZE_SPINCTRL = 14019;
const int ID4_BIN_SELECT_CHECKBOX = 14020;
wxSizer *RecBookDataFunc4( wxWindow *parent, bool call_fit = TRUE, bool set_sizer = TRUE );

const int ID4_TEXTPgBin = 14021;
const int ID4_BIN_CHOICE = 14022;
const int ID4_TEXTRgnSize = 14023;
const int ID4_LINE1 = 14024;
const int ID4_DEACTIVATE_DIALOG_CHECKBOX = 14025;
wxSizer *RecBinSelectDlgFunc( wxWindow *parent, bool call_fit = TRUE, bool set_sizer = TRUE );

// Declare menubar functions

const int ID4_MENU_FILE = 14026;
const int ID4_MENU0 = 14027;
const int ID4_NEW_BOOK = 14028;
const int ID4_OPEN_BOOK = 14029;
const int ID4_CLOSE_BOOK = 14030;
const int ID4_SAVE_BOOK = 14031;
const int ID4_SAVE_AS_BOOK = 14032;
const int ID4_IMPORT_MEI = 14033;
const int ID4_EXPORT_MEI = 14034;
const int ID4_EXPORT_MUSICXML = 14035;
const int ID4_MENU_EDIT = 14036;
const int ID4_MENU = 14037;
const int ID4_PROCESS = 14038;
const int ID4_CANCEL_REC = 14039;
const int ID4_BOOK = 14040;
const int ID4_BOOK_EDIT = 14041;
const int ID4_BOOK_LOAD = 14042;
const int ID4_BOOK_PRE = 14043;
const int ID4_BOOK_REC = 14044;
const int ID4_BOOK_FULL = 14045;
const int ID4_BOOK_ADAPT = 14046;
const int ID4_BOOK_RESET_ADAPT = 14047;
const int ID4_BOOK_EXPORT_MODELS = 14048;
const int ID4_BOOK_EXPORT_MEI = 14049;
const int ID4_BOOK_IMPORT_MODELS = 14050;
const int ID4_PAGE = 14051;
const int ID4_ZOOM_OUT = 14052;
const int ID4_ZOOM_IN = 14053;
const int ID4_ADJUST = 14054;
const int ID4_ADJUST_V = 14055;
const int ID4_ADJUST_H = 14056;
const int ID4_TOOLS = 14057;
const int ID4_SHOW_STAFF_BMP = 14058;
const int ID4_INSERT_MODE = 14059;
const int ID4_NOTES = 14060;
const int ID4_KEYS = 14061;
const int ID4_SIGNS = 14062;
const int ID4_SYMBOLES = 14063;
wxMenuBar *MenuBarFunc4();

// Declare toolbar functions

// Declare bitmap functions

wxBitmap BitmapsFunc4( size_t index );

wxBitmap BitmapsFuncClassification( size_t index );

#endif

// End of generated file
