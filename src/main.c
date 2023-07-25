#include <raylib.h>
#include "utils.h"

int main(void)
{
  const char *winTitle = "raypong - By Payn";
  
  InitWindow(0, 0, winTitle);
  SetTargetFPS(60);

  const int winWidth = GetScreenWidth() / 2;
  const int winHeight = GetScreenHeight() / 2;

  SetWindowSize(winWidth, winHeight);
 
  // creates the ball
  Rectangle ballShape;
  // set the ball to be a square
  const float BALL_SIZE = 15.0;
  ballShape.width = BALL_SIZE;
  ballShape.height = BALL_SIZE;
  // set the initial ball position to the center of the screen
  ballShape.x = winWidth / 2 + (ballShape.width / 2); 
  ballShape.y = winHeight / 2 + (ballShape.height / 2);
  
  // this structre contains the props of the ball in game
  GameBall gameball;
  gameball.borderX = winWidth;
  gameball.borderY = winHeight;
  gameball.IsDiffXNegative = false;
  gameball.IsDiffYNegative = false;
  gameball.ballShape = &ballShape;
 
  // creates the rackets
  Rectangle racketLeft, racketRight;
  
  const float racketsSize = 15.0;
  racketLeft.width = racketsSize * 1.5;
  racketLeft.height = racketsSize * 5.0;

  racketRight.width = racketsSize * 1.5;
  racketRight.height = racketsSize * 5.0;

  racketLeft.x = 0;
  racketLeft.y = winHeight / 2; 

  racketRight.x = winWidth - racketRight.width; 
  racketRight.y = winHeight / 2;

  // the game's main loop
  while (!WindowShouldClose()) 
  {
    BeginDrawing();
    {
      ClearBackground(BLACK);
      // draw the rackets
      DrawRectangleRec(racketLeft, RAYWHITE);
      DrawRectangleRec(racketRight, RAYWHITE);
      // draw the ball
      DrawRectangleRec(ballShape, RAYWHITE);
      // update stuff on the screen
      UpdateBallPos(&gameball);
      UpdateRackets(&racketLeft, &racketRight, winHeight);
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
