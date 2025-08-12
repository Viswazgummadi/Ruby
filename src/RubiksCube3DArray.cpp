#include "RubiksCube3DArray.h"

// Constructor: Initializes the grid to the solved state.
RubiksCube3DArray::RubiksCube3DArray()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                // Assigns the color corresponding to the face index.
                grid[i][j][k] = static_cast<Color>(i);
            }
        }
    }
}

// Returns the color of a sticker using the Face enum.
// This is a simple lookup in our grid.
RubiksCube::Color RubiksCube3DArray::getColor(Face face, unsigned int row, unsigned int col) const
{
    return grid[static_cast<int>(face)][row][col];
}

// Checks if the cube is solved by verifying each sticker's color.
bool RubiksCube3DArray::isSolved() const
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (grid[i][j][k] != static_cast<Color>(i))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// Helper function to rotate the stickers on a single face clockwise.
void RubiksCube3DArray::rotateFace(int faceIndex)
{
    Color temp_grid[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp_grid[i][j] = grid[faceIndex][i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[faceIndex][i][j] = temp_grid[2 - j][i];
        }
    }
}

// --- Move Implementations ---

void RubiksCube3DArray::u()
{
    rotateFace(static_cast<int>(Face::UP));

    Color temp_row[3];
    // Store Front face's top row
    for (int i = 0; i < 3; i++)
        temp_row[i] = grid[static_cast<int>(Face::FRONT)][0][i];

    // Left -> Front
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::FRONT)][0][i] = grid[static_cast<int>(Face::LEFT)][0][i];
    // Back -> Left
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::LEFT)][0][i] = grid[static_cast<int>(Face::BACK)][0][i];
    // Right -> Back
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::BACK)][0][i] = grid[static_cast<int>(Face::RIGHT)][0][i];
    // Temp (Front) -> Right
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::RIGHT)][0][i] = temp_row[i];
}

void RubiksCube3DArray::uPrime()
{
    u();
    u();
    u();
}

void RubiksCube3DArray::u2()
{
    u();
    u();
}

void RubiksCube3DArray::l()
{
    rotateFace(static_cast<int>(Face::LEFT));

    Color temp_col[3];
    // Store UP face's left column
    for (int i = 0; i < 3; i++)
        temp_col[i] = grid[static_cast<int>(Face::UP)][i][0];

    // Back -> Up
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::UP)][i][0] = grid[static_cast<int>(Face::BACK)][2 - i][2];
    // Down -> Back
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::BACK)][i][2] = grid[static_cast<int>(Face::DOWN)][2 - i][0];
    // Front -> Down
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::DOWN)][i][0] = grid[static_cast<int>(Face::FRONT)][i][0];
    // Temp (Up) -> Front
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::FRONT)][i][0] = temp_col[i];
}

void RubiksCube3DArray::lPrime()
{
    l();
    l();
    l();
}

void RubiksCube3DArray::l2()
{
    l();
    l();
}

void RubiksCube3DArray::f()
{
    rotateFace(static_cast<int>(Face::FRONT));

    Color temp_row[3];
    // Store UP face's bottom row
    for (int i = 0; i < 3; i++)
        temp_row[i] = grid[static_cast<int>(Face::UP)][2][i];

    // Left -> Up
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::UP)][2][i] = grid[static_cast<int>(Face::LEFT)][2 - i][2];
    // Down -> Left
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::LEFT)][i][2] = grid[static_cast<int>(Face::DOWN)][0][i];
    // Right -> Down
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::DOWN)][0][i] = grid[static_cast<int>(Face::RIGHT)][2 - i][0];
    // Temp (Up) -> Right
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::RIGHT)][i][0] = temp_row[i];
}

void RubiksCube3DArray::fPrime()
{
    f();
    f();
    f();
}

void RubiksCube3DArray::f2()
{
    f();
    f();
}

void RubiksCube3DArray::r()
{
    rotateFace(static_cast<int>(Face::RIGHT));

    Color temp_col[3];
    // Store UP face's right column
    for (int i = 0; i < 3; i++)
        temp_col[i] = grid[static_cast<int>(Face::UP)][i][2];

    // Front -> Up
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::UP)][i][2] = grid[static_cast<int>(Face::FRONT)][i][2];
    // Down -> Front
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::FRONT)][i][2] = grid[static_cast<int>(Face::DOWN)][i][2];
    // Back -> Down
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::DOWN)][i][2] = grid[static_cast<int>(Face::BACK)][2 - i][0];
    // Temp (Up) -> Back
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::BACK)][i][0] = temp_col[2 - i];
}

void RubiksCube3DArray::rPrime()
{
    r();
    r();
    r();
}

void RubiksCube3DArray::r2()
{
    r();
    r();
}

void RubiksCube3DArray::b()
{
    rotateFace(static_cast<int>(Face::BACK));

    Color temp_row[3];
    // Store UP face's top row
    for (int i = 0; i < 3; i++)
        temp_row[i] = grid[static_cast<int>(Face::UP)][0][i];

    // Right -> Up
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::UP)][0][i] = grid[static_cast<int>(Face::RIGHT)][i][2];
    // Down -> Right
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::RIGHT)][i][2] = grid[static_cast<int>(Face::DOWN)][2][2 - i];
    // Left -> Down
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::DOWN)][2][i] = grid[static_cast<int>(Face::LEFT)][2 - i][0];
    // Temp (Up) -> Left
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::LEFT)][i][0] = temp_row[2 - i];
}

void RubiksCube3DArray::bPrime()
{
    b();
    b();
    b();
}

void RubiksCube3DArray::b2()
{
    b();
    b();
}

void RubiksCube3DArray::d()
{
    rotateFace(static_cast<int>(Face::DOWN));

    Color temp_row[3];
    // Store Front face's bottom row
    for (int i = 0; i < 3; i++)
        temp_row[i] = grid[static_cast<int>(Face::FRONT)][2][i];

    // Right -> Front
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::FRONT)][2][i] = grid[static_cast<int>(Face::RIGHT)][2][i];
    // Back -> Right
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::RIGHT)][2][i] = grid[static_cast<int>(Face::BACK)][2][i];
    // Left -> Back
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::BACK)][2][i] = grid[static_cast<int>(Face::LEFT)][2][i];
    // Temp (Front) -> Left
    for (int i = 0; i < 3; i++)
        grid[static_cast<int>(Face::LEFT)][2][i] = temp_row[i];
}

void RubiksCube3DArray::dPrime()
{
    d();
    d();
    d();
}

void RubiksCube3DArray::d2()
{
    d();
    d();
}

bool RubiksCube3DArray::operator==(const RubiksCube3DArray &other) const
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (this->grid[i][j][k] != other.grid[i][j][k])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

RubiksCube3DArray &RubiksCube3DArray::operator=(const RubiksCube3DArray &other)
{
    // 1. Check for self-assignment
    if (this == &other)
    {
        return *this;
    }

    // 2. Perform the deep copy
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                this->grid[i][j][k] = other.grid[i][j][k];
            }
        }
    }

    // 3. Return the current object
    return *this;
}

// Hash function implementation
size_t Hash3D::operator()(const RubiksCube3DArray &cube) const
{
    std::string str = "";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                str += static_cast<char>(cube.grid[i][j][k]);
            }
        }
    }
    return std::hash<std::string>()(str);
}