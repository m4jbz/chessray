#include "game.h"
#include <raylib.h>

void draw_init_position(Textures textures)
{
    float y = 50.0f;

    for (int i = 0; i < N; i++) {
        float x = 50.0f;
        for (int j = 0; j < N; j++) {
            DrawTextureV(textures[i][j], (Vector2) {x, y}, WHITE);
            x += 125.0f;
        }
        y += 125.0f;
    }
}

void draw_board()
{
    float y = 50.0f;

    for (int i = 0; i < N; i++) {
        float x = 50.0f;
        for (int j = 0; j < N; j++) {
            DrawRectangleV((Vector2) {x, y}, SIZE, (i+j) % 2 == 0 ? MY_PURPLE : MY_YELLOW);
            x += 125.0f;
        }
        y += 125.0f;
    }
}
