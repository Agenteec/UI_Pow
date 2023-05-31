#pragma once
#include <SFML/Graphics.hpp>
class Button : public sf::RectangleShape {
public:
    Button(float width, float height) : sf::RectangleShape(sf::Vector2f(width, height)) {
        // Инициализация параметров кнопки
        enabled = true;

        // Задание цвета и внешнего вида кнопки
        setFillColor(sf::Color::White);
        setOutlineColor(sf::Color::Blue);
        setOutlineThickness(2.0f);

        // Установка текста по умолчанию
        buttonText.setFont(buttonFont);
        buttonText.setCharacterSize(20);
        buttonText.setFillColor(sf::Color::Black);
        buttonText.setString("Button");
        buttonText.setPosition(width / 2 - buttonText.getGlobalBounds().width / 2,
            height / 2 - buttonText.getGlobalBounds().height / 2);
    }


    void setFont(sf::Font& font){ buttonFont = font;}

    void draw(sf::RenderWindow& window) {
        // Отрисовка кнопки
        window.draw(*this);
        window.draw(buttonText);
    }

    void setEnabled(bool value) {
        enabled = value;

        if (enabled) {
            setFillColor(sf::Color::Blue);
        }
        else {
            setFillColor(sf::Color(128,128,128));
        }
    }

    bool isEnabled() const {
        return enabled;
    }

    void setText(const std::string& text) {
        buttonText.setString(text);
        buttonText.setPosition(getSize().x / 2 - buttonText.getGlobalBounds().width / 2,
            getSize().y / 2 - buttonText.getGlobalBounds().height / 2);
    }

    void setPosition(sf::Vector2f pos)
    {
        this->sf::RectangleShape::setPosition(pos);
        buttonText.setPosition(sf::Vector2f(pos.x,pos.y));
    }
private:
    bool enabled;
    sf::Font buttonFont;  
    sf::Text buttonText;  
};

