#ifndef BULLET_H
#define BULLET_H

#include <Tinyfont.h>

class Bullet
{
    void init(int x, int y, char spr);

    public:

    int x;
    int y;
    char spr;
    int speed;
    bool active;

    Bullet();
    Bullet(int x, int y);
    Bullet(int x, int y, char spr);
    void move();
    void draw(Tinyfont& tf);
    void reset();
};

#endif