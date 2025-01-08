#include <raylib.h>
#include "pieces.h"
#include <iostream>

using namespace std;

#define BPURPLE (Color) {141, 0, 173, 255}
#define BYELLOW (Color) {237, 208, 0, 255}
#define BACKGROUND_COLOR (Color) {8, 8, 8, 1}
#define WINDOW_WIDTH 1100
#define WINDOW_HEIGHT 1100
#define GAME_WIDTH 1000
#define GAME_HEIGHT 1000
#define SIZE (Vector2) {GAME_WIDTH, GAME_HEIGHT}
#define OFFSET (WINDOW_WIDTH - GAME_WIDTH) / 2.0f
#define INIT_POS (Vector2) {OFFSET, OFFSET}
#define SQUARE_SIZE (Vector2) {GAME_WIDTH/8.0f, GAME_HEIGHT/8.0f}


Piece **Pieces = new Piece*[2];

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chessray");
    SetTargetFPS(1000);

    /* IMAGE LOADING */
    init_pieces(Pieces);
    Texture2D **textures;
    textures = texture_pieces(Pieces);
    unload_images(Pieces);

    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(BACKGROUND_COLOR);


        float init_y = INIT_POS.y;

        for (int i = 0; i < 8; i++) {
            float init_x = INIT_POS.x;
            for (int j = 0; j < 8; j++) {
                DrawRectangleV((Vector2) {init_x, init_y}, SQUARE_SIZE, ((i + j) % 2 == 0) ? BPURPLE : BYELLOW);
                init_x += SQUARE_SIZE.x;
            }
            init_y += SQUARE_SIZE.y;
        }

        float y = INIT_POS.y;
        for (int i = 0; i < 2; i++) {
            float x = INIT_POS.x;
            for (int j = 0; j < 6; j++) {
                DrawTextureV(textures[i][j], (Vector2) {x, y}, WHITE);
                x += SQUARE_SIZE.x;
            }
            y += SQUARE_SIZE.y;
        }


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
