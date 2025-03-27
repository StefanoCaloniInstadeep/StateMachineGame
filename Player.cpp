#include "Player.h"

#include "Constants.h"
#include <iostream>
#include <ostream>
#include <print>
#include <raylib.h>

constexpr float EDGE = SCREEN_HEIGHT * 0.1;
std::array<float, 2> NORMAL_SHAPE{EDGE, EDGE};
std::array<float, 2> JUMPING_SHAPE{EDGE * 3 / 4, EDGE * 5 / 4};
std::array<float, 2> DUCKING_SHAPE{EDGE * 5 / 4, EDGE * 3 / 4};
std::array<float, 2> DIVING_SHAPE{EDGE * 3 / 4, EDGE * 3 / 4};

Player::Player()
    : pos{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f},
      vel{0, 0},
      shape{NORMAL_SHAPE},
      state{State::STANDING}
{}

void Player::HandleInput()
{
    vel.x = 0;
    if (IsKeyDown(KEY_LEFT))
    {
        MoveLeft();
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        MoveRight();
    }
    if ((IsKeyPressed(KEY_UP)))
    {
        switch (state)
        {
            case State::STANDING: Jump(); break;
            case State::FALLING:
            case State::JUMPING:
            case State::DUCKING:
            case State::DIVING:
        }
    }
    if ((IsKeyDown(KEY_DOWN)))
    {
        switch (state)
        {
            case State::STANDING: Duck(); break;
            case State::FALLING:
            case State::JUMPING: Dive(); break;
            case State::DUCKING:
            case State::DIVING:
        }
    }
    if (IsKeyReleased(KEY_DOWN))
    {
        switch (state)
        {
            case State::STANDING:
            case State::FALLING:
            case State::DIVING:
            case State::JUMPING: break;
            case State::DUCKING: StandUp(); break;
        }
    }
}

void Player::OnFalling()
{
    switch (state)
    {
        case State::FALLING:
        case State::STANDING:
        case State::JUMPING: break;
        case State::DUCKING: StandUp(); break;
        case State::DIVING: return;
    }
    state = State::FALLING;
}

void Player::OnHit()
{
    shape = NORMAL_SHAPE;
    state = State::STANDING;
}

void Player::MoveLeft()
{
    switch (state)
    {
        case State::FALLING:
        case State::STANDING:
        case State::JUMPING: vel.x -= PLAYER_HOR_SPD; break;
        case State::DUCKING: vel.x -= PLAYER_HOR_SPD_WHILE_DUCKING; break;
        case State::DIVING: vel.x = 0;
    }
}

void Player::MoveRight()
{
    switch (state)
    {
        case State::FALLING:
        case State::STANDING:
        case State::JUMPING: vel.x += PLAYER_HOR_SPD; break;
        case State::DUCKING: vel.x += PLAYER_HOR_SPD_WHILE_DUCKING; break;
        case State::DIVING: vel.x = 0;
    }
}

void Player::Jump()
{
    shape = JUMPING_SHAPE;
    vel.y = PLAYER_JUMP_SPD;
    state = State::JUMPING;
}

void Player::Dive()
{
    shape = DIVING_SHAPE;
    vel.y = PLAYER_DIVING_SPD;
    state = State::DIVING;
}

void Player::Duck()
{
    shape = DUCKING_SHAPE;
    state = State::DUCKING;
}

void Player::StandUp()
{
    shape = NORMAL_SHAPE;
    state = State::STANDING;
}
