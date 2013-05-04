#ifndef LinkedList_ListADT_h
#define LinkedList_ListADT_h

#include "BadIndexException.h"
#include <iostream>
#include<iomanip>

using namespace std;


template <typename T>
class ListADT
{
public:
    /**
     This will simply insert the data at the end of the list.
	@param data the data to be inserted
     */
    virtual void insert( T data ) = 0;
    /**
     This is a zero based insert.  That is to say that the first node is labeled 0 and
     if you tell it to insert at 0, it will go before the first node.
     If you insert after count() number of nodes, it will simply be inserted at the end
	@param data  the data to be insert
	@param location a 0 based location for where to insert this element.  When 
	insert is done, data will be found at location location
	@throw BadIndexExeption if the index is less than 0
     */
    virtual void insertAt( T data, int location ) throw(BadIndexException) = 0;
    /**
    This will attempt to go through the list and look for the given piece of data.
    If it is found then it will return a copy of the data.
    It assumes that the T class has the operator= overloaded
	@param data the data we are looking for. The element might only be a partial element
	and might only have a key set.
	@return the element we found or a default constructed element of type T
    */    
    virtual T find( T data ) = 0;
    /**
    This will go through the list and look for the item at the given location.
    The location is 0 based.
    If location is past the end of the list, then a default object of type T
    will be returned.
	@param location the location where the element is to be found
	@return the element that was at the given location or a default element if the location is too large.
    	@throw BadIndexExeption if the index is less than 0
 */
    virtual T itemAt( int location ) throw(BadIndexException) = 0;
    /**
    This will attempt to remove the data from the list.  It assumes that the data has the
    operator= overloaded
	@param data the data we are looking to remove.  This data element might only have 
	a key value set.
	@return the actual element that was removed or a default element if it was not found.
    */
    virtual T remove( T data ) = 0;
    /**
    This will attempt to remove the item at the given location.  The location is 0 based.
	@param location this is the location where we want to remove the element
    	@return the element that was at the given location or a default element if the location is too large.
 	@throw BadIndexExeption if the index is less than 0
 */
    virtual T removeAt( int location ) throw(BadIndexException) = 0;
    /**
	This will display the list.
	@param out the ostream to be used to display the list.
	*/ 
    virtual void display( ostream& out) = 0;
	/**
	This will empty the list. It will be as if the list was newly constructed.
	*/
    virtual void clear() = 0;
    /**
	This will return the list's number of elements.
	@return The number of elements currently stored in the list.
	*/
    virtual int count() = 0;
	/**
	The destructor for this class.
	*/
	virtual ~ListADT() {}
};

#endif
