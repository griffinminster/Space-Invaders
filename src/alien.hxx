#pragma once

#include <ge211.hxx>

using Position = ge211::Posn<float>;
using Block = ge211::Rect<int>;

struct Alien : Block
{
    Alien(Coordinate x, Coordinate y,
          Coordinate width, Coordinate height);

    ///
    /// MEMBER VARIABLES
    ///

    int x_;
    int y_;
    int width_;
    int height_;

    static int dir;
};