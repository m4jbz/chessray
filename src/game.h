#ifndef GAME_H
#define GAME_H

#include "piece.h"
#include <raylib.h>

#define N 8
#define MY_PURPLE (Color) {167, 0, 237, 255}
#define MY_YELLOW (Color) {255, 229, 9, 255}
#define SIZE (Vector2) {125, 125}
#define WIDTH 1100
#define HEIGHT 1100

void draw_current_position(Pieces pieces);
void draw_board();
bool is_mouse_over_piece(int x, int y, Pieces pieces);
void check_mouse_position(Pieces &pieces);

#endif
