#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace sf;

int main()
{
    RenderWindow app(VideoMode(720,720), "15-Puzzle!");
    app.setFramerateLimit(60);

    Texture t;
    t.loadFromFile("15.png");

    int w = 180;
    int grid[6][6] = {0};
    Sprite sprite[17];

    int n=0;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
        {
            n++;
            sprite[n].setTexture(t);
            sprite[n].setTextureRect( IntRect(i*w,j*w,w,w) );
            grid[i+1][j+1]=n;
            std::cout<<spriteс<<std::endl;
        }
    for (int i = 1; i < 15; ++i)
        std::swap(sprite[i], sprite[std::rand() % 15]);


    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();

            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left)
                {
                    Vector2i pos = Mouse::getPosition(app);
                    int x = pos.x/w + 1;
                    int y = pos.y/w + 1;

                    int dx=0;
                    int dy=0;

                    if (grid[x+1][y]==16) {dx=1; dy=0;};
                    if (grid[x][y+1]==16) {dx=0; dy=1;};
                    if (grid[x][y-1]==16) {dx=0; dy=-1;};
                    if (grid[x-1][y]==16) {dx=-1;dy=0;};

                    int n = grid[x][y];
                    grid[x][y] = 16;
                    grid[x+dx][y+dy] = n;

                }

        }

        app.clear(Color::White);
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
            {
                int n = grid[i+1][j+1];
                sprite[n].setPosition(i*w,j*w);
                app.draw(sprite[n]);
            }
        app.display();

    }

    return 0;
}