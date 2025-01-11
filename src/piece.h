#ifndef PIECE_H
#define PIECE_H

#include <raylib.h>
#include <array>
#include <iostream>

using namespace std;

#define N 8

enum PieceType {
    EMPTY,
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING
};

enum PieceColor {
    COLORLESS,
    W,
    B
};

struct Piece {
    PieceType type;
    PieceColor color;
    Image image;
};

using Pieces = array<array<Piece, N>, N>;
using Textures = array<array<Texture2D, N>, N>;

Pieces init_pieces();
Textures load_textures(Pieces pieces);
void unload_images(Pieces pieces);

#endif
