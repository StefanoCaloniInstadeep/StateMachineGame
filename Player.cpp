#include "Player.h"

#include "Constants.h"

std::array<float, 2> NORMAL_SHAPE{40, 40};
std::array<float, 2> JUMPING_SHAPE{30, 50};

Player::Player() : pos{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f}, vel{0, 0}, shape{NORMAL_SHAPE}, canJump{false}
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
    if ((IsKeyDown(KEY_UP)) && canJump)
    {
        Jump();
    }
}

void Player::OnHit()
{
    shape = NORMAL_SHAPE;
    canJump = true;
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
    canJump = false;
}
