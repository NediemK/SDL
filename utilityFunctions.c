#include "SDL/SDL.h"

// void renderCursor(Game* game) {
//   SDL_GetMouseState(&game->cursor.cursorPos.x, &game->cursor.cursorPos.y);
//   SDL_BlitSurface(game->cursor.cursor, 0, game->screen, &(game->cursor.cursorPos));
// }


int checkMouseInside(SDL_Rect pos, int mouseX, int mouseY) {
  return mouseX >= pos.x && mouseX <= pos.x + pos.w && mouseY >= pos.y && mouseY <= pos.y + pos.h;
}

void switchFullscreen(Game* game) {
  game->screen = SDL_SetVideoMode(game->screen->w, game->screen->h, 32, game->fullScreen ? SDL_FULLSCREEN : SDL_HWSURFACE|SDL_DOUBLEBUF);
}

SDL_TimerID my_timer_id;
Uint32 bounceBack(Uint32 interval, void* param){
  int* state = param;
  *state = MOUSE_OUTSIDE;
  return 0;
}


Uint32 startGame(Uint32 interval, void* param) {
  Game* game = param;
  game->done=0;
  return 0;
}

Uint32 animateBg(Uint32 interval, void* param) {
  Game* game = param;
  game->mainMenu.currentBg++;
  if(game->mainMenu.currentBg == 302) {
    game->mainMenu.currentBg=0;
    return interval;
  } 
  return 0;
}

Uint32 animatePortal(Uint32 interval, void* param) {
  Game* game = param;
  game->currentPortal++;
  if(game->currentPortal == 9) {
    game->currentPortal=0;
    return interval;
  } 
  return 0;
}


void handleKeyDownMenu(Game* game, int key) {
  switch(key) {
    case SDLK_ESCAPE: 
      game->done = 1;
    case SDLK_s:
      game->currentMenu = 1;
    case SDLK_p:
      game->currentMenu = LEVELSELECT;
  }
}

void handleMouseMotion(Game* game) {
  int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        for(int i=0; i<3; i++) {
          SDL_Rect pos = game->mainMenu.buttons[i].pos;
          int mouseInside = checkMouseInside(pos, mouseX, mouseY);
          game->mainMenu.buttons[i].state = mouseInside ? MOUSE_HOVER : MOUSE_OUTSIDE;
          if(mouseInside) {
            Mix_VolumeChunk(game->hoverSFX, game->sfxVolume);
            Mix_PlayChannel(-1, game->hoverSFX, 1);
          }
        }
}

void handleMouseButtonDown(Game* game) {
  int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        SDL_Rect pos0 = game->mainMenu.buttons[0].pos;
        SDL_Rect pos1 = game->mainMenu.buttons[1].pos;
        SDL_Rect pos2 = game->mainMenu.buttons[2].pos;

        int mouseInside0 = checkMouseInside(pos0, mouseX, mouseY);
        int mouseInside1 = checkMouseInside(pos1, mouseX, mouseY);
        int mouseInside2 = checkMouseInside(pos2, mouseX, mouseY);

        if (mouseInside0) {
          Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
          Mix_PlayChannel(-1, game->clickSFX, 0);
          game->currentMenu = LEVELSELECT;
          SDL_Delay(400);
        }
        if (mouseInside1) {
          Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
          Mix_PlayChannel(-1, game->clickSFX, 0);
          game->currentMenu = SETTINGS_MENU;
          SDL_Delay(400);
        }
        if (mouseInside2) {
          Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
          Mix_PlayChannel(-1, game->clickSFX, 0);
          game->done = 1;
          SDL_Delay(400);
        }      
}

void handleMouseButtonUp(Game* game) {
  for(int i=0; i<3; i++) {
          my_timer_id = SDL_AddTimer(60, bounceBack, &game->mainMenu.buttons[i].state); 
        }
}

void handleKeyDownSettingsMenu(Game* game, int key) {
  switch(key) {
    case SDLK_ESCAPE: 
      game->done = 1;
    case SDLK_m:
      game->currentMenu = MAIN_MENU;
      break;
    case SDLK_f:
      game->fullScreen = !game->fullScreen;
      switchFullscreen(game);
      game->mainMenu.currentFullscreen = game->fullScreen ? WINDOWED : FULLSCREEN;
      break;

  }
}

void handleMouseMotionSettingsMenu(Game* game) {
  // data
}

void handleMouseButtonDownSettingsMenu(Game* game) {
  int mouseX, mouseY;
  SDL_Rect pos[4];
    SDL_GetMouseState(&mouseX, &mouseY);

    for (int i=0; i<4; i++) {
      pos[i] = game->settingsMenu.buttons[i].pos;
    }

    if (checkMouseInside(pos[0], mouseX, mouseY)) {
      if (game->bgMusicVolume<128) {
          game->bgMusicVolume+=9;
          Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
          Mix_PlayChannel(-1, game->clickSFX, 0);
          if (game->settingsMenu.state1!=14) {
            game->settingsMenu.state1+=1;
          }
      }
    }
    if (checkMouseInside(pos[1], mouseX, mouseY)) {
      if (game->bgMusicVolume>0) {
          game->bgMusicVolume-=9;
          Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
          Mix_PlayChannel(-1, game->clickSFX, 0);
          if (game->settingsMenu.state1!=0) {
            game->settingsMenu.state1-=1;
          }
      }
    }
    if (checkMouseInside(pos[2], mouseX, mouseY)) {
      if (game->sfxVolume<128) {
          game->sfxVolume+=9;
          Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
          Mix_PlayChannel(-1, game->clickSFX, 0);
          if (game->settingsMenu.state2!=14) {
            game->settingsMenu.state2+=1;
          }
      }
    }
    if (checkMouseInside(pos[3], mouseX, mouseY)) {
      if (game->sfxVolume>0) {
          game->sfxVolume-=9;
          Mix_VolumeChunk(game->clickSFX, game->sfxVolume);
          Mix_PlayChannel(-1, game->clickSFX, 0);
          if (game->settingsMenu.state2!=0) {
            game->settingsMenu.state2-=1;
          }
      }
    }
}

void handleMouseButtonUpSettingsMenu(Game* game) {
  // data
}

int collisionBB(MC m, Entity e) {
  int ew = e.spriteSheet[e.direction][e.state][e.currentSprite]->w;
  int eh = e.spriteSheet[e.direction][e.state][e.currentSprite]->h;

  int xCollision = m.pos.x > e.spritePos.x + ew || m.pos.x + m.img[0]->w < e.spritePos.x;
  int yCollision = m.pos.y > e.spritePos.y + eh || m.pos.y + m.img[0]->h < e.spritePos.y;
  return !(xCollision || yCollision);
}