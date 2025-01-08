#ifndef PIECES_H
#define PIECES_H

#include <raylib.h>
#include <iostream>

using namespace std;

typedef struct {
    Image image;
    int value;
    string name;
    Color color;
} Piece;

void init_pieces(Piece **Pieces);
Texture2D **texture_pieces(Piece **Pieces);
void unload_images(Piece **Pieces);

#endif
