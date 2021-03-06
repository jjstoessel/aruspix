/////////////////////////////////////////////////////////////////////////////
// Name:        musdurationinterface.h
// Author:      Laurent Pugin
// Created:     2011
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef __MUS_DURATION_INTERFACE_H__
#define __MUS_DURATION_INTERFACE_H__

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#define TUPLET_INITIAL  (1<<1)
#define TUPLET_MEDIAL  (1<<2) 
#define TUPLET_TERMINAL  (1<<3)

#define DURATION_MAX_TUPLETS 6

class MusObject;

//----------------------------------------------------------------------------
// MusDurationInterface
//----------------------------------------------------------------------------

/** 
 * This class is an interface for elements with duration, such as notes and rests.
 * It is not an abstract class but should not be instanciate directly.
 */
class MusDurationInterface
{
public:
    // constructors and destructors
    MusDurationInterface();
    virtual ~MusDurationInterface();
    
    virtual void SetDuration( int value );
    
    /**
     * Look if the note or rest is in a beam.
     * Look for the fist beam parent and check is the note is in is content list.
     * Looking in the content list is necessary for grace notes or imbricated beams.
     */
    bool IsInBeam( MusObject *noteOrRest );
    
    /**
     * Return true if the note or rest is the first of a beam.
     */
    bool IsFirstInBeam( MusObject *noteOrRest );
    
    /**
     * Return true if the note or rest is the last of a beam.
     */
    bool IsLastInBeam( MusObject *noteOrRest );
    
    
    /**
     * Inteface comparison operator. 
     * Check if the MusLayerElement has a MusDurationInterface and compare attributes
     */
    bool HasIdenticalDurationInterface(MusDurationInterface  *otherDurationInterface);
    
private:
    
public:
    /** Indicates a break in the beaming */
    unsigned char m_breakSec;
    /** Indicates the number of augmentation dots */
    unsigned char m_dots;
    /** Indicates the duration */
    int m_dur;
    /** Indicates the numerator of the duration ratio */
    int m_num;
    /** Indicates the denominator of the duration ratio */
    int m_numBase;
    /** Indicates if intial, medial or termial part of a tuplet for up to 6 nesting/overlaping tuplets */
    unsigned char m_tuplet[DURATION_MAX_TUPLETS];
    /** Indicates if a fermata should be drawn on this note/rest */
    bool m_fermata;
    

private:
    
};


#endif
