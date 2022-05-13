void updateBg(Game* game) {

  game->character[game->character->id].keystate = SDL_GetKeyState(NULL);
  int left = SDLK_a;
  int right = SDLK_d;
  int run = SDLK_LALT;

  if(game->character[game->character->id].keystate[run] && game->character[game->character->id].keystate[right]) {
    if(game->character[game->character->id].spritePos.x <= (game->screen->w - game->character[game->character->id].spriteSheet[game->character[game->character->id].direction][game->character[game->character->id].state][game->character[game->character->id].currentSprite]->w)/2 || game->bg.camera.x + game->screen->w >= game->bg.img[game->currentLevel]->w) {
      game->character[game->character->id].spritePos.x+=30;
    }
    else game->bg.camera.x+=30;
  }

  else if(game->character[game->character->id].keystate[run] && game->character[game->character->id].keystate[left]) {
    if(game->bg.camera.x <= 0 || game->character[game->character->id].spritePos.x >= (game->screen->w - game->character[game->character->id].spriteSheet[game->character[game->character->id].direction][game->character[game->character->id].state][game->character[game->character->id].currentSprite]->w)/2)
      game->character[game->character->id].spritePos.x -=30;
    else game->bg.camera.x-=30;
  }

  else if(game->character[game->character->id].keystate[run]) {
    if(game->character[game->character->id].spritePos.x <= (game->screen->w - game->character[game->character->id].spriteSheet[game->character[game->character->id].direction][game->character[game->character->id].state][game->character[game->character->id].currentSprite]->w)/2 || game->bg.camera.x + game->screen->w >= game->bg.img[game->currentLevel]->w) {
      game->character[game->character->id].spritePos.x+=30;
    }
    else game->bg.camera.x+=30;
  }

  if ((collision[2]!=1) && (collision[7]!=1)) {
    if(game->character[game->character->id].keystate[right]) {
      // printf("%d\n", collision[6]);
     if(game->character[game->character->id].spritePos.x <= (game->screen->w - game->character[game->character->id].spriteSheet[game->character[game->character->id].direction][game->character[game->character->id].state][game->character[game->character->id].currentSprite]->w)/2 || game->bg.camera.x + game->screen->w >= game->bg.img[game->currentLevel]->w) {
      game->character[game->character->id].spritePos.x+=7;
     }
    else {
      game->bg.camera.x+=7;
    }
  }
  }
  
  
    if(game->character[game->character->id].keystate[left]) {
      if ((collision[0]!=1) && (collision[3]!=1) ) {
      if(game->bg.camera.x <= 0 || game->character[game->character->id].spritePos.x >= (game->screen->w - game->character[game->character->id].spriteSheet[game->character[game->character->id].direction][game->character[game->character->id].state][game->character[game->character->id].currentSprite]->w)/2)
        {
          game->character[game->character->id].spritePos.x-=7;
          }
      else {
        game->bg.camera.x-=7;
        }
      }
  }
  


  if(game->character[game->character->id].spritePos.x+game->character[game->character->id].spriteSheet[game->character[game->character->id].direction][game->character[game->character->id].state][game->character[game->character->id].currentSprite]->w >= game->screen->w)
    game->character[game->character->id].spritePos.x = game->screen->w - game->character[game->character->id].spriteSheet[game->character[game->character->id].direction][game->character[game->character->id].state][game->character[game->character->id].currentSprite]->w;
  if(game->character[game->character->id].spritePos.x < 0)
    game->character[game->character->id].spritePos.x = 0;



   /*if(bg->state == JUMPING) {
    game->bg->camera.y-=5;
    if(game->bg->camera.y <= 240)
      bg->state = FALLING;
  }


  if(bg->state == FALLING) {
    game->bg->camera.y+=8;
    if(game->bg->camera.y >= 300) {
      game->character[game->character->id].spritePos->y = !bg->num ? FLOOR : FLOOR1;
      bg->state = IDLE;
    }
  }*/



  if(game->bg.camera.x <= 0) game->bg.camera.x = 0;
  if(game->bg.camera.x + game->screen->w >= game->bg.img[game->currentLevel]->w) game->bg.camera.x = game->bg.img[game->currentLevel]->w - game->screen->w;

  SDL_Event e;
  while (SDL_PollEvent(&e)) {
      switch(e.type) {
        case SDL_KEYDOWN: {
          int key = e.key.keysym.sym;
          switch(key) {
            case SDLK_ESCAPE: 
              game->done = 1;
              break;
        }
      }
    }
  }
}

void showBg(Game game) {
  SDL_Rect yo;
  yo.x = 0;
  yo.y = 0;
  SDL_BlitSurface(game.bg.img[game.currentLevel], &game.bg.camera, game.screen, &game.bg.pos);
}

void initBg(Game* game) {
  game->bg.img[0] = IMG_Load("Images/Maps/lvl1.png");
  game->bg.img[1] = IMG_Load("Images/Maps/lvl2.png");
  game->bg.img[2] = IMG_Load("Images/Maps/lvl3.png");
  game->bg.img[4] = IMG_Load("Images/Maps/lvl1.png");
  game->bg.pos.x = 0;
  game->bg.pos.y = 0;
  game->bg.camera.x = 0;
  game->bg.camera.y =0;
  game->bg.camera.h = game->screen->h;
  game->bg.camera.w = game->screen->w;
  // bg->state = IDLE;
}


