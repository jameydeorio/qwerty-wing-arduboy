#include <Arduboy2.h>
#include <Tinyfont.h>
#include "Player.h"
#include "Vector.h"

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

static const int FPS = 30;

static const int TITLE_SCREEN = 0;
static const int GAME_PLAY = 1;
static const int GAME_OVER = 2;
int gameState = GAME_PLAY;

Player player = Player::Player();
Vector bullets(3);

void resetGame() {
    player = Player::Player(0, arduboy.height() / 2, 'E');
}

void titleScreen() {
    tinyfont.setCursor(0, 0);
    tinyfont.println("TITLE SCREEN");
    tinyfont.println();
    tinyfont.println("Press A");
    if (arduboy.justPressed(A_BUTTON)) {
        gameState = GAME_PLAY;
    }
}

void gamePlay() {
    //
    // input
    //
    if (arduboy.pressed(UP_BUTTON) && player.y > 0) {
        player.moveUp();
    }
    if (arduboy.pressed(DOWN_BUTTON) && player.y + player.h < arduboy.height()) {
        player.moveDown();
    }
    if (arduboy.pressed(LEFT_BUTTON) && player.x > 0) {
        player.moveLeft();
    }
    if (arduboy.pressed(RIGHT_BUTTON) && player.x + player.w < arduboy.width()) {
        player.moveRight();
    }
    if (arduboy.justPressed(A_BUTTON)) {
        player.shoot(bullets);
    }

    //
    // movement
    //

    // bullets
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].active) {
            bullets[i].x += bullets[i].speed;
        }
        if (bullets[i].x > arduboy.width() + 10) {
            bullets[i].reset();
        }
    }

    //
    // collision
    //

    //
    // draw
    //

    // bullets
    arduboy.setCursor(0, 0);
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].active) {
            bullets[i].draw(tinyfont);
        }
    }

    // player
    player.draw(tinyfont);
}

void gameOver() {
    tinyfont.setCursor(0, 0);
    tinyfont.println("GAME OVER");
    tinyfont.println();
    tinyfont.println("Press A");
    if (arduboy.justPressed(A_BUTTON)) {
        gameState = TITLE_SCREEN;
    }
}

void gameLoop() {
    switch(gameState) {
        case TITLE_SCREEN:
        {
            titleScreen();
            break;
        }

        case GAME_PLAY:
        {
            gamePlay();
            break;
        }

        case GAME_OVER:
        {
            gameOver();
            break;
        }
    }
}

void setup() {
//    arduboy.boot();
    arduboy.begin();
    arduboy.setFrameRate(FPS);
    arduboy.initRandomSeed();
    resetGame();
}

void loop() {
    if (!(arduboy.nextFrame())) return;
    arduboy.pollButtons();
    arduboy.clear();
    gameLoop();
    arduboy.display();
}
