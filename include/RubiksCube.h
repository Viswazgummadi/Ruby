#ifndef RUBIKS_CUBE_H
#define RUBIKS_CUBE_H

#include <vector>
#include <string>

// Abstract base class for a Rubik's Cube model.
class RubiksCube
{
public:
    // Enum to represent the different colors of the cube's faces.
    enum class Color
    {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    // Enum to represent the different faces of the cube.
    enum class Face
    {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    // Virtual destructor.
    virtual ~RubiksCube() = default;

    // Pure virtual functions for all 18 possible moves.
    // These must be implemented by any concrete Rubik's Cube class.
    virtual void u() = 0;
    virtual void uPrime() = 0;
    virtual void u2() = 0;

    virtual void l() = 0;
    virtual void lPrime() = 0;
    virtual void l2() = 0;

    virtual void f() = 0;
    virtual void fPrime() = 0;
    virtual void f2() = 0;

    virtual void r() = 0;
    virtual void rPrime() = 0;
    virtual void r2() = 0;

    virtual void b() = 0;
    virtual void bPrime() = 0;
    virtual void b2() = 0;

    virtual void d() = 0;
    virtual void dPrime() = 0;
    virtual void d2() = 0;

    // Pure virtual function to check if the cube is in a solved state.
    virtual bool isSolved() const = 0;

    // Generic print function.
    void print() const;

    // Randomly shuffles the cube.
    void randomShuffle(unsigned int times);

    // Returns a string representation of a move.
    std::string getMove(int ind);

protected:
    // Pure virtual helper function to get the color of a specific sticker on a face.
    // This must be implemented by derived classes.
    virtual Color getColor(Face face, unsigned int row, unsigned int col) const = 0;
};

#endif // RUBIKS_CUBE_H