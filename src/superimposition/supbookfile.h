/////////////////////////////////////////////////////////////////////////////
// Name:        supbookfile.h
// Author:      Laurent Pugin
// Created:     2004
// Copyright (c) Authors and others. All rights reserved.   
/////////////////////////////////////////////////////////////////////////////

#ifndef __supbook_H__
#define __supbook_H__

#ifdef AX_SUPERIMPOSITION

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wx/dynarray.h"
//#include "wx/treectrl.h"

#include "app/axfile.h"

#include "sup_wdr.h"

class SupEnv;
class SupBookCtrl;


//----------------------------------------------------------------------------
// SupBookFile
//----------------------------------------------------------------------------

class SupBookFile: public AxFile 
{
public:
    // constructors and destructors
    SupBookFile( wxString name, SupEnv *env = NULL );
    virtual ~SupBookFile();
    
        virtual void NewContent(); // Create content for a new file
    virtual void OpenContent( ); // Open content after archive extraction
    virtual void SaveContent( ); // Save content before archive creation
    virtual void CloseContent( ); // Desactivate content before deletion
    
    // operations
    bool LoadImages1( );
	bool LoadImages2( );
    bool LoadAxfiles( );
    bool RemoveImage( wxString filename, int book_no );
    bool DesactivateImage( wxString filename, int book_no );
    bool RemoveAxfile( wxString filename );
    bool DeleteAxfile( wxString filename );
	bool DesactivateAxfile( wxString filename );
	// files
	bool CreateFiles( bool ask_user );
	int FilesToSuperimpose( wxArrayString *filenames, wxArrayString *paths );
	//bool HasToBeSuperimposed( wxString imagefile );
    
public:
        // infos
    wxString m_RISM;
    wxString m_Composer;
    wxString m_Title;
    wxString m_Printer;
    wxString m_Year;
    wxString m_Library1;
    wxString m_Library2;
    // files
    wxString m_axFileDir;
    wxString m_imgFileDir1;
	wxString m_imgFileDir2;
    ArrayOfBookFileItems m_axFiles;
    ArrayOfBookFileItems m_imgFiles1;
	ArrayOfBookFileItems m_imgFiles2;
	//

protected:
        SupEnv *m_envPtr;


private:
    
};

#endif //AX_SUPERIMPOSITION

#endif
