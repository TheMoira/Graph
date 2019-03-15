// Calosc mozna dowolnie edytowac wedle uznania. 
#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Draws.h"
#include "Menu.h"



int main()
{
	//otwiera okno
	sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01", sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	sf::RenderTexture Rtxtr;
	sf::Texture txtr;

	char pressedkey;
	Menu menu;
	Draws* draws = new Draws(&Rtxtr);
	sf::Color currentColor = sf::Color::White;
	sf::Color bgcolor = sf::Color::Transparent;

	//co ile odswieza bufor
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		window.clear(sf::Color::Black);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			pressedkey = '0';


			switch (event.type)
			{
			case sf::Event::KeyPressed:
				pressedkey = WhichKey(event.key.code);
				break;
			case sf::Event::MouseButtonPressed:
				if (menu.MouseOnColors())
				{
					if (pressedkey == 'f') currentColor = menu.colorPicked();
					else if (pressedkey == 'b') bgcolor = menu.colorPicked();
				}
				else
				{
					draws->_isDrawing = true;
					draws->SetAColor(currentColor);
					draws->SetABackgroundColor(bgcolor);
					draws->StartDrawing(&(sf::Vector2f)(sf::Mouse::getPosition()));
					draws->TimeToDraw(pressedkey);
				}

				break;
			case sf::Event::MouseMoved:
				if (draws->_isDrawing == true)
				{
					draws->Update();
				}

				break;
			case sf::Event::MouseButtonReleased:
				draws->_isDrawing = false;
				draws->FinishDrawing(&(sf::Vector2f)(sf::Mouse::getPosition()));


				break;
			}


			//sf::Color color = sf::Shape::getOutlineColor();

		}
		//Draw BEGIN




		//wyczysc okno
		window.clear(sf::Color::Black);

		if (Draws::count != 0)
		{
			window.draw(*(draws->retShape()));
			draws->load(&Rtxtr, txtr);
			window.draw(menu);
			window.draw(draws->returnDrawing(&Rtxtr));
		}
		


		//dodaj narysowane ksztalty do tekstury

		


		//wyrysuj sprite


		window.display();



		//Draw END
	}
	return 0;
}