/*
This is the member function definition for the player class. Most of these functions are simple mutators and accessors.  The jump function initiates movement in the y-direction if the player is standing on a platform (i.e. not already in a jump) and has indicated that they would like their character to jump based on keyboard input.  The overloaded operator calculates velocity and position using the inputted value.

BUG: For some reason, no matter how I implemented this, whenever the velocity of the players was equal to 5 or negative five, the characters would shake back and forth, moving back and forth by only one or two pixels. I believe that it has something to do with bounds in that when xVel == +/- 5, they next calculation moves it back slightly.

-->FEATURE: "scaredy cats" who are to afraid to assert dominance by fighting for yarn, so stand and shake instead.
*/

#include "player.h"
using namespace std;

int player::num=0;

player::player() : physObj(){
	n=getNum(); //player number	
	
	//set parameters
	bFactor=0;
	score=0;
	ball=0;
	flip=0;
	
	//object variables
	objHeight=P_HEIGHT;
	objWidth=P_WIDTH;
	
	//SDL_Rect variables
	objRect.w = objWidth;
	objRect.h = objHeight;
	
	//set bounds
	maxX = S_WIDTH-mins-objWidth;
	maxY = S_HEIGHT-mins-objHeight;
	
	//concatenate image file path
	ostringstream os;
	os << imPath << "cat" << n << imExt;
	s=os.str();
	
	objSurf=SDL_LoadBMP(s.c_str()); //get picture
}

int player::getNum(){
	return ++num;
}

int player::getScore(){
	return score;
}

void player::jump(){
	if(yPlat>0){ //Allow jump if player is on a platform
		int tmpVy=-maxYVel; //give initial y-velocity
		dTime++;
		setVel(xVel,tmpVy);
		
		int tmpY = yPos+yVel*(dTime)+.5*(yAcc)*(dTime * dTime);
		setPos(xPos,tmpY);
		dTime--;
	}
}

int player::hasBall(){
	return ball;
}

void player::setBall(int b){
	ball=b;
}

int player::isFlipped(){
	return flip;
}

void player::setFlip(int f){
	flip=f;
}

player& player::operator++(){ //add to score
	score++;
}

player& player::operator+=(int i){ //move
	int tmpAcc=-i;
	if(xVel+i*dTime==5) xVel+=(i+1)*dTime; //get around bug - shaky cats when xVel==5
	else if(xVel+i*dTime==-5) xVel+=(i-1)*dTime; //get around bug - shaky cats when xVel==-5
	else xVel+=i*dTime;
	xPos+=xVel*(dTime)+.1*tmpAcc*(dTime*dTime);
	
	return (* this);
}
