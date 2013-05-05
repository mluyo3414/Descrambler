DESCRIPTION:
=============

There are two funcionalities in this program. The first is a file scrambler which takes a text file 
and saves it as a scrambled bin file. The second is a file descrambler which reads in the scrambled bin 
file and descrambles it back to a text file. There is a GUI interface that selects the file to be converted
and contains two push bottons and two corresponding QTextEdits. The first button runs the file scrambler code
and displays the scrambled file on the first QTextEdit. The second button calls the descrambler program and
then displays the descrambled code on the second QTextEdit.

ADDITIONAL PROGRAMS TO RUN THE PROJECT:
=======================================

- QT

* The program can be made and executed from the terminal as well as from QT.
For reference on how to install Qt, please go to:
http://qt-project.org/doc/qt-4.8/installation.html

INSTRUCTIONS:
=======================================
*From the terminal once in the project directory:
qmake - project
qmake
make

* There are some test files to try the project in the the TestFiles directory.
* You can click on any of those files and click Scramble or Descramble in the GUI to see both formats of the file.

* Detailed steps on how to use our scrambler/descrambler:

1. Put The descramble File from the repo in a folder, then run the qmake instructions from inside that folder you just created
2. Run the executable that was just created 
3. Press file, then open pick a file, press scramble and watch it get encrypted into binary
4. Press descramble to change it back to the original format

