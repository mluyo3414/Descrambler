#ifndef LinkedList_h
#define LinkedList_h

#include"ListADT.h"
#include"Node.h"
#include"BadIndexException.h"

#include<iostream>
#include<iomanip>

using namespace std;

template <typename T>
class LinkedList : public ListADT<T>
{
private:
	Node<T>* head;
	Node<T>* curr;
	int cnt;

public:
	LinkedList();
	~LinkedList();
	LinkedList( T data );
	LinkedList( const LinkedList<T>&ll );
	const LinkedList<T>& operator = ( const LinkedList<T>&ll );
	void insert( T data );
	void insertAt( T data, int location ) throw( BadIndexException );
	T find( T data );
	T itemAt( int location ) throw( BadIndexException );
	T remove( T data );
	T removeAt( int location ) throw( BadIndexException );
	void display( ostream &out );
	void clear();
	int count();

};

//Default Constructor
template<typename T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	cnt = 0;
}

//Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* curr = head;

	while( curr != NULL )
	{
		head = head->getNext();
		delete curr;
		curr = head;
	}
}

//Paramaterized Constructor
template<typename T>
LinkedList<T>::LinkedList( T data )
{
	head = new Node<T>( data );
	cnt = 1;
}

template<typename T>
LinkedList<T>::LinkedList( const LinkedList<T> &ll )
{
	cnt = ll.cnt;
	head = NULL;
	Node<T>* otherCurr, *curr;
	otherCurr= ll.head;

	if( otherCurr != NULL )
	{
		head = new Node<T>( otherCurr->getData() );
		curr = head;
		otherCurr = otherCurr->getNext();

		while( otherCurr != NULL )
		{
			curr->setNext( new Node<T>( otherCurr->getData() ) ); 
			otherCurr = otherCurr->getNext();
			curr = curr->getNext();
		}
	}
}

//Assignment Operator
template<typename T>
const LinkedList<T> &LinkedList<T>::operator = ( const LinkedList<T> &ll )
{
	//compares addresses to see if items are the same
	if( this != &ll )
	{
		clear();
		head = NULL;
		cnt = ll.cnt;

		Node<T>* curr1;
		
		curr1 = ll.head;

		if( curr1 != NULL )
		{
			head = new Node<T> (curr1->getData() );
			curr = head;
			curr1 = curr1->getNext();

			while( curr1 != NULL )
			{
				curr-> setNext( new Node<T> (curr1->getData() ) );

				curr1 = curr1->getNext();
				curr = curr->getNext();
			}
		}
	}
	return *this;
}

//Insert into Linked List
template<typename T>
void LinkedList<T>::insert( T data )
{
	//if list it empty
	if( head == NULL )
	{
		head = new Node<T>( data );
		cnt = 1;
	}
	
	else
	{
		Node<T>* curr = head;
		while( curr->getNext() != NULL )
		{
			curr = curr->getNext();
		}

		Node<T> *temp = new Node<T>( data );
		curr->setNext( temp );
		cnt++;
	}
}

//Inserts item at specific location
template<typename T>
void LinkedList<T>::insertAt( T data, int location ) throw( BadIndexException )
{
	//throw exception if location is less than 0
	if( location < 0 )
	{
		throw( BadIndexException() );
	}

	//Inserts data of location 0
	else if( location == 0 )
	{
		Node<T> *curr = head;
		Node<T> *temp = new Node<T>( data );
		temp->getNext();
		temp->setNext( head );
		curr = head;
		head = temp;
		cnt++;
	}

	//Inserts data at given location
	else if( location > 0 && location <= cnt )
	{
		Node<T> *curr = head;
		for(int i = 0; i < location - 1; i++ )
		{
			curr = curr ->getNext();
		}

		Node<T> *temp = new Node<T>( data );
		temp->getNext(); //temp->setNext();
		temp->setNext( curr->getNext() );
		curr->setNext( temp );
		cnt++;
	}

	//inserts data at end of list
	else if( location > cnt )
	{
		insert( data );
	}
}

//Finds data in list
template<typename T>
T LinkedList<T>::find( T data )
{
	bool found = false;
	T toReturn = T();

	Node<T>* curr = head;
	while( curr != NULL && !found )
	{
		if( curr->getData() == data )
		{
			toReturn = curr->getData();
			found = true;
		}

		curr = curr->getNext();
	}

	return toReturn;
}

//Finds item at a given location
template<typename T>
T LinkedList<T>::itemAt( int location ) throw( BadIndexException )
{
	T toReturn = T();

	//throws exeception if location is invalid
	if( location < 0 || location > cnt )
	{
		throw( BadIndexException() );
	}

	else if( location >= 0 && location <= cnt )
	{
		Node<T> *curr = head;
		for( int i = 0; i < location; i++ )
		{
			curr = curr ->getNext();
		}

		toReturn = curr->getData();
	}

	return toReturn;
}

//Removes a given piece of data from list
template<typename T>
T LinkedList<T>::remove( T data )
{
	bool found = false;
	T toReturn = T();

	Node<T>* follow = NULL;
	Node<T>* curr = head;
	while( curr != NULL && !found )
	{
		if( curr->getData() == data )
		{
			toReturn = curr->getData();

			//removes head of list
			if( curr == head )
			{
				head = head->getNext();
			}

			else
			{
				follow->setNext( curr->getNext() );
			}

			delete curr;
			cnt--;
			found = true;
		}

		follow = curr;
		curr = curr->getNext();
	}

	return toReturn;
}

//Removes data from a given location
template<typename T>
T LinkedList<T>::removeAt( int location ) throw( BadIndexException )
{
	T toReturn = T();

	//Throws exception if location is invalid
	if( location < 0 || location > cnt )
	{
		throw( BadIndexException() );
	}

	//removes data from location 0
	if( location == 0 )
	{
		Node<T> *curr = head;
		curr = curr->getNext();
		toReturn = curr->getData();
		delete head;
		head = curr ;
		cnt--;
	}

	if( location > 0 && location <= cnt )
	{
		Node<T> *curr = head;
		Node<T> *follow = NULL;

		for( int i = 0; i < ( location ); i++ )
		{
			follow = curr;
			curr = curr ->getNext();
		}

		toReturn = curr->getData();

		if( curr == head )
		{
			head = head->getNext();
		}
		else
		{
			follow->setNext( curr->getNext() );
		}

		delete curr;
		cnt--;
	}

	return toReturn;
}

//Displays items in the list
template<typename T>
void LinkedList<T>::display( ostream &out )
{
	if( head == NULL )
	{
		out << "The list is empty" << endl;
	}
	else
	{
		Node<T>* curr = head;
		while( curr -> getNext() != NULL )
		{
			out << curr-> getNext() << endl; 

			curr = curr->getNext();
		}
	}
}

//Empties the list
template<typename T>
void LinkedList<T>::clear()
{
	Node<T>* temp = head;

	while( temp != NULL )
	{
		head = head->getNext();
		delete temp;
		temp = head;
	}

	cnt = 0;
}

//Returns the number of item in the list
template<typename T>
int LinkedList<T>::count()
{
	return cnt;
}


/* Traversal

Node<T>* curr = head;
while( curr != NULL )
{
//do something

curr = curr->getNext();
}
*/

#endif
