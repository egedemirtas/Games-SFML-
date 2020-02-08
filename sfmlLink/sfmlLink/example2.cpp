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
//	RenderWindow window(VideoMode(640, 400), "SFML works!", Style::Default);
//	window.setFramerateLimit(60);
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed) //closes window if you press close(x)
//				window.close();
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) //closes window if you press [ESC]
//				window.close();
//		}
//
//		if (Keyboard::isKeyPressed(Keyboard::Escape)) { //basically the same thing as above, but this checks outside of event!
//			window.close();
//		}
//
//		if (Mouse::isButtonPressed(Mouse::Left)) {
//			window.close();
//		}
//
//		//update
//
//		//draw
//		window.clear(Color::Black); //for every frame you draw something, so you want to clear the previous frame, so you dont draw on top of it / clears the background color with blue
//
//		//draw everything
//
//		window.display();//ok i drew something go ahead and display the frame
//	}
//
//	return 0;
//}