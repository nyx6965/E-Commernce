#include "raylib.h"

#define MAX_TOUCH_POINTS 3000

int main(void) {

  const int screenWidth = 400;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - input multitouch");

  Vector2 touchPositions[MAX_TOUCH_POINTS] = {0};

  SetTargetFPS(60);

  for (int i = 0; i < 10; ++i) {
    touchPositions[i].x = (int)GetRandomValue(0, screenWidth);
    touchPositions[i].y = (int)GetRandomValue(0, screenHeight);
  }

  Vector2 current_positon = GetMousePosition();
  while (!WindowShouldClose()) {

    Vector2 new_pos;
    new_pos.x = GetMousePosition().x - current_positon.x;
    new_pos.y = GetMousePosition().y - current_positon.y;

    for (int i = 0; i < 10; ++i) {
      touchPositions[i].x += new_pos.x;
      touchPositions[i].y += new_pos.y;
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int i = 0; i < 10; ++i) {
      if ((touchPositions[i].x > 0) && (touchPositions[i].y > 0)) {
        DrawCircleV(touchPositions[i], 10, BLACK);
        // DrawCircleV(mousePosition, 1.5, BLACK);
      }
    }

    // DrawCircle((int)position, GetScreenHeight() / 2 - 25, 50, RED);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
