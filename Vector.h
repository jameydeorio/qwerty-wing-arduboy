#ifndef QWERTY_WING_VECTOR_H
#define QWERTY_WING_VECTOR_H

#include "Bullet.h"

class Vector {
    Bullet* elem;
    int sz;
public:
    Vector(int s) :elem{new Bullet[s]}, sz{s} {};
    Bullet& operator[](int i) { return elem[i]; }
    int size() { return sz; }
};

#endif //QWERTY_WING_VECTOR_H
