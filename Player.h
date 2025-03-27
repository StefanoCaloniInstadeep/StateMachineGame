#pragma once

#include <array>
#include <raylib.h>

enum class State
{
    STANDING,
    FALLING,
    JUMPING,
    DUCKING,
    DIVING,
};

class Player
{
public:
    Player();

    Vector2 pos;
    Vector2 vel;
    std::array<float, 2> shape;

    State state;

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
