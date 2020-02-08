//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Network.hpp>
//#include <iostream>
//using namespace sf;
//
//int main()
//{
//	RenderWindow window(VideoMode(640, 480), "Game2");
//	window.setFramerateLimit(60);
//	CircleShape hoop;
//	int dir = 0;
//	hoop.setRadius(50.f);
//	hoop.setFillColor(Color::Black);
//	hoop.setOutlineColor(Color::Blue);
//	hoop.setOutlineThickness(2.f);
//	hoop.setPosition(Vector2f(0, 10.f));
//
//	CircleShape ball;
//	bool isShot = false;
//	ball.setRadius(20.f);
//	ball.setFillColor(Color::Red);
//	ball.setOutlineColor(Color::Blue);
//	ball.setOutlineThickness(2.f);
//	ball.setPosition(Vector2f(0, window.getSize().y - ball.getRadius()*3));
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
//		//update hoop
//		if(hoop.getPosition().x <= 0)
//		{
//			dir = 1;
//		}
//		else if((hoop.getPosition().x + (hoop.getRadius()*2)) >= window.getSize().x)
//		{
//			dir = 0;
//		}
//
//		if(dir == 0) //means that the circle is at right corner so should move left, aka dir = 0 is move left
//		{
//			hoop.move(-5.f, 0);
//		}
//		else
//		{
//			hoop.move(5.f, 0);
//		}
//
//		//update ball
//		if (Mouse::isButtonPressed(Mouse::Left))
//		{
//			isShot = true;
//		}
//		if (!isShot)
//		{
//			ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);
//		}
//		else
//		{
//			ball.move(0, -5.f);
//		}
//		
//		//collusion
//		if(ball.getPosition().y < 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds()))
//		{
//			isShot = false;
//			ball.setPosition(Vector2f(Mouse::getPosition().x, window.getSize().y - ball.getRadius() * 3));
//		}
//
//		window.clear(Color::White);
//
//		//draw
//		window.draw(hoop);
//		window.draw(ball);
//		window.display();
//	}
//
//
//	return 0;
//}