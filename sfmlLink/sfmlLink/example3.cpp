//
//#include<iostream>
//#include"SFML\Graphics.hpp"
//#include"SFML\Window.hpp"
//#include"SFML\System.hpp"
//
//using namespace sf;
//
//int main()
//{
//	RenderWindow window(VideoMode(800, 600), "Example3", Style::Default);
//	window.setFramerateLimit(60);
//
//	Font font;
//	font.loadFromFile("Fonts/luckiestguy.ttf");
//
//	Text text;
//	text.setFont(font);
//	text.setCharacterSize(300);
//	text.setFillColor(Color::Green);
//	text.setStyle(Text::Bold);
//	text.setString("EGE");
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
//		//Draw
//		window.clear();
//
//		window.draw(text);
//
//		window.display();
//	}
//
//	return 0;
//}