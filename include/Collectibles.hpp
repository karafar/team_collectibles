/**
	Class: Collectibles
	Purpose: Acts as a parent to specific colllectible items. This class
	is not intended to be instantiated.

	Made for CIS343 @ GVSU Fall 2018
	Team Members:
	Isfar Baset
	Allision Bickford
	Nick Cone
	Farid Karadsheh

*/
#ifndef H__COLLECTIBLES__
#define H__COLLECTIBLES__

#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window.hpp"
#include "Collision.hpp"
#include "Person.hpp"
#include <string.h>
#include <stdio.h>

class Collectibles {
public:

	// Detects collision with a player.
	bool detectCollision(Person &person) {
		return Collision::BoundingBoxTest(person.getSprite(), this->sprite);
	}

	// Moves the collectible up and down.
	void move() {
		sf::Time time = clock.getElapsedTime();
		sf::Int32 mills = time.asMilliseconds();
		if(mills % 1000 > 500) {
			y += bounce;
			sprite.setPosition(x, y);
			bounce *= -1;
			clock.restart();
		}
	}
	
	// When colliding with player, activate the collectibles powers.\
	Collision detection is not handled here.
	virtual void activate(Person &person) = 0;

	// Loads sprite to sprite field.
	void loadSprite(const std::string filename) {
		if(!texture.loadFromFile(filename)) {
			printf("Failed to load texture: %s\n", filename.c_str());
			exit(EXIT_FAILURE);
		}
		sprite.setTexture(texture);
		sf::FloatRect spriteSize = sprite.getGlobalBounds();
		sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
		sprite.setPosition(x,y);
	}
	
	// Will be called each frame. Checks flags, calls move(), and \
	activates if neccessary.
	void update(Person &person) {
		if(!hasActivated)
			if(detectCollision(person))
				activate(person);

		else 
			deactivate(person);
		
		move();
	}

	// Recieves game's window, then draws the collectible.
	void render(sf::RenderWindow &window) {
		if(!hasActivated)
			window.draw(sprite);
	}
	
	void deactivate(Person &person){}
	
	sf::Sprite getSprite() {
		return this->sprite;
	}

protected:
	sf::Sprite sprite;
	sf::Texture texture;
	int x = 300;
	int y = 300;
	int bounce = 1;
	bool hasActivated = false;
	sf::Clock clock;
};

#endif
