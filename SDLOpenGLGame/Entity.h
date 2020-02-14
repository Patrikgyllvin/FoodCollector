#ifndef ENTITY_H
#define ENTITY_H

#include <stdlib.h>

enum EntityTypes {
	ENTITY_PLAYER = 0,
	ENTITY_PIG,
    ENTITY_ENEMY,
};

struct EntityTypeAndCollision {
    bool Collision = false;
    EntityTypes type;
};

class EntityManager;

class Entity {
private:
	unsigned const int uniqueID;
	int health;
    
protected:
	bool isDead;
	bool willRespawn;
    float x, y, velX, velY, width, height;
    EntityManager *entityMgr;
    EntityTypes type;
    
public:
	Entity( bool willRespawn );
	unsigned const int getUniqueID();

    void setX( float x );
    float getX();
    
    void setY( float y );
    float getY();
    
    void setVelocityX( float velX );
    float getVelocityX();
    
    void setVelocityY( float velY );
    float getVelocityY();
    
    void setWidth( float width );
    float getWidth();
    
    void setHeight( float height );
    float getHeight();
    
	int getHealth();
	void setHealth( int health );
	
    EntityTypes getType();
    
	void setDead();

	void hurtEntity( int damage );
    
    void updateHealth();
    
	virtual void draw() = 0;
	virtual void update() = 0;
};

#endif