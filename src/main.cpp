#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "Fractal Generation");
    window.setFramerateLimit(144);
    std::vector<sf::CircleShape> circles;
    std::srand(std::time(nullptr));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        
        sf::CircleShape circle(10); // Radius of 10
        sf::Color color(rand() % 256, rand() % 256, rand() % 256);
        circle.setFillColor(color);
        sf::Vector2f position(rand() % 800, rand() % 600);
        circle.setPosition(position);

        circles.push_back(circle); // Store the circle

        // Clear window before drawing new frame
        window.clear();

        // Draw all stored circles
        for (const auto& c : circles)
        {
            window.draw(c);
        }
        window.display();
    }
}
