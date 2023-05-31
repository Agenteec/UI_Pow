#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Tab_rect {
	RectangleShape box(Vector2f(800.f, 80.f));
};
class Tab
{
	
public:
	int x, y;
	Tab_rect tab;
	Tab(int x, int y):x(x), y(y) {

	}
};

