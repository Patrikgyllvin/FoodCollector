#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <iostream>

#include "Player.h"
#include "Pig.h"
#include "EntityEnemyBox.h"

class EntityManager {
private:
    unsigned int currentEntityID;
	std::vector<Entity*> Entities;
	std::vector<Entity*>::iterator EntitiesIter;
public:
    EntityManager();
    
    unsigned int getCurrentEntityID();
	
    void registerEntity( Entity *entity );
    void createPlayer( float x, float y, float width, float height, InputManager *inputManager );

    void deregisterEntity( Entity *entity );
    void removeEntity( Entity *entity );
    
    EntityTypeAndCollision EntityIntersectsWithAnotherEntity( Entity *entity );

	void updateEntities();
	void drawEntities();
};

#endif