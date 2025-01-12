#include <raylib.h>
#include "game.h"
#include "piece.h"
#include <stdio.h>

int main(void)
{
    Pieces pieces = init_pieces();

    InitWindow(WIDTH, HEIGHT, "Chessray");
    pieces = load_textures(pieces);
    unload_images(pieces);

    /* FPS */
    SetTargetFPS(-1);

    /* GAME LOOP */
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);

        draw_board();
        draw_current_position(pieces);
        check_mouse_position(pieces);

        EndDrawing();
    }

    CloseWindow();
}
