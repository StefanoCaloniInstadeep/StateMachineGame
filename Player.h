#pragma once

#include <array>
#include <raylib.h>

class Player;

class State
{
public:
    virtual ~State() = default;

    virtual void Enter(Player& player) = 0;

    virtual void HandleInput(Player& player) = 0;

    virtual void OnHit(Player& player);
    virtual void OnFalling(Player& player);
};

class StandingState : public State
{
public:
    void Enter(Player& player) override;
    void HandleInput(Player& player) override;
};

class FallingState : public State
{
public:
    void Enter(Player& player) override;
    void HandleInput(Player& player) override;
};

class JumpingState : public State
{
public:
    void Enter(Player& player) override;
    void HandleInput(Player& player) override;

    void OnFalling(Player& player) override;
};

class DuckingState : public State
{
public:
    void Enter(Player& player) override;
    void HandleInput(Player& player) override;
};

class DivingState : public State
{
public:
    void Enter(Player& player) override;
    void HandleInput(Player& player) override;

    void OnFalling(Player& player) override;
};

class Player
{
public:
    Player();

    Vector2 pos;
    Vector2 vel;
    std::array<float, 2> shape;

    State* state;

    void HandleInput();
};
