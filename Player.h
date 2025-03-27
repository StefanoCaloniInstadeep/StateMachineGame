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
    bool isDucking;
    bool isDiving;

    void HandleInput();

    void MoveLeft();
    void MoveRight();
    void Jump();
    void Dive();
    void Duck();
    void StandUp();

    void OnHit();
    void OnFalling();
};
