#include "include/Collectibles.hpp"
#include "include/Collision.hpp"
#include <stdio.h>

class OrangePotion: public Collectibles {
public:
	OrangePotion()
	{
		loadSprite("sprites/orangePoition.png");	
	}

	OrangePotion(int x, int y)
	: Collectibles()
	{
		this->x = x;
		this->y = y;
		loadSprite("sprites/orangePoition.png");
	}

	void activate(Person &person){
		int health = person.getHealth();
		if(health <= 50) person.setHealth(health+50);
		else person.setHealth(100);
		hasActivated = true;
	}
};
