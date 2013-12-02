/////////////////////////////////////////////////////////////////////////////
// Name:        muslayer.h
// Author:      Laurent Pugin
// Created:     2011
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////


#ifndef __MUS_LAYER_H__
#define __MUS_LAYER_H__

#include <typeinfo>

#include "musobject.h"

class MusClef;
class MusDC;
class MusLayerElement;
class MusNote;

//----------------------------------------------------------------------------
// MusLayer
//----------------------------------------------------------------------------

/**
 * This class represents a layer in a laid-out score (MusDoc).
 * A MusLayer is contained in a MusStaff.
 * It contains MusLayerElement objects.
*/
class MusLayer: public MusDocObject, public MusObjectListInterface
{
public:
    // constructors and destructors
    MusLayer( int logLayerNb );
    virtual ~MusLayer();
    
    virtual std::string MusClassName( ) { return "MusLayer"; };
    virtual std::string GetIdShortName() { return "layer-"; };
    
    void Clear();
	
	void AddElement( MusLayerElement *element, int idx = -1 );
    	
	int GetElementCount() const { return (int)m_children.size(); };
    
    int GetLayerNo() const;

    // functors
    /**
     * Copy the elements to a MusLayer passed in parameters. 
     * Also take into account a start and end uuid for the page (if any)
     */ 
    virtual int CopyToLayer( ArrayPtrVoid params );
    void CopyElements( ArrayPtrVoid params ); // unused
    void GetMaxXY( ArrayPtrVoid params ); // unused
    virtual int Save( ArrayPtrVoid params );
    void CheckAndResetSectionOrMeasure( ArrayPtrVoid params ); // unused
    
	void CopyAttributes( MusLayer *layer ); // copy all attributes but none of the elements
    
	MusLayerElement *GetFirst( );
	MusLayerElement *GetLast( );
	MusLayerElement *GetNext( MusLayerElement *element );
	MusLayerElement *GetPrevious( MusLayerElement *element );
	MusLayerElement *GetAtPos( int x );
	MusLayerElement *Insert( MusLayerElement *element, int x ); // return a pointer on the inserted element
    
    void Insert( MusLayerElement *element, MusLayerElement *before );
    
	void Delete( MusLayerElement *element );
	/** 
     * Looks for the first MusLayerElement with an LayoutElement of type elementType.
     * Looks FORWARD of BACKWARD depending on the direction parameter.
     * Returns the retrieved element if *succ == true or the original element if not.
     */
    MusLayerElement *GetFirst( MusLayerElement *element, unsigned int direction, const std::type_info *elementType, bool *succ );
    /** Get the current clef for the test element */
	MusClef *GetClef ( MusLayerElement *test );
	void getOctDec (int ft, int _ot, int rupt, int *oct);
    /** Return the clef offset for the position x (retrieve the first clef before it) */
    int GetClefOffset( MusLayerElement *test  );
    
    /**
     * Add an element to the drawing list.
     * The drawing list is used to postponed the drawing of elements
     * that need to be drawn in a particular order.
     * For example, we need to draw beams before tuplets
     */
    void AddToDrawingList( MusLayerElement *element );

    /**
     * Return the darwing list.
     * This is used when actually darwing the list (see MusRC::DrawLayerList)
     */
    ListOfMusObjects *GetDrawingList( );

    /**
     * Reset the darwing list.
     * Clears the list - called when the layer starts to be drawn
     */
    void ResetDrawingList( );
    
    /**
     * Basic method that remove intermediate clefs and custos.
     * Used for building collations (See CmpFile::Collate).
     */
    void RemoveClefAndCustos( );
    
    /**
     * Checks that the X position of the currentElement is not before the previous element or after the next one.
     * This works for facsimile (transcription) encodings only because it looks at the m_x_abs position
     */ 
    void CheckXPosition( MusLayerElement *currentElement );

    //Lyric related methods
    /*
	int GetLyricPos( MusSymbol *lyric );
	MusSymbol *GetPreviousLyric( MusSymbol *lyric );
	MusSymbol *GetNextLyric( MusSymbol *lyric );
	MusSymbol *GetFirstLyric( );
	MusSymbol *GetLastLyric( );
	MusSymbol *GetLyricAtPos( int x );
	void DeleteLyric( MusSymbol *symbol );
	MusNote *GetNextNote( MusSymbol * lyric );
	MusNote *GetPreviousNote( MusSymbol * lyric );
	void SwitchLyricNoteAssociation( MusSymbol *lyric, MusNote *oldNote, MusNote* newNote, bool beginning );
	void AdjustLyricLineHeight( int delta );
    */
    
    /**
     * Align the content of a system.
     */
    virtual int Align( ArrayPtrVoid params );
    
private:
    
public:
    /** The logical layer */
    int m_logLayerNb;
    /** The logical staff - used to overwrite the parent staff */
    int m_logStaffNb;
	/** voix de la portee*/
	unsigned short voix;  
    
protected:
    // drawing variables
    //MusLayerElement *beamListPremier; // we need to replace this with a proper beam class that handles a list of notes/rests
    ListOfMusObjects m_drawingList;

private:
    
};


#endif
