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
//	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
//	window.setFramerateLimit(60);
//
//	View mainView;
//	mainView.setSize(1200, 800);
//
//	RectangleShape player;
//	player.setSize(Vector2f(50.f, 50.f));
//	player.setPosition(600, 400);
//	player.setFillColor(Color::Green);
//
//	RectangleShape object;
//	object.setSize(Vector2f(50.f, 50.f));
//	object.setPosition(800, 200);
//	object.setFillColor(Color::Red);
//
//	RectangleShape shape;
//	shape.setSize(Vector2f(200.f, 20.f));
//
//	while (window.isOpen())
//	{
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		//update
//		if (Keyboard::isKeyPressed(Keyboard::A))
//			player.move(-10.f, 0.f);
//		if (Keyboard::isKeyPressed(Keyboard::D))
//			player.move(10.f, 0.f);
//		if (Keyboard::isKeyPressed(Keyboard::W))
//			player.move(0.f, -10.f);
//		if (Keyboard::isKeyPressed(Keyboard::S))
//			player.move(0.f, 10.f);
//
//		mainView.setCenter(player.getPosition()); //so the camera folows the player's position!
//
//		window.clear();
//
//		//draw
//		window.setView(mainView);//so the player will be drawn according to the view
//								//if you change as mainView.setSize(600, 600);, you will see that player is a rectangle since the view is distorted
//		window.draw(player);
//		window.draw(object);
//
//		window.setView(window.getDefaultView());//so it goes back to regular view which is the window
//												//so you the same shape at mainView.setSize(600, 600);
//												//do this for ui elements that is not in the world, (hp bar alwyas stay there although player moves)
//		window.draw(shape);
//
//
//		window.display();
//	}
//
//	return 0;
//}