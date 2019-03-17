#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

#include "TMXParser.h"


// #include "lib/rapidxml-1.13/rapidxml.hpp"

int main()
{
    // objeto TMXparser
    TMX::Parser tmx;
    tmx.load("assets/PaPablo.tmx");


    // cout << "Map Version: " << tmx.mapInfo.version << endl;

    return 0;
}
