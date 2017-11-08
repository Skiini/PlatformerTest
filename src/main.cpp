#include <iostream>
#include <rectangle.h>
#include <SFML/Graphics.hpp>
#include <inputManager.h>

const b2Vec2 SPEED = b2Vec2(2.5f, 2.5f);

int main(int argc, const char* argv[])
{
	sf::RenderWindow window(
		sf::VideoMode(800, 600), 
		"SFML Box2D Example");
	window.setFramerateLimit(60.f);


	b2World world = b2World(b2Vec2(0.f, 9.81f));
	MyContactListener myContactListenerInstance;
	world.SetContactListener(&myContactListenerInstance);

	sf::Clock clock;

	Rect player;
	Rect ground(sf::Vector2f(400.f, 600.f), sf::Vector2f(800.f, 100.f));
	Rect wallTop(sf::Vector2f(400.f, 0.f), sf::Vector2f(800.f, 100.f));
	Rect wallLeft(sf::Vector2f(0.f, 0.f), sf::Vector2f(800.f, 100.f));
	player.init(world, b2_dynamicBody);
	ground.init(world, b2_staticBody);
	wallTop.init(world, b2_staticBody);
	wallLeft.init(world, b2_staticBody);

	InputManager input;

	float32 timeStep = 1 / 60.f;      //the length of time passed to simulate (seconds)
	int32 velocityIterations = 8;   //how strongly to correct velocity
	int32 positionIterations = 3;   //how strongly to correct position

	
	// run the program as long as the window is open
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		world.Step(timeStep, velocityIterations, positionIterations);
		player.update(dt);

		input.checkInputs(player, SPEED);

		window.clear();
		player.draw(window);
		ground.draw(window);
		wallTop.draw(window);
		wallLeft.draw(window);
		window.display();
	}


#if WIN32
	system("pause");
#endif
	return EXIT_SUCCESS;
}
