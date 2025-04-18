#include <SFML/Graphics.hpp>

static void MoveShape(float xMove, float yMove);

float x = 0, y = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "This is snake!!!!");

    float step = 0.2;

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ x, y });

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            MoveShape(-step, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            MoveShape(0, step);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            MoveShape(step, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            MoveShape(0, -step);
        }

        shape.setPosition({ x, y });

        window.clear();
        window.draw(shape);
        window.display();
    }
}

static void MoveShape(float xMove, float yMove)
{
    x += xMove;
    y += yMove;
}
