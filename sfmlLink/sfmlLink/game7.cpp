//#include<iostream>
//#include"SFML\Graphics.hpp"
//#include"SFML\Window.hpp"
//#include"SFML\System.hpp"
//
//using namespace sf;
//
//int main()
//{
//	RenderWindow window(VideoMode(800, 600), "Framerate independent!", Style::Default);
//	//window.setFramerateLimit(60);
//
//	//dt at 60fps = 0,016s
//
//	Clock clock;
//	float dt;
//	float multiplier = 62.5;
//
//	RectangleShape shape;
//	shape.setFillColor(Color::White);
//	shape.setSize(Vector2f(50.f, 50.f));
//
//	Vector2f currVelocity;
//	Vector2f direction;
//	float maxVelocity = 25.f;
//	float acceleration = 1.f;
//	float deacceleration = 0.5f;
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
//				window.close();
//		}
//
//		dt = clock.restart().asSeconds(); //clock will restart after each frame and will give the time passed to dt before restarting, so 60fps means it will show 0.016
//
//		direction = Vector2f(0.f, 0.f); //reset direction each time to determine acceleration and velocity
//
//		if (Keyboard::isKeyPressed(Keyboard::A))
//		{
//			//shape.move(-10.f, 0);	//if you leave it like this at 60fps: you will go -10 per dt(0.016s), but at 200fps it is -10 per dt(0.005s), so frame changes your speed
//			//shape.move(-10.f * dt * multiplier, 0); //so at 60fps formula is: 10*0.016*62.5 = 10!!!, at 200fps: 10*0.005*62.5= 3.125
//													//but remember that 200fps is 0.016/0.005 = 3.2 times faster than 60fps, so: 3.125 * 3.2 = 10!!!
//													//thus no need for window.setFramerateLimit(60); and will be independent from computer speed
//													//but always start with it then add dt then add multiplier to achive same speeds as you wished at setFramerateLimit(60)
//			//this is for acceleration
//			direction.x = -1;
//			if (currVelocity.x > -maxVelocity)
//			{
//				//currVelocity.x += acceleration * direction.x; //this wont work the same in 200fps as discussed before
//															  //we want to add 1 to the currVelocity at every frame(as acceleration)
//															  //dt is 0.016 as average
//															  //so think: acceleration * direction.x * 0.016 = 0.016
//															  //how can i make this 1 as I intended before?
//															  //determine a multiplier!!!: 1/0.016 = 62.5!!!
//										//do this for every velocity and acceleration related calculation and you will have Framerate independent gameplay
//				currVelocity.x += acceleration * direction.x * dt * multiplier;
//			}
//		}	
//		if (Keyboard::isKeyPressed(Keyboard::D))
//		{
//			direction.x = 1;
//			if (currVelocity.x < maxVelocity)
//			{
//				currVelocity.x += acceleration * direction.x * dt * multiplier;
//			}
//		}
//		if (Keyboard::isKeyPressed(Keyboard::W))
//		{
//			direction.y = -1;
//			if (currVelocity.y > -maxVelocity)
//			{
//				currVelocity.y += acceleration * direction.y * dt * multiplier;
//			}
//		}
//		if (Keyboard::isKeyPressed(Keyboard::S))
//		{
//			direction.y = 1;
//			if (currVelocity.y < maxVelocity)
//			{
//				currVelocity.y += acceleration * direction.y * dt * multiplier;
//			}
//		}
//
//		//deacceleration
//		if (currVelocity.x > 0.f)
//		{
//			currVelocity.x -= deacceleration * dt * multiplier;
//			if (currVelocity.x < 0.f)
//			{
//				currVelocity.x = 0;
//			}
//		}
//		else if (currVelocity.x < 0.f)
//		{
//			currVelocity.x += deacceleration * dt * multiplier;
//			if (currVelocity.x > 0.f)
//			{
//				currVelocity.x = 0;
//			}
//		}
//
//		if (currVelocity.y > 0.f)
//		{
//			currVelocity.y -= deacceleration * dt * multiplier;
//			if (currVelocity.y < 0.f)
//			{
//				currVelocity.y = 0;
//			}
//		}
//		else if (currVelocity.y < 0.f)
//		{
//			currVelocity.y += deacceleration * dt * multiplier;
//			if (currVelocity.y > 0.f)
//			{
//				currVelocity.y = 0;
//			}
//		}
//
//		shape.move(currVelocity.x * dt * multiplier, currVelocity.y * dt * multiplier);
//
//		window.clear();
//
//		//Draw everything
//		window.draw(shape);
//		window.display();
//
//		std::cout << "dt: " << dt << "\n";
//	}
//
//	return 0;
//}