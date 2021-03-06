/////////////////////////////////////////////////////////////////////////////
// Name:        musapp.h
// Author:      Laurent Pugin
// Created:     2011
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef __MUS_APP_H__
#define __MUS_APP_H__

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "muslayer.h"

class MusLayerRdg;

//----------------------------------------------------------------------------
// MusLayerApp
//----------------------------------------------------------------------------

/** 
 * This class models the MEI <app> element within a <layer> element.
 */
class MusLayerApp: public MusLayerElement
{
public:
    // constructors and destructors
    MusLayerApp();
    virtual ~MusLayerApp();
    
    void AddLayerRdg( MusLayerRdg *layerRdg );
    
    int GetRdgCount() { return (int)m_children.size(); };
    
    // functor
    virtual bool Save( ArrayPtrVoid params );
    
private:
    
public:

private:
    
};


//----------------------------------------------------------------------------
// MusLayerRdg
//----------------------------------------------------------------------------

/** 
 * This class models the MEI <rdg> element for a <app> in a <layer>
 */
class MusLayerRdg: public MusObject
{
public:
    // constructors and destructors
    MusLayerRdg( );
    virtual ~MusLayerRdg();
    
	void AddElement( MusLayerElement *element, int idx = -1 );
    
	int GetElementCount() const { return (int)m_children.size(); };
    
    // functor
    virtual bool Save( ArrayPtrVoid params );

private:
    
public:
    /** The source id */
    wxString m_source;
    
private:
    
};


#endif
