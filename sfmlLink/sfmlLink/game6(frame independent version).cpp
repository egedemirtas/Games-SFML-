//#include<iostream>
//#include"SFML\Graphics.hpp"
//#include"SFML\Window.hpp"
//#include"SFML\System.hpp"
//#include<math.h>
//#include<vector>
//#include<cstdlib>
//#include <string>
//
////LENGTH OF VECTOR: |V| = sqrt(V.x^2 + V.y^2)
////NORMALIZE VECTOR: U = V / |V|
//
//using namespace sf;
//
//class Bullet {
//public:
//	Sprite shape;
//	Texture* texture;
//	int damage;
//
//	Bullet(Texture* texture, Vector2f pos) :damage(1) {
//		this->texture = texture;
//		this->shape.setTexture(*texture);
//		this->shape.setScale(0.07f, 0.07f);
//		this->shape.setPosition(pos);
//	}
//};
//
//class Player {
//public:
//	Sprite shape;
//	Texture* texture;
//	int hp;
//	int hpMax;
//	int score;
//	std::vector<Bullet> bullets;
//	Player(Texture* texture) :hpMax(10), score(0) {
//		this->hp = hpMax;
//		this->texture = texture;
//		this->shape.setTexture(*texture);
//		this->shape.setScale(0.1f, 0.1f);
//	}
//};
//
//class Enemy {
//public:
//	Sprite shape;
//	int hpMax;
//	int hp;
//	Text enemyHp;
//
//	Enemy(Texture* texture, Vector2u pos, Font& font) { //always pass font with reference
//		this->hpMax = rand() % 3 + 1;
//		this->hp = this->hpMax;
//		this->shape.setTexture(*texture);
//		this->shape.setScale(0.1f, 0.1f);
//		this->shape.setPosition(pos.x, rand() % (int)(pos.y - this->shape.getGlobalBounds().height));
//		enemyHp.setFont(font);
//		enemyHp.setStyle(Text::Bold);
//		enemyHp.setCharacterSize(15);
//		enemyHp.setFillColor(Color::Red);
//		enemyHp.setPosition(this->shape.getPosition().x + this->shape.getGlobalBounds().width, this->shape.getPosition().y);
//		enemyHp.setString(std::to_string(this->hp));
//	}
//};
//
//
//int main()
//{
//	srand(time(NULL));
//
//	RenderWindow window(VideoMode(800, 600), "Game6", Style::Default);
//	//window.setFramerateLimit(60);
//	
//	//----------------------UPDATED FOR FRAME INDEPENDENT------------------------------------------------
//	//since the timers will incremened/decremented each frame, different fps will reach end of a timer at different times
//	//below timer calculations are changed BUT you must also make timers float!!! If not you will multiply float with int and there will be overflow, generating irrelevant results
//	float enemySpawnTimer = 20.f;
//	float bulletTimer = 0.f;
//
//	//fonts
//	Font font;
//	font.loadFromFile("Fonts/Dosis-Light.ttf");
//
//	//Textures------------------------------------------------Textures------------------------------------------------Textures
//	//player
//	Texture playerTex;
//	playerTex.loadFromFile("Textures/ship.png");
//	Player player(&playerTex);
//	Text playerHp;
//	playerHp.setFont(font);
//	playerHp.setCharacterSize(12);
//	playerHp.setFillColor(Color::White);
//	//enemy
//	Texture enemyTex;
//	enemyTex.loadFromFile("Textures/enemy.png");
//	//bullet
//	Texture bulletTex;
//	bulletTex.loadFromFile("Textures/missile.png");
//
//	//UI
//	Text score;
//	score.setFont(font);
//	score.setCharacterSize(50);
//	score.setFillColor(Color::White);
//	score.setString("Score: 0");
//
//	Text gameOver;
//	gameOver.setFont(font);
//	gameOver.setStyle(Text::Bold);
//	gameOver.setCharacterSize(100);
//	gameOver.setFillColor(Color::Red);
//	gameOver.setString("GAME OVER");
//	gameOver.setPosition(window.getSize().x / 2 - gameOver.getGlobalBounds().width / 2, window.getSize().y / 2 - gameOver.getGlobalBounds().height);
//
//	//frame independent
//	Clock clock;
//	float dt;
//	float multiplier = 62.5;
//
//	Vector2f currVelocity;
//	Vector2f direction;
//	float maxVelocity = 20.f;
//
//
//	//vectors
//	std::vector<Enemy> enemies;
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
//		dt = clock.restart().asSeconds();
//		std::cout << "dt: " << dt << "\n";
//
//		if (player.hp > 0) {
//			//UPDATE------------------------------------------------UPDATE------------------------------------------------UPDATE
//			//player&UI
//			player.shape.setPosition(0.f, Mouse::getPosition(window).y);
//			playerHp.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - playerHp.getGlobalBounds().height);
//			playerHp.setString(std::to_string(player.hp));
//			//player window bounds
//			if (player.shape.getPosition().y < 0)
//			{
//				player.shape.setPosition(0.f, 0.f);
//			}
//			else if (player.shape.getPosition().y > window.getSize().y - player.shape.getGlobalBounds().height)
//			{
//				player.shape.setPosition(0.f, window.getSize().y - player.shape.getGlobalBounds().height);
//			}
//
//			//enemy
//			if (enemySpawnTimer > 20)
//			{
//				enemies.push_back(Enemy(&enemyTex, window.getSize(), font));
//				enemySpawnTimer = 0;
//			}
//			else
//			{
//				//----------------------UPDATED FOR FRAME INDEPENDENT------------------------------------------------
//				enemySpawnTimer += dt * multiplier;
//			}
//			for (size_t i = 0; i < enemies.size(); i++) //move and delete enemies
//			{
//				if (enemies[i].shape.getPosition().x + enemies[i].shape.getGlobalBounds().width < 0)//enemy out of bounds
//				{
//					enemies.erase(enemies.begin() + i);
//					break;
//				}
//				else if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) //player crashes enemy
//				{
//					enemies.erase(enemies.begin() + i);
//					player.hp--;
//					break;
//				}
//				else
//				{
//					//----------------------UPDATED FOR FRAME INDEPENDENT------------------------------------------------
//					enemies[i].shape.move(-5.f * dt * multiplier, 0.f); 
//					enemies[i].enemyHp.move(-5.f * dt * multiplier, 0.f);
//				}
//			}
//
//			//bullet && score &&enemy
//			if (Mouse::isButtonPressed(Mouse::Left) && bulletTimer >= 12)
//			{
//				bulletTimer = 0;
//				player.bullets.push_back(Bullet(&bulletTex, Vector2f(player.shape.getPosition().x, player.shape.getPosition().y + (player.shape.getGlobalBounds().height / 3))));
//			}
//			for (size_t i = 0; i < player.bullets.size(); i++)
//			{
//				//----------------------UPDATED FOR FRAME INDEPENDENT------------------------------------------------
//				player.bullets[i].shape.move(5.f * dt * multiplier, 0.f);
//				if (player.bullets[i].shape.getPosition().x + player.bullets[i].shape.getGlobalBounds().width > window.getSize().x) //out of bounds
//				{
//					player.bullets.erase(player.bullets.begin() + i);
//					break;
//				}
//				for (size_t k = 0; k < enemies.size(); k++)//collusion of bullets and enemies
//				{
//					if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
//					{
//						if (enemies[k].hp <= 1)
//						{
//							player.score += enemies[k].hpMax;
//							score.setString("Score: " + std::to_string(player.score));
//							enemies.erase(enemies.begin() + k);
//						}
//						else
//						{
//							enemies[k].hp--;
//							enemies[k].enemyHp.setString(std::to_string(enemies[k].hp));
//						}
//						player.bullets.erase(player.bullets.begin() + i);
//						break;
//					}
//				}
//			}
//			bulletTimer += dt * multiplier;
//		}
//		window.clear();
//
//		//DRAW------------------------------------------------DRAW------------------------------------------------DRAW
//		//enemy
//		for (size_t i = 0; i < enemies.size(); i++)
//		{
//			window.draw(enemies[i].enemyHp);
//			window.draw(enemies[i].shape);
//		}
//		//bullets
//		for (size_t i = 0; i < player.bullets.size(); i++)
//		{
//			window.draw(player.bullets[i].shape);
//		}
//		//player
//		window.draw(score);
//		window.draw(player.shape);
//		window.draw(playerHp);
//		if (player.hp <= 0)
//		{
//			window.draw(gameOver);
//		}
//		window.display();
//	}
//
//	return 0;
//}