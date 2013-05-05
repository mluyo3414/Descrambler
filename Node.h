/* File Scrambler and Descrambler

created by: James Dagres, Curtis Johnson, Matt Luckam, and Miguel Suarez

This program scrambles a text file into a binary file, and displays the ouput.
 It also can take the scrambled binary file, descramble it, and display the unscrambled file.
*/

#ifndef Node_h
#define Node_h

#include<iostream>
#include<iomanip>

using namespace std;

template<typename T>
class Node
{
private:
	Node<T> *next;
	T data;

public:
	Node();
	Node( T newData, Node<T> *newNext = NULL );
	void setData( T newData );
	void setNext( Node<T> *newNext );
	T getData();
	Node<T> *getNext();
};


template<typename T>
Node<T>::Node()
{
	this->data = T();
	this->next = NULL;
}

template<typename T>
Node<T>::Node( T newData, Node<T> *newNext )
{
	this->data = newData;

	if( newNext != NULL )
	{
		this->next = newNext;
	}
	else
	{
		this->next = NULL;
	}
}

template<typename T>
T Node<T>::getData()
{
	return data;
}

template<typename T>
Node<T> *Node<T>::getNext()
{
	return next;
}

template<typename T>
void Node<T>::setData( T newData )
{
	this->data = newData;
}

template<typename T>
void Node<T>::setNext( Node<T> *newNext )
{
	this->next = newNext;
}
#endif
