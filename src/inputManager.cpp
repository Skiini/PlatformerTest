#include <inputManager.h>

void InputManager::checkInputs(Rect player, b2Vec2 speed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.move(b2Vec2(speed.x * -1, speed.y * -1));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.move(speed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player.jump(speed);
	}

	if (sf::Event::KeyReleased == sf::Keyboard::Left ||
		sf::Event::KeyReleased == sf::Keyboard::A ||
		sf::Event::KeyReleased == sf::Keyboard::Right ||
		sf::Event::KeyReleased == sf::Keyboard::W)
	{
		player.move(b2Vec2_zero);
	}

	if (sf::Event::KeyReleased == sf::Keyboard::W ||
		sf::Event::KeyReleased == sf::Keyboard::Space ||
		sf::Event::KeyReleased == sf::Keyboard::Up)
	{
		player.jump(b2Vec2_zero);
	}
}

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}
