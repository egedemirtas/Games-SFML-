#include<iostream>
#include<sstream>
#include<vector>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
using namespace sf;

int main()
{
	//Init Game
	float gridSizeF = 100.f;
	unsigned gridSizeU = static_cast<unsigned>(gridSizeF);

	float dt = 0.f;
	Clock dtClock;

	Vector2i mousePosScreen;
	Vector2i mousePosWindow;
	Vector2f mousePosView;
	Vector2u mousePosGrid;

	Font font;
	font.loadFromFile("Fonts/Dosis-Light.ttf");
	Text text;
	text.setCharacterSize(30);
	text.setFillColor(Color::Magenta);
	text.setFont(font);
	text.setPosition(20.f, 20.f);

	//Init window
	RenderWindow window(VideoMode(1200, 800), "SFML works!");
	window.setFramerateLimit(120);

	View view;
	view.setSize(1200.f, 800.f); //should be same as window, not a good idea to use constants
	view.setCenter(window.getSize().x / 2.f, window.getSize().y / 2.f);	//view's position is set from the center, not like shapes(right top), be careful the function takes floats!!!
	float viewSpeed = 100.f;

	//Init Game Elements
	RectangleShape shape(Vector2f(gridSizeF, gridSizeF));


	//Int the Map
	const int mapSize = 100; //you cant make this very big since after wards 2D array is created statically and this uses stack in memeory which is small
	//RectangleShape tileMap[mapSize][mapSize];  //dont use this, use dynamic array or vectors to use the heap memory
	//even after you make it dynamic when you make mapSize=100, you will lag a lot
	//so the main idea is to draw what you need according to the view, 
	//why would you draw and test collusion of all map when your player is in a specific place
	//to do this you need "fromX toX fromY toY" to enclose the area you want to draw
	std::vector<std::vector<RectangleShape>> tileMap;
	tileMap.resize(mapSize, std::vector<RectangleShape>());

	for (size_t i = 0; i < mapSize; i++)
	{
		tileMap[i].resize(mapSize, RectangleShape()); //add colums to the vector
		for (size_t k = 0; k < mapSize; k++)
		{
			tileMap[i][k].setSize(Vector2f(gridSizeF, gridSizeF));
			tileMap[i][k].setFillColor(Color::White);
			tileMap[i][k].setOutlineThickness(1.f);
			tileMap[i][k].setOutlineColor(Color::Blue);
			tileMap[i][k].setPosition(i * gridSizeF, k * gridSizeF);
		}
	}

	int fromX = 0, 
		toX = 0, 
		fromY = 0, 
		toY = 0;


	//Int the green square selector
	RectangleShape tileSelector(Vector2f(gridSizeF, gridSizeF));
	tileSelector.setFillColor(Color::Transparent);
	tileSelector.setOutlineThickness(1.f);
	tileSelector.setOutlineColor(Color::Green);

	while (window.isOpen())
	{
		//Update delta time
		dt = dtClock.restart().asSeconds();

		//Update Mouse Position
		mousePosScreen = Mouse::getPosition(); //this is relative to your monitor's screen
		mousePosWindow = Mouse::getPosition(window); //this is relative to the window of game
		window.setView(view); //you need to set view to see mousePosView
		mousePosView = window.mapPixelToCoords(mousePosWindow);
		if (mousePosView.x >= 0.f)
		{
			mousePosGrid.x = mousePosView.x / gridSizeU;
		}
		if (mousePosView.y >= 0.f)
		{
			mousePosGrid.y = mousePosView.y / gridSizeU;
		}
		window.setView(window.getDefaultView());

		//Update Game Elements
		tileSelector.setPosition(mousePosGrid.x * gridSizeF, mousePosGrid.y * gridSizeF); //so the green rectangle follows the grid that your mouse belongs to

		//Update UI to test mouse positions
		std::stringstream ss;
		ss << "Screen: " << mousePosScreen.x << " / " << mousePosScreen.y << "\n"
			<< "Window: " << mousePosWindow.x << " / " << mousePosWindow.y << "\n"
			<< "View: " << mousePosView.x << " / " << mousePosView.y << "\n"
			<< "Grid: " << mousePosGrid.x << " / " << mousePosGrid.y << "\n";
		text.setString(ss.str());
		//you will see that, before moving the view:
		//the mousePosWindow, mousePosView are the same, they are both 0,0 at left top of window
		//the mousePosScreen is 0,0 at top left of the screen
		//after you move the view:
		//mousePosScreen, mousePosWindow doesnt change
		//mousePosView changes since you changed the view with keys, and mousePosGrid changes since it is dependent on view


		//Events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//Update
		//Update Input for Camera
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Left
		{
			view.move(-viewSpeed * dt, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Right
		{
			view.move(viewSpeed * dt, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //Up
		{
			view.move(0.f, -viewSpeed * dt);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //Down
		{
			view.move(0.f, viewSpeed * dt);
		}

		//Draw
		window.clear();

		//Draw Game elements
		window.setView(view);

		window.draw(shape);
		/*//modified this to draw enclosed map
		for (size_t i = 0; i < mapSize; i++)
		{
			for (size_t k = 0; k < mapSize; k++)
			{
				window.draw(tileMap[i][k]);
			}
		}
		*/
		//so you are only rendering *only* 3x3 map 
		//when you make a game assume the mouse is the player
		//for collisions you only have to check 9 tiles,
		//it is way more efficient and faster(optimized) than checking all the walls and whether they collide with player
		/*
		fromX = mousePosGrid.x - 1;
		toX = mousePosGrid.x + 2;
		fromY = mousePosGrid.y - 1;
		toY = mousePosGrid.y + 2;
		*/
		//same as above but view oriented
		fromX = view.getCenter().x / gridSizeF- 6;
		toX = view.getCenter().x / gridSizeF + 7;
		fromY = view.getCenter().y / gridSizeF - 5;
		toY = view.getCenter().y / gridSizeF + 6;
		//do the "from"
		if (fromX < 0)
		{
			fromX = 0;
		}
		else if (fromX >= mapSize)
		{
			fromX = mapSize - 1;
		}
		if (fromY < 0)
		{
			fromY = 0;
		}
		else if (fromY >= mapSize)
		{
			fromY = mapSize - 1;
		}
		//do the "to"
		if (toX < 0)
		{
			toX = 0;
		}
		else if (toX >= mapSize)
		{
			toX = mapSize - 1;
		}
		if (toY < 0)
		{
			toY = 0;
		}
		else if (toY >= mapSize)
		{
			toY = mapSize - 1;
		}

		for (size_t i = fromX; i < toX; i++)
		{
			for (size_t k = fromY; k < toY; k++)
			{
				window.draw(tileMap[i][k]);
			}
		}
		window.draw(tileSelector);

		//Draw UI
		window.setView(window.getDefaultView());	//reset the view at the end of drawing, 
											//because if i want to draw GUI elements in the next frame,
											//i dont want to do it using camera view
		window.draw(text);


		window.display();
	}

	return 0;
}