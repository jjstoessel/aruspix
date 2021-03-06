 /////////////////////////////////////////////////////////////////////////////
// Name:        musobject.h
// Author:      Laurent Pugin
// Created:     2005
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __MUS_OBJECT_H__
#define __MUS_OBJECT_H__

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include <uuid/uuid.h>
#include <typeinfo>
#include <vector>
#include <list>

class MusDoc;
class MusFunctor;
class MusObject;

typedef std::vector<MusObject*> ArrayOfMusObjects;

typedef std::list<MusObject*> ListOfMusObjects;

typedef std::vector<void*> ArrayPtrVoid;

//----------------------------------------------------------------------------
// MusObject
//----------------------------------------------------------------------------

/** 
 * This class represents a basic object
 */
class MusObject: public wxObject
{
public:
    // constructors and destructors
    MusObject();
    virtual ~MusObject();
    
    virtual bool operator==( MusObject& other );
    
    int GetId() { return 0; }; // used in SVG - TODO
    uuid_t* GetUuid() { return &m_uuid; };
    wxString GetUuidStr();
    void SetUuid( uuid_t uuid );
    void ResetUuid( );
    
    /**
     * Clear the children vector and delete all the objects.
     */
    void ClearChildren();
    
    /**
     * Set the parent of the MusObject.
     * The current parent is expected to be NULL.
     */
    void SetParent( MusObject *parent );
    
    virtual wxString MusClassName( ) { return "[MISSING]"; };
    
    /**
     * Look for the MusObject in the children and return its position (-1 if not found)
     */
    int GetChildIndex( const MusObject *child );
    
    /**
     * Insert a element at the idx position.
     */
    void InsertChild( MusObject *element, int idx );
    
    /**
     * Detach the child at the idx position (NULL if not found)
     * The parent pointer is set to NULL.
     */
    MusObject *DetachChild( int idx );
    
    /**
     * Remove and delete the child at the idx position.
     */
    void RemoveChildAt( int idx );
    
    /**
     * Return the first parent of the specified type.
     * The maxSteps parameter limit the search to a certain number of level if not -1.
     */
    MusObject *GetFirstParent( const std::type_info *elementType, int maxSteps = -1 );
    
    /**
     * Fill the list of all the children MusLayerElement.
     * This is used for navigating in a MusLayer (See MusLayer::GetPrevious and MusLayer::GetNext).
     */  
    void FillList( ListOfMusObjects *list );
    
    /**
     * Add a sameAs attribute to the object.
     * If a filename is given, the attribute with be filename#id
     * If several value are added, they will be separated by a whitespace.
     */
    void AddSameAs( wxString id, wxString filename = "" );
    
    /**
     * Parse the sameAs attribute and return the one at the #idx position (if any).
     */
    bool GetSameAs( wxString *id, wxString *filename, int idx = 0 );
    
    /**
     * Check if the content was modified or not
     */
    bool IsModified( ) { return m_isModified; };
    
    /**
     * Mark the object and its parent (if any) as modified
     */
    void Modify( bool modified = true );
    
    // moulinette
    virtual void Process(MusFunctor *functor, ArrayPtrVoid params );
    
    // functor methods
    /**
     * Add each MusLayerElements and its children to a list
     */
    virtual bool AddMusLayerElementToList( ArrayPtrVoid params );
    
    /**
     * See MusLayer::CopyToLayer
     */ 
    virtual bool CopyToLayer( ArrayPtrVoid params ) { return false; };
    
    /**
     * Find a MusObject with a specified uuid.
     */
    virtual bool FindByUuid( ArrayPtrVoid params );
    
    virtual bool Save( ArrayPtrVoid params ) { return false; };
    virtual bool TrimSystem( ArrayPtrVoid params );
    virtual bool UpdateLayerElementXPos( ArrayPtrVoid params );
    virtual bool UpdateStaffYPos( ArrayPtrVoid params );

public:
    ArrayOfMusObjects m_children;
    MusObject *m_parent;
    wxString m_sameAs;
    
protected:
    uuid_t m_uuid;

private:
    /**
     * Indicated whether the object content is up-to-date or not.
     * This is usefull for object using sub-lists of objects when drawing.
     * For example, MusBeam has a list of children notes and this value indicates if the
     * list needs to be updated or not. Is is moslty and optimization feature.
     */
    bool m_isModified;
    
};


//----------------------------------------------------------------------------
// MusDocObject
//----------------------------------------------------------------------------

/** 
 * This class represents a basic object in the layout domain
 */
class MusDocObject: public MusObject
{
public:
    // constructors and destructors
    MusDocObject();
    virtual ~MusDocObject();
    
