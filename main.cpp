#include <print>

#include <raylib.h>
#include <raymath.h>

#include "Constants.h"
#include "Physics.h"
#include "Player.h"
#include "Rendering.h"
#include "World.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "State example");

    Player player{};

    World world{};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_Q)) break;
        if (IsKeyDown(KEY_R)) player = Player{};

        float deltaTime = GetFrameTime();

        player.HandleInput();
        UpdatePhysics(player, world, deltaTime);

        Draw(player, world);
    }

    CloseWindow();

    return 0;
}
