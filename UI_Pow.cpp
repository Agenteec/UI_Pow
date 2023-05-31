
#include <iostream>
#include <SFML/Graphics.hpp>
#pragma region SFMLFont
sf::Font font;

#pragma endregion
void openWindow2(sf::RenderWindow &w) {
    sf::Event event;
while (w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w.close();
        }
w.clear(sf::Color::White);
w.display();
}

int main()
{
    if (!font.loadFromFile("Fonts\\arial.ttf"))
    {
        std::cout << "Unable to load font!\n";
        return EXIT_FAILURE;
    }
    //
    sf::RenderWindow window1(sf::VideoMode(800, 600), L"Окно 1");
    sf::RenderWindow window2(sf::VideoMode(800, 600), L"Окно 2");
    while (window1.isOpen() && window2.isOpen())
    {

        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        openWindow2(window2);
        
        // Обновление и отрисовка содержимого окон
        window1.clear(sf::Color::White);
        // Рисуем содержимое окна 1
        window1.display();
    }

    return 0;
}
