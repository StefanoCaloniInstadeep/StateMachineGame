#pragma once

#include <raylib.h>
#include <vector>

struct EnvItem
{
    Rectangle rect;
    int blocking;
    Color color;
};

class World
{
public:
    World();

    std::vector<EnvItem> obstacles;
};
