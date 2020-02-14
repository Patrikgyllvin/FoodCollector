//
//  InputListener.cpp
//  SDLOpenGLGame
//
//  Created by Patrik Gyllvin on 2013-05-06.
//  Copyright (c) 2013 Patrik Gyllvin. All rights reserved.
//

#include "InputListener.h"
#include "InputManager.h"

InputListener::InputListener( InputManager *inputManager )
:
inputMgr( inputManager )
{
    inputMgr->addListener( this );
}

InputListener::~InputListener()
{
    inputMgr->removeListener( this );
}