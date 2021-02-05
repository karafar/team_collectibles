#include "SFML/Graphics.hpp"
#include "include/Collectibles.hpp"
#include "include/Person.hpp"
#include <iostream>

/************************************************************************
 * This is the green potion that speeds up the player
 * 
 * @author Team Collectibles
 * @version October 6, 2018
 ************************************************************************/
 class GreenPotion: public Collectibles{
     public:

     GreenPotion(){
	 // loading the potion image 
         loadSprite("sprites/greenPoition.png");
     }
     
     // positioning the image 
     GreenPotion(int x, int y): Collectibles(){
         this->x = x;
         this->y = y;
         loadSprite("sprites/greenPoition.png");
     }

     // activates the collectible and speeds up the player if it is hit
     void activate(Person &person){
        
	     //speed up
         int s = person.getSpeed();
         person.setSpeed(s + 10.0);
	     hasActivated = true;
     }
 };
