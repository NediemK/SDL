void settingsMenuMusic(Game* game) {
  Mix_VolumeMusic(game->bgMusicVolume);
  if(game->musicPlaying == 0) {
    Mix_PlayMusic(game->bgMusic, -1);
    game->musicPlaying = 1;
  }
}

void settingsMenuSound(Game* game) {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN: {
        int key = event.key.keysym.sym;
        handleKeyDownSettingsMenu(game, key);
      }
      case SDL_MOUSEMOTION: {
        handleMouseMotionSettingsMenu(game);
      }
      break;
      case SDL_MOUSEBUTTONDOWN: {
        handleMouseButtonDownSettingsMenu(game);
      }
      case SDL_MOUSEBUTTONUP: 
        handleMouseButtonUpSettingsMenu(game);
        break;
    }
  }
}


void settingsMenuRenderSound(Game game) {
  SDL_FillRect(game.screen, 0, SDL_MapRGB(game.screen->format, 0,0,0));
  SDL_BlitSurface(game.mainMenu.bg[game.mainMenu.currentBg], &game.mainMenu.bgPosition, game.screen, 0);
  int state1 = game.settingsMenu.state1;
  int state2 = game.settingsMenu.state2;
  SDL_BlitSurface(game.settingsMenu.sliders1[state1].slider, 0, game.screen, &game.settingsMenu.sliders1[state1].pos);
  SDL_BlitSurface(game.settingsMenu.sliders2[state2].slider, 0, game.screen, &game.settingsMenu.sliders2[state2].pos);
  for (int i=0; i<4; i++) {
    SDL_BlitSurface(game.settingsMenu.buttons[i].button[0], 0, game.screen, &game.settingsMenu.buttons[i].pos);
  }
  SDL_Flip(game.screen);
}


void settingsMenu(Game* game) {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_MOUSEMOTION: {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        for(int i=0; i<2; i++) {
          SDL_Rect pos = game->settingsMenu.btnS[i].pos;
          int mouseInside = checkMouseInside(pos, mouseX, mouseY);
          game->settingsMenu.btnS[i].state = mouseInside ? MOUSE_HOVER : MOUSE_OUTSIDE;
      }
      break;
      case SDL_MOUSEBUTTONDOWN: {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        SDL_Rect pos0 = game->settingsMenu.btnS[0].pos;
        SDL_Rect pos1 = game->settingsMenu.btnS[1].pos;

        int mouseInside0 = checkMouseInside(pos0, mouseX, mouseY);
        int mouseInside1 = checkMouseInside(pos1, mouseX, mouseY);

        if (mouseInside0) {
          game->settingsMenu.currentMenu = 1;
          SDL_Delay(400);
        }
        if (mouseInside1) {
          game->settingsMenu.currentMenu = 2;
          SDL_Delay(400);
        }
      }
    }
  }
}
}

void settingsMenuRender(Game game) {
  SDL_FillRect(game.screen, 0, SDL_MapRGB(game.screen->format, 0,0,0));
  SDL_BlitSurface(game.mainMenu.bg[game.mainMenu.currentBg], &game.mainMenu.bgPosition, game.screen, 0);
  int state1 = game.settingsMenu.btnS[0].state;
  int state2 = game.settingsMenu.btnS[1].state;
  SDL_BlitSurface(game.settingsMenu.btnS[0].button[state1], 0, game.screen, &game.settingsMenu.btnS[0].pos);
  SDL_BlitSurface(game.settingsMenu.btnS[1].button[state2], 0, game.screen, &game.settingsMenu.btnS[1].pos);
  SDL_Flip(game.screen);
}

void settingsMenuControlsRender(Game game) {
  SDL_FillRect(game.screen, 0, SDL_MapRGB(game.screen->format, 0,0,0));
  SDL_BlitSurface(game.mainMenu.bg[game.mainMenu.currentBg], &game.mainMenu.bgPosition, game.screen, 0);

  int state1 = game.settingsMenu.btnSC[0].state;
  int state2 = game.settingsMenu.btnSC[1].state;
  int state3 = game.settingsMenu.btnSC[2].state;
  int state4 = game.settingsMenu.btnSC[3].state;

  SDL_BlitSurface(game.settingsMenu.btnSC[0].button[state1], 0, game.screen, &game.settingsMenu.btnSC[0].pos);
  SDL_BlitSurface(game.settingsMenu.btnSC[1].button[state1], 0, game.screen, &game.settingsMenu.btnSC[1].pos);
  SDL_BlitSurface(game.settingsMenu.btnSC[2].button[state1], 0, game.screen, &game.settingsMenu.btnSC[2].pos);
  SDL_BlitSurface(game.settingsMenu.btnSC[3].button[state1], 0, game.screen, &game.settingsMenu.btnSC[3].pos);

  SDL_Flip(game.screen);
}