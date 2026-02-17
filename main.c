#include "include/raylib.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;
  // SetTraceLogLevel(LOG_NONE);
  InitWindow(screenWidth, screenHeight, "raylib basic window");
  SetTargetFPS(60);

  Image img = {0};
  int width = 160;
  int height = 60;
  int bytes_per_pixel = 4;
  img.data = malloc(width * height * bytes_per_pixel);
  
  printf("width %d height %d\n", img.width, img.height);
  img.width = width;
  img.height = height;
  img.mipmaps = 1;
  img.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;

  unsigned char *pixels = (unsigned char*) img.data;

  for(int h = 0; h < height; h++)
  {
    for(int w = 0; w < width; w++)
    {
      int r_index = h * width * 4 + w * 4 + 0;
      int g_index = h * width * 4 + w * 4 + 1;
      int b_index = h * width * 4 + w * 4 + 2;
      int a_index = h * width * 4 + w * 4 + 3;
      pixels[r_index] = 255;
      pixels[g_index] = 0;
      pixels[b_index] = 0;
      pixels[a_index] = 255;
      // printf("line %d\n", r_index);
      // printf("line %d\n", g_index);
      // printf("line %d\n", b_index);
      // printf("line %d\n", a_index);
      // printf("new line\n\n");
    }
  }

  Texture2D texture = LoadTextureFromImage(img);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(texture, 0, 0, WHITE);
    DrawText("It works!", 20, 20, 20, BLACK);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}

//gcc -o hello.exe hello.c -I include -L lib -lraylib -lgdi32 -lwinmm
// gcc -o hello.exe hello.c -I include -L lib -lraylib -lgdi32 -lwinmm -O3 -DNDEBUG -s -flto -mwindows

