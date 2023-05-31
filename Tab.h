#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
using namespace sf;
bool is_pow2(int x) {
    if (x % 2 == 0) {
        while (x % 2 == 0) {
            x /= 2;
        }
        if (x == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else { return false; }
}
bool is_pow3(int x){
        if (x % 3 == 0) {
            while (x % 3 == 0) {
                x /= 3;
            }
            if (x == 1) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
 }

int wich_pow(int x) {
	int g;
	int n=0;
	if (x % 2 == 0) {
		g = 2;
	}
	else {
		g = 3;
	}
	while (x > 1) {
		x /= g;
		n++;
	}
	return n;

}
struct TabIB
{
	int data;
	char color;
};
TabIB mas[15][15];
void Random_click() {
	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; i < 15; i++) {
			mas[i][j].data = rand();
		}
	}
};
void Test_click() {
	int c = 1;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; i < 15; i++){
			mas[i][j].data = c;
			c++;
		}
	}
}
int Find_clicked() {
	int n = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; i < 15; i++) {
			if (is_pow2(mas[i][j].data)) {
				mas[i][j].color=1;
				n++;
			}
			else {
				if (is_pow3(mas[i][j].data)) {
					mas[i][j].color = 2;
					n++;
				}
				else {
					mas[i][j].color = 0;
				}
			}
		}
	}
	return n;

}
class Tab
{
	
public:
	int x, y;
	Tab(int x, int y):x(x), y(y) {

	}
	void draw(int* mas[], RenderWindow& w) {
		
	}
};

