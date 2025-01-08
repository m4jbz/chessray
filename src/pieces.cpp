#include "pieces.h"
#include <raylib.h>

void init_pieces(Piece **Pieces) {
    for (int i = 0; i < 2; i++) {
        Pieces[i] = new Piece[6];
    }

    Pieces[0][0].name = "pawn";
    Pieces[0][0].value = 1;
    Pieces[0][1].name = "bishop";
    Pieces[0][1].value = 3;
    Pieces[0][2].name = "knight";
    Pieces[0][2].value = 3;
    Pieces[0][3].name = "rook";
    Pieces[0][3].value = 5;
    Pieces[0][4].name = "queen";
    Pieces[0][4].value = 9;
    Pieces[0][5].name = "king";
    Pieces[0][5].value = -1;
    Pieces[0][0].image = LoadImage("assets/white_pawn.png");
    ImageResize(&Pieces[0][0].image, 125, 125);
    Pieces[0][1].image = LoadImage("assets/white_bishop.png");
    ImageResize(&Pieces[0][1].image, 125, 125);
    Pieces[0][2].image = LoadImage("assets/white_knight.png");
    ImageResize(&Pieces[0][2].image, 125, 125);
    Pieces[0][3].image = LoadImage("assets/white_rook.png");
    ImageResize(&Pieces[0][3].image, 125, 125);
    Pieces[0][4].image = LoadImage("assets/white_queen.png");
    ImageResize(&Pieces[0][4].image, 125, 125);
    Pieces[0][5].image = LoadImage("assets/white_king.png");
    ImageResize(&Pieces[0][5].image, 125, 125);
    Pieces[0][0].color = WHITE;
    Pieces[0][1].color = WHITE;
    Pieces[0][2].color = WHITE;
    Pieces[0][3].color = WHITE;
    Pieces[0][4].color = WHITE;
    Pieces[0][5].color = WHITE;

    Pieces[1][0].name = "pawn";
    Pieces[1][0].value = 1;
    Pieces[1][1].name = "bishop";
    Pieces[1][1].value = 3;
    Pieces[1][2].name = "knight";
    Pieces[1][2].value = 3;
    Pieces[1][3].name = "rook";
    Pieces[1][3].value = 5;
    Pieces[1][4].name = "queen";
    Pieces[1][4].value = 9;
    Pieces[1][5].name = "king";
    Pieces[1][5].value = -1;
    Pieces[1][0].image = LoadImage("assets/black_pawn.png");
    ImageResize(&Pieces[1][0].image, 125, 125);
    Pieces[1][1].image = LoadImage("assets/black_bishop.png");
    ImageResize(&Pieces[1][1].image, 125, 125);
    Pieces[1][2].image = LoadImage("assets/black_knight.png");
    ImageResize(&Pieces[1][2].image, 125, 125);
    Pieces[1][3].image = LoadImage("assets/black_rook.png");
    ImageResize(&Pieces[1][3].image, 125, 125);
    Pieces[1][4].image = LoadImage("assets/black_queen.png");
    ImageResize(&Pieces[1][4].image, 125, 125);
    Pieces[1][5].image = LoadImage("assets/black_king.png");
    ImageResize(&Pieces[1][5].image, 125, 125);
    Pieces[1][0].color = BLACK;
    Pieces[1][1].color = BLACK;
    Pieces[1][2].color = BLACK;
    Pieces[1][3].color = BLACK;
    Pieces[1][4].color = BLACK;
    Pieces[1][5].color = BLACK;
}

Texture2D **texture_pieces(Piece **Pieces)
{
    Texture2D **textures = new Texture2D*[2];

    for (int i = 0; i < 2; i++) {
        textures[i] = new Texture2D[6];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            Texture2D texture = LoadTextureFromImage(Pieces[i][j].image);
            textures[i][j] = texture;
        }
    }

    return textures;
    delete[] textures;
}

void unload_images(Piece **Pieces)
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            UnloadImage(Pieces[i][j].image);
        }
    }
}
