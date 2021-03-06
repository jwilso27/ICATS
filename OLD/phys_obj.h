//Andrew Gnott
//March 18, 2015
//A base class for an object that will have be effected by physics
//and have properties such as size, (shape?), position, and gravity

#ifndef PHYS_OBJ_H
#define PHYS_OBJ_H


class PhysicalObject {
	public: 
		//Constructor (height, width, start positionX, start positionY, upkey, downkey, left key, right key, bounce factor);
		PhysicalObject(int = 10, int = 10, float = 30, float = 30, int=0, int=1, int=2, int=3, float = .5);
		
		//Functions to get position of object
		float getPosX(void);
		float getPosY(void);

		//Functions to take movement commands, may need to be CHAR, need to understand keyboard input
		virtual void move(void);
	
	protected: 
		int height;
		int width; 
		//store keys chosen to move object
		int upKey;
		int downKey;
		int rightKey;
		int leftKey;
		float positionX;
		float positionY;
		float bounceFactor; //How much speed will be retained after the object hits a wall/boundary

};

#endif
