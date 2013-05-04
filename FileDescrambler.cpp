#include"Node.h"
#include"LinkedList.h"
#include"Record.h"
#include"FileDescrambler.h"


using namespace std;

FileDescrambler::FileDescrambler() : File()
{

}

void FileDescrambler::displayFile( QTextEdit* out, QString fileName )
{
    //takes file and opens
    QFile file ( fileName );
    file.open( QIODevice::ReadOnly );
    QTextStream readFile( &file );

    while( !readFile.atEnd() )
    {

        out->append( readFile.readLine() );
    }

    file.close();
}

void FileDescrambler::descramble( ifstream &in )
{
    //reads in position
    char* pos = new char [ sizeof( int ) ];
    char* size = new char [ sizeof( int ) ];
    char* msg;

    in.read(pos, sizeof( int ) );

    while( !in.eof() )
    {
        istringstream iss( pos );

        int intPos;
        iss >> intPos;

        in.read( size, sizeof( int ) );
        istringstream iss2( size );

        int intSize;
        iss2>> intSize;

        msg = new char[ intSize + 1 ];
        in.read( msg, intSize );

        msg[ intSize ] = '\0';

        Record r( intPos, msg, intSize );

        delete[]msg;

        //sorted insert
        if( File.count() == 0 )
        {
            File.insert( r );
        }

        in.read( pos, sizeof( int ) );
    }
}

int FileDescrambler::numberOfParts()
{
    return File.count();
}

void FileDescrambler::displayPart( ostream &out, int position )
{
    out<< File.itemAt( position ) << endl;

}
