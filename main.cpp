#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    //создание фигуры
    sf::CircleShape shape(50.f);//, (колво вершин)
    shape.setPosition(0.f, 0.f);
    shape.move(500.f, 500.f);
    shape.setFillColor(sf::Color::Red);// можно задать как (r, g, b)

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}