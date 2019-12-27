#include <Arduboy2.h>
#include <Tinyfont.h>
#include "Player.h"

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

static const int FPS = 30;

static const int TITLE_SCREEN = 0;
static const int GAME_PLAY = 1;
static const int GAME_OVER = 2;
int gameState = GAME_PLAY;

Player player = Player::Player();

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

  //
  // movement
  //

  //
  // collision
  //

  //
  // draw
  //

  player.draw(&tinyfont);

  if (arduboy.justPressed(A_BUTTON)) {
    gameState = GAME_OVER;
  }
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
