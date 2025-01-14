# Compiler and flags
CXX = g++
CXXFLAGS = -Wall

# Source files and output
SRCDIR = src
BINDIR = bin
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/game.cpp $(SRCDIR)/piece.cpp
TARGET = chessray

# Raylib paths for Windows
RAYLIB_DIR_WIN = C:/raylib/raylib
RAYLIB_INCLUDE_WIN = $(RAYLIB_DIR_WIN)/src
RAYLIB_LIB_WIN = $(RAYLIB_DIR_WIN)/src

# Libraries
LIBS_LINUX = -lraylib -lGL -lm -lpthread -ldl -lrt
LIBS_WIN = -lraylib -lopengl32 -lgdi32 -lwinmm

# Detect platform
ifeq ($(OS),Windows_NT)
    PLATFORM = Windows
else
    PLATFORM = Linux
endif

# Build rules
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(SOURCES)
	@mkdir -p $(BINDIR)
ifeq ($(PLATFORM),Windows)
	$(CXX) -o $@ $^ -I$(RAYLIB_INCLUDE_WIN) -L$(RAYLIB_LIB_WIN) $(LIBS_WIN)
else
	$(CXX) -o $@ $^ $(LIBS_LINUX)
endif

clean:
	rm -rf $(BINDIR)/*

.PHONY: all clean
