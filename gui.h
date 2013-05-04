#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
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
#include "FileDescrambler.h"

using std::rand;
using std::srand;
using std::string;
using std::stringstream;
using std::istringstream;
using std::ostringstream;
using std::endl;
using std::setw;
using std::ios;
using std::ifstream;
using std::ofstream;


namespace Ui {
class Gui;
}

class Gui : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Gui(QWidget *parent = 0);
    ~Gui();
    
private slots:

    void on_actionOpen_triggered();

    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::Gui *ui;
    //opens file
    void openFile();
    //loads file
    void loadFile(const QString &fileName);
    //sets current file to m_FileName
    void setCurrentFile(const QString &fileName);
    //creates binary file
    void createBinary( string filename, int fileSizeBase );
    // opens file
    void displayFile( QString fileName, QTextEdit* whereTo );

    QString m_FileName;
    QString binFile;
};

#endif // GUI_H
