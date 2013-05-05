/* File Scrambler and Descrambler

created by: James Dagres, Curtis Johnson, Matt Luckam, and Miguel Suarez

This program scrambles a text file into a binary file, and displays the ouput.
 It also can take the scrambled binary file, descramble it, and display the unscrambled file.
*/

#include <QtGui/QApplication>
#include "gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gui w;
    w.show();
    
    return a.exec();
}
