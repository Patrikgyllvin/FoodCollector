//
//  EntityEnemyBox.cpp
//  SDLOpenGLGame
//
//  Created by Patrik Gyllvin on 2013-05-05.
//  Copyright (c) 2013 Patrik Gyllvin. All rights reserved.
//

#include "EntityEnemyBox.h"
#include "EntityManager.h"

EntityEnemyBox::EntityEnemyBox( float x, float y, float width, float height ) : Entity( false )
{
    this->setX( x );
    this->setY( y );
    this->setWidth( width );
    this->setHeight( height );
    this->type = ENTITY_ENEMY;
}

void EntityEnemyBox::update()
{
    int random = rand() % 200;
    int random1 = rand() % 200;
    
    if ( random == random1 )
    {
        setVelocityX( ( rand() % 10001 ) / 1000.0f - 5.0f );
        setVelocityY( ( rand() % 10001 ) / 1000.0f - 5.0f );
    }
    
    setX( getX() + getVelocityX() );
    setY( getY() + getVelocityY() );
    
    if( getX() < 0 )
    {
        setX( 0 );
        setVelocityX( -getVelocityX() );
    }
    else if( getX() > 1920 - 10 )
    {
        setX( 1920 - 10 );
        setVelocityX( -getVelocityX() );
    }
    
    if( getY() < 0 )
    {
        setY( 0 );
        setVelocityY( -getVelocityY() );
    }
    else if( getY() > 1080 - 10 )
    {
        setY( 1080 - 10 );
        setVelocityY( -getVelocityY() );
    }
}

void EntityEnemyBox::draw()
{
    glColor4f( 0.9f, 0.1f, 0.1f, 1.0f );
    glPushMatrix();
        glTranslatef( getX(), getY(), 0 );
        glRectf( -10, -10, 10, 10 );
    glPopMatrix();
}