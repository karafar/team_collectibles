#include "SFML/Graphics.hpp"
#include "include/Collectibles.hpp"
#include "include/Person.hpp"
#include <iostream>

/******************************
 *Class for collectible that
 *slows the character to .8
 *movement speed.
 *
 *
 *****************************/
 class BluePotion: public Collectibles {

public:
	BluePotion() : Collectibles(){
		loadSprite();
		sprite.setTexture(texture);
		sf::FloatRect spriteSize = sprite.getGlobalBounds();
		sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
		sprite.setPosition(x,y);
	}
	
	BluePotion(int x , int y) : Collectibles() {
		loadSprite();
                sprite.setTexture(texture);
                sf::FloatRect spriteSize = sprite.getGlobalBounds();
                sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
                sprite.setPosition(x,y);
		
		this->x = x;
		this->y = y;
		elapsedTime = 0;
	}


	sf::Sprite getSprite(){
		return this->sprite;
	}

	bool detectCollision(Person &person) {
		return false;
	}

	void move() {
		this->bounce *= -1;
		y += bounce;
		sprite.setPosition(x, y);	
	}

	void activate(Person &person) {
		//slow the character
	}

	void update(Person &person) {
		//to deactivate
	}

	void loadSprite() {
		if(!texture.loadFromFile("sprites/bluePoition.png")) {
			std::cout << "Failed to load bluePoition.png" << std::endl;
                        exit(EXIT_FAILURE);
                 }
                 sprite.setTexture(texture);

	}

private:
	sf::Sprite sprite;
	sf::Texture texture;

	int bounce = 1;	
	int x = 300;
	int y = 300;

 };
