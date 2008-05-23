/////////////////////////////////////////////////////////////////////////////
// Name:        supim.h
// Author:      Laurent Pugin
// Created:     2004
// Copyright (c) Laurent Pugin. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __supim_H__
#define __supim_H__

#ifdef AX_SUPERIMPOSITION

#ifdef __GNUG__
    #pragma interface "supim.cpp"
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "app/aximagecontroller.h"
#include "app/axscrolledwindow.h"


class SupEnv;
class SupFile;

// WDR: class declarations


//----------------------------------------------------------------------------
// SupImSrcWindow
//----------------------------------------------------------------------------

class SupImSrcWindow: public AxScrolledWindow
{
public:
    // constructors and destructors
    SupImSrcWindow();
    SupImSrcWindow( AxImageController *parent, wxWindowID id = -1,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxScrolledWindowStyle );
    virtual ~SupImSrcWindow();
    
    // WDR: method declarations for SupImSrcWindow
    void SetCirclePen( const wxPen *pen, int width );
    void DrawCircle( );
    void ScrollSource( double x, double y );
    
private:
    // WDR: member variable declarations for SupImSrcWindow
    wxPoint m_circleCenter;
    wxPen m_pen;
    
private:
    // WDR: handler declarations for SupImSrcWindow

private:
    DECLARE_CLASS(SupImSrcWindow)
    DECLARE_EVENT_TABLE()
};


//----------------------------------------------------------------------------
// SupImWindow
//----------------------------------------------------------------------------

class SupImWindow: public AxScrolledWindow
{
public:
    // constructors and destructors
    SupImWindow();
    SupImWindow( AxImageController *parent, wxWindowID id = -1,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxScrolledWindowStyle );
    virtual ~SupImWindow();
    
    // WDR: method declarations for SupImWindow
    void SynchronizeScroll( int x, int y );
    
private:
    // WDR: member variable declarations for SupImWindow
    
private:
    // WDR: handler declarations for SupImWindow
    void OnMouse( wxMouseEvent &event );

private:
    DECLARE_CLASS(SupImWindow)
    DECLARE_EVENT_TABLE()
};

//----------------------------------------------------------------------------
// SupImController
//----------------------------------------------------------------------------

class SupImController: public AxImageController
{
public:
    // constructors and destructors
    SupImController();
    SupImController( wxWindow *parent, wxWindowID id = -1,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxTAB_TRAVERSAL | wxNO_BORDER, int flags = CONTROLLER_ALL );
    virtual ~SupImController();
    
    // WDR: method declarations for SupImController
    void UpdateBrightness( );
    virtual void CloseDraggingSelection(wxPoint start, wxPoint end);
    void SetControllers( AxImageController *controller1, AxImageController *controller2 );
    void SetViews( SupImSrcWindow *view1, SupImSrcWindow *view2 );
    void ScrollSources( double x, double y );
    void DrawCircles( bool clear = false );
	//SupFile *GetSupFile( ) { return m_supFilePtr; }

private:
    virtual void OpenPage( bool yield = true );
    
private:
    // WDR: member variable declarations for SupImController
    _imImage *m_greenIm;
    _imImage *m_redIm;
    AxImageController *m_imControl1Ptr;
    AxImageController *m_imControl2Ptr;
    SupImSrcWindow *m_viewSrc1Ptr;
    SupImSrcWindow *m_viewSrc2Ptr;
    int m_selectCounter; // for manual point selection

public:
    int m_red, m_green;
    wxPoint m_points[4]; // for manual point selection
	
protected:
    // WDR: member variable declarations for SupImController
    //SupEnv *m_envPtr;
    // to synchronize view
    //SupFile *m_supFilePtr;
    
private:
    // WDR: handler declarations for SupImController

private:
    DECLARE_CLASS(SupImController)
    DECLARE_EVENT_TABLE()
};

#endif // AX_SUPERIMPOSITION

#endif
