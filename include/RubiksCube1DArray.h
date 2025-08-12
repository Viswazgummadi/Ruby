#ifndef RUBIKS_CUBE_1D_ARRAY_H
#define RUBIKS_CUBE_1D_ARRAY_H

#include "RubiksCube.h"

// Concrete implementation of RubiksCube using a single 1D array.
class RubiksCube1DArray : public RubiksCube
{
private:
    // The core data structure: an array of 54 colors.
    Color grid[54];

    // Helper to map (face, row, col) to a 1D index.
    int getIndex(Face face, unsigned int row, unsigned int col) const;

    // Helper to rotate the stickers on a single face.
    void rotateFace(int face_idx);

public:
    // Constructor: Initializes the cube to a solved state.
    RubiksCube1DArray();

    // Default virtual destructor.
    ~RubiksCube1DArray() override = default;

    // --- Overridden Public Interface from RubiksCube ---

    Color getColor(Face face, unsigned int row, unsigned int col) const override;

    bool isSolved() const override;

    // --- Overridden Move Functions ---

    void u() override;
    void uPrime() override;
    void u2() override;

    void l() override;
    void lPrime() override;
    void l2() override;

    void f() override;
    void fPrime() override;
    void f2() override;

    void r() override;
    void rPrime() override;
    void r2() override;

    void b() override;
    void bPrime() override;
    void b2() override;

    void d() override;
    void dPrime() override;
    void d2() override;
};

#endif // RUBIKS_CUBE_1D_ARRAY_H
