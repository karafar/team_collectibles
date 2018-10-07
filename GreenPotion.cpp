#include "include/Collectibles.hpp"
#include "include/Collision.hpp"
#include <stdio.h>
/************************************************************************
 * This is the green potion which gives health to the player
 *
 * @author Team Collectibles 
 * @version October 6, 2018
 ************************************************************************/
class GreenPotion: public Collectibles {
public:
	GreenPotion()
	{   // loading image 
		loadSprite("sprites/greenPoition.png");	
	}

	// positioning the potion
	GreenPotion(int x, int y)
	: Collectibles()
	{
		this->x = x;
		this->y = y;
		loadSprite("sprites/greenPoition.png");
	}

	// give health to the player
	void activate(Person &person){
		int health = person.getHealth();
		// check if health is needed
		if(health <= 50) person.setHealth(health+50);
		else person.setHealth(100);
		hasActivated = true;
	}
};