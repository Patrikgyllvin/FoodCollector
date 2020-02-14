#include "Entity.h"
#include "EntityManager.h"

Entity::Entity( bool willRespawn )
:
uniqueID( rand() % sizeof( unsigned int ) ), // needs to be changed, may be duplicate!
health( 20 ),
isDead( false ),
willRespawn( willRespawn )
{}

unsigned const int Entity::getUniqueID()
{
	return this->uniqueID;
}

void Entity::setX( float x )
{
    this->x = x;
}
float Entity::getX()
{
    return this->x;
}

void Entity::setY( float y )
{
    this->y = y;
}
float Entity::getY()
{
    return this->y;
}

void Entity::setVelocityX( float velX )
{
    this->velX = velX;
}
float Entity::getVelocityX()
{
    return this->velX;
}

void Entity::setVelocityY( float velY )
{
    this->velY = velY;
}
float Entity::getVelocityY()
{
    return this->velY;
}

void Entity::setWidth( float width )
{
    this->width = width;
}
float Entity::getWidth()
{
    return this->width;
}

void Entity::setHeight( float height )
{
    this->height = height;
}
float Entity::getHeight()
{
    return this->height;
}

int Entity::getHealth()
{
	return this->health;
}

void Entity::setHealth( int health )
{
	this->health = health;
}

EntityTypes Entity::getType()
{
    return this->type;
}

void Entity::hurtEntity( int damage )
{
	this->setHealth( this->getHealth() - damage );
}

void Entity::setDead()
{
	// if the entity will respawn do NOT fully remove it... Called for players
	if( this->willRespawn )
	{
		this->isDead = true;
	}
	/*else if( !this->willRespawn ) // if not just remove it!
	{
		EntityMgr->deregisterEntity( this );
		delete this;
	}*/
}

void Entity::updateHealth()
{
    if( this->getHealth() == 0 )
	{
	//	EntityMgr->removeEntity( this );
	}
}