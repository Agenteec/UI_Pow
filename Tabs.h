#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
using namespace sf;




class Tab
{

public:
	int x, y;
	void draw(int* mas[], RenderWindow& w) {

	}


class TabIB
{
public:
	int data;
	char color;
};
TabIB mas[15][15];
void Test_click();
bool is_pow2(int x);
bool is_pow3(int x);
void Random_click();
int Find_clicked();
int wich_pow(int x);



};

