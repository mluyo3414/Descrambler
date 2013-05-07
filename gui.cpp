#include "gui.h"
#include "ui_gui.h"

Gui::Gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gui)
{
    ui->setupUi(this);
}

Gui::~Gui()
{
    ui->pushButton->setEnabled( false );
    ui->pushButton_2->setEnabled( false );
    delete ui;
}

//opens file
void Gui::on_actionOpen_triggered()
{
    openFile();

}

//opens file
void Gui::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
    {
        loadFile(fileName);
    }
}

//loads file
void Gui::loadFile(const QString &fileName)
{

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Mian Window"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return;
    }

    setCurrentFile(fileName);

    statusBar()->showMessage(tr("File loaded"), 2000);
}

//determines if words in a file are in the dictionary
void Gui::displayFile( QString fileName, QTextEdit *whereTo )
{
    //takes file and opens
    QFile file ( fileName );
    file.open( QIODevice::ReadOnly );
    QTextStream readFile( &file );

    while( !readFile.atEnd() )
    {

        whereTo->append( readFile.readLine() );
        file.close();
    }
}

//sets name of file being used as current file m_FileName
void Gui::setCurrentFile(const QString &fileName)
{
    m_FileName = fileName;

    ui->pushButton->setEnabled( true );
    ui->pushButton_2->setEnabled( false );
    ui->originalFile->clear();
    ui->scrambledFile->clear();
    ui->descrambledFile->clear();

    displayFile( m_FileName, ui->originalFile );
}

// Creates the scrambled binary file based on the selected input file
void Gui::createBinary( string filename, int fileSizeBase )
{
    string fileStub = filename.substr( 0, filename.find( '.' ) );
    fileStub += ".bin";
    ifstream in( filename.c_str() );
    ofstream out( fileStub.c_str(), ios::binary );
    ifstream in2( filename.c_str() );
    in2.seekg(0, ios::end);
    int fileSize = in2.tellg();
    in2.close();
    int whatsLeft = fileSize;
    std::vector<Record> ll;
    srand( time( NULL ) );
    int recordSize = rand() % 50 + fileSizeBase;
    int i=0;
    char* filePart = new char[recordSize+1];
    in.read( filePart, recordSize );
    while( !in.eof() && !in.fail() )
    {
        filePart[recordSize] = '\0';
        Record r( i, filePart, recordSize );
        ll.push_back(r );
        delete [] filePart;
        whatsLeft -= recordSize;
        recordSize = rand() % 50 + fileSizeBase;
        if ( recordSize > whatsLeft )
            recordSize = whatsLeft+1;
        filePart = new char[recordSize+1];
        in.read( filePart, recordSize );
        i++;
    }
    filePart[recordSize-1] = '\0';
    ll.push_back( Record( i, filePart, recordSize-1 ));
    int totalParts = ll.size();
    bool* choosen = new bool[totalParts];
    for ( int j=0; j<totalParts; j++ )
        choosen[j] = false;
    for( int k=0; k<totalParts; k++ )
    {
        int part;
        do
        {
            part = rand() % totalParts;
        } while ( choosen[part] );
        choosen[part] = true;
        stringstream ss, ss1;
        Record r = ll[ part ];
        ss << r.getPosition();
        string number, number1;
        ss >> number;
        out.write( number.c_str(), sizeof( int ) );
        ss.str( "" );
        ss1 << r.getSize();
        ss1 >> number1;
        out.write( number1.c_str(), sizeof( int ) );
        out.write( r.getRecord(), r.getSize() );
    }
    in.close();
    out.close();

    binFile = QString::fromStdString( fileStub );

    displayFile( binFile, ui->scrambledFile );
}

void Gui::on_pushButton_released()
{
    ui->scrambledFile->clear();
    ui->descrambledFile->clear();
    createBinary( m_FileName.toStdString() , 50 );  // was 50
    ui->pushButton_2->setEnabled( true );

}

void Gui::on_pushButton_2_released()
{
    FileDescrambler descram;

    ui->descrambledFile->clear();

    ifstream myFile;
    myFile.open( binFile.toStdString().data() );

    descram.descramble( myFile );

    descram.displayFile( ui->descrambledFile, m_FileName );
}
