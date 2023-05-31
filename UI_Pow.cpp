
#include <iostream>
#include <SFML/Graphics.hpp>
#pragma region SFMLFont
sf::Font font;

#pragma endregion
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

        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        // Обновление и отрисовка содержимого окон
        window1.clear(sf::Color::White);
        // Рисуем содержимое окна 1
        window1.display();

        window2.clear(sf::Color::Black);
        // Рисуем содержимое окна 2
        window2.display();
    }

    return 0;
}
