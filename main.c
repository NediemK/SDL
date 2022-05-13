#include <stdio.h>
#include <string.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "types.h"
#include "game.h"
#include "mainMenu.c"
#include "settingsMenu.c"
#include "levelSelect.c"
#include "lot1.c"
#include "lot2.c"
#include "lot3.c"
#include "lot4.c"
#include "lot5.c"
#include "lot6.c"
#include "levels.c"
#include "pauseMenu.c"
#include "manageProcess.c"
#include "xo.c"
#include "cards.c"



void main() {
  Game game = gameInit();
  animateMC = SDL_AddTimer(100, animateChar, &game);
  animateEnnemyy = SDL_AddTimer(150, animateEnnemy, &game);
  while(!game.done) {
    if(game.currentMenu == MAIN_MENU) {
      startTimer = SDL_AddTimer(1000, animateBg, &game);
      mainMenuMusic(&game);
      mainMenu(&game);
      mainMenuRender(game);
      game.settingsMenu.currentMenu = 0;
    } else if(game.currentMenu == SETTINGS_MENU) {
      if (game.settingsMenu.currentMenu == 0) {
        startTimer = SDL_AddTimer(1000, animateBg, &game);
        settingsMenu(&game);
        settingsMenuRender(game);
      } else if (game.settingsMenu.currentMenu == 1) {
        startTimer = SDL_AddTimer(1000, animateBg, &game);
        settingsMenuMusic(&game);
        settingsMenuSound(&game);
        settingsMenuRenderSound(game);
      } else if (game.settingsMenu.currentMenu == 2) {
        startTimer = SDL_AddTimer(1000, animateBg, &game);
        settingsMenuControlsRender(game);
      }
    } else if(game.currentMenu == LEVELSELECT) {
      startTimer = SDL_AddTimer(1000, animateBg, &game);
      levelSelect(&game);
      levelSelectRender(game);
    } else if (game.currentMenu == LEVELONE) {
      startTimer1 = SDL_AddTimer(1000, animatePortal, &game);
      animateEC = SDL_AddTimer(1000, animateE, &game);
      manageState(&game);
      updateBg(&game);
      showBg(game);
      showE(game);
      jumpChar(&game);
      showChar(game);
      showMiniMap(game);
      levelOneRende(game);
      showMiniMap(game);
      showTime(game);
      collisionPP(game, &collision);
    } else if (game.currentMenu == LEVELTWO) {
      startTimer1 = SDL_AddTimer(1000, animatePortal, &game);
      manageState(&game);
      updateBg(&game);
      showBg(game);
      showE(game);
      jumpChar(&game);
      showChar(game);
      showMiniMap(game);
      levelOneRende(game);
      showMiniMap(game);
      showTime(game);
      collisionPP(game, &collision);
    } else if (game.currentMenu == LEVELTHREE) {
      startTimer1 = SDL_AddTimer(1000, animatePortal, &game);
      manageState(&game);
      updateBg(&game);
      showBg(game);
      // animerEnnemy(&game);
      showEnnemy(game);
      moveEnnemy(&game);
      showE(game);
      jumpChar(&game);
      showChar(game);
      showMiniMap(game);
      levelOneRende(game);
      showMiniMap(game);
      showTime(game);
      collisionPP(game, &collision);
    } else if (game.currentMenu == PAUSEMENU) {
      showPause(game);
      managePause(&game);
    } else if (game.currentMenu == RIDDLE) {
      SDL_TimerID startTimer3 = SDL_AddTimer(10, animateSprite, &game);
      afficherEnigme(&game);
      resolutionEnigme(&game);
    } else if (game.currentMenu == TICTACTOE) {
      showXo (game);
      placeXo (&game);
      manageXo (&game);
    } else if (game.currentMenu == CARDS) {
      showCards (&game);
      manageCards (&game);
    }
    SDL_Flip(game.screen);
  }
  SDL_RemoveTimer(startTimer);
  SDL_Quit();
}