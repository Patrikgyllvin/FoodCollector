#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "InputManager.h"
#include "InputListener.h"

#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_keyboard.h>

class Player : public Entity, public InputListener {
private:
    float size;
    
public:
	Player( float x, float y, float width, float height, InputManager *inputManager );

	// implement
	void update();
	void draw();
    void handleKeyboardInput( Uint8 *data );
};

#endif