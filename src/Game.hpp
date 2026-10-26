#pragma once

#include "Square.hpp"

class Game
{
public:
    Game();

    void update(float deltaTime, const Input& input);

    float getPlayerX() const;
    float getPlayerY() const;
    float getPlayerSize() const;

    float getTargetX() const;
    float getTargetY() const;
    float getTargetSize() const;

    bool targetIsHit() const;

private:
    Square square;

    float targetX;
    float targetY;
    float targetSize;

    bool targetHit;
};