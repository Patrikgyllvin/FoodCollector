//
//  EntityEnemyBox.h
//  SDLOpenGLGame
//
//  Created by Patrik Gyllvin on 2013-05-05.
//  Copyright (c) 2013 Patrik Gyllvin. All rights reserved.
//

#ifndef ENTITYENEMYBOX_H
#define ENTITYENEMYBOX_H

#include "Entity.h"

#include <SDL2/SDL_opengl.h>

class EntityEnemyBox : public Entity {
public:
    EntityEnemyBox( float x, float y, float width, float height );
    
    // implement
    void update();
    void draw();
};

#endif
