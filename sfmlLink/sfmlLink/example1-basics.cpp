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
//	Vector2f vec(10.f, 15.f); //creates 2 floats at the same time for x and y coordinates, f for float, u can use i for int
//
//	CircleShape shape(100.f);
//	shape.setFillColor(Color::Green);
//
//	RectangleShape rect(Vector2f(100.f, 150.f));//first is size, then position(but not included in this example)
//	rect.setPosition(Vector2f(100.f, 100.f));
//	rect.setFillColor(Color(55,100,255, 255)); // Color() takes 4 values: 3 for rgb, and transparency// the are all out of 255
//
//	//essential to createa a triangle
//	CircleShape triangle;
//	triangle.setRadius(50.f);
//	triangle.setPointCount(3);//5 makes star
//	triangle.setFillColor(Color::Magenta);
//	triangle.setOutlineColor(Color::Red);
//	triangle.setOutlineThickness(5.f);
//	//create line
//	Vertex line[] = { Vertex(Vector2f(100.f, 400.f)), Vertex(Vector2f(50.f, 100.f)) };//start and end for a line
//
//	//create trapezoid
//	ConvexShape convex;
//	 //resize it to 5 points
//	convex.setPointCount(5);
//	 //define the points
//	convex.setPoint(0, Vector2f(0.f, 0.f));
//	convex.setPoint(1, Vector2f(150.f, 10.f));
//	convex.setPoint(2, Vector2f(120.f, 90.f));
//	convex.setPoint(3, Vector2f(30.f, 100.f));
//	convex.setPoint(4, Vector2f(0.f, 50.f));
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed) //closes window if you press close(x)
//				window.close();
//			if (event.type == Event::KeyPressed) //closes window if you press a key
//				window.close();
//		}
//		//update
//		shape.move(0.8f, 0.f);//x and y/ f = to say to complier it is float type(saves time, no conversion for complier)
//		rect.move(2.0f, 0.f);
//		rect.rotate(1.f);
//		//draw
//		window.clear(Color::Black); //for every frame you draw something, so you want to clear the previous frame, so you dont draw on top of it / clears the background color with blue
//
//		//draw everything
//		window.draw(shape);
//		window.draw(rect);
//		window.draw(line, 2, Lines);
//		window.draw(convex);
//		window.draw(triangle);
//		window.display();//ok i drew something go ahead and display the frame
//	}
//
//	return 0;
//}