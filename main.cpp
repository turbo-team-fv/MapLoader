#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

#include "include/TMXParser.h"

using namespace std;

// #include "lib/rapidxml-1.13/rapidxml.hpp"

int main()
{
    /// objeto TMXparser
    // TMX::Parser tmx;
    //tmx.load( "desert.tmx" );

    /// Lectura de fichero
    streampos size; // flag
    char * memblock; // blocke de memoria
    ifstream file ("assets/PaPablo2.tmx", ios::in|ios::binary|ios::ate); // fstream

    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char [size];
        file.seekg(0, ios::beg);
        file.read(memblock, size);
        file.close();

        cout << "Archivo leido correctamente";
    }

    else cout << "Unable to open de file;";

    return 0;
}
