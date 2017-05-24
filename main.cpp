#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
int const WINDOW_W = 720;
int const WINDOW_H = 720;

using namespace sf;

int main(){
    RenderWindow app(VideoMode(WINDOW_W,WINDOW_H), "15-Puzzle!", sf::Style::Titlebar | sf::Style::Close);
    app.setFramerateLimit(60);
//типо main.hpp, ибо он просто не работает
int n=0;
int day=1;
int check=1;
int scene=1;
int pos[6][6];
int w = 180;
int grid[6][6] = {0};
int a[16];
int sum=0;
Sprite *image_index;
Texture *image_texture;
Sprite sprite[17];
Texture t;
Font* font;
Text* text;
Text* end_game;
//конец main.hpp

    t.loadFromFile("resources/15.png");
    image_texture = new sf::Texture;
    image_texture->loadFromFile("resources/15_end.png");

    image_index = new Sprite(*image_texture);
    image_index->setTexture(*image_texture);

    font = new sf::Font;
    font->loadFromFile("resources/SF-Light.otf");

    end_game = new sf::Text(L"You won this game",*font,75);
    end_game->setPosition(60, 232);
    end_game->setColor(sf::Color(0, 0, 0));


    for (int j=0;j<4;j++){
        for (int i=0;i<4;i++){
            n++;
            pos[i+1][j+1]=n;
            sprite[n].setTexture(t);
            sprite[n].setTextureRect( IntRect(i*w,j*w,w,w) );
            grid[i+1][j+1]=n;
        }
    }
    srand(time(0));
    for (int j=0;j<4;j++){
        for (int i=0;i<4;i++){
            if(i!=3 && j!=3)std::swap(grid[i+1][j+1], grid[1+rand()%4][1+rand()%4]);
        }
    }
    for (int j=0;j<4;j++){
        for (int i=0;i<4;i++){
          std::cout<<grid[i+1][j+1]<<"  ";
          a[sum]=grid[i+1][j+1];
          sum++;
        }
    }


    int inv = 0;                          //проверка на решение
    for (int i=0; i<16; ++i)
    	if (a[i])
    		for (int j=0; j<i; ++j)
    			if (a[j] > a[i])
    				++inv;
    for (int i=0; i<16; ++i)
    	if (a[i] == 0)
    		inv += 1 + i / 4;

    std::cout<< ((inv & 1) ? "Решения нет!" : "Решение есть!")<<std::endl;

    if (inv & 1){
      std::swap(grid[1][2], grid[2][2]);    //делаем решаемой
      sum=0;
      for (int j=0;j<4;j++){
          for (int i=0;i<4;i++){
            std::cout<<grid[i+1][j+1]<<"  ";
            a[sum]=grid[i+1][j+1];
            sum++;
          }
      }
      std::cout<<std::endl<<"Ты не решишь это, сейчас поправим."<<std::endl;
      inv = 0;
      for (int i=0; i<16; ++i)
        if (a[i])
          for (int j=0; j<i; ++j)
            if (a[j] > a[i])
              ++inv;
      for (int i=0; i<16; ++i)
        if (a[i] == 0)
          inv += 1 + i / 4;

      std::cout<< ((inv & 1) ? "Решения нет!" : "Поправил, проверяй!")<<std::endl;
    }



    while (app.isOpen()){
        Event event;
        while (app.pollEvent(event)){
            if (event.type == Event::Closed)
                app.close();
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            app.close();
            }

            if (event.type == Event::MouseButtonPressed){
                if (event.key.code == Mouse::Left){
                    Vector2i pos = Mouse::getPosition(app);
                    int x = pos.x/w + 1;
                    int y = pos.y/w + 1;

                    if(grid[x+1][y]==16){std::swap(grid[x][y], grid[x+1][y]);}
                    if(grid[x-1][y]==16){std::swap(grid[x][y], grid[x-1][y]);}
                    if(grid[x][y-1]==16){std::swap(grid[x][y], grid[x][y-1]);}
                    if(grid[x][y+1]==16){std::swap(grid[x][y], grid[x][y+1]);}

                  }
                }
              }
//win
        day=1;
        check=0;
        for (int j=0;j<4;j++){
            for (int i=0;i<4;i++){
                if(grid[i+1][j+1]==day){check++;}
                day++;
            }
        }
        if(check==16){scene=2;}
//
        app.clear(Color::White);
        if(scene==1){
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++){
                int n = grid[i+1][j+1];
                sprite[n].setPosition(i*w,j*w);
                app.draw(sprite[n]);
            }
        }
        if(scene==2){
            app.draw(*image_index);
            app.draw(*end_game);
        }
        app.display();
    }

    return 0;
}
