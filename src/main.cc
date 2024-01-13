#include "raylib.h"

#define MAX_TOUCH_POINTS 3000

int main(void) {

  const int screenWidth = 400;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - input multitouch");

  Vector2 touchPositions[MAX_TOUCH_POINTS] = {0};

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  // Custom timming variables
  double previousTime = GetTime(); // Previous time measure
  double currentTime = 0.0;        // Current time measure
  double updateDrawTime = 0.0;     // Update + Draw time
  double waitTime = 0.0;           // Wait time (if target fps required)
  float deltaTime = 0.0f;          // Frame time (Update + Draw + Wait time)

  float timeCounter = 0.0f; // Accumulative time counter (seconds)
  float position = 0.0f;    // Circle position
  bool pause = false;       // Pause control flag

  int targetFPS = 60; // Our initial target fps
  //--------------------------------------------------------------------------------------
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {

    // Update
    //----------------------------------------------------------------------------------
    PollInputEvents(); // Poll input events (SUPPORT_CUSTOM_FRAME_CONTROL)

    if (IsKeyPressed(KEY_SPACE))
      pause = !pause;

    if (IsKeyPressed(KEY_UP))
      targetFPS += 20;
    else if (IsKeyPressed(KEY_DOWN))
      targetFPS -= 20;

    if (targetFPS < 0)
      targetFPS = 0;

    if (!pause) {
      position += 200 * deltaTime; // We move at 200 pixels per second
      if (position >= GetScreenWidth())
        position = 0;
      timeCounter += deltaTime; // We count time (seconds)
    }

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


     DrawCircle((int)position, GetScreenHeight() / 2 - 25, 50, RED);
    //DrawCircleV(mousePosition, 1.5, BLACK);

    EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
