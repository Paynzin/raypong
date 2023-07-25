#include <stdlib.h>
#include <stdint.h>
#include <raylib.h>
#include "utils.h"

void UpdateBallPos(GameBall *gameball)
{
  const uint8_t SPEED = 5;
  int diffY = SPEED;
  int diffX = SPEED;

  // X axis
  if (gameball->IsDiffXNegative)
  {
    if (gameball->ballShape->x >= 0)
      diffX = -diffX;
    else
      gameball->IsDiffXNegative = false;
  }
  else 
  {
    if (!(gameball->ballShape->x <= gameball->borderX - gameball->ballShape->width))
    {
      diffX = -diffX;
      gameball->IsDiffXNegative = true;
    }
  }

  // Y axis
  if (gameball->IsDiffYNegative)
  {
    if (gameball->ballShape->y >= 0)
      diffY = -diffY;
    else
      gameball->IsDiffYNegative = false;
  }
  else 
  {
    if (!(gameball->ballShape->y <= gameball->borderY - gameball->ballShape->height))
    {
      diffY = -diffY;
      gameball->IsDiffYNegative = true;
    }
  }

  gameball->ballShape->x += diffX;
  gameball->ballShape->y += diffY;
}

Controls UpdateControls()
{
  Controls racketControls;
  racketControls.LeftRacketMov = 0;
  racketControls.RightRacketMov = 0;

  // left racket 
  if (IsKeyDown(LEFT_RACKET_MOV_UP)) racketControls.LeftRacketMov = 1;
  if (IsKeyDown(LEFT_RACKET_MOV_DOWN)) racketControls.LeftRacketMov = -1;

  // right racket 
  if (IsKeyDown(RIGHT_RACKET_MOV_UP)) racketControls.RightRacketMov = 1;
  if (IsKeyDown(RIGHT_RACKET_MOV_DOWN)) racketControls.RightRacketMov = -1;

  return racketControls;
}

void UpdateRackets(Rectangle *racketLeft, Rectangle *racketRight, int borderY)
{
  const uint8_t SPEED = 7;
  Controls racketControls = UpdateControls();
  
  // left racket
  if (!(racketLeft->y > borderY - racketLeft->height))
  {
    if ((racketLeft->y < 0))
    {
      if (racketControls.LeftRacketMov > 0)
        racketLeft->y += racketControls.LeftRacketMov * SPEED;
      goto COMPUTE_RIGHT_RACKET;
    }
    racketLeft->y += racketControls.LeftRacketMov * SPEED;
  }
  else 
  {
    if (racketControls.LeftRacketMov < 0)
      racketLeft->y += racketControls.LeftRacketMov * SPEED;
  }
 
  COMPUTE_RIGHT_RACKET:
  // right racket
  if (!(racketRight->y > borderY - racketRight->height))
  {
    if ((racketRight->y < 0))
    {
      if (racketControls.RightRacketMov > 0)
        racketRight->y += racketControls.RightRacketMov * SPEED;
      return;
    }
    racketRight->y += racketControls.RightRacketMov * SPEED;
  }
  else 
  {
    if (racketControls.RightRacketMov < 0)
      racketRight->y += racketControls.RightRacketMov * SPEED;
  }
}
