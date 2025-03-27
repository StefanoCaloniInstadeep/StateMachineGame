
#include "World.h"
#include "Constants.h"

World::World()
{
    auto h0 = SCREEN_HEIGHT * 0.9f;
    auto h1 = SCREEN_HEIGHT * 0.65f;
    auto h2 = SCREEN_HEIGHT * 0.4f;
    auto h = SCREEN_HEIGHT * 0.01f;
    auto v0 = SCREEN_WIDTH * 0.25f;
    auto v1 = SCREEN_WIDTH * 0.50f;
    auto v2 = SCREEN_WIDTH * 0.75f;
    auto v = SCREEN_WIDTH * 0.1f;
    obstacles = {{{0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}, 0, LIGHTGRAY},
                {{0, h0, SCREEN_WIDTH, SCREEN_HEIGHT - h0}, 1, GRAY},
                {{v0 - v, h1, 2 * v, h}, 1, GRAY},
                {{v2 - v, h1, 2 * v, h}, 1, GRAY},
                {{v1 - 2 * v, h2, 4 * v, h}, 1, GRAY}};
}
