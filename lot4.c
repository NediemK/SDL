void initChar(Game* game) {
  game->minimap.miniMap[0] = IMG_Load("Images/Maps/mini1.png");
  game->minimap.miniMap[1] = IMG_Load("Images/Maps/mini2.png");
  game->minimap.miniMap[2] = IMG_Load("Images/Maps/mini3.png");
  game->minimap.miniChar = IMG_Load("mc/miniChar.png");

  SDL_Rect pos = {0, 458};
  SDL_Rect miniMapPos = {30, 20};
  SDL_Rect miniPos = {30,110};
  SDL_Rect cam = {0,0, game->screen->w, game->screen->h};

  game->minimap.miniMapPos = miniMapPos;
  game->minimap.miniPos = miniPos;
  game->currentMp = 0;
  font = TTF_OpenFont("FFFFORWA.TTF", 20);
  times = TTF_RenderText_Blended(font, "0", co);
  camera = cam;
}


void showMiniMap(Game game) {
  SDL_BlitSurface(game.minimap.miniMap[game.currentMp], 0, game.screen, &game.minimap.miniMapPos);
  SDL_BlitSurface(game.minimap.miniChar, 0, game.screen, &game.minimap.miniPos);

}


void showTime(Game game) {
  Uint32 timer = SDL_GetTicks();
  Uint32 minutes = timer/(1000*60);
  Uint32 seconds = timer/1000 % 60;
  Uint32 tenthSeconds = timer/10 % 100;
  char str[100];
  sprintf(str, "%ld : %ld : %ld", minutes, seconds, tenthSeconds);
  SDL_FreeSurface(times);
  times = TTF_RenderText_Blended(font, str, co);
  SDL_BlitSurface(times, 0, game.screen, &timePos);
}
