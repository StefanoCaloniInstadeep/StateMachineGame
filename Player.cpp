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

void State::OnLeft(Player& player)
{
    player.vel.x -= PLAYER_HOR_SPD;
}

void State::OnRight(Player& player)
{
    player.vel.x += PLAYER_HOR_SPD;
}

void State::OnUp(Player& player)
{
    (void)player;
}

void State::OnDown(Player& player)
{
    (void)player;
}

void State::OnDownReleased(Player& player)
{
    (void)player;
}

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

void StandingState::OnUp(Player& player)
{
    JUMPING.Enter(player);
}

void StandingState::OnDown(Player& player)
{
    player.shape = DUCKING_SHAPE;
    player.state = &DUCKING;
}

void FallingState::Enter(Player& player)
{
    player.shape = NORMAL_SHAPE;
    player.state = this;
}

void JumpingState::Enter(Player& player)
{
    player.shape = JUMPING_SHAPE;
    player.vel.y = PLAYER_JUMP_SPD;
    player.state = this;
}

void JumpingState::OnDown(Player& player)
{
    DIVING.Enter(player);
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

void DuckingState::OnLeft(Player& player)
{
    player.vel.x -= PLAYER_HOR_SPD_WHILE_DUCKING;
}

void DuckingState::OnRight(Player& player)
{
    player.vel.x += PLAYER_HOR_SPD_WHILE_DUCKING;
}

void DuckingState::OnDownReleased(Player& player)
{
    STANDING.Enter(player);
}

void DivingState::Enter(Player& player)
{
    player.shape = DIVING_SHAPE;
    player.vel.y = PLAYER_DIVING_SPD;
    player.state = this;
}

void DivingState::OnLeft(Player& player)
{
    player.vel.x = 0;
}

void DivingState::OnRight(Player& player)
{
    player.vel.x = 0;
}

void DivingState::OnFalling(Player& player)
{
    (void)player;
}

Player::Player() : pos{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f}, vel{0, 0}, shape{NORMAL_SHAPE}, state{&STANDING}
{}

void Player::HandleInput()
{
    if (IsKeyDown(KEY_LEFT))
    {
        state->OnLeft(*this);
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        state->OnRight(*this);
    }
    if ((IsKeyPressed(KEY_UP)))
    {
        state->OnUp(*this);
    }
    if ((IsKeyDown(KEY_DOWN)))
    {
        state->OnDown(*this);
    }
    if (IsKeyReleased(KEY_DOWN))
    {
        state->OnDownReleased(*this);
    }
}
