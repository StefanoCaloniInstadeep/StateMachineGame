#include "Rendering.h"
#include "Constants.h"

void Draw(const Player& player, const World& world)
{
    Camera2D camera = {
        .offset = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f},
        .target = {SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f},
        .rotation = 0.0f,
        .zoom = 1.0f,
    };
    BeginDrawing();

    ClearBackground(LIGHTGRAY);

    BeginMode2D(camera);
    const auto& envItems = world.obstacles;
    for (auto ei : envItems)
        DrawRectangleRec(ei.rect, ei.color);

    auto dx = player.shape[0];
    auto dy = player.shape[1];
    Rectangle playerRect = {player.pos.x - dx / 2, player.pos.y - dy, dx, dy};
    DrawRectangleRec(playerRect, RED);

    DrawCircleV(player.pos, 5.0f, GOLD);

    EndMode2D();

    DrawText("Controls:", 20, 20, 10, BLACK);
    DrawText("- Right/Left to move", 40, 40, 10, DARKGRAY);
    DrawText("- Up to jump", 40, 60, 10, DARKGRAY);
    DrawText("- Down to duck", 40, 80, 10, DARKGRAY);
    DrawText("- R to reset zoom", 40, 100, 10, DARKGRAY);
    DrawText("- Q to quit", 40, 120, 10, DARKGRAY);

    EndDrawing();
}
