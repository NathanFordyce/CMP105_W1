#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	
	//3 Squares
	rect1.setSize(sf::Vector2f(10, 10));
	rect1.setPosition(120, 120);
	rect1.setFillColor(sf::Color::Blue);

	rect2.setSize(sf::Vector2f(30, 30));
	rect2.setPosition(110, 110);
	rect2.setFillColor(sf::Color::Green);

	rect3.setSize(sf::Vector2f(50, 50));
	rect3.setPosition(100, 100);
	rect3.setFillColor(sf::Color::Red);

	rect4.setSize(sf::Vector2f(30, 30));

	rect4.setFillColor(sf::Color::Green);

	//Text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font \n";
	}

	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	rect4.setPosition(pos.x - 30, pos.y - 30);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect3);
	window->draw(rect2);
	window->draw(rect1);

	window->draw(text);

	window->draw(rect4);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}