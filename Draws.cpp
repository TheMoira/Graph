#include "D:\docs\agh\semestr4\grafika\Draws.h"
#include <iostream>

Draws::count = 0;



Draws::Draws(sf::RenderTexture* r)
{
	r->create(796, 636);
	r->clear(sf::Color::Black);
}


Draws::~Draws()
{
	for (int i = 0; i < count; i++)
	{
		delete[] ShapeArray[i];
	}
}



void Draws::TimeToDraw(char mode)
{
	_mode = mode;

	switch (_mode)
	{
	case 'r':
		SetABackgroundColor(sf::Color::Transparent);
		DrawRect();
		break;
	case 'a':
		DrawRect();
	case 'c':
		DrawCircle();
		break;
	case 'l':
		DrawLine();
		break;
	default:
		std::cout << "Not an option\n";
	}
}
//void Draws::EndDrawing();



sf::Sprite Draws::returnDrawing(sf::RenderTexture rt)
{
	sf::Sprite sprite(rt.getTexture());
	sprite.setPosition(2.0, 62.0);
	return sprite;
}

void Draws::SetAColor(sf::Color color)
{
	_color = color;
}

void Draws::SetABackgroundColor(sf::Color color)
{
	_bgcolor = color;
}

void Draws::DrawLine()
{
	sf::VertexArray* l = new sf::VertexArray(sf::LinesStrip, 5);

	(*l)[0].position = _begin;
	(*l)[1].position = _end;

	(*l)[0].color = _color;
	(*l)[1].color = _color;

	shape = l;
}


void Draws::DrawRect()
{
	sf::RectangleShape *rect = new sf::RectangleShape(sf::Vector2f(1,1));
	
	rect->setFillColor(_bgcolor);
	rect->setOutlineColor(_color);
	rect->setOutlineThickness(2.0);
	rect->setPosition(_begin);
	rect->setSize(_size);

	shape = rect;

}

void Draws::DrawCircle()
{
	sf::CircleShape* circle = new sf::CircleShape(1.0);


	circle->setOutlineColor(_color);
	circle->setFillColor(_bgcolor);
	circle->setPosition(_begin.x - 1, _begin.y - 1);
	circle->setRotation(atan2f(0, 0));
	circle->setOutlineThickness(2.0);

	shape = circle;
}

void Draws::load(sf::RenderTexture rt, sf::Texture t)
{
	rt.clear(sf::Color::Black);
	rt.draw(sf::Sprite(t));


	for (int i = 0; i < count; i++)
	{
		rt.draw(*(*ShapeArray[i]));
	}
		

	rt.draw(*shape);
	rt.display();

}

void Draws::StartDrawing(sf::Vector2f* start)
{
	count++;
	_begin = *start;
}
void Draws::FinishDrawing(sf::Vector2f* end)
{
	if (count==1)
	{
		ShapeArray = new sf::Drawable*[1];
		ShapeArray[0] = shape;
		goto finish;
	}

	sf::Drawable **temp = new sf::Drawable*[count - 1];
	for (int i = 0;i < count-1;i++)
	{
		*temp[i] = *ShapeArray[i];
	}

	ShapeArray = new sf::Drawable*[count];
	for (int i = 0;i < count-1;i++)
	{
		*ShapeArray[i] = *temp[i];
	}

	ShapeArray[count - 1] = shape;

	for (int j = 0;j < count - 1;j++)
	{
		delete[] temp[j];
	}

	finish:
	_end = end;
}

void Draws::Update()
{
	switch (mode)
	{
	case 'r':
		UpRect();
		break;
	case 'c':
		UpCircle();
		break;
	case 'l':
		UpLine();
		break;
	}
}
void Draws::UpLine()
{
	sf::VertexArray* line = static_cast<sf::VertexArray*>shape;
	(*line)[1].position = _end;
}

void Draws::UpRect()
{
	sf::RectangleShape* rect = static_cast<sf::RectangleShape*>shape;
	float X = 1.0;
	float Y = 1.0;



	if (rect->getPosition().x > _end.x)
	{
		X *= -1;
	}

	if (rect->getPosition().y > _end.y)
	{
		Y *= -1;
	}

	sf::Vector2f newsize;
	newsize.x = abs(rect->getPosition().x - _end.x);
	newsize.y = abs(rect->getPosition().y - _end.y);

	rect->setScale(X,Y);
	rect->setSize(newsize);
}

void Draws::UpCircle()
{
	sf::CircleShape* circle = static_cast<sf::CircleShape*>(shape);

	float angle = atan2f(_end.x - _begin.x, _end.y - _begin.y);
	float r = sqrt(pow(_end.x - _begin.x, 2) + pow(_end.y - _begin.y, 2)) / 2;
	
	float X = 1.0;
	float Y = 1.0;
	if (circle->getPosition().x > _end.x)
	{
		X *= -1;
	}

	if (circle->getPosition().y > _end.y)
	{
		Y *= -1;
	}

	circle->setRotation(angle);
	circle->setRadius(r);
	circle->setScale(X,Y);
}

void Draws::SaveToFile(std::string name, sf::RenderTexture rendert) const
{
	rendert.getTexture().copyToImage().saveToFile(name);
}
void Draws::OpenFromFile(std::string name, sf::RenderTexture* rendert)
{
	rendert->OpenFromFile(name);
	rendert->setSmooth(true);
}