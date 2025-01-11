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

void draw_init_position(Textures textures);
void draw_board();

#endif
