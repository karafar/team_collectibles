//TODO: add info here.

#ifndef H__COLLECTIBLES__
#define H__COLLECTIBLES__

#include "SFML/Graphics.hpp"
#include "Person.hpp"

class Collectibles {
public:
	Collectibles(){}
	// Detects collision with a player. Has no effect on monsters.
	virtual bool detectCollision(Person &person) = 0;

	// If the collectible is stationary then this method does nothing.
	virtual void move() = 0;
	
	// When colliding with player, activate the collectibles powers.
	virtual void activate(Person &person) = 0;

	// Loads sprite to sprite field.
	virtual void loadSprite() = 0;
	
	// Will be called each frame. Checks flags, calls move(), and \
	activates if neccessary.
	virtual void update(Person &person) = 0;

protected:
	// time management
	const int POWER_UP_TIME = 10;
	int elapsedTime = 0;
};

#endif
