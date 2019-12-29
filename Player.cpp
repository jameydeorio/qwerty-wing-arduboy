#include <Tinyfont.h>
#include "Player.h"
#include "Bullet.h"
#include "Vector.h"

static const char DEFAULT_SPR = 'E';

void Player::init(int x, int y, char spr, int score) {
    this->x = x;
    this->y = y;
    this->spr = spr;
    this->score = score;
    this->w = 4;
    this->h = 4;
    this->speed = 1;
    this->bullets = new Vector(3);
}

Player::Player() {
    init(0, 0, DEFAULT_SPR, 0);
}

Player::Player(int x, int y, char spr) {
    init(x, y, spr, 0);
}

void Player::draw(Tinyfont& tf) {
    tf.setCursor(x, y);
    tf.print(spr);
}

void Player::moveUp() {
    y -= speed;
}

void Player::moveDown() {
    y += speed;
}

void Player::moveLeft() {
    x -= speed;
}

void Player::moveRight() {
    x += speed;
}

void Player::shoot() {
    Serial.print("SHOTTED\n");
    auto index = -1;
    for (int i = 0; i < bullets->size(); i++) {
        Bullet& b = bullets->get(i);
        if (!b.active) {
            index = i;
            break;
        }
    }
    Serial.println(index);
    if (index == -1) return;
    Bullet& b = bullets->get(index);
    b.x = x + w + 2;
    b.y = y;
    b.active = true;
}
