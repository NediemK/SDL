void manageLevels (Game* game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case (SDL_KEYDOWN): {
                int key = event.key.keysym.sym;
                switch (key) {
                    case(SDLK_p): {
                        game->currentMenu = PAUSEMENU;
                        break;
                    }
                }
            }
        }
    }
}

void levelOneRende(Game game) {
    SDL_BlitSurface (game.levels.portal[game.currentPortal].portal, NULL, game.bg.img[0], &game.levels.portal[0].pos);
    SDL_BlitSurface (game.levels.portal[game.currentPortal].portal, NULL, game.bg.img[1], &game.levels.portal[0].pos);
    SDL_BlitSurface (game.levels.portal[game.currentPortal].portal, NULL, game.bg.img[2], &game.levels.portal[0].pos);
}

SDL_Color getpixel ( SDL_Surface *psurface , int x , int y ) 
{
   SDL_Color color ; 
   Uint32 col = 0 ; 
   char* pPosition =(char*) psurface->pixels ; 
   pPosition+=(psurface->pitch * y ); 
   pPosition+=(psurface->format->BytesPerPixel * x ) ; 
   memcpy(&col,pPosition,psurface->format->BytesPerPixel) ; 
   SDL_GetRGB (col,psurface->format,&color.r,&color.g,&color.b); 
   return(color) ; 
}

void collisionPP(Game game, int* collision){
    SDL_Color CouleurObstacle,CouleurTrouver;
    CouleurObstacle.r=255;
    CouleurObstacle.g=0;
    CouleurObstacle.b=0;
    int x=game.character[game.character->id].spritePos.x,y=game.character[game.character->id].spritePos.y,w=game.character[game.character->id].spritePos.w,h=game.character[game.character->id].spritePos.h;
    SDL_Rect posRef[8];
    posRef[0].x=x;
    posRef[0].y=y;
    posRef[1].x=(x+w)/2;
    posRef[1].y=y;
    posRef[2].x=x+w;
    posRef[2].y=y;
    posRef[3].x=x;
    posRef[3].y=(y+h)/2;
    posRef[4].x=x;
    posRef[4].y=y+h;
    posRef[5].x=(x+w)/2;
    posRef[5].y=y+h;
    posRef[6].x=x+w;
    posRef[6].y=y+h;
    posRef[7].x=x+w;
    posRef[7].y=((y+h)/2);
    for (int o=0; o<8; o++) {
        posRef[o].w = game.character[game.character->id].spritePos.w;
        posRef[o].h = game.character[game.character->id].spritePos.h;
    }
    int i=0;
    for(i=0;i<8;i++){
        CouleurTrouver=getpixel(game.bg.img[game.currentLevel],posRef[i].x,posRef[i].y);
        collision[i] = ((CouleurObstacle.r == CouleurTrouver.r) && (CouleurObstacle.g == CouleurTrouver.g) && (CouleurObstacle.b == CouleurTrouver.b));
        if ((CouleurObstacle.r == CouleurTrouver.r)) {
            //data
        }
        
    
    }
}