#ifndef Record_h
#define Record_h

#include<iostream>
#include<iomanip>

using namespace std;

class Record
{
private:
	int size;
	int position;
	char *record;

public:
	Record( int position = 0, char *record = NULL, int size = 0 );	//
	~Record();	//
    Record( const Record &rhs );	//
	const Record &operator = ( const Record &rhs );	//
	bool operator == ( const Record &rhs );
	void print( ostream &out );
	int getPosition();	//
	char *getRecord();	//
	int getSize();	//
	friend ostream& operator << ( ostream &out, const Record &rhs );	//Friend

};

#endif
