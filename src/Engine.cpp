#include "Engine.hpp"

Engine::Engine()
    : window(
        sf::VideoMode({ 800, 600 }),
        "SFML Game Engine"
    )
{
}

void Engine::run()
{
    while (window.isOpen())
    {
        processEvents();

        float deltaTime = clock.restart().asSeconds();

        update(deltaTime);
        render();
    }
}

void Engine::processEvents()
{
    while (const auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

Input Engine::getInput()
{
    Input input;

    input.up =
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);

    input.down =
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);

    input.left =
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);

    input.right =
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

    return input;
}

void Engine::update(float deltaTime)
{
    Input input = getInput();

    game.update(deltaTime, input);
}

void Engine::render()
{
    window.clear(sf::Color(30, 30, 30));

    // Draw player
    sf::RectangleShape player({
        game.getPlayerSize(),
        game.getPlayerSize()
        });

    player.setPosition({
        game.getPlayerX(),
        game.getPlayerY()
        });

    player.setFillColor(sf::Color::Blue);

    window.draw(player);

    // Draw target
    sf::RectangleShape target({
        game.getTargetSize(),
        game.getTargetSize()
        });

    target.setPosition({
        game.getTargetX(),
        game.getTargetY()
        });

    if (game.targetIsHit())
        target.setFillColor(sf::Color::Green);
    else
        target.setFillColor(sf::Color::Red);

    window.draw(target);

    window.display();
}