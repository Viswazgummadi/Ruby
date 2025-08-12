#include <iostream>
// 1. Change the include to the bitboard model.
#include "RubiksCubeBitboard.h"

int main()
{
    // 2. Change the class being instantiated.
    RubiksCubeBitboard cube;

    std::cout << "Initial Solved State (Bitboard Model):" << std::endl;
    cube.print();
    std::cout << "Is the cube solved? " << (cube.isSolved() ? "Yes" : "No") << std::endl;
    std::cout << "------------------------------------" << std::endl;

    std::cout << "Applying a single 'F' move..." << std::endl;
    cube.f();
    cube.print();
    std::cout << "Is the cube solved? " << (cube.isSolved() ? "Yes" : "No") << std::endl;
    std::cout << "------------------------------------" << std::endl;

    // Note: The random shuffle will only use 'F' moves until you implement the others.
    std::cout << "Shuffling the cube with 5 random moves..." << std::endl;
    RubiksCubeBitboard fresh_cube;
    fresh_cube.randomShuffle(5);
    fresh_cube.print();
    std::cout << "Is the cube solved? " << (fresh_cube.isSolved() ? "Yes" : "No") << std::endl;

    return 0;
}