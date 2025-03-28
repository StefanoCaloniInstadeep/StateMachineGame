#include "Player.h"

#include "Constants.h"
#include <print>
#include <raylib.h>

constexpr float EDGE = SCREEN_HEIGHT * 0.1;
std::array<float, 2> NORMAL_SHAPE{EDGE, EDGE};
std::array<float, 2> JUMPING_SHAPE{EDGE * 3 / 4, EDGE * 5 / 4};
std::array<float, 2> DUCKING_SHAPE{EDGE * 5 / 4, EDGE * 3 / 4};
std::array<float, 2> DIVING_SHAPE{EDGE * 3 / 4, EDGE * 3 / 4};

StandingState STANDING{};
FallingState FALLING{};
JumpingState JUMPING{};
DivingState DIVING{};
DuckingState DUCKING{};

void State::OnHit(Player& player)
{
    STANDING.Enter(player);
}

void State::OnFalling(Player& player)
{
    FALLING.Enter(player);
}

void StandingState::Enter(Player& player)
{
    player.shape = NORMAL_SHAPE;
    player.state = this;
}

void StandingState::HandleInput(Player& player)
{
    if (IsKeyDown(KEY_LEFT))
    {
        player.vel.x -= PLAYER_HOR_SPD;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        player.vel.x += PLAYER_HOR_SPD;
    }
    if ((IsKeyPressed(KEY_UP)))
    {
        JUMPING.Enter(player);
    }
    if ((IsKeyDown(KEY_DOWN)))
    {
        DUCKING.Enter(player);
    }
    // no IsKeyReleased(KEY_DOWN)
}

void FallingState::Enter(Player& player)
{
    player.shape = NORMAL_SHAPE;
    player.state = this;
}

void FallingState::HandleInput(Player& player)
{
    if (IsKeyDown(KEY_LEFT))
    {
        player.vel.x -= PLAYER_HOR_SPD;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        player.vel.x += PLAYER_HOR_SPD;
    }
    // no IsKeyPressed(KEY_UP)
    // no IsKeyDown(KEY_DOWN)
    // no IsKeyReleased(KEY_DOWN)
}

void JumpingState::Enter(Player& player)
{
    player.shape = JUMPING_SHAPE;
    player.vel.y = PLAYER_JUMP_SPD;
    player.state = this;
}

void JumpingState::HandleInput(Player& player)
{
    if (IsKeyDown(KEY_LEFT))
    {
        player.vel.x -= PLAYER_HOR_SPD;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        player.vel.x += PLAYER_HOR_SPD;
    }
    // no IsKeyPressed(KEY_UP)
    if ((IsKeyDown(KEY_DOWN)))
    {
        DIVING.Enter(player);
    }
    // no IsKeyReleased(KEY_DOWN)
}

void JumpingState::OnFalling(Player& player)
{
    (void)player;
}

void DuckingState::Enter(Player& player)
{
    player.shape = DUCKING_SHAPE;
    player.state = this;
}

void DuckingState::HandleInput(Player& player)
{
    if (IsKeyDown(KEY_LEFT))
    {
        player.vel.x -= PLAYER_HOR_SPD_WHILE_DUCKING;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        player.vel.x += PLAYER_HOR_SPD_WHILE_DUCKING;
    }
    // no IsKeyPressed(KEY_UP)
    // no IsKeyDown(KEY_DOWN)
    if (IsKeyReleased(KEY_DOWN))
    {
        STANDING.Enter(player);
    }
}

void DivingState::Enter(Player& player)
{
    player.shape = DIVING_SHAPE;
    player.vel.y = PLAYER_DIVING_SPD;
    player.state = this;
}

void DivingState::HandleInput(Player& player)
{
    (void)player;
    // no IsKeyDown(KEY_LEFT)
    // no IsKeyDown(KEY_RIGHT)
    // no IsKeyPressed(KEY_UP)
    // no IsKeyDown(KEY_DOWN)
    // no IsKeyReleased(KEY_DOWN)
}

void DivingState::OnFalling(Player& player)
{
    (void)player;
}

Player::Player() : pos{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f}, vel{0, 0}, shape{NORMAL_SHAPE}, state{&STANDING}
{}

void Player::HandleInput()
{
    state->HandleInput(*this);
}