    /**
     * Refreshes the views from MusDoc.
     * From other MusDocObject, simply pass it to its parent until MusDoc is reached.
     */
    virtual void Refresh();
    
    void UpdateContentBB( int x1, int y1, int x2, int y2);
    void UpdateSelfBB( int x1, int y1, int x2, int y2 );
    bool HasContentBB();
    bool HasSelfBB();
    void ResetBB();

    int m_contentBB_x1, m_contentBB_y1, m_contentBB_x2, m_contentBB_y2;
    int m_selfBB_x1, m_selfBB_y1, m_selfBB_x2, m_selfBB_y2; 
    
    /**
     * Is true if the bounding box (self or content) has been updated at least once.
     * We need this to avoid not updating bounding boxes to screw up the layout with their intial values.
     */
    bool HasUpdatedBB( ) { return m_updatedBB; };
    
private:
    bool m_updatedBB;
    
protected:
    //MusDoc *m_doc;
    
public:
    
};


//----------------------------------------------------------------------------
// MusObjectListInterface
//----------------------------------------------------------------------------

/** 
 * This class is an interface for elements maintaining a list of children
 * MusLayerElement for processing.
 * The list is a flatten list of pointers to children elements.
 * It is not an abstract class but should not be instanciate directly.
 */
class MusObjectListInterface
{
public:
    // constructors and destructors
    MusObjectListInterface() {};
    virtual ~MusObjectListInterface() {};
    
    /**
     * Look for the MusObject in the list and return its position (-1 if not found)
     */
    int GetListIndex( const MusObject *listElement );
    
    /**
     * Returns the previous object in the list (NULL if not found)
     */
    MusObject *GetListPrevious( const MusObject *listElement );

    /**
     * Returns the previous next in the list (NULL if not found)
     */
    MusObject *GetListNext( const MusObject *listElement );
    
    /**
     * Return the list.
     * Because this is an interface, we need to pass the object - not the best design.
     */
    ListOfMusObjects *GetList( MusObject *node );
    
protected:
    /**
     * Filter the list for a specific class.
     * For example, keep only notes in MusBeam
     */
    virtual void FilterList() {};

public:    
    /**
     * Reset the list of children and call FilterList().
     * As for GetList, we need to pass the object.
     */
    void ResetList( MusObject *node );
        
    ListOfMusObjects m_list;
    
};

//----------------------------------------------------------------------------
// abstract base class MusFunctor
//----------------------------------------------------------------------------

/** 
 * This class is an abstact Functor for the object hierarchy.
 * Needs testing.
 */
class MusFunctor
{
private:
    bool (MusObject::*obj_fpt)( ArrayPtrVoid params );   // pointer to member function
    
public:
    
    // constructor - takes pointer to an object and pointer to a member and stores
    // them in two private variables
    MusFunctor( );
    MusFunctor( bool(MusObject::*_obj_fpt)( ArrayPtrVoid ));
	virtual ~MusFunctor() {};
    
    // override function "Call"
    virtual void Call( MusObject *ptr, ArrayPtrVoid params );
    
    bool m_stopIt;
    bool m_reverse;
    
private:
    
};


//----------------------------------------------------------------------------
// MusEnv
//----------------------------------------------------------------------------

/** 
 * This class contains the document environment variables.
 * It remains from the Wolfgang parameters strcuture.
 * TODO - Integrate them in MEI.
 */
class MusEnv 
{
public:
    // constructors and destructors
    MusEnv();
    virtual ~MusEnv();
    
    
public:
    /** landscape paper orientation */
    char m_landscape;
    /** staff line width */
    unsigned char m_staffLineWidth;
    /** stem width */
    unsigned char m_stemWidth;
    /** barline width */
    unsigned char m_barlineWidth;
    /** beam width */
    unsigned char m_beamWidth;
    /** beam white width */
    unsigned char m_beamWhiteWidth;
    /** maximum beam slope */
    unsigned char m_beamMaxSlope;
    /** minimum beam slope */
    unsigned char m_beamMinSlope;     
    /** small staff size ratio numerator */
    unsigned char m_smallStaffNum;
    /** small staff size ratio denominator */
    unsigned char m_smallStaffDen;
    /** grace size ratio numerator */
    unsigned char m_graceNum;
    /** grace size ratio denominator */
    unsigned char m_graceDen;
    /** stem position correction */
    signed char m_stemCorrection;
    /** header and footer type */
    unsigned int m_headerType;
    /** notation mode. Since since Aruspix 1.6.1 */
    int m_notationMode;
};


#endif
