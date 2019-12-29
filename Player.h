#ifndef QWERTY_WING_PLAYER_H
#define QWERTY_WING_PLAYER_H

#include <Tinyfont.h>
#include "Bullet.h"
#include "BulletVector.h"

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
    BulletVector* bullets;

    Player();
    Player(int x, int y, char spr);

    void draw(Tinyfont& tf);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void shoot();
};

#endif
