#include"Record.h"

#include<iomanip>
#include<iostream>
#include<string>

using namespace std;

//what if size if 0?
Record::Record( int position, char *record, int size )
{
    if( size > 0 )
    {
        this->size = size;
    }
    else
    {
        this->size = 0;
    }

    if( position > 0 )
    {
        this->position = position;
    }
    else
    {
        this->position = 0;
    }

    this->record = new char[ size ];

    for( int i = 0; i < size; i++ )
    {
        this->record[i] = record[i];
    }
}

Record::~Record()
{
    delete[] record;
}

//deep copy
Record::Record(const Record &rhs)
{
    this->size = rhs.size;
    this->position = rhs.position;

    if(!rhs.record)
        record=0;
    else
    {
        this->record = new char[size];
        int j=0;
        while( j<size)
        {
            this->record[j]=rhs.record[j];
            j++;
        }
    }
}
//assignment operator
const Record &Record::operator=( const Record &rhs )
{
    if( this != &rhs )
    {
        delete[] record;
        this->position = rhs.position;
        this->size = rhs.size;
        this->record = new char [ size ];	//possible error here

        for( int i = 0; i < size; i++ )
        {
            this->record[i] = rhs.record[i];	//possibly this->record[i] = rhs.record[i]
        }
    }
    return *this;
}

bool Record::operator == ( const Record &rhs )
{
    return( this->position == rhs.position );
}

void Record::print( ostream &out )
{
    out << "Position: " << getPosition() << endl;
    out << "Size: " << getSize() << endl;
    out << "Record" << getRecord() << endl;
    out << endl;
}

int Record::getPosition()
{
    return position;
}

char* Record::getRecord()
{
    return record;
}

int Record::getSize()
{
    return size;
}

ostream& operator << ( ostream &out, const Record &rhs )
{
    out << rhs.record << endl;

    return out;
}

