/////////////////////////////////////////////////////////////////////////////
// Name:        muspage.h
// Author:      Laurent Pugin
// Created:     2005
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef __MUS_PAGE_H__
#define __MUS_PAGE_H__

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

class MusDC;

#include "musdoc.h"

class MusSystem;
class MusStaff;

enum {
    PAGE_VALUES_VOICES = 0,
    PAGE_VALUES_INDENT
};


//----------------------------------------------------------------------------
// MusPage
//----------------------------------------------------------------------------

/**
 * This class represents a page in a laid-out score (MusDoc).
 * A MusPage is contained in a MusDoc.
 * It contains MusSystem objects.
*/
class MusPage: public MusDocObject
{
public:
    // constructors and destructors
    MusPage();
    virtual ~MusPage();
    
    virtual wxString MusClassName( ) { return "MusPage"; };	    
    
    void Clear();
	
	void AddSystem( MusSystem *system );
    
	MusSystem *GetFirst( );
	MusSystem *GetLast( );
	MusSystem *GetNext( MusSystem *system );
	MusSystem *GetPrevious( MusSystem *system );
	MusSystem *GetAtPos( int y );

    void SetValues( int type );
	
	int GetSystemCount() const { return (int)m_children.size(); };
    
    int GetPageNo() const;
    
    /**
     * Return the position of the staff on the page, from top to bottom
     */
    int GetStaffPosOnPage( MusStaff *staff );


    // functors
    virtual bool Save( ArrayPtrVoid params );
    
    
private:
    
public:
    /** Page width (MEI scoredef@page.width). Saved if != -1 */
    int m_pageWidth;
    /** Page height (MEI scoredef@page.height). Saved if != -1 */
    int m_pageHeight;
    /** Page left margin (MEI scoredef@page.leftmar). Saved if != 0 */
    short m_pageLeftMar;
    /** Page right margin (MEI scoredef@page.rightmar). Saved if != 0 */
    short m_pageRightMar;
    /** Page top margin (MEI scoredef@page.topmar). Saved if != 0 */
    short m_pageTopMar;
    /** 
     * Surface (MEI @surface). Saved as facsimile for transciption layout.
     * For now, the target of the <graphic> element within surface is loaded here.
     */
    wxString m_surface;
    
    
    /** definition en mm des portees de la page */
    unsigned char defin; // m_pageScale
    /** longueur en mm de l'indentation des portees de la page */
    //int indent; // ax2
    /** longueur en mm de l'indentation droite des portees de la page */
    //int indentDroite; // ax2
    /** longueur en mm des lignes de la pages */
    //int lrg_lign; // ax2

private:
    
};

#endif
