#include "raylib.h"
#include <iostream>
#include <vector>

#define MAX_TOUCH_POINTS 10000

const int screenWidth = 400;
const int screenHeight = 600;

int main(void) {

  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - input multitouch");

  Vector2 touchPositions[MAX_TOUCH_POINTS] = {0};

  int randValuex = GetRandomValue(0, screenWidth);
  int randValuey = GetRandomValue(0, screenHeight);

  Vector2 test;
  test.x = randValuex;
  test.y = randValuey;
  std::vector<Vector2> stack;
  SetTargetFPS(60);

  float smo = 0.00001;

  while (!WindowShouldClose()) {
    stack.push_back(GetMousePosition());

    for (auto s : stack) {
      if (test.x >= GetMousePosition().x) {
        test.x -= s.x * smo;
      } else {
        test.x += s.x * smo;
      }

      if (test.y >= GetMousePosition().y) {
        test.y -= s.y * smo;
      } else {
        test.y += s.y * smo;
      }
    }


    if (test.y > screenHeight) {
      test.y = screenHeight - 10;
    }

    if (test.x > screenWidth) {
      test.x = screenWidth - 10;
    }
    if (test.x < 0) {
      test.x = 0;
    }

    if (test.y < 0) {
      test.y = 0;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawCircleV(test, 5, BLACK);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
