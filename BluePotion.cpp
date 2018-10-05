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
		loadSprite("sprites/bluePotion.png");
	}
	
	BluePotion(int x , int y) : Collectibles() {
		this->x = x;
		this->y = y;

		loadSprite("sprites/bluePotion.png");
		
	}


	void activate(Person &person) {

		//slow the character
		hasActivated = true;
	
	}

	void deactivate(Person &person) {
	  	 sf::Time time = clock.getElapsedTime();
                 sf::Int32 mills = time.asMilliseconds();
                 if(mills % 5000 > 500) {
                         //speed up character
                 
		 }
		hasDeactivated = true;
	}
 };
