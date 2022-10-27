#include "shapes.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    sf::Vector2i win(1280, 720);
    sf::RenderWindow window(sf::VideoMode(win.x, win.y), "oop-lab6");

    int quantity = 5;
    std::vector<Shape *> shapes;
    for (int i = 0; i < quantity; i++)
    {
        shapes.push_back(new Point());
        shapes.push_back(new Ellipse());
        shapes.push_back(new Circle());
        shapes.push_back(new Rectangle());
        shapes.push_back(new Rhombus());
        shapes.push_back(new Triangle());
        shapes.push_back(new Line());
    }
    for (int i = 0; i < quantity * 7; i++)
    {
        shapes[i]->setPosition(rand() % win.x, rand() % win.y);
        shapes[i]->setSpeed((rand() % 400) + 20.0, (rand() % 400) + 20.0);
    }

    sf::Clock clock;
    float elapsedSecs = 0;
    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        elapsedSecs = clock.restart().asSeconds();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            for (int i = 0; i < quantity * 7; i++)
            {
                shapes[i]->rotate(-0.5);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            for (int i = 0; i < quantity * 7; i++)
            {
                shapes[i]->rotate(0.5);
            }
        }
        for (int i = 0; i < quantity * 7; i++)
        {
            shapes[i]->move(win, shapes[i]->getSpeed() * elapsedSecs);
        }

        window.clear(sf::Color::Black);
        for (int i = 0; i < quantity * 7; i++)
        {
            window.draw(*shapes[i]);
        }
        window.display();
    }
    return EXIT_SUCCESS;
}