#include <raylib.h>
#include "game.h"
#include "piece.h"

int main(void)
{
    Pieces pieces = init_pieces();
    bool first_move_was_made = false;

    InitWindow(WIDTH, HEIGHT, "Chessray");
    Textures textures = load_textures(pieces);
    unload_images(pieces);

    /* FPS */
    SetTargetFPS(-1);

    /* GAME LOOP */
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);

        draw_board();
        if (!first_move_was_made) draw_init_position(textures);

        EndDrawing();
    }

    CloseWindow();
}
