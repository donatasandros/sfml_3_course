#include "Square.hpp"

Square::Square()
{
    x = 100.f;
    y = 275.f;

    size = 50.f;
    speed = 300.f;
}

void Square::update(float deltaTime, const Input& input)
{
    if (input.left)
        x -= speed * deltaTime;

    if (input.right)
        x += speed * deltaTime;

    if (input.up)
        y -= speed * deltaTime;

    if (input.down)
        y += speed * deltaTime;
}

float Square::getX() const
{
    return x;
}

float Square::getY() const
{
    return y;
}

float Square::getSize() const
{
    return size;
}