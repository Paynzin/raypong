#include <stdlib.h>
#include <stdint.h>
#include <raylib.h>

typedef struct GameBall
{
  int borderX;
  int borderY;
  bool IsDiffXNegative;
  bool IsDiffYNegative;
  Rectangle *ballShape;
} GameBall;

void UpdateBallPos(GameBall *gameball, Rectangle racketLeft, Rectangle racketRight);

typedef struct Controls
{
  int8_t LeftRacketMov;
  int8_t RightRacketMov;
} Controls;

// defines the control mappings
#define LEFT_RACKET_MOV_UP KEY_Z
#define LEFT_RACKET_MOV_DOWN KEY_X

#define RIGHT_RACKET_MOV_UP KEY_COMMA
#define RIGHT_RACKET_MOV_DOWN KEY_PERIOD

void UpdateRackets(Rectangle *racketLeft, Rectangle *racketRight, int borderY);

typedef struct Scoreboard
{
  int8_t Player1Score;
  int8_t Player2Score;
} Scoreboard;

void UpdateScore(Scoreboard *scoreboard, Rectangle ballShape, int borderX);
