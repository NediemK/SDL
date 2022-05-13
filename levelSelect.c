void handleKeyDownLevelSelect(Game* game, int key) {
  switch(key) {
    case SDLK_ESCAPE: 
      game->done = 1;
    case SDLK_m:
      game->currentMenu = MAIN_MENU;
  }
}

void handleMouseMotionLevelSelect(Game* game) {
  int mouseX, mouseY;
  SDL_GetMouseState(&mouseX, &mouseY);
  for(int i=0; i<6; i++) {
    SDL_Rect pos = game->levelSelect.btn[i].pos;
    int mouseInside = checkMouseInside(pos, mouseX, mouseY);
    game->levelSelect.btn[i].state = mouseInside ? MOUSE_HOVER : MOUSE_OUTSIDE;
    if(mouseInside) {
      Mix_VolumeChunk(game->hoverSFX, game->sfxVolume);
      Mix_PlayChannel(-1, game->hoverSFX, 0);
    }
  }
}

void handleMouseButtonDownLevelSelect(Game* game) {
  int mouseX, mouseY;
  SDL_GetMouseState(&mouseX, &mouseY);

  SDL_Rect pos0 = game->levelSelect.btn[0].pos;
  SDL_Rect pos1 = game->levelSelect.btn[1].pos;
  SDL_Rect pos2 = game->levelSelect.btn[2].pos;
  SDL_Rect pos3 = game->levelSelect.btn[3].pos;
  SDL_Rect pos4 = game->levelSelect.btn[5].pos;

  int mouseInside0 = checkMouseInside(pos0, mouseX, mouseY);
  int mouseInside1 = checkMouseInside(pos1, mouseX, mouseY);
  int mouseInside2 = checkMouseInside(pos2, mouseX, mouseY);
  int mouseInside3 = checkMouseInside(pos3, mouseX, mouseY);
  int mouseInside4 = checkMouseInside(pos4, mouseX, mouseY);

  if (mouseInside0) {
    Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
    Mix_PlayChannel(-1, game->clickSFX, 0);
    game->currentMenu = LEVELONE;
    game->character[game->character->id].spritePos.x = 0;
    SDL_Delay(400);
  }
  if (mouseInside1) {
    Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
    Mix_PlayChannel(-1, game->clickSFX, 0);
    game->currentLevel = 1;
    game->currentMp = 1;
    game->currentMenu = LEVELTWO;
    game->character[game->character->id].spritePos.y = game->currentFloor;
    game->character[game->character->id].spritePos.x = 0;

    game->levels.portal[0].pos.x = 5800;
    game->levels.portal[0].pos.y = 218;

    SDL_Delay(400);
  }
  if (mouseInside2) {
    Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
    Mix_PlayChannel(-1, game->clickSFX, 0);
    game->currentLevel = 2;
    game->currentMp = 2;
    game->currentMenu = LEVELTHREE;
    game->character[game->character->id].spritePos.y = game->currentFloor;
    game->character[game->character->id].spritePos.x = 0;

    game->levels.portal[0].pos.x = 4000;
    game->levels.portal[0].pos.y = 348;
    SDL_Delay(400);
  }
  if (mouseInside3) {
    Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
    Mix_PlayChannel(-1, game->clickSFX, 0);
    loadGame(&game);
    SDL_Delay(400);
  }
  if(mouseInside4) {
    switch (game->character->id) {
      case(1):
      {game->character->id = 0;
      break;}
      case(0):
      {game->character->id = 1;
      break;}
    }
  }
}

void levelSelect(Game* game) {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN: {
        int key = event.key.keysym.sym;
        handleKeyDownLevelSelect(game, key);
        break;
      }
      case SDL_MOUSEMOTION: {
        handleMouseMotionLevelSelect(game);
        break;
      }
      case SDL_MOUSEBUTTONDOWN: {
        handleMouseButtonDownLevelSelect(game);
        break;
      }
    }
  }
}

void levelSelectRenderBtns(Game game) {
  for (int i=0; i<6; i++) {
    int state = game.levelSelect.btn[i].state;
    SDL_BlitSurface(game.levelSelect.btn[i].button[state], 0, game.screen, &game.levelSelect.btn[i].pos);
  }
}

void levelSelectRender(Game game) {
  SDL_FillRect(game.screen, 0, SDL_MapRGB(game.screen->format, 0,0,0));
  SDL_BlitSurface(game.mainMenu.bg[game.mainMenu.currentBg], &game.mainMenu.bgPosition, game.screen, 0);
  levelSelectRenderBtns(game);
  SDL_BlitSurface(game.levelSelect.icon[game.character->id], 0, game.screen, &game.levelSelect.posIcon);
  SDL_Flip(game.screen);
}

