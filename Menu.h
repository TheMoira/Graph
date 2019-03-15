#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include "font.h"
//#include "font.h"



class Menu : public sf::Drawable
{
private:
	sf::Font font;
	sf::Text *text;
	//prostaokat do wypisywania
	sf::RectangleShape *rectangle;

	sf::Texture *colors_texture;
	sf::Sprite *colors_sprite;
	sf::Uint8 *colors_pixels;

	//rozmiar paska z kolorami
	const unsigned int colors_size_x = 765;
	const unsigned int colors_size_y = 60;
	void draw_to_color_pixels(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b);



public:
	Menu();

	~Menu();

	void outtextxy(sf::RenderTarget& target, float x, float y, const wchar_t *str) const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool MouseOnColors() const;

	sf::Color colorPicked() const;

};

char WhichKey(sf::Keyboard::Key k);

