//#include<iostream>
//#include"SFML\Graphics.hpp"
//#include"SFML\Window.hpp"
//#include"SFML\System.hpp"
//#include<math.h>
//#include<vector>
//#include<cstdlib>
//
////LENGTH OF VECTOR: |V| = sqrt(V.x^2 + V.y^2)
////NORMALIZE VECTOR: U = V / |V|
//
//using namespace sf;
//
//class Bullet {
//public:
//	Bullet(float radius = 5.f) : currVelocity(0.f, 0.f), maxSpeed(5.f){
//		shape.setRadius(radius);
//		shape.setFillColor(Color::Red);
//	};
//	CircleShape shape;
//	Vector2f currVelocity;
//	float maxSpeed;
//};
//
//int main()
//{
//	srand(time(NULL));
//	RenderWindow window(VideoMode(800, 600), "Game5", Style::Default);
//	window.setFramerateLimit(60);
//
//	//Player
//	CircleShape player(25.f);
//	player.setFillColor(Color::White);
//
//	//find direction by the distance of playerCenter and mousePos, then normalize it
//	Vector2f playerCenter;
//	Vector2f mousePos;
//	Vector2f aimDir;
//	Vector2f aimDirNorm;
//
//	//Bullets
//	Bullet b1;
//	std::vector<Bullet> bullets;
//
//	//Enemy
//	RectangleShape enemy;
//	std::vector<RectangleShape> enemies;
//	enemy.setFillColor(Color::Magenta);
//	enemy.setSize(Vector2f(50.f, 50.f));
//	int spawnTimer = 20;
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//		}
//
//		//update
//		//vectors
//		playerCenter = Vector2f(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
//		mousePos = Vector2f(Mouse::getPosition(window));
//		aimDir = mousePos - playerCenter;
//		aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
//		//player
//		if (Keyboard::isKeyPressed(Keyboard::W))
//		{
//			player.move(0.f, -15.f);
//		}
//		if (Keyboard::isKeyPressed(Keyboard::S))
//		{
//			player.move(0.f, +15.f);
//		}
//		if (Keyboard::isKeyPressed(Keyboard::A))
//		{
//			player.move(-15.f, 0.f);
//		}
//		if (Keyboard::isKeyPressed(Keyboard::D))
//		{
//			player.move(15.f, 0.f);
//		}
//		//shooting
//		if (Mouse::isButtonPressed(Mouse::Left))
//		{
//			b1.shape.setPosition(playerCenter);
//			b1.currVelocity = aimDirNorm * b1.maxSpeed;
//			bullets.push_back(Bullet(b1));
//		}
//		for (size_t i = 0; i < bullets.size(); i++)
//		{
//			bullets[i].shape.move(bullets[i].currVelocity);
//			//out of bounds
//			if (bullets[i].shape.getPosition().x + bullets[i].shape.getRadius() < 0 || bullets[i].shape.getPosition().x > window.getSize().x
//				|| bullets[i].shape.getPosition().y + bullets[i].shape.getRadius() < 0 || bullets[i].shape.getPosition().y > window.getSize().y)
//			{
//				bullets.erase(bullets.begin() + i);
//				break;
//			}
//			else//collusion
//			{
//				for (size_t k = 0; k < enemies.size(); k++)
//				{
//					if (bullets[i].shape.getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
//					{
//						bullets.erase(bullets.begin() + i);
//						enemies.erase(enemies.begin() + k);
//						break;
//					}
//				}
//			}
//			
//			std::cout << bullets.size() <<"\n"; //for testing
//		}
//		//enemies
//		if (spawnTimer >= 20 && enemies.size() < 50)
//		{
//			enemy.setPosition(Vector2f(rand() % int(window.getSize().x - enemy.getSize().x), rand() % int(window.getSize().y - enemy.getSize().y)));
//			enemies.push_back(enemy); //or RectangleShape(enemy)
//			spawnTimer = 0;
//		}
//		else 
//		{
//			spawnTimer++;
//		}
//		
//		window.clear();
//
//		//draw
//		//player
//		window.draw(player);
//		//bullets
//		for (size_t i = 0; i < bullets.size(); i++)
//		{
//			window.draw(bullets[i].shape);
//		}
//		//enemies
//		for (size_t i = 0; i < enemies.size(); i++)
//		{
//			window.draw(enemies[i]);
//		}
//		window.display();
//	}
//
//	return 0;
//}