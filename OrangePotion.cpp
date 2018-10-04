#include "include/Collectibles.hpp"
#include "include/Collision.hpp"
#include <stdio.h>

class OrangePotion: public Collectibles {
public:
	OrangePotion()
	: Collectibles()
	 {
		loadSprite();	
		sprite.setTexture(texture);
		sf::FloatRect spriteSize = sprite.getGlobalBounds();
		sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
		sprite.setPosition(x,y);
	}

	OrangePotion(int x, int y)
	: Collectibles()
	{
		loadSprite();
		sprite.setTexture(texture);
		sf::FloatRect spriteSize = sprite.getGlobalBounds();
		sprite.setOrigin(spriteSize.width/2.0, spriteSize.height/2.0);
		this->x = x;
		this->y = y;
		sprite.setPosition(this->x,this->y);
	}

	bool detectCollision(Person &person) {
		return Collision::BoundingBoxTest(person.getSprite(), this->sprite);
	}

	sf::Sprite getSprite() {
		return this->sprite;
	}

	void move(){}
	void activate(Person &person){}
	void loadSprite(){
		if(!texture.loadFromFile("sprites/orangePoition.png"))
		{
			printf("Failed to load texture:  orangePotion.png\n");
			exit(EXIT_FAILURE);
		}		
	}

	void update(Person &person){}

private:
	sf::Sprite sprite;
	sf::Texture texture;
	int x = 300;
	int y = 300;	
};
