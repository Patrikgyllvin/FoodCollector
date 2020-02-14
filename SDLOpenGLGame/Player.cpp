#include "Player.h"
#include "EntityManager.h"
#include "InputManager.h"

Player::Player( float x, float y, float width, float height, InputManager *inputManager )
:
Entity( true ),
InputListener( inputManager )
{
    this->type = ENTITY_PLAYER;
    this->setX( x );
    this->setY( y );
    this->setVelocityX( 0 );
    this->setVelocityY( 0 );
    this->setWidth( width );
    this->setHeight( height );
}

void Player::update()
{
    setX( getX() + getVelocityX() );
    setY( getY() + getVelocityY() );
}

void Player::draw()
{
    glColor4f( 1.0f, 1.0f, 1.0f, 1.0f );
    glPushMatrix();
        glTranslatef( getX(), getY(), 0 );
        glRectf( -this->getWidth(), -this->getHeight(), this->getWidth(), this->getHeight() );
    glPopMatrix();
}

void Player::handleKeyboardInput( Uint8 *data )
{
    if( data[ SDL_SCANCODE_UP ] )
    {
        setVelocityY( -3 );
    }
    else if( data[ SDL_SCANCODE_DOWN ] )
    {
        setVelocityY( 3 );
    }
    else
    {
        setVelocityY( 0 );
    }
    
    if( data[ SDL_SCANCODE_LEFT ] )
    {
        setVelocityX( -3 );
    }
    else if( data[ SDL_SCANCODE_RIGHT ] )
    {
        setVelocityX( 3 );
    }
    else
    {
        setVelocityX( 0 );
    }
}