#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace sf;

int main()
{
    int day=1;
    int check=1;
    int pos[6][6];
    RenderWindow app(VideoMode(720,720), "15-Puzzle!");
    app.setFramerateLimit(60);

    Texture t;
    t.loadFromFile("15.png");

    int w = 180;
    int grid[6][6] = {0};
    Sprite sprite[17];

    int n=0;
    for (int j=0;j<4;j++)
        for (int i=0;i<4;i++){

            n++;
            pos[i+1][j+1]=n;
            sprite[n].setTexture(t);
            sprite[n].setTextureRect( IntRect(i*w,j*w,w,w) );
            grid[i+1][j+1]=n;


        }

    while (app.isOpen()){
        Event e;
        while (app.pollEvent(e)){
            if (e.type == Event::Closed)
                app.close();

            if (e.type == Event::MouseButtonPressed){
                if (e.key.code == Mouse::Left){
                    Vector2i pos = Mouse::getPosition(app);
                    int x = pos.x/w + 1;
                    int y = pos.y/w + 1;

                    if(grid[x+1][y]==16){std::swap(grid[x][y], grid[x+1][y]);std::cout << grid[x+1][y] << '\n';}
                    if(grid[x-1][y]==16){std::swap(grid[x][y], grid[x-1][y]);std::cout << grid[x-1][y] << '\n';}
                    if(grid[x][y-1]==16){std::swap(grid[x][y], grid[x][y-1]);std::cout << grid[x][y-1] << '\n';}
                    if(grid[x][y+1]==16){std::swap(grid[x][y], grid[x][y+1]);std::cout << grid[x][y+1] << '\n';}

                  }
                }
              }
//win
        day=1;
        check=1;
        for (int j=0;j<4;j++){
          for (int i=0;i<4;i++){
            if(grid[i+1][j+1]==day){check++;}
            std::cout<<grid[i+1][j+1]<<" ";
            day++;

          }
        }
        if(check==16){std::cout<<check;}
//
        app.clear(Color::White);
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++){
                int n = grid[i+1][j+1];
                sprite[n].setPosition(i*w,j*w);
                app.draw(sprite[n]);
            }
        app.display();
    }

    return 0;
}
