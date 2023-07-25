#include <stdlib.h>
#include <raylib.h>

typedef struct GameBall
{
  int borderX;
  int borderY;
  bool IsDiffXNegative;
  bool IsDiffYNegative;
  Rectangle *ballShape;
} GameBall;

void UpdateBallPos(GameBall *gameball);
