//
//  InputListener.h
//  SDLOpenGLGame
//
//  Created by Patrik Gyllvin on 2013-05-05.
//  Copyright (c) 2013 Patrik Gyllvin. All rights reserved.
//

#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

#include <SDL2/SDL.h>

class InputManager;

class InputListener {
private:
	InputManager *inputMgr;
public:
	InputListener( InputManager *inputManager );
    ~InputListener();
    
	virtual void handleKeyboardInput( Uint8 *data ) = 0;
};

#endif