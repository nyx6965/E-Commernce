#include "raylib.h"
#include <deque>

#define MAX_TOUCH_POINTS 10000

int main(void) {

  std::deque<Vector2> d;

  const int screenWidth = 400;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - input multitouch");

  Vector2 touchPositions[MAX_TOUCH_POINTS] = {0};

  Vector2 test;
  SetTargetFPS(60);

  /*
  for (int i = 0; i < MAX_TOUCH_POINTS; ++i) {
    touchPositions[i].x = (int)GetRandomValue(0, screenWidth);
    touchPositions[i].y = (int)GetRandomValue(0, screenHeight);
  }
  */

  float smo = 0.001;

  while (!WindowShouldClose()) {

    Vector2 mouse_pos = GetMousePosition();
    test = mouse_pos;
    d.push_back(mouse_pos);
    BeginDrawing();
    ClearBackground(RAYWHITE);

    /*
     for (int i = 0; i < MAX_TOUCH_POINTS; ++i) {

       }

      */
    if ((test.x > 0) && (test.y > 0)) {
      // DrawCircleV(mousePosition, 1.5, BLACK);
    }

      DrawCircleV(test, 5, BLACK);

    // DrawCircle((int)position, GetScreenHeight() / 2 - 25, 50, RED);

    EndDrawing();
  }
  CloseWindow(); // Close window and OpenGL context
  return 0;
}
