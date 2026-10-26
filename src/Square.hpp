#pragma once

struct Input
{
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
};

class Square
{
public:
    Square();

    void update(float deltaTime, const Input& input);

    float getX() const;
    float getY() const;

    float getSize() const;

private:
    float x;
    float y;

    float size;
    float speed;
};