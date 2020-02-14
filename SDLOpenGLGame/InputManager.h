#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_keyboard.h>

#include "InputListener.h"

class InputManager {
private:
    Uint8 *inputData;
	std::vector<InputListener*> listeners;
    
public:

	void addListener( InputListener *listener )
	{
		listeners.push_back( listener );
	}

	void removeListener( InputListener *listener )
	{}
    
	void sendInputDataToListeners()
	{
        SDL_PumpEvents();
        inputData = SDL_GetKeyboardState( NULL );
        
        for( std::vector<InputListener*>::iterator listenersIter = listeners.begin(); listenersIter != listeners.end(); ++listenersIter )
		{
            std::cout << inputData;
            (*listenersIter)->handleKeyboardInput( inputData );
		}
	}
};

#endif