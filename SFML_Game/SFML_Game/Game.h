#ifndef GAME_H
#define GAME_H

#include<iostream>
#include <ctime>
#include <cstdlib>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	//Initialization
	void initWindow();

public:

	//Constructor/Destructor
	Game();
	virtual ~Game();

	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif // !GAME_H