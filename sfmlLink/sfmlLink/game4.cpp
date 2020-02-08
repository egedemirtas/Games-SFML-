//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Network.hpp>
//#include <iostream>
//#include <vector>
//#include <cstdlib>
//
//using namespace sf;
//
//int main()
//{
//	srand(time(NULL));
//	RenderWindow window(VideoMode(1000, 800), "Game4");
//	window.setFramerateLimit(60);
//
//	int hp = 10;
//
//	//enemy
//	Texture cryTex;
//	Sprite cry;
//	if (!cryTex.loadFromFile("Textures/cry.png")) {
//		throw "Could not upload png\n";
//	}
//	cry.setTexture(cryTex);
//	cry.setScale(Vector2f(0.2f, 0.2f));
//	int crySpawnTimer = 100;
//	std::vector<Sprite> crys;
//
//	//player
//	Texture drakeTex;
//	Sprite drake;
//	if (!drakeTex.loadFromFile("Textures/drake.png")) {
//		throw "Could not upload png\n";
//	}
//	drake.setTexture(drakeTex);
//	drake.setScale(Vector2f(0.2f, 0.2f));
//
//	//hp bar
//	RectangleShape hpBar;
//	hpBar.setFillColor(Color::Red);
//	hpBar.setSize(Vector2f((float)hp * 30.f, 30.f));
//
//	while (window.isOpen() && hp>0)
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed) //closes window if you press close(x)
//				window.close();
//			if (event.type == Event::KeyPressed) //closes window if you press a key
//				window.close();
//		}
//
//		//UPDATE ENEMY	
//		for (size_t i = 0; i < crys.size(); i++)//move enemies
//		{
//			crys[i].move(-4.f, 0);
//			if (crys[i].getPosition().x <= 0 - cry.getGlobalBounds().width)
//			{
//				crys.erase(crys.begin() + i);
//			}
//		}
//		if (crySpawnTimer < 20)
//		{
//			crySpawnTimer++;
//		}
//		if (crySpawnTimer >= 20)
//		{
//			cry.setPosition(Vector2f(window.getSize().x, rand() % int(window.getSize().y - cry.getGlobalBounds().height)));
//			crys.push_back(Sprite(cry));
//			crySpawnTimer = 0;
//		}
//
//		//UPDATE DRAKE
//		drake.setPosition(drake.getPosition().x, Mouse::getPosition(window).y);
//
//		if (drake.getPosition().y <= 0) //so you cant escape window boundaries(top)
//		{
//			drake.setPosition(drake.getPosition().x, 0);
//		}
//		if (drake.getPosition().y >= window.getSize().y - drake.getGlobalBounds().height)//so you cant escape window boundaries(bottom)
//		{
//			drake.setPosition(drake.getPosition().x, window.getSize().y - drake.getGlobalBounds().height);
//		}
//
//
//		//Collision
//		for (size_t i = 0; i < crys.size(); i++)
//		{
//			if (drake.getGlobalBounds().intersects(crys[i].getGlobalBounds()))
//			{
//				hp--;
//				hpBar.setSize(Vector2f((float)hp * 30.f, 30.f));
//				crys.erase(crys.begin() + i);
//			}
//		}
//
//		window.clear(); //for every frame you draw something, so you want to clear the previous frame, so you dont draw on top of it / clears the background color with blue
//		
//		//draw
//		for (size_t i = 0; i < crys.size(); i++)
//		{
//			window.draw(crys[i]);
//		}
//		
//		window.draw(drake);
//		window.draw(hpBar);
//		window.display();//ok i drew something go ahead and display the frame
//	}
//	return 0;
//}