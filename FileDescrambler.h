/*
For this project, I have neither given nor receive
unauthorized assistance
Matt Luckam
*/

#ifndef FileDescrambler_h
#define FileDescrambler_h

#include <QtGui>

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "Record.h"
#include "BadIndexException.h"
#include "LinkedList.h"
#include "Node.h"
#include "ListADT.h"

using namespace std;

class FileDescrambler
{
private:
	LinkedList<Record> File;

public:
	FileDescrambler();
    void displayFile( QTextEdit* out, QString fileName );
    void descramble( ifstream &in );
	int numberOfParts();
	void displayPart( ostream &out, int position );
};

#endif

