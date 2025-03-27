#pragma once

#include <array>
#include <raylib.h>

class Player
{
public:
    Player();

    Vector2 pos;
    Vector2 vel;
    std::array<float, 2> shape;

    bool isMidAir;

    void HandleInput();

    void MoveLeft();
    void MoveRight();
    void Jump();

    void OnHit();
    void OnFalling();
};
