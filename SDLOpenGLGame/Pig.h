#ifndef PIG_H
#define PIG_H

#include <iostream>
#include "Entity.h"

class Pig : public Entity {
public:
	Pig();

	// implement
	void update();
	void draw();
};

#endif