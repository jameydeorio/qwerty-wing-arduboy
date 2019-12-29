#ifndef QWERTY_WING_BULLET_VECTOR_H
#define QWERTY_WING_BULLET_VECTOR_H

#include "Bullet.h"

class BulletVector {
    Bullet* elem;
    int sz;
public:
    BulletVector(int s) :elem{new Bullet[s]}, sz{s} {};
    Bullet& operator[](int i) { return elem[i]; }
    Bullet& get(int i) { return elem[i]; }
    int size() { return sz; }
};

#endif //QWERTY_WING_BULLET_VECTOR_H
