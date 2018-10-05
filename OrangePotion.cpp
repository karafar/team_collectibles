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

	void move(){
		sf::Time time = clock.getElapsedTime();
		sf::Int32 mills = time.asMilliseconds();
		if(mills % 1000 > 500) {
			y += bounce;
			sprite.setPosition(x, y);
			bounce *= -1;
			clock.restart();
		}
	}
	void activate(Person &person){
		int health = person.getHealth();
		if(health <= 50) person.setHealth(health+50);
		else person.setHealth(100);
		hasActivated = true;
	}

	void loadSprite(){
		if(!texture.loadFromFile("sprites/orangePoition.png"))
		{
			printf("Failed to load texture:  orangePotion.png\n");
			exit(EXIT_FAILURE);
		}		
	}

	void update(Person &person){
		if(!hasActivated)
			if(detectCollision(person))
				activate(person);
		move();	
	}

	void render(sf::RenderWindow &window) {
		if(!hasActivated)
			window.draw(sprite);
	}

private:
//	sf::Sprite sprite;
//	sf::Texture texture;
//	int x = 300;
//	int y = 300;	
//	int bounce = 1;
//	bool hasActivated = false;
//	sf::Clock clock;
};
