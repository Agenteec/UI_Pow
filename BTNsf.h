#pragma once
#include <SFML/Graphics.hpp>
#include <string>
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
        buttonString = "Button";
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
        sf::FloatRect textBounds = buttonText.getLocalBounds();
        sf::Vector2f buttonSize = getSize();
        buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f,
            textBounds.top + textBounds.height / 2.0f);
        buttonText.setPosition(buttonSize.x / 2.0f, buttonSize.y / 2.0f);
    }

    void setPosition(sf::Vector2f pos)
    {
        this->sf::RectangleShape::setPosition(pos);
        buttonText.setPosition(sf::Vector2f(pos.x,pos.y));
        setText(buttonString);
    }
private:
    bool enabled;
    sf::Font buttonFont;  
    sf::Text buttonText;
    std::string buttonString;
};