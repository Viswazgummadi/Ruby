#include "RubiksCube1DArray.h"
#include <utility> // for std::swap

// Helper to map 3D coordinates to a 1D index.
int RubiksCube1DArray::getIndex(Face face, unsigned int row, unsigned int col) const
{
    return static_cast<int>(face) * 9 + row * 3 + col;
}

// Constructor: Initializes the 1D grid to a solved state.
RubiksCube1DArray::RubiksCube1DArray()
{
    for (int i = 0; i < 54; i++)
    {
        grid[i] = static_cast<Color>(i / 9);
    }
}

// getColor is now a simple lookup using our helper function.
RubiksCube::Color RubiksCube1DArray::getColor(Face face, unsigned int row, unsigned int col) const
{
    return grid[getIndex(face, row, col)];
}

bool RubiksCube1DArray::isSolved() const
{
    for (int i = 0; i < 54; i++)
    {
        if (grid[i] != static_cast<Color>(i / 9))
        {
            return false;
        }
    }
    return true;
}

// Rotates the stickers on a face clockwise using the 1D indices.
void RubiksCube1DArray::rotateFace(int face_idx)
{
    int base_idx = face_idx * 9;
    Color temp_face[9];
    for (int i = 0; i < 9; i++)
    {
        temp_face[i] = grid[base_idx + i];
    }
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            grid[base_idx + r * 3 + c] = temp_face[(2 - c) * 3 + r];
        }
    }

}

void RubiksCube1DArray::u()
{
    rotateFace(static_cast<int>(Face::UP));

    // Indices for the top rows of FRONT, LEFT, BACK, RIGHT
    int sides[] = {
        static_cast<int>(Face::FRONT),
        static_cast<int>(Face::LEFT),
        static_cast<int>(Face::BACK),
        static_cast<int>(Face::RIGHT)};

    // Cycle the 3 stickers on the top rows
    for (int i = 0; i < 3; i++)
    {
        Color temp = grid[getIndex(static_cast<Face>(sides[0]), 0, i)];
        grid[getIndex(static_cast<Face>(sides[0]), 0, i)] = grid[getIndex(static_cast<Face>(sides[3]), 0, i)];
        grid[getIndex(static_cast<Face>(sides[3]), 0, i)] = grid[getIndex(static_cast<Face>(sides[2]), 0, i)];
        grid[getIndex(static_cast<Face>(sides[2]), 0, i)] = grid[getIndex(static_cast<Face>(sides[1]), 0, i)];
        grid[getIndex(static_cast<Face>(sides[1]), 0, i)] = temp;
    }
}

void RubiksCube1DArray::uPrime()
{
    u();
    u();
    u();
}
void RubiksCube1DArray::u2()
{
    u();
    u();
}

void RubiksCube1DArray::l()
{
    rotateFace(static_cast<int>(Face::LEFT));

    Color temp[3];
    for (int i = 0; i < 3; i++)
        temp[i] = grid[getIndex(Face::UP, i, 0)]; // Store Up

    // Back -> Up
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::UP, i, 0)] = grid[getIndex(Face::BACK, 2 - i, 2)];
    // Down -> Back
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::BACK, i, 2)] = grid[getIndex(Face::DOWN, 2 - i, 0)];
    // Front -> Down
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::DOWN, i, 0)] = grid[getIndex(Face::FRONT, i, 0)];
    // Temp -> Front
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::FRONT, i, 0)] = temp[i];
}

void RubiksCube1DArray::lPrime()
{
    l();
    l();
    l();
}
void RubiksCube1DArray::l2()
{
    l();
    l();
}

void RubiksCube1DArray::f()
{
    rotateFace(static_cast<int>(Face::FRONT));

    Color temp[3];
    for (int i = 0; i < 3; i++)
        temp[i] = grid[getIndex(Face::UP, 2, i)]; // Store Up

    // Left -> Up
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::UP, 2, i)] = grid[getIndex(Face::LEFT, 2 - i, 2)];
    // Down -> Left
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::LEFT, i, 2)] = grid[getIndex(Face::DOWN, 0, i)];
    // Right -> Down
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::DOWN, 0, i)] = grid[getIndex(Face::RIGHT, 2 - i, 0)];
    // Temp -> Right
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::RIGHT, i, 0)] = temp[i];
}

void RubiksCube1DArray::fPrime()
{
    f();
    f();
    f();
}
void RubiksCube1DArray::f2()
{
    f();
    f();
}

void RubiksCube1DArray::r()
{
    rotateFace(static_cast<int>(Face::RIGHT));

    Color temp[3];
    for (int i = 0; i < 3; i++)
        temp[i] = grid[getIndex(Face::UP, i, 2)]; // Store Up

    // Front -> Up
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::UP, i, 2)] = grid[getIndex(Face::FRONT, i, 2)];
    // Down -> Front
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::FRONT, i, 2)] = grid[getIndex(Face::DOWN, i, 2)];
    // Back -> Down
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::DOWN, i, 2)] = grid[getIndex(Face::BACK, 2 - i, 0)];
    // Temp -> Back
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::BACK, i, 0)] = temp[2 - i];
}

void RubiksCube1DArray::rPrime()
{
    r();
    r();
    r();
}
void RubiksCube1DArray::r2()
{
    r();
    r();
}

void RubiksCube1DArray::b()
{
    rotateFace(static_cast<int>(Face::BACK));

    Color temp[3];
    for (int i = 0; i < 3; i++)
        temp[i] = grid[getIndex(Face::UP, 0, i)]; // Store Up

    // Right -> Up
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::UP, 0, i)] = grid[getIndex(Face::RIGHT, i, 2)];
    // Down -> Right
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::RIGHT, i, 2)] = grid[getIndex(Face::DOWN, 2, 2 - i)];
    // Left -> Down
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::DOWN, 2, i)] = grid[getIndex(Face::LEFT, 2 - i, 0)];
    // Temp -> Left
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::LEFT, i, 0)] = temp[2 - i];
}

void RubiksCube1DArray::bPrime()
{
    b();
    b();
    b();
}
void RubiksCube1DArray::b2()
{
    b();
    b();
}

void RubiksCube1DArray::d()
{
    rotateFace(static_cast<int>(Face::DOWN));

    Color temp[3];
    for (int i = 0; i < 3; i++)
        temp[i] = grid[getIndex(Face::FRONT, 2, i)]; // Store Front

    // Right -> Front
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::FRONT, 2, i)] = grid[getIndex(Face::RIGHT, 2, i)];
    // Back -> Right
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::RIGHT, 2, i)] = grid[getIndex(Face::BACK, 2, i)];
    // Left -> Back
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::BACK, 2, i)] = grid[getIndex(Face::LEFT, 2, i)];
    // Temp -> Left
    for (int i = 0; i < 3; i++)
        grid[getIndex(Face::LEFT, 2, i)] = temp[i];
}

void RubiksCube1DArray::dPrime()
{
    d();
    d();
    d();
}
void RubiksCube1DArray::d2()
{
    d();
    d();
}