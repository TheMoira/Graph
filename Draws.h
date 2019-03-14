#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>


class Draws
{

public:

	Draws();

	~Draws();

	void SetAColor(sf::Color color);
	void SetABackgroundColor(sf::Color color);

	void DrawLine();
	void DrawRect();
	void DrawCircle();

	void StartDrawing(double x, double y);
	void FinishDrawing(double x, double y);
	

	void SaveToFile(std::string name) const;
	void OpenFromFile(std::string name);



};

