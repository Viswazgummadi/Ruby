#ifndef RUBIKS_CUBE_BITBOARD_H
#define RUBIKS_CUBE_BITBOARD_H

#include "RubiksCube.h"
#include <cstdint> // Required for uint64_t

// Concrete implementation of RubiksCube using bitboards for high performance.
class RubiksCubeBitboard : public RubiksCube
{
private:
    // The core data structure: 6 unsigned 64-bit integers, one for each face.
    uint64_t bitboard[6];

    // Helper to map a (row, col) to a clockwise sticker index (0-7).
    // Returns -1 for the center piece.
    int rowColToStickerIndex(unsigned int r, unsigned int c) const;

    // Helper to decode a color from a face's bitboard given a sticker index.
    Color getColorFromSticker(int face_idx, int sticker_idx) const;

public:
    // Constructor: Initializes the cube to a solved state.
    RubiksCubeBitboard();

    // Default virtual destructor.
    ~RubiksCubeBitboard() override = default;

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

#endif // RUBIKS_CUBE_BITBOARD_H