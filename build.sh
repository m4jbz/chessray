#!/bin/sh

set -xe

g++ -o bin/chessray src/main.cpp src/game.cpp src/piece.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -Wall
