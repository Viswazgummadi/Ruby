// RubiksCubeSolver/include/RubiksCube3DArray.h

#ifndef RUBIKS_CUBE_3D_ARRAY_H
#define RUBIKS_CUBE_3D_ARRAY_H

#include "RubiksCube.h"
#include <string> // For hashing

class RubiksCube3DArray : public RubiksCube
{
    // --- Task 5: Change from private to public ---
public:
    // The core data structure: a 6x3x3 array of Color enums.
    Color grid[6][3][3];

private:
    // Helper function to perform a clockwise rotation of a single face.
    void rotateFace(int faceIndex);

public:
    // Constructor: Initializes the cube to a solved state.
    RubiksCube3DArray();

    // Default virtual destructor.
    ~RubiksCube3DArray() override = default;
    bool operator==(const RubiksCube3DArray &other) const;
    RubiksCube3DArray &operator=(const RubiksCube3DArray &other);

    // --- Overridden Public Interface from RubiksCube ---

    // Returns the color of a specific sticker on the cube.
    Color getColor(Face face, unsigned int row, unsigned int col) const override;

    // Checks if the cube is in the solved state.
    bool isSolved() const override;

    // --- Overridden Move Functions ---
    // Note: They return a reference to the object to allow for method chaining (e.g., cube.u().r())

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
struct Hash3D
{
    size_t operator()(const RubiksCube3DArray &cube) const;
};
#endif // RUBIKS_CUBE_3D_ARRAY_H