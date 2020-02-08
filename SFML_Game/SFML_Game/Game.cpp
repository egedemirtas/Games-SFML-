#include "Game.h"

//Static Functions

//Initializer Function
void Game::initWindow()
{
	this-> window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

//Constructor/Destructor

Game::Game() 
{
	this->initWindow();
}

Game::~Game() 
{
	delete this->window;

}

//updates the delta time for each frame in Game::run()
void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
	system("cls");
	std::cout << this->dt << "\n";
}

//Functions
void Game::updateSFMLEvents()
{

	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}

}

void Game::update()
{
	this->updateSFMLEvents();
}

void Game::render()
{
	window->clear();
	//Render Items
	window->display();
}

void Game::run()
{

	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

