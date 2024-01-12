#include "raylib.h"

#define MAX_TOUCH_POINTS 3000

int main(void) {

  const int screenWidth = 400;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - input multitouch");

  Vector2 touchPositions[MAX_TOUCH_POINTS] = {0};

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {

    BeginDrawing();

    /*
    for (int i = 0; i < 2000; ++i){
      touchPositions[i].x = (int)GetRandomValue(0, screenWidth);
      touchPositions[i].y = (int)GetRandomValue(0, screenHeight);
    }
    */

    ClearBackground(RAYWHITE);

    /*
    for (int i = 0; i < 2000; ++i) {
      if ((touchPositions[i].x > 0) && (touchPositions[i].y > 0)) {
        DrawCircleV(touchPositions[i], 1.5,BLACK );
      }
    }
    */
    // Get the mouse position
    Vector2 mousePosition = GetMousePosition();

    DrawCircleV(mousePosition, 1.5, BLACK);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
