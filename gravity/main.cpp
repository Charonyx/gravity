#include <SFML/Graphics.hpp>
#include "Player.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 640), "Gravity!");
	
	Player player({ 80,80 });
	player.setPos({ 100,500 });

	//gravity
	const int groundHeight = 500;
	const float gravitySpeed = 5.0;
	bool jump = 0; // 0 == false

	while (window.isOpen())
	{
		sf::Event event;

		const float moveSpeed = 3.0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			player.move({ 0, -moveSpeed });
			jump = 1; // 1 == true
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player.move({ moveSpeed, 0 });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player.move({ -moveSpeed, 0 });
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased) {
				jump = 0; // 0 == false
			}
		}

		//gravity logic
		if (player.getY() < groundHeight && jump == 0) {
			player.move({ 0,gravitySpeed });
		}

		window.clear();
		player.draww(window);
		window.display();
	}
	return 0;
}
