#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>


class Draws
{

public:

	Draws(sf::RenderTexture* r);

	~Draws();

	void TimeToDraw(char mode);
//	void EndDrawing();

	sf::Sprite returnDrawing(sf::RenderTexture *rt) const;
	void SetAColor(sf::Color color);
	void SetABackgroundColor(sf::Color color);

	void DrawLine();
	void DrawRect();
	void DrawCircle();

	void load(sf::RenderTexture *rt, sf::Texture t);

	void StartDrawing(sf::Vector2f*);
	void FinishDrawing(sf::Vector2f*);

	void Update();

	void UpLine();
	void UpRect();
	void UpCircle();

	void SaveToFile(std::string name, sf::RenderTexture rendert) const;
	void OpenFromFile(std::string name, sf::RenderTexture* rendert);

	sf::Drawable* retShape() { return shape; }
	bool _isDrawing = false;
	static int count;

private:

	char _mode;
	sf::Drawable* shape;
	sf::Color _color = sf::Color::White;
	sf::Color _bgcolor = sf::Color::Transparent;
	sf::Vector2f _begin = sf::Vector2f(0.0, 0.0);
	sf::Vector2f _end = sf::Vector2f(0.0, 0.0);
	sf::Vector2f _size = sf::Vector2f(0.0, 0.0);

	sf::Drawable **ShapeArray;
	


};

