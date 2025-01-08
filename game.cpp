#include <iostream>
#include <raylib.h>
#include <vector>

using namespace std;

#define BORDER_COLOR (Color) {230, 230, 230, 255}
#define WINDOW_WIDTH 1100
#define WINDOW_HEIGHT 1100
#define GAME_WIDTH 1000
#define GAME_HEIGHT 1000
#define SIZE (Vector2) {GAME_WIDTH, GAME_HEIGHT}
#define OFFSET (WINDOW_WIDTH - GAME_WIDTH) / 2.0f
#define INIT_POS (Vector2) {OFFSET, OFFSET}
#define SQUARE_SIZE (Vector2) {GAME_WIDTH/8.0f, GAME_HEIGHT/8.0f}

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chessray");
    SetTargetFPS(1000);

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(BORDER_COLOR);

        float init_y = INIT_POS.y;

        for (int i = 0; i < 8; i++) {
            float init_x = INIT_POS.x;
            for (int j = 0; j < 8; j++) {
                DrawRectangleV((Vector2) {init_x, init_y}, SQUARE_SIZE, ((i + j) % 2 == 0) ? PURPLE : YELLOW);
                init_x += SQUARE_SIZE.x;
            }
            init_y += SQUARE_SIZE.y;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
