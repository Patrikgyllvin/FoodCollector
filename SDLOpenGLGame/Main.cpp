#include <iostream>
#include <vector>
#include <ctime>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "InputListener.h"
#include "InputManager.h"

#include "Entity.h"
#include "EntityEnemyBox.h"
#include "EntityManager.h"

int main()
{
    srand( time( NULL ) );
    
    SDL_Window *window;
    SDL_GLContext glContext;
    
    window = SDL_CreateWindow( "This is a window!",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              1920,
                              1080,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );
    
    glContext = SDL_GL_CreateContext( window );
    
	EntityManager *entityMgr = new EntityManager();
    InputManager *inputMgr = new InputManager();
    
    bool isRunning = true;
    
    SDL_Event event;
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, 1920, 1080, 0, 0, 1 );
    glMatrixMode( GL_MODELVIEW );
    
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    
    entityMgr->createPlayer( 100, 100, 10, 10, inputMgr );
    entityMgr->createEntity( ENTITY_ENEMY );
    
    do {
        inputMgr->sendInputDataToListeners();
        
        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_QUIT || ( event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE ) )
            {
                isRunning = false;
            }
        }
        
        // game loop
        
        if ( entityMgr->Entity) {
            <#statements#>
        }
        
        //rendering
        glClear( GL_COLOR_BUFFER_BIT );
        
        entityMgr->updateEntities();
        entityMgr->drawEntities();
        
        SDL_GL_SwapWindow( window );
    }
    while( isRunning );
    
    delete entityMgr;
    delete inputMgr;
	
    SDL_GL_DeleteContext( glContext );
    
    SDL_DestroyWindow( window );
    
    SDL_Quit();

	return 0;
}