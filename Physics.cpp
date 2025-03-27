#include "Physics.h"

#include "Constants.h"

void UpdatePhysics(Player& player, const World& world, float delta)
{
    const auto& envItems = world.obstacles;
    player.pos.x += player.vel.x * delta;

    bool hitObstacle = false;
    for (auto ei : envItems)
    {
        Vector2& p = player.pos;
        if (ei.blocking && ei.rect.x <= p.x && ei.rect.x + ei.rect.width >= p.x && ei.rect.y >= p.y
            && ei.rect.y <= p.y + player.vel.y * delta)
        {
            hitObstacle = true;
            player.vel.y = 0.0f;
            p.y = ei.rect.y;
            break;
        }
    }

    if (!hitObstacle)
    {
        player.pos.y += player.vel.y * delta;
        player.vel.y += GRAVITY * delta;
        player.canJump = false;
    }
    else
    {
        player.OnHit();
    }
}
