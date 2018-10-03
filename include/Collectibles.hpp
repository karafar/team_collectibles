//TODO: add info here.

#ifndef H__COLLEcTIBLES__
#define H__COLLECTIBLES__

#include "SFML/Graphics.hpp"

class Collectibles {
	// Detects collision with a player. Has no effect on monsters.
	virtual bool detectCollision(Person person);

	// If the collectible is stationary then this method does nothing.
	virtual void move();
	
	// When colliding with player, activate the collectibles powers.
	virtual void activate();

	// Will be called each frame. Checks flags, calls move(), and \
	activates if neccessary.
	virtual void update();

protected:
	// Coordinates and Dimensions
	int x;	// Collectibles X origin
	int y;	// Collectibles Y origin
	int w;  // Width of collectible
	int h;  // Height of collectible

	// Sprite and Texture
	sf::Sprite sprite;	
	sf::Texture texture;	// Used to build the sprite
	
	// Flag - is true when collectible is colliding with player.
	bool isColliding;
}
