#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <cctype>

// #include "lib/rapidxml-1.13/rapidxml.hpp"

int main()
{
    std::ifstream openfile("Mapa.txt"); /// fichero stream lectura mapa

    sf::Texture tileTexture; /// variable donde vamos a almacenar la con todos los recursos del mapa
    sf::Sprite tiles; /// variable donde vamos a almacenar los distintos sprites

    sf::Vector2i map[100][100]; /// matriz de tiles del mapa
    sf::Vector2i loadCounter = sf::Vector2i(0, 0); /// contador para las posiciones ya leidas

    if(openfile.eof())
    {
        std::string tileLocation; /// string para almacenar el path
        openfile >> tileLocation; /// busca el archivo dentro del path indicado
        tileTexture.loadFromFile(tileLocation); /// cargamos textura
        tiles.setTexture(tileTexture); /// seteamos textura a sprite

        while(!openfile.eof()) ///
        {
            std::string str;
            openfile >> str;
            char x = str[0], y = str[2]; /// los primeros digitos que nos encontramos en el fichero, saltandonos la coma

            if(!isdigit(x) || !isdigit(y)) /// comprobamos que esos char sean un digito, si no no ponemos ningun sprite
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1); /// posicion vacia o de color de fondo
            else
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0'); /// le restamos el valor ASCII del 0 por alguna razon neonazi

            if (openfile.peek() == '\n') /// buscamos el salto de linea
            {
                loadCounter.x = 0; /// empezamos la nueva linea de
                loadCounter.y++; /// bajamos una fila dentro del loader
            }
            else /// si no hemos llegado el final de la linea aumentamos la y del loader
                loadCounter.y++;
        }

        loadCounter.y++; /// cuando acabamos de leer el fichero saltamos una linea en el loader
    }

    sf::RenderWindow window(sf::VideoMode(640, 580, 32), "Cargando tilemap desde archivo [modo noob]");

    while(window.isOpen())
    {
        sf::Event Event;
        while(window.pollEvent(Event))
        {
            switch(Event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }

            window.clear(); /// limpiamos

            for(int i = 0; i < loadCounter.y; i++)
            {
                for(int j = 0; j < loadCounter.x; j++)
                {
                    tiles.setPosition(i * 32, j * 32); /// contando con que el tile ocupe 32 px en la textura
                    tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
                    window.draw(tiles);
                }
            }

            window.display(); /// dibujamos
        }
    }
}
