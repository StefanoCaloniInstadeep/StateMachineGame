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

Player::Player()
    : pos{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f},
      vel{0, 0},
      shape{NORMAL_SHAPE},
      isMidAir{false},
      isDucking(false)
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
    if ((IsKeyPressed(KEY_UP)) && !isMidAir)
    {
        Jump();
    }
    if ((IsKeyDown(KEY_DOWN)) && !isMidAir)
    {
        Duck();
    }
    if (IsKeyReleased(KEY_DOWN) && !isMidAir)
    {
        StandUp();
    }
}

void Player::OnFalling()
{
    if (isDucking)
    {
        StandUp();
    }
    isMidAir = true;
}

void Player::OnHit()
{
    std::println("on hit");
    std::flush(std::cout);
    shape = NORMAL_SHAPE;
    isMidAir = false;
}

void Player::MoveLeft()
{
    if (isDucking)
    {
        vel.x -= PLAYER_HOR_SPD_WHILE_DUCKING;
    }
    else
    {
        vel.x -= PLAYER_HOR_SPD;
    }
}

void Player::MoveRight()
{
    if (isDucking)
    {
        vel.x += PLAYER_HOR_SPD_WHILE_DUCKING;
    }
    else
    {
        vel.x += PLAYER_HOR_SPD;
    }
}

void Player::Jump()
{
    shape = JUMPING_SHAPE;
    vel.y = PLAYER_JUMP_SPD;
    isMidAir = true;
}

void Player::Duck()
{
    shape = DUCKING_SHAPE;
    isDucking = true;
}

void Player::StandUp()
{
    shape = NORMAL_SHAPE;
    isDucking = false;
}
