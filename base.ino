#include <Arduboy2.h>

Arduboy2 arduboy;

static const int FPS = 30;

static const int TITLE_SCREEN = 0;
static const int GAME_OVER = 1;
int gameState = TITLE_SCREEN;

void resetGame() {
  // TODO
}

void titleScreen() {
  arduboy.setCursor(0, 0);
  arduboy.println("TITLE SCREEN");
  arduboy.println();
  arduboy.println("Press A");
  if (arduboy.justPressed(A_BUTTON)) {
    gameState = GAME_OVER;
  }
}

void gameOver() {
  arduboy.setCursor(0, 0);
  arduboy.println("GAME OVER");
  arduboy.println();
  arduboy.println("Press A");
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
