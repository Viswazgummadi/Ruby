#include "RubiksCube.h"
#include <iostream>
#include <random>
#include <vector>

// Helper function to convert a Color enum to a string for printing.
char getColorChar(RubiksCube::Color color)
{
    switch (color)
    {
    case RubiksCube::Color::WHITE:
        return 'W';
    case RubiksCube::Color::GREEN:
        return 'G';
    case RubiksCube::Color::RED:
        return 'R';
    case RubiksCube::Color::BLUE:
        return 'B';
    case RubiksCube::Color::ORANGE:
        return 'O';
    case RubiksCube::Color::YELLOW:
        return 'Y';
    }
    return ' '; // Should not happen
}

// Implements the generic print function for the Rubik's Cube.
void RubiksCube::print() const
{
    std::cout << "Rubik's Cube State:" << std::endl;

    // Print the UP face
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "        ";
        for (int j = 0; j < 3; ++j)
        {
            std::cout << getColorChar(getColor(Face::UP, i, j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Print LEFT, FRONT, RIGHT, and BACK faces in a row
    for (int i = 0; i < 3; ++i)
    {
        // LEFT
        for (int j = 0; j < 3; ++j)
        {
            std::cout << getColorChar(getColor(Face::LEFT, i, j)) << " ";
        }
        std::cout << "  ";

        // FRONT
        for (int j = 0; j < 3; ++j)
        {
            std::cout << getColorChar(getColor(Face::FRONT, i, j)) << " ";
        }
        std::cout << "  ";

        // RIGHT
        for (int j = 0; j < 3; ++j)
        {
            std::cout << getColorChar(getColor(Face::RIGHT, i, j)) << " ";
        }
        std::cout << "  ";

        // BACK
        for (int j = 0; j < 3; ++j)
        {
            std::cout << getColorChar(getColor(Face::BACK, i, j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Print the DOWN face
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "        ";
        for (int j = 0; j < 3; ++j)
        {
            std::cout << getColorChar(getColor(Face::DOWN, i, j)) << " ";
        }
        std::cout << std::endl;
    }
}

// Returns a string representation of a move given its index (0-17)
std::string RubiksCube::getMove(int ind)
{
    switch (ind)
    {
    case 0:
        return "U";
    case 1:
        return "U'";
    case 2:
        return "U2";
    case 3:
        return "L";
    case 4:
        return "L'";
    case 5:
        return "L2";
    case 6:
        return "F";
    case 7:
        return "F'";
    case 8:
        return "F2";
    case 9:
        return "R";
    case 10:
        return "R'";
    case 11:
        return "R2";
    case 12:
        return "B";
    case 13:
        return "B'";
    case 14:
        return "B2";
    case 15:
        return "D";
    case 16:
        return "D'";
    case 17:
        return "D2";
    }
    return "";
}

// Applies a sequence of random moves to shuffle the cube.
void RubiksCube::randomShuffle(unsigned int times)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 17);

    for (unsigned int i = 0; i < times; ++i)
    {
        int move_idx = distrib(gen);
        switch (move_idx)
        {
        case 0:
            u();
            break;
        case 1:
            uPrime();
            break;
        case 2:
            u2();
            break;
        case 3:
            l();
            break;
        case 4:
            lPrime();
            break;
        case 5:
            l2();
            break;
        case 6:
            f();
            break;
        case 7:
            fPrime();
            break;
        case 8:
            f2();
            break;
        case 9:
            r();
            break;
        case 10:
            rPrime();
            break;
        case 11:
            r2();
            break;
        case 12:
            b();
            break;
        case 13:
            bPrime();
            break;
        case 14:
            b2();
            break;
        case 15:
            d();
            break;
        case 16:
            dPrime();
            break;
        case 17:
            d2();
            break;
        }
    }
}