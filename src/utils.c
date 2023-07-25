#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "utils.h"

void UpdateBallPos(GameBall *gameball)
{
  const int SPEED = 5;
  int diffY = SPEED;
  int diffX = SPEED;

  // X axis
  if (gameball->IsDiffXNegative)
  {
    if (gameball->ballShape->x > 0)
      diffX = -diffX;
    else
      gameball->IsDiffXNegative = false;
  }
  else 
  {
    if (!(gameball->ballShape->x < gameball->borderX))
    {
      diffX = -diffX;
      gameball->IsDiffXNegative = true;
    }
  }
  
  // Y axis
  if (gameball->IsDiffYNegative)
  {
    if (gameball->ballShape->y > 0)
      diffY = -diffY;
    else
      gameball->IsDiffYNegative = false;
  }
  else 
  {
    if (!(gameball->ballShape->y < gameball->borderY))
    {
      diffY = -diffY;
      gameball->IsDiffYNegative = true;
    }
  }

  gameball->ballShape->x += diffX;
  gameball->ballShape->y += diffY;
}
