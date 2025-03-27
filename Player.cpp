#include "Player.h"

#include "Constants.h"

constexpr float EDGE = SCREEN_HEIGHT * 0.1;
std::array<float, 2> NORMAL_SHAPE{EDGE, EDGE};
std::array<float, 2> JUMPING_SHAPE{EDGE * 3 / 4, EDGE * 5 / 4};

Player::Player() : pos{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f}, vel{0, 0}, shape{NORMAL_SHAPE}, isMidAir{false}
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
    if ((IsKeyDown(KEY_UP)) && !isMidAir)
    {
        Jump();
    }
}

void Player::OnFalling()
{
    isMidAir = true;
}

void Player::OnHit()
{
    shape = NORMAL_SHAPE;
    isMidAir = false;
}

void Player::MoveLeft()
{
    vel.x -= PLAYER_HOR_SPD;
}

void Player::MoveRight()
{
    vel.x += PLAYER_HOR_SPD;
}

void Player::Jump()
{
    shape = JUMPING_SHAPE;
    vel.y = PLAYER_JUMP_SPD;
    isMidAir = true;
}
