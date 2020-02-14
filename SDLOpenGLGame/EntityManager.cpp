//
//  EntityManager.cpp
//  SDLOpenGLGame
//
//  Created by Patrik Gyllvin on 2013-05-09.
//  Copyright (c) 2013 Patrik Gyllvin. All rights reserved.
//

#include "EntityManager.h"
#include "Entity.h"

EntityManager::EntityManager()
{
    
}

unsigned int EntityManager::getCurrentEntityID()
{
    
}

void EntityManager::registerEntity( Entity *entity )
{
    Entities.push_back( entity );
}

void EntityManager::createPlayer( float x, float y, float width, float height, InputManager *inputManager )
{
    Entity *player = new Player( x, y, width, height, inputManager );
    Entities.push_back( player );
}

void EntityManager::deregisterEntity( Entity *entity )
{
    // iterate through the entities vector
    for( EntitiesIter = Entities.begin(); EntitiesIter != Entities.end(); )
    {
        // if the entity we're trying to remove is indeed in the entities vector
        if( (*EntitiesIter)->getUniqueID() == entity->getUniqueID() )
        {
            // remove the entity
            delete * EntitiesIter;
            EntitiesIter = Entities.erase( EntitiesIter );
        }
        else
        {
            ++EntitiesIter;
        }
    }
}

bool EntityManager::EntityIntersectsWithAnotherEntity( Entity *entity, Entity *entity )
{
    for( EntitiesIter = Entities.begin(); EntitiesIter != Entities.end(); ++EntitiesIter )
    {
        if( !entityTAC.Collision )
        {
            if( entity->getX() + entity->getWidth() < (*EntitiesIter)->getX() ||
               entity->getX() > (*EntitiesIter)->getX() + (*EntitiesIter)->getWidth() )
                entityTAC.Collision = false;
            else
            {
                entityTAC.type = (*EntitiesIter)->getType();
                entityTAC.Collision = true;
            }
        }
        
        if( !entityTAC.Collision )
        {
            if( entity->getY() + entity->getHeight() < (*EntitiesIter)->getY() ||
               entity->getY() > (*EntitiesIter)->getY() + (*EntitiesIter)->getHeight() )
                entityTAC.Collision = false;
            else
            {
                entityTAC.type = (*EntitiesIter)->getType();
                entityTAC.Collision = true;
            }
        }
    }
    
    return entityTAC;
}

void EntityManager::removeEntity( Entity *entity )
{
    entity->setDead();
}

void EntityManager::updateEntities()
{
    for( EntitiesIter = Entities.begin(); EntitiesIter != Entities.end(); ++EntitiesIter )
    {
        (*EntitiesIter)->update();
    }
}

void EntityManager::drawEntities()
{
    for( EntitiesIter = Entities.begin(); EntitiesIter != Entities.end(); ++EntitiesIter )
    {
        (*EntitiesIter)->draw();
    }
}