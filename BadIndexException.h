/* File Scrambler and Descrambler

created by: James Dagres, Curtis Johnson, Matt Luckam, and Miguel Suarez

This program scrambles a text file into a binary file, and displays the ouput.
 It also can take the scrambled binary file, descramble it, and display the unscrambled file.
*/

#ifndef BADINDEXEXCEPTION_H
#define BADINDEXEXCEPTION_H

#include <exception>

using std::exception;

class BadIndexException : public exception
{
};

#endif
