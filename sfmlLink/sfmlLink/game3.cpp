//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Network.hpp>
//#include <iostream>
//#include <vector>
//#include <cstdlib>
///*A random number generator requires a number(it is called seed) to generate random numbers . 
//If the random number generator is given the same seed then every time it will generate the same sequence of random numbers . 
//
//For example :-
//If you run the program and it is generating random sequence 2,78,45,60 . 
//If second time you run the program you will again get the same sequence 2,78,45,60.
//
//srand function is used to change the seed of the random number generator.By setting srand(time(NULL)) , 
//you are setting the seed of the random number generator to the current time.
//By doing this every time you run the program you will get different random sequences :-*/
//using namespace sf;
//
//int main()
//{
//	srand(time(NULL));
//	RenderWindow window(VideoMode(640, 480), "Game3");
//	window.setFramerateLimit(60);
//
//	//BALLS
//	CircleShape projectile;
//	projectile.setFillColor(Color::Red);
//	projectile.setRadius(5.f);
//
//	RectangleShape enemy;
//	enemy.setFillColor(Color::Magenta);
//	enemy.setSize(Vector2f(50.f, 50.f));
//	int enemySpawnTimer = 0;
//
//	CircleShape player;
//	player.setFillColor(Color::White);
//	player.setRadius(30.f);
//	player.setPosition(window.getSize().x/2 - player.getRadius(), window.getSize().y - player.getRadius()*2 - 10.f); //initial position is center bottom
//	Vector2f playerCenter; //this is needed so that when you shoot projectiles it is shot out of player's center point
//	int shootTimer = 0;
//
//	std::vector<CircleShape> projectiles;
//	std::vector<RectangleShape> enemies;
//
//	while(window.isOpen())
//	{
//		Event event;
//		while(window.pollEvent(event))
//		{
//			if (event.type == Event::Closed) 
//			{
//				window.close();
//			}
//		}
//
//		//UPDATE player & projectile
//		playerCenter = Vector2f(player.getPosition().x + player.getRadius() - projectile.getRadius(), player.getPosition().y + player.getRadius()); //record the position of player(center of it)
//		if (shootTimer < 5) //shoot projectiles 3s at a time
//			shootTimer++;
//
//		player.setPosition(Mouse::getPosition(window).x, window.getSize().y - player.getRadius() * 2 - 10.f); //move player with mouse
//
//		if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 5) //shoot
//		{
//			projectile.setPosition(playerCenter);
//			projectiles.push_back(CircleShape(projectile));
//			shootTimer = 0;
//		}
//
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			projectiles[i].move(0.f, -10.f);
//			if (projectiles[i].getPosition().y <= 0)//erase projectiles if out of screen
//			{
//				projectiles.erase(projectiles.begin() + i); //take projectiles, give the beginning iterator and add i to find the location
//			}
//		}
//
//		//UPDATE enemies
//		if (enemySpawnTimer < 20) //spawn time
//		{
//			enemySpawnTimer++;
//		}
//
//		if (enemySpawnTimer >= 20)
//		{
//			enemy.setPosition(rand() % int(window.getSize().x - enemy.getSize().x), -enemy.getSize().y); //spawn enemies in random locations on top
//			enemies.push_back(RectangleShape(enemy));
//			enemySpawnTimer = 0;
//		}
//
//		for (size_t i = 0; i < enemies.size(); i++)//move enemies
//		{
//			enemies[i].move(0.f, 7.f);
//			if (enemies[i].getPosition().y >= window.getSize().y)//remove enemies that are out of window
//			{
//				enemies.erase(enemies.begin() + i);
//			}
//		}
//
//		//Collusion
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			for (size_t j = 0; j < enemies.size(); j++)
//			{
//				if (projectiles[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds()))
//				{
//					projectiles.erase(projectiles.begin()+ i);
//					enemies.erase(enemies.begin() + j);
//					break;
//				}
//			}
//		}
//		window.clear();
//
//		//DRAW
//
//		for (size_t i = 0; i < enemies.size(); i++)
//		{
//			window.draw(enemies[i]);
//		}
//
//		for (size_t i = 0; i < projectiles.size(); i++)
//		{
//			window.draw(projectiles[i]);
//		}
//		window.draw(player);
//		window.display();
//
//	}
//	return 0;
//}