/* File Scrambler and Descrambler

created by: James Dagres, Curtis Johnson, Matt Luckam, and Miguel Suarez

This program scrambles a text file into a binary file, and displays the ouput.
 It also can take the scrambled binary file, descramble it, and display the unscrambled file.
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

