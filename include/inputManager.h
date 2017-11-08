#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>
#include <rectangle.h>

class InputManager
{
public:
	void checkInputs(Rect player, b2Vec2 speed);
	InputManager();
	~InputManager();
private:
};

#endif // !INPUT_MANAGER_H