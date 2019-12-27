#include <Tinyfont.h>
#include "Bullet.h"

static const int DEAD_LOCATION = -50;

void Bullet::init(int x, int y, char spr) {
    this->x = x;
    this->y = y;
    this->spr = spr;
    this->speed = 3;
    this->active = false;
}

Bullet::Bullet() {
    init(DEAD_LOCATION, DEAD_LOCATION, '-');
}

Bullet::Bullet(int x, int y) {
    init(x, y, '-');
}

Bullet::Bullet(int x, int y, char spr) {
    init(x, y, spr);
}

void Bullet::move() {
    x += speed;
}

void Bullet::draw(Tinyfont& tf) {
    tf.setCursor(x, y);
    tf.print(spr);
}

void Bullet::reset() {
    x = DEAD_LOCATION;
    y = DEAD_LOCATION;
    active = false;
}