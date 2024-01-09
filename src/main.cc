#include "../build/_deps/raylib-src/src/raylib.h"
#include "../build/_deps/raylib-src/src/rlgl.h"
#include <ctime>

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION 330
#else // PLATFORM_ANDROID, PLATFORM_WEB
#define GLSL_VERSION 100
#endif

int main() {

  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight,
             "raylib [shaders] example - hot reloading");

  const char *fragShaderFileName = "resources/shaders/glsl%i/reload.fs";
  time_t fragShaderFileModTime =
      GetFileModTime(TextFormat(fragShaderFileName, GLSL_VERSION));

  Shader shader = LoadShader(0, TextFormat(fragShaderFileName, GLSL_VERSION));

  int resolutionLoc = GetShaderLocation(shader, "resolution");
  int mouseLoc = GetShaderLocation(shader, "mouse");
  int timeLoc = GetShaderLocation(shader, "time");

  float resolution[2] = {(float)screenWidth, (float)screenHeight};
  SetShaderValue(shader, resolutionLoc, resolution, SHADER_UNIFORM_VEC2);

  float totalTime = 0.0f;
  bool shaderAutoReloading = false;

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    totalTime += GetFrameTime();
    Vector2 mouse = GetMousePosition();
    float mousePos[2] = {mouse.x, mouse.y};

    SetShaderValue(shader, timeLoc, &totalTime, SHADER_UNIFORM_FLOAT);
    SetShaderValue(shader, mouseLoc, mousePos, SHADER_UNIFORM_VEC2);

    if (shaderAutoReloading || (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
      long currentFragShaderModTime =
          GetFileModTime(TextFormat(fragShaderFileName, GLSL_VERSION));

      if (currentFragShaderModTime != fragShaderFileModTime) {
        Shader updatedShader =
            LoadShader(0, TextFormat(fragShaderFileName, GLSL_VERSION));

        if (updatedShader.id !=
            rlGetShaderIdDefault()) // It was correctly loaded
        {
          UnloadShader(shader);
          shader = updatedShader;

          resolutionLoc = GetShaderLocation(shader, "resolution");
          mouseLoc = GetShaderLocation(shader, "mouse");
          timeLoc = GetShaderLocation(shader, "time");

          SetShaderValue(shader, resolutionLoc, resolution,
                         SHADER_UNIFORM_VEC2);
        }

        fragShaderFileModTime = currentFragShaderModTime;
      }
    }

    if (IsKeyPressed(KEY_A))
      shaderAutoReloading = !shaderAutoReloading;

    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginShaderMode(shader);
    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
    EndShaderMode();

    EndDrawing();
  }

  UnloadShader(shader); // Unload shader

  CloseWindow(); // Close window and OpenGL context

  return 0;
}
