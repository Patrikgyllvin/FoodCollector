#include "Pig.h"
#include "EntityManager.h"

Pig::Pig() : Entity( false ) {}

void Pig::update()
{
	std::cout << "I am updating this pig\n";
}

void Pig::draw()
{
	std::cout << "I am drawing this pig!\n";
}