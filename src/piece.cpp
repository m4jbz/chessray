#include "piece.h"
#include <raylib.h>

Pieces init_pieces()
{
    Pieces pieces;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pieces[i][j] = {EMPTY, COLORLESS, LoadImage("../assets/empty.png")};
        }
    }

    /* WHITE PIECES */
    pieces[0][0] = {ROOK, W, LoadImage("../assets/white_rook.png")};
    pieces[0][1] = {KNIGHT, W, LoadImage("../assets/white_knight.png")};
    pieces[0][2] = {BISHOP, W, LoadImage("../assets/white_bishop.png")};
    pieces[0][3] = {QUEEN, W, LoadImage("../assets/white_queen.png")};
    pieces[0][4] = {KING, W, LoadImage("../assets/white_king.png")};
    pieces[0][5] = {BISHOP, W, LoadImage("../assets/white_bishop.png")};
    pieces[0][6] = {KNIGHT, W, LoadImage("../assets/white_knight.png")};
    pieces[0][7] = {ROOK, W, LoadImage("../assets/white_rook.png")};

    for (int i = 0; i < N; i++) {
        pieces[1][i] = {PAWN, W, LoadImage("../assets/white_pawn.png")};
    }

    /* BLACK PIECES */
    pieces[7][0] = {ROOK, B, LoadImage("../assets/black_rook.png")};
    pieces[7][1] = {KNIGHT, B, LoadImage("../assets/black_knight.png")};
    pieces[7][2] = {BISHOP, B, LoadImage("../assets/black_bishop.png")};
    pieces[7][3] = {QUEEN, B, LoadImage("../assets/black_queen.png")};
    pieces[7][4] = {KING, B, LoadImage("../assets/black_king.png")};
    pieces[7][5] = {BISHOP, B, LoadImage("../assets/black_bishop.png")};
    pieces[7][6] = {KNIGHT, B, LoadImage("../assets/black_knight.png")};
    pieces[7][7] = {ROOK, B, LoadImage("../assets/black_rook.png")};

    for (int i = 0; i < N; i++) {
        pieces[6][i] = {PAWN, B, LoadImage("../assets/black_pawn.png")};
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ImageResize(&pieces[i][j].image, 125, 125);
        }
    }

    return pieces;
}

Textures load_textures(Pieces pieces)
{
    Textures textures;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            textures[i][j] = LoadTextureFromImage(pieces[i][j].image);
        }
    }

    return textures;
}

void unload_images(Pieces pieces)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            UnloadImage(pieces[i][j].image);
        }
    }
}
