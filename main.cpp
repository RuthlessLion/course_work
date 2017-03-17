#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    float posx = 0,posy = 0;
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")){
        std::cout << "Error load font"<<std::endl;}
    sf::Text text;
    text.setFont(font);
    text.setString("Hello");
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);





    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::CircleShape m_radius(200);
    window.setFramerateLimit(60);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if (posy > 0){
                posy--;}
            std::cout<<"up"<<posy<<std::endl;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if (posy < 573){
                posy++;}
            std::cout<<"up"<<posy<<std::endl;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if (posx > 0){
                posx--;}
            std::cout<<"up"<<posx<<std::endl;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if (posx < 538){
                posx++;}
            std::cout<<"up"<<posx<<std::endl;}

        text.setPosition ( posx , posy ) ;


        window.draw(text);
        window.display();
        window.clear();
    }

    return 0;
}
