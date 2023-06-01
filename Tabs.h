#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
using namespace sf;




class Tab
{
	Font font;
	RectangleShape pods;
	Text podst;
	bool isPD = 0;
public:
	Tab(Font font) :IsInit(0),font(font){
		pods = RectangleShape(Vector2f(45, 15));
		pods.setFillColor(Color::White);
		pods.setOutlineColor(Color::Black);
		pods.setOutlineThickness(1);
		podst.setFont(this->font);
		podst.setFillColor(Color(0,0,0));
		podst.setCharacterSize(10);
		podst.setString("0");

	}
	int x, y;
	Vector2i pos;
	void draw(RenderWindow& w) {
		for (size_t i = 0; i < 15; i++)
		{
			for (size_t j = 0; j < 15; j++)
			{
				w.draw(mas[i][j].rect);
				w.draw(mas[i][j].text);
				
			}
		}
		if (isPD)
		{
			w.draw(pods);
			podst.setPosition(pods.getPosition().x+10, pods.getPosition().y);
			w.draw(podst);
		}
		
	}
	void drawPow(RenderWindow& w,sf::Event e) {
		pos = sf::Mouse::getPosition(w);
		for (size_t i = 0; i < 15; i++)
		{
			for (size_t j = 0; j < 15; j++)
			{
				if (mas[i][j].color!=0)
				{
					if (mas[i][j].rect.getGlobalBounds().contains(pos.x, pos.y))
					{
						pods.setPosition(pos.x,pos.y);
						podst.setString(std::to_string((int)(mas[i][j].color+1))+"^"+std::to_string(wich_pow(mas[i][j].data)));
						isPD = 1;
						i = 15;
						break;
					}
					isPD = 0;
				}
				
			}
		}
	}
	void Init()
	{
		IsInit = true;
		for (size_t i = 0; i < 15; i++)
		{
			for (size_t j = 0; j < 15; j++)
			{
				

				mas[i][j].rect.setSize(sf::Vector2f(50.f, 50.f));
				switch (mas[i][j].color)
				{
				case 0:
					mas[i][j].rect.setFillColor(sf::Color::White);
					break;
				case 1:
					mas[i][j].rect.setFillColor(sf::Color(156,48,210));
					break;
				case 2:
					mas[i][j].rect.setFillColor(sf::Color(120, 48, 210));
					break;
				default:
					break;
				}
				
				mas[i][j].rect.setOutlineColor(sf::Color::Black);
				mas[i][j].rect.setOutlineThickness(1.f);
				mas[i][j].rect.setPosition(60.f + j * 55.f, 60.f + i * 55.f);

				mas[i][j].text.setFont(font);
				mas[i][j].text.setCharacterSize(20);
				mas[i][j].text.setFillColor(sf::Color::Black);
				mas[i][j].text.setString(std::to_string(mas[i][j].data));
				sf::FloatRect textBounds = mas[i][j].text.getLocalBounds();
				mas[i][j].text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
				mas[i][j].text.setPosition(mas[i][j].rect.getPosition() + sf::Vector2f(25.f, 25.f));
			}
		}
	}

class TabIB
{
public:
	int data;
	char color;
	RectangleShape rect;
	Text text;
};
TabIB mas[15][15];
void Test_click();
bool is_pow2(int x);
bool is_pow3(int x);
void Random_click();
int Find_clicked();
int wich_pow(int x);
bool IsInit;


};

