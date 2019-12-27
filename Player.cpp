#include <Tinyfont.h>
#include "Player.h"

static const char DEFAULT_SPR = 'W';

void Player::init(int x, int y, char spr, int score) {
    this->x = x;
    this->y = y;
    this->spr = spr;
    this->score = score;
    this->w = 4;
    this->h = 4;
    this->speed = 1;
}

Player::Player() {
    init(0, 0, DEFAULT_SPR, 0);
}

Player::Player(int x, int y, char spr) {
    init(x, y, spr, 0);
}

Player::Player(int x, int y, char spr, int score) {
    init(x, y, spr, score);
}

void Player::draw(Tinyfont *tf) {
    tf->setCursor(this->x, this->y);
    tf->print(this->spr);
}

void Player::moveUp() {
    this->y -= this->speed;
}

void Player::moveDown() {
    this->y += this->speed;
}

void Player::moveLeft() {
    this->x -= this->speed;
}

void Player::moveRight() {
    this->x += this->speed;
}