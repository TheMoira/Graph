// Calosc mozna dowolnie edytowac wedle uznania. 

#include "Menu.h"
#include "Draws.h"
#include "font.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>



int main()
{
	//otwiera okno
 sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01",sf::Style::Titlebar | sf::Style::Close);
 sf::Event event;
 sf::RenderTexture Rtxtr;
 sf::Texture txtr;

 char pressedkey;
 Menu menu;
 Draws* draw;
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
			pressedkey = WhichKey(sf::Event::KeyEvent::code);
			break;
		case sf::Event::MouseButtonPressed:
			if (MouseOnColors())
			{
				if(pressedkey == 'f') currentColor = menu.colorPicked();
				else if(pressedkey == 'b') bgcolor = menu.colorPicked();
			}
			else
			{
				draw->_isDrawing = true;
				draw->SetAColor(currentColor);
				draw->SetABackgroundColor(bgcolor);
				draw->StartDrawing(dynamic_cast<sf::Vector2f*>(sf::Mouse::getPosition()*));
				draw->TimeToDraw(pressedkey);
			}

			break;
		case sf::Event::MouseMoved:
			if (draw->_isDrawing == true)
			{
				draw->Update();
			}
			
			break;
		case sf::Event::MouseButtonReleased:
			draw->_isDrawing = false;
			draw->FinishDrawing( dynamic_cast<sf::Vector2f*>(sf::Mouse::getPosition()*));
	

			break;
	   }


	 //sf::Color color = sf::Shape::getOutlineColor();
	 
    }
   //Draw BEGIN
  


   
   //wyczysc okno
   window.clear(sf::Color::Black);
   window.draw(draw->shape);


   //dodaj narysowane ksztalty do tekstury


   //dodaj teksture do sprite

   draw->load(Rtxrt, txtr);
   window.draw(menu);
   window.draw(draw->returnDrawing(Rtxtr));


   //wyrysuj sprite


   window.display();



   //Draw END
  }
 return 0;
}