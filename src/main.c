#ifdef _WIN32
#include <windef.h>
#endif
#include <raylib.h>
#include "utils.h"

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main(void)
#endif
{
  const char *winTitle = "raypong - By Payn";
  
  InitWindow(0, 0, winTitle);
  SetTargetFPS(60);

  const int winWidth = GetScreenWidth() / 2;
  const int winHeight = GetScreenHeight() / 2;
  
  SetWindowPosition(winWidth - (winWidth / 2), winHeight - (winHeight / 2));
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

  // create the scoreboard
  Scoreboard scoreboard;
  scoreboard.Player1Score = 0;
  scoreboard.Player2Score = 0;

  // the game's main loop
  while (!WindowShouldClose()) 
  {
    // update stuff on the screen
    UpdateScore(&scoreboard, ballShape, winWidth);
    UpdateRackets(&racketLeft, &racketRight, winHeight);
    UpdateBallPos(&gameball, racketLeft, racketRight);
    // start drawing things
    BeginDrawing();
    {
      ClearBackground(BLACK);
      // draw the score
      char *score = TextFormat("%02i | %02i", scoreboard.Player1Score, scoreboard.Player2Score);
      DrawText(score, winWidth / 2 - (MeasureText(score, 40) / 2), (int)(winHeight * 0.3), 40, RAYWHITE);
      // draw the ball
      DrawRectangleRec(ballShape, RAYWHITE);
      // draw the rackets
      DrawRectangleRec(racketLeft, RAYWHITE);
      DrawRectangleRec(racketRight, RAYWHITE);
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
