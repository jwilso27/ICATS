//Player class

#include <iostream>
#include <cmath>
#include <string>
#include "phys_obj.h"
#include "field.h"
#include "constants.h"
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class player: public PhysObj{
	public:
		player(float, float, playField &);
		void moveLeft(void);
		void moveRight(void);
		void noMove(void);
		void jump(void);
	private:
};

#endif

//Constructor
player::player(float ixPos, float iyPos, playField &arena) : PhysObj(ixPos, iyPos, width, height, arena){
	width = 15;
	height = 30;
	return;
}

//Move left
void player::moveLeft(void){
	xVel -= xAccel*dTime;
	if(xVel < -maxxVel){
		xVel = -maxxVel;
	}	
	xPos = xPos+xVel*(dTime)-.5*(xAccel/5.0)*(dTime*dTime);
}

//Move right
void player::moveRight(void){
	xVel += xAccel*dTime;
	if(xVel > maxxVel){
		xVel = maxxVel;
	}	
	xPos = xPos+xVel*(dTime)+.5*(xAccel/5.0)*(dTime*dTime);
}

//Handle no input keys
void player::noMove(void){
	//If the velocity is negative	
	if(xVel < -1){
		xVel += (xAccel/5.0)*dTime;
		if(xVel < -maxxVel){
			xVel = -maxxVel;
		}	
		xPos = xPos+xVel*(dTime)+.5*(xAccel/5.0)*(dTime*dTime);
	}else if(xVel > 1){ //If velocity is positive
		xVel -= (xAccel/5.0)*dTime;
		if(xVel > maxxVel){
			xVel = maxxVel;
		}
		xPos = xPos+xVel*(dTime)-.5*(xAccel/5.0)*(dTime*dTime);	
	}else{
		xVel = 0;
		xPos = xPos;
	}
	gravity();
}

//Jump function
void player::jump(void){
	//Allow jump if player is not in air from a previous jump	
	if(jumped == 0){
		//give initial yVelocity 
		yVel -= 15;
		yPos = yPos + yVel*(dTime)+.5*(yAccel)*(dTime * dTime);
		jumped = 1;
	}
}
