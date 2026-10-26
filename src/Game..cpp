#include "Game.hpp"

Game::Game()
{
    targetX = 650.f;
    targetY = 275.f;
    targetSize = 50.f;

    targetHit = false;
}

void Game::update(float deltaTime, const Input& input)
{
    square.update(deltaTime, input);

    float playerLeft = square.getX();
    float playerRight = square.getX() + square.getSize();

    float playerTop = square.getY();
    float playerBottom = square.getY() + square.getSize();

    float targetLeft = targetX;
    float targetRight = targetX + targetSize;

    float targetTop = targetY;
    float targetBottom = targetY + targetSize;

    targetHit =
        playerRight > targetLeft &&
        playerLeft < targetRight &&
        playerBottom > targetTop &&
        playerTop < targetBottom;
}

float Game::getPlayerX() const
{
    return square.getX();
}

float Game::getPlayerY() const
{
    return square.getY();
}

float Game::getPlayerSize() const
{
    return square.getSize();
}

float Game::getTargetX() const
{
    return targetX;
}

float Game::getTargetY() const
{
    return targetY;
}

float Game::getTargetSize() const
{
    return targetSize;
}

bool Game::targetIsHit() const
{
    return targetHit;
}