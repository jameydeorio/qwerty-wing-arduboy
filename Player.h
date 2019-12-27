#include <Tinyfont.h>

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    char spr;
    int score;

    void init(int x, int y, char spr, int score);

public:
    int x;
    int y;
    int w;
    int h;
    int speed;

    Player();
    Player(int x, int y, char spr);
    Player(int x, int y, char spr, int score);

    void draw(Tinyfont *tf);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif