#include "game.h"
#include <raylib.h>

void draw_current_position(Pieces pieces)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            DrawTextureV(pieces[i][j].texture, (Vector2) {pieces[i][j].x, pieces[i][j].y}, WHITE);
        }
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

bool is_valid_index(int i, int j)
{
    return (i > 7 || i < 0 || j > 7 || j < 0) ? false : true;
}

int get_index(int i)
{
    i -= 50;
    return i / 125;
}

bool is_valid_piece(Piece piece)
{
    return (piece.type != EMPTY) ? true : false;
}

bool is_mouse_over_piece(int x, int y, Pieces pieces)
{
    int i = get_index(y);
    int j = get_index(x);

    if (is_valid_index(i, j) && is_valid_piece(pieces[i][j])) return true;

    return false;
}

void check_mouse_position(Pieces &pieces)
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        int mouse_x = GetMouseX();
        int mouse_y = GetMouseY();
        int i = get_index(mouse_y);
        int j = get_index(mouse_x);
        if (is_mouse_over_piece(mouse_x, mouse_y, pieces)) {
            pieces[i][j].x = mouse_x - (125/2.0f);
            pieces[i][j].y = mouse_y - (125/2.0f);
        }
    }
}
