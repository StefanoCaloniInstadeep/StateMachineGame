#include "Physics.h"

#include "Constants.h"

void UpdatePhysics(Player& player, const World& world, float delta)
{
    player.pos.x += player.vel.x * delta;

    bool hitObstacle = false;
    for (auto ob : world.obstacles)
    {
        Vector2& pos = player.pos;
        if (ob.blocking && ob.rect.x <= pos.x && ob.rect.x + ob.rect.width >= pos.x && ob.rect.y >= pos.y
            && ob.rect.y <= pos.y + player.vel.y * delta)
        {
            hitObstacle = true;
            player.vel.y = 0.0f;
            pos.y = ob.rect.y;
            break;
        }
    }

    if (!hitObstacle)
    {
        player.pos.y += player.vel.y * delta;
        player.vel.y += GRAVITY * delta;
        player.OnFalling();
    }
    else
    {
        player.OnHit();
    }
}
