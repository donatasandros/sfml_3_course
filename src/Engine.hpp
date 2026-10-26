#pragma once

#include <SFML/Graphics.hpp>

#include "Game.hpp"

class Engine
{
public:
    Engine();

    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();

    Input getInput();

    sf::RenderWindow window;
    sf::Clock clock;

    Game game;
};