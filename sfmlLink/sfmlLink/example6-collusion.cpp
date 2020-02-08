//#include<iostream>
//#include<cmath>
//#include"SFML\Graphics.hpp"
//#include"SFML\Window.hpp"
//#include"SFML\System.hpp"
//
//using namespace sf;
//
//int main()
//{
//	const unsigned WINDOW_WIDTH = 1200;
//	const unsigned WINDOW_HEIGHT = 800;
//	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
//	window.setFramerateLimit(120);
//
//	float dt;
//	Clock dt_clock;
//
//	const float gridSize = 50.f; //this is to divide the window into grids, represents one side of a grid box
//								 //also the walls will be according to 1 gridSize, also their position
//
//	Vector2i mousePosGrid; //to find which grid the mouse position belong to when adding/removing grids
//
//	//PLAYER
//	RectangleShape player;
//	player.setFillColor(Color::Green);
//	player.setSize(Vector2f(gridSize, gridSize));
//	const float movementSpeed = 100.f;
//	Vector2f velocity;
//
//	//WALLS
//	std::vector<RectangleShape> walls;
//
//	RectangleShape wall;
//	wall.setFillColor(Color::Red);
//	wall.setSize(Vector2f(gridSize, gridSize));
//	wall.setPosition(gridSize * 5, gridSize*2);
//
//	walls.push_back(wall);
//
//	//COLLISION
//	FloatRect nextPos; //basically a bounding box
//	RectangleShape nextBox; //this box is to visualise nextPos
//	nextBox.setSize(Vector2f(gridSize, gridSize));
//	nextBox.setFillColor(Color::Transparent);
//	nextBox.setOutlineColor(Color::White);
//	nextBox.setOutlineThickness(1.f);
//
//	while (window.isOpen())
//	{
//		dt = dt_clock.restart().asSeconds();
//
//		mousePosGrid.x = Mouse::getPosition(window).x / (int)gridSize;		//divide window to grids and findout which grid the mouse belong to
//		mousePosGrid.y = Mouse::getPosition(window).y / (int)gridSize;
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		//add wall
//		if (Mouse::isButtonPressed(Mouse::Left))
//		{
//			bool exists = false;
//			for (size_t i = 0; i < walls.size() && !exists; i++) //go through all the existing walls
//			{
//				if (walls[i].getPosition().x / (int)gridSize == mousePosGrid.x		//if the mouse is on an existing wall's grid break the loop
//					&& walls[i].getPosition().y / (int)gridSize == mousePosGrid.y)
//				{
//					exists = true;
//				}
//			}
//
//			if (!exists)		//if a wall does not exist under the grid of mouse, create one at that grid
//			{
//				wall.setPosition(mousePosGrid.x * gridSize, mousePosGrid.y * gridSize);
//				walls.push_back(wall);
//			}
//		}
//
//		//Remove wall
//		if (Mouse::isButtonPressed(Mouse::Right))
//		{
//			bool exists = false;
//			int index = -1;
//			for (size_t i = 0; i < walls.size() && !exists; i++)
//			{
//				if (walls[i].getPosition().x / (int)gridSize == mousePosGrid.x
//					&& walls[i].getPosition().y / (int)gridSize == mousePosGrid.y)
//				{
//					exists = true;
//					index = i;
//				}
//			}
//
//			if (exists)
//			{
//				walls.erase(walls.begin() + index);
//			}
//		}
//
//		//UPDATES
//		velocity.x = 0.f;
//		velocity.y = 0.f;
//		if (Keyboard::isKeyPressed(Keyboard::W))
//		{
//			velocity.y += -movementSpeed * dt;
//		}
//		if (Keyboard::isKeyPressed(Keyboard::S))
//		{
//			velocity.y += movementSpeed * dt;
//		}
//		if (Keyboard::isKeyPressed(Keyboard::A))
//		{
//			velocity.x += -movementSpeed * dt;
//		}
//		if (Keyboard::isKeyPressed(Keyboard::D))
//		{
//			velocity.x += movementSpeed * dt;
//		}
//
//		//COLLISION
//		for (auto &wall : walls)
//		{
//			FloatRect playerBounds = player.getGlobalBounds(); //nothing fancy here, just to make coding easier later on
//			FloatRect wallBounds = wall.getGlobalBounds();
//			nextPos = playerBounds;		//make them in same position, then iterate nextPos by adding velocity, so you know what would happen in the next frame
//			nextPos.left += velocity.x; // normally no multiplication with 40, just to make visualisation clear
//			nextPos.top += velocity.y;
//
//			nextBox.setPosition(nextPos.left, nextPos.top);
//
//			if (wallBounds.intersects(nextPos))
//			{
//				//velocity.x = 0.f; //you can also do these but when you collide to wall you cant glide through that surface
//				//velocity.y = 0.f;
//
//				//right collusion
//				if (playerBounds.left < wallBounds.left		//player's left should be smaller than wall's left in x axis
//					&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width //same for right side
//					&& playerBounds.top < wallBounds.top + wallBounds.height  //player's top should be smaller than wall's bottom in y axis
//					&& playerBounds.top + playerBounds.height > wallBounds.top)//same for bottom
//				{
//					velocity.x = 0.f;
//					player.setPosition(wallBounds.left - playerBounds.width, player.getPosition().y);
//				}
//				//left collusion
//				else if (playerBounds.left > wallBounds.left		//player's left should be smaller than wall's left in x axis
//					&& playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width //same for right side
//					&& playerBounds.top < wallBounds.top + wallBounds.height  //player's top should be smaller than wall's bottom in y axis
//					&& playerBounds.top + playerBounds.height > wallBounds.top)//same for bottom
//				{
//					velocity.x = 0.f;
//					player.setPosition(wallBounds.left + playerBounds.width, player.getPosition().y);
//				}
//
//				//bottom collusion
//				if (playerBounds.top < wallBounds.top		
//					&& playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height 
//					&& playerBounds.left < wallBounds.left + wallBounds.width  
//					&& playerBounds.left + playerBounds.width > wallBounds.left)
//				{
//					velocity.y = 0.f;
//					player.setPosition(player.getPosition().x, wallBounds.top - playerBounds.height);
//				}
//				//top collusion
//				else if (playerBounds.top > wallBounds.top
//					&& playerBounds.top - playerBounds.height > wallBounds.top - wallBounds.height
//					&& playerBounds.left < wallBounds.left + wallBounds.width
//					&& playerBounds.left + playerBounds.width > wallBounds.left)
//				{
//					velocity.y = 0.f;
//					player.setPosition(player.getPosition().x, wallBounds.top + playerBounds.height);
//				}
//				std::cout << "Collision" << "\n";
//			}
//		}
//		
//		player.move(velocity);
//
//		//WINDOW COLLISION
//		if (player.getPosition().x < 0)
//		{
//			player.setPosition(0.f, player.getPosition().y);
//		}
//		if (player.getPosition().x + player.getGlobalBounds().width > WINDOW_WIDTH)
//		{
//			player.setPosition(WINDOW_WIDTH - player.getGlobalBounds().width, player.getPosition().y);
//		}
//		if (player.getPosition().y < 0)
//		{
//			player.setPosition(player.getPosition().x, 0.f);
//		}
//		if (player.getPosition().y + player.getGlobalBounds().height > WINDOW_HEIGHT)
//		{
//			player.setPosition(player.getPosition().x, WINDOW_HEIGHT - player.getGlobalBounds().height);
//		}
//
//		window.clear();
//
//		//DRAW
//		window.draw(player);
//
//		for (auto &i : walls)
//		{
//			window.draw(i);
//		}
//
//		//window.draw(nextBox);
//
//		window.display();
//	}
//
//	return 0;
//}