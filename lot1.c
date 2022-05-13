int f = 10;
Uint32 animateChar(Uint32 interval, void* param) {
  Game* game = param;
  int limit;
  switch (game->character[game->character->id].state) {
    case (IDLE): {
      limit =2;
      break;
    }
    case (WALKING):{
      limit = 8;
      break;
    }
    case (FALLING):{
      limit = 3;
      break;
    }
    case (JUMPING):{
      limit = 3;
      break;
    }
    case (ATTACKING):{
      limit = 5;
      break;
    }
  }
  game->character[game->character->id].currentSprite++;
  if(game->character[game->character->id].currentSprite == limit) {
    if(game->character[game->character->id].state == ATTACKING)
      game->character[game->character->id].state = IDLE;
    if(game->character[game->character->id].state == FALLING && game->character[game->character->id].spritePos.y >= game->currentFloor)
      game->character[game->character->id].state = IDLE;
      
    game->character[game->character->id].currentSprite = 0;
  }
  return interval;
}


void initMc(Game* game) {
  game->character[0].id = 0;
  SDL_Surface* idle[2] = {
    IMG_Load("mc/idle1.png"),
    IMG_Load("mc/idle2.png"),
  };

  SDL_Surface* walking[8] = {
    IMG_Load("mc/walking1.png"),
    IMG_Load("mc/walking2.png"),
    IMG_Load("mc/walking3.png"),
    IMG_Load("mc/walking4.png"),
    IMG_Load("mc/walking5.png"),
    IMG_Load("mc/walking6.png"),
    IMG_Load("mc/walking7.png"),
    IMG_Load("mc/walking8.png"),
  };

  SDL_Surface* running[8] = {
    IMG_Load("mc/walking1.png"),
    IMG_Load("mc/walking2.png"),
    IMG_Load("mc/walking3.png"),
    IMG_Load("mc/walking4.png"),
    IMG_Load("mc/walking5.png"),
    IMG_Load("mc/walking6.png"),
    IMG_Load("mc/walking7.png"),
    IMG_Load("mc/walking8.png"),
  };

  SDL_Surface* jumping[3]= {
    IMG_Load("mc/jumping1.png"),
    IMG_Load("mc/jumping2.png"),
    IMG_Load("mc/jumping3.png"),
  }; 
  SDL_Surface* falling[3] = {
    IMG_Load("mc/jumping3.png"),
    IMG_Load("mc/jumping2.png"),
    IMG_Load("mc/jumping1.png"),
  };

  SDL_Surface* attacking[5] = {
    IMG_Load("mc/attacking1.png"),
    IMG_Load("mc/attacking2.png"),
    IMG_Load("mc/attacking3.png"),
    IMG_Load("mc/attacking4.png"),
    IMG_Load("mc/attacking5.png"),
  };

  SDL_Surface* idle1[2] = {
    IMG_Load("mc/idle3.png"),
    IMG_Load("mc/idle4.png"),
  };

  SDL_Surface* walking1[8] = {
    IMG_Load("mc/walking9.png"),
    IMG_Load("mc/walking10.png"),
    IMG_Load("mc/walking11.png"),
    IMG_Load("mc/walking12.png"),
    IMG_Load("mc/walking13.png"),
    IMG_Load("mc/walking14.png"),
    IMG_Load("mc/walking15.png"),
    IMG_Load("mc/walking16.png"),
  };

  SDL_Surface* running1[8] = {
    IMG_Load("mc/walking9.png"),
    IMG_Load("mc/walking10.png"),
    IMG_Load("mc/walking11.png"),
    IMG_Load("mc/walking12.png"),
    IMG_Load("mc/walking13.png"),
    IMG_Load("mc/walking14.png"),
    IMG_Load("mc/walking15.png"),
    IMG_Load("mc/walking16.png"),
  };

  SDL_Surface* jumping1[3]= {
    IMG_Load("mc/jumping4.png"),
    IMG_Load("mc/jumping5.png"),
    IMG_Load("mc/jumping6.png"),
  };

  SDL_Surface* falling1[3] = {
    IMG_Load("mc/jumping6.png"),
    IMG_Load("mc/jumping5.png"),
    IMG_Load("mc/jumping4.png"),
  };

  SDL_Surface* attacking1[5] = {
    IMG_Load("mc/attacking6.png"),
    IMG_Load("mc/attacking7.png"),
    IMG_Load("mc/attacking8.png"),
    IMG_Load("mc/attacking9.png"),
    IMG_Load("mc/attacking10.png"),
  };

  for(int i=0; i<2; i++) {
    game->character[0].spriteSheet[RIGHT][IDLE][i] = idle[i];
    game->character[0].spriteSheet[LEFT][IDLE][i] = idle1[i];
  }

  for(int i=0; i<8; i++) {
    game->character[0].spriteSheet[RIGHT][WALKING][i] = walking[i];
    game->character[0].spriteSheet[LEFT][WALKING][i] = walking1[i];
  }

  for(int i=0; i<8; i++) {
    game->character[0].spriteSheet[RIGHT][RUNNING][i] = running[i];
    game->character[0].spriteSheet[LEFT][RUNNING][i] = running1[i];
  }
  for(int i=0; i<3; i++) {
    game->character[0].spriteSheet[RIGHT][JUMPING][i] = jumping[i];
    game->character[0].spriteSheet[LEFT][JUMPING][i] = jumping1[i];
  }

  for(int i=0; i<3; i++) {
    game->character[0].spriteSheet[RIGHT][FALLING][i] = falling[i];
    game->character[0].spriteSheet[LEFT][FALLING][i] = falling1[i];
  }

  for(int i=0; i<5; i++) {
    game->character[0].spriteSheet[RIGHT][ATTACKING][i] = attacking[i];
    game->character[0].spriteSheet[LEFT][ATTACKING][i] = attacking1[i];
  }

  game->character[0].state = IDLE;
  game->character[0].currentSprite = 0;
  game->character[0].direction = RIGHT;
  game->character[0].spritePos.x = 0;
  game->character[0].spritePos.y = game->currentFloor ;
  game->character[0].spritePos.w = game->character[0].spriteSheet[game->character[0].direction][game->character[0].state][game->character[0].currentSprite]->w;
  game->character[0].spritePos.h = game->character[0].spriteSheet[game->character[0].direction][game->character[0].state][game->character[0].currentSprite]->h;

  game->character[0].health = 3;

  game->character[0].hearts[3] = IMG_Load ("Images/Assets/3l3.png");
  game->character[0].hearts[2] = IMG_Load ("Images/Assets/3l2.png");
  game->character[0].hearts[1] = IMG_Load ("Images/Assets/3l1.png");
  game->character[0].hearts[0] = IMG_Load ("Images/Assets/3l0.png");

  game->character[0].heartsPos.x = 1074;
  game->character[0].heartsPos.y = 12;
  game->character[0].heartsPos.w = game->character[0].hearts[0]->w;
  game->character[0].heartsPos.h = game->character[0].hearts[0]->h;
}

void manageState(Game* game) {
  game->character[game->character->id].keystate = SDL_GetKeyState(NULL);
  int run = SDLK_LALT;
  int right = SDLK_d;
  int left = SDLK_a;
  if(game->character[game->character->id].state == ATTACKING || game->character[game->character->id].state == JUMPING || game->character[game->character->id].state == FALLING) {

  } else if(game->character[game->character->id].keystate[run] && game->character[game->character->id].keystate[right]){
    game->character[game->character->id].direction = RIGHT;
    game->character[game->character->id].state = RUNNING;
  } else if(game->character[game->character->id].keystate[run] && game->character[game->character->id].keystate[left]) {
    game->character[game->character->id].direction = LEFT;
    game->character[game->character->id].state = RUNNING;
  } else if(game->character[game->character->id].keystate[run]) {
    game->character[game->character->id].direction = RIGHT;
    game->character[game->character->id].state = RUNNING;
  } else if(game->character[game->character->id].keystate[right]) {
    game->character[game->character->id].direction = RIGHT;
    game->character[game->character->id].state = WALKING;
    if(game->character[game->character->id].currentSprite >= 8)
      game->character[game->character->id].currentSprite = 0;
  } else if(game->character[game->character->id].keystate[left]) {
    game->character[game->character->id].direction = LEFT;
    game->character[game->character->id].state = WALKING;
    if(game->character[game->character->id].currentSprite >= 8)
      game->character[game->character->id].currentSprite = 0;
  } else {
    game->character[game->character->id].state = IDLE;
    if(game->character[game->character->id].currentSprite >= 2)
      game->character[game->character->id].currentSprite = 0;
  }
}

void moveChar(Game* game) {

  int run = SDLK_LALT;
  int right = SDLK_d;
  int left = SDLK_a;
  int jump = SDLK_SPACE;
  int attack = SDLK_x;
  // collision = 6;
  //printf("yo\n");
  if(game->character[0].keystate[run]) {
    game->character[0].spritePos.x += game->character[0].keystate[left] ? -5 : 5; 
    if (game->character[0].keystate[left]) {
      if (game->minimap.miniPos.x > game->minimap.miniMapPos.x) {
        game->minimap.miniPos.x -= 6;
      }
    } else {
      if (game->minimap.miniPos.x <= game->minimap.miniMap[game->currentMp]->w) {
        game->minimap.miniPos.x += 6;
      }
    }
  }
    if(game->character[0].keystate[left]){
      game->character[0].spritePos.x -= 2;
      if (game->minimap.miniPos.x > game->minimap.miniMapPos.x) {
        game->minimap.miniPos.x -= 2;
      }
  }
      if(game->character[0].keystate[right]){
      game->character[0].spritePos.x += 2;
      if (game->minimap.miniPos.x <= game->minimap.miniMap[game->currentMp]->w) {
        game->minimap.miniPos.x += 2;
      }
      
      //printf("%d\n",game->avancement);
    }
  
  
}

void jumpChar (Game* game) {

  if(game->character[game->character->id].spritePos.x >= 1100 && game->currentMenu == LEVELONE) {
    game->currentMenu = RIDDLE;
  }

  if (game->bg.camera.x == 700 && game->currentMenu == LEVELTWO) {
    game->currentMenu = TICTACTOE;
  }

  if (game->bg.camera.x >= 4000 && game->currentMenu == LEVELTWO) {
    game->currentMenu = CARDS;
  }

  if ((game->character[game->character->id].state == IDLE) || (game->character[game->character->id].state == WALKING)) {
    if ((collision[6] == 0) && (game->character[game->character->id].spritePos.y < game->currentFloor)) {
      // game->character[0].state = FALLING;
      game->character[game->character->id].spritePos.y += 10;
    }
  }
  //printf("%d\n", game->character[0].spritePos.y);
  if(game->character[game->character->id].state == JUMPING) {
  game->character[game->character->id].spritePos.y-=10;
  
    if(game->character[game->character->id].spritePos.y <= 150) {
      if (collision[6]==1){
      game->character[game->character->id].currentSprite = 0;
      game->character[game->character->id].state = IDLE;
      } else {
        game->character[game->character->id].state = FALLING;
      }
    }
  }
  
  if(game->character[game->character->id].state == FALLING) {
      // printf("%d\n", collision == 5);
      
    if(game->character[game->character->id].spritePos.y > game->currentFloor) {
      game->character[game->character->id].spritePos.y = game->currentFloor;
      game->character[game->character->id].state = IDLE;
    }
     //printf("%d\n", collision[6]);
    if (collision[6]==1){
        game->character[game->character->id].state = IDLE;
        game->character[game->character->id].spritePos.y -= 13;
      } else if (collision[6]==0) {
        game->character[game->character->id].spritePos.y += 10;
      }
  }
  // if ((game->character[0].spritePos.y < game->currentFloor) && (collision[6]==0) && (game->character[0].state != JUMPING)) {
  //   game->character[0].state = FALLING;
  // }
  SDL_Event e;
  while(SDL_PollEvent(&e)) {
      switch(e.type) {
        case SDL_KEYDOWN: {
          int key = e.key.keysym.sym;
          if(key == SDLK_ESCAPE) {
            game->done = 1;
            break;
          }
          if(key == SDLK_x) {
            game->character[game->character->id].currentSprite = 0;
            game->character[game->character->id].state = ATTACKING;
            break;
          }
          if(key == SDLK_SPACE) {
            game->character[game->character->id].currentSprite = 0;
            game->character[game->character->id].state = JUMPING;
            break;
          }
          if (key == SDLK_s) {
            game->character[game->character->id].spritePos.y += 2;
            game->character[game->character->id].state = IDLE;
            break;
          }
          if (key == SDLK_w) {
            game->character[game->character->id].spritePos.y -= 2;
            game->character[game->character->id].state = IDLE;
            break;
          }
          if (key == SDLK_p) {
            game->currentMenu = PAUSEMENU;
            break;
          }
          break;
        }
      }
    }

}


void showChar(Game game) {
  SDL_BlitSurface(game.character[game.character->id].hearts[game.character[game.character->id].health], 0, game.screen, &game.character[game.character->id].heartsPos);
  SDL_BlitSurface(game.character[game.character->id].spriteSheet[game.character[game.character->id].direction][game.character[game.character->id].state][game.character[game.character->id].currentSprite], 0, game.screen, &game.character[game.character->id].spritePos);
}


void initMc1(Game* game) {
  game->character[0].id = 0;
  SDL_Surface* idle[2] = {
    IMG_Load("mc1/idle1.png"),
    IMG_Load("mc1/idle2.png"),
  };

  SDL_Surface* walking[8] = {
    IMG_Load("mc1/walking1.png"),
    IMG_Load("mc1/walking2.png"),
    IMG_Load("mc1/walking3.png"),
    IMG_Load("mc1/walking4.png"),
    IMG_Load("mc1/walking5.png"),
    IMG_Load("mc1/walking6.png"),
    IMG_Load("mc1/walking7.png"),
    IMG_Load("mc1/walking8.png"),
  };

  SDL_Surface* running[8] = {
    IMG_Load("mc1/walking1.png"),
    IMG_Load("mc1/walking2.png"),
    IMG_Load("mc1/walking3.png"),
    IMG_Load("mc1/walking4.png"),
    IMG_Load("mc1/walking5.png"),
    IMG_Load("mc1/walking6.png"),
    IMG_Load("mc1/walking7.png"),
    IMG_Load("mc1/walking8.png"),
  };

  SDL_Surface* jumping[3]= {
    IMG_Load("mc1/jumping1.png"),
    IMG_Load("mc1/jumping2.png"),
    IMG_Load("mc1/jumping3.png"),
  }; 
  SDL_Surface* falling[3] = {
    IMG_Load("mc1/jumping3.png"),
    IMG_Load("mc1/jumping2.png"),
    IMG_Load("mc1/jumping1.png"),
  };

  SDL_Surface* attacking[5] = {
    IMG_Load("mc1/attacking1.png"),
    IMG_Load("mc1/attacking2.png"),
    IMG_Load("mc1/attacking3.png"),
    IMG_Load("mc1/attacking4.png"),
    IMG_Load("mc1/attacking5.png"),
  };

  SDL_Surface* idle1[2] = {
    IMG_Load("mc1/idle3.png"),
    IMG_Load("mc1/idle4.png"),
  };

  SDL_Surface* walking1[8] = {
    IMG_Load("mc1/walking9.png"),
    IMG_Load("mc1/walking10.png"),
    IMG_Load("mc1/walking11.png"),
    IMG_Load("mc1/walking12.png"),
    IMG_Load("mc1/walking13.png"),
    IMG_Load("mc1/walking14.png"),
    IMG_Load("mc1/walking15.png"),
    IMG_Load("mc1/walking16.png"),
  };

  SDL_Surface* running1[8] = {
    IMG_Load("mc1/walking9.png"),
    IMG_Load("mc1/walking10.png"),
    IMG_Load("mc1/walking11.png"),
    IMG_Load("mc1/walking12.png"),
    IMG_Load("mc1/walking13.png"),
    IMG_Load("mc1/walking14.png"),
    IMG_Load("mc1/walking15.png"),
    IMG_Load("mc1/walking16.png"),
  };

  SDL_Surface* jumping1[3]= {
    IMG_Load("mc1/jumping4.png"),
    IMG_Load("mc1/jumping5.png"),
    IMG_Load("mc1/jumping6.png"),
  };

  SDL_Surface* falling1[3] = {
    IMG_Load("mc1/jumping6.png"),
    IMG_Load("mc1/jumping5.png"),
    IMG_Load("mc1/jumping4.png"),
  };

  SDL_Surface* attacking1[5] = {
    IMG_Load("mc1/attacking6.png"),
    IMG_Load("mc1/attacking7.png"),
    IMG_Load("mc1/attacking8.png"),
    IMG_Load("mc1/attacking9.png"),
    IMG_Load("mc1/attacking10.png"),
  };

  for(int i=0; i<2; i++) {
    game->character[1].spriteSheet[RIGHT][IDLE][i] = idle[i];
    game->character[1].spriteSheet[LEFT][IDLE][i] = idle1[i];
  }

  for(int i=0; i<8; i++) {
    game->character[1].spriteSheet[RIGHT][WALKING][i] = walking[i];
    game->character[1].spriteSheet[LEFT][WALKING][i] = walking1[i];
  }

  for(int i=0; i<8; i++) {
    game->character[1].spriteSheet[RIGHT][RUNNING][i] = running[i];
    game->character[1].spriteSheet[LEFT][RUNNING][i] = running1[i];
  }
  for(int i=0; i<3; i++) {
    game->character[1].spriteSheet[RIGHT][JUMPING][i] = jumping[i];
    game->character[1].spriteSheet[LEFT][JUMPING][i] = jumping1[i];
  }

  for(int i=0; i<3; i++) {
    game->character[1].spriteSheet[RIGHT][FALLING][i] = falling[i];
    game->character[1].spriteSheet[LEFT][FALLING][i] = falling1[i];
  }

  for(int i=0; i<5; i++) {
    game->character[1].spriteSheet[RIGHT][ATTACKING][i] = attacking[i];
    game->character[1].spriteSheet[LEFT][ATTACKING][i] = attacking1[i];
  }

  game->character[1].state = IDLE;
  game->character[1].currentSprite = 0;
  game->character[1].direction = RIGHT;
  game->character[1].spritePos.x = 0;
  game->character[1].spritePos.y = game->currentFloor ;
  game->character[1].spritePos.w = game->character[1].spriteSheet[game->character[1].direction][game->character[1].state][game->character[1].currentSprite]->w;
  game->character[1].spritePos.h = game->character[1].spriteSheet[game->character[1].direction][game->character[1].state][game->character[1].currentSprite]->h;

  game->character[1].health = 3;

  game->character[1].hearts[3] = IMG_Load ("Images/Assets/3l3.png");
  game->character[1].hearts[2] = IMG_Load ("Images/Assets/3l2.png");
  game->character[1].hearts[1] = IMG_Load ("Images/Assets/3l1.png");
  game->character[1].hearts[0] = IMG_Load ("Images/Assets/3l0.png");

  game->character[1].heartsPos.x = 1074;
  game->character[1].heartsPos.y = 12;
  game->character[1].heartsPos.w = game->character[1].hearts[0]->w;
  game->character[1].heartsPos.h = game->character[1].hearts[0]->h;
}