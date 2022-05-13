void initializeSDL() {
  SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER );
  atexit(SDL_Quit);
  SDL_WM_SetCaption("Game", NULL);
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 0);
  TTF_Init();
}



void initializeMainMenu(Game* game) {
  
  game->bgMusic = Mix_LoadMUS("Audio/BgMusic/bgMusic.mp3");
  game->musicPlaying = 0;
  game->bgMusicVolume = 128;
  game->sfxVolume = 128;
  game->hoverSFX = Mix_LoadWAV("Audio/ButtonsSound/soundButton.wav");
  game->clickSFX = Mix_LoadWAV("Audio/ButtonsSound/soundButtonClicked.wav");
  
  MainMenu mainMenu = game->mainMenu;

  char bgpath[100]="Images/Bg/background1_0000";
  for(int k=0; k<10; k++) {
      char path[100];
      sprintf(path, "%s%i.png", bgpath, k);
      mainMenu.bg[k] = IMG_Load(path);
    }
  char bgpath1[100]="Images/Bg/background1_000";
  for(int k=10; k<100; k++) {
      char path[100];
      sprintf(path, "%s%i.png", bgpath1, k);
      mainMenu.bg[k] = IMG_Load(path);
    }
  char bgpath2[100]="Images/Bg/background1_00";
  for(int k=100; k<303; k++) {
      char path[100];
      sprintf(path, "%s%i.png", bgpath2, k);
      mainMenu.bg[k] = IMG_Load(path);
    }

  mainMenu.bgPosition.x = 0;
  mainMenu.bgPosition.y = 0;
  mainMenu.bgPosition.h = game->screen->h;
  mainMenu.bgPosition.w = game->screen->w;

  mainMenu.currentBg = 0;

  char PLAY_BTN_PATH[100]     = "Images/Buttons/PlayB";
  char SETTINGS_BTN_PATH[100] = "Images/Buttons/SettingsB";
  char QUIT_BTN_PATH[100]     = "Images/Buttons/QuitB";
  char* paths[3] = { PLAY_BTN_PATH, SETTINGS_BTN_PATH, QUIT_BTN_PATH };
    int padding = 30;

  for(int i=0; 3>i; i++) {
    mainMenu.buttons[i].state = MOUSE_OUTSIDE;
    for(int k=0; 3>k; k++) {
      char path[100];
      sprintf(path, "%s%i.png", paths[i], k+1);
      mainMenu.buttons[i].button[k] = IMG_Load(path);
    }

    
  }

  mainMenu.buttons[0].pos.x = 1280 / 2 - 100;
  mainMenu.buttons[2].pos.x = 1280 - 360;
  mainMenu.buttons[1].pos.x = 150;

  mainMenu.buttons[0].pos.y = 720 / 2 - 20;
  mainMenu.buttons[1].pos.y = 720 / 2 - 20;
  mainMenu.buttons[2].pos.y = 720 / 2 - 20;

  mainMenu.buttons[0].pos.w = mainMenu.buttons[0].button[0]->w;
  mainMenu.buttons[0].pos.h = mainMenu.buttons[0].button[0]->h;

  mainMenu.buttons[1].pos.w = mainMenu.buttons[1].button[0]->w;
  mainMenu.buttons[1].pos.h = mainMenu.buttons[1].button[0]->h;

  mainMenu.buttons[2].pos.w = mainMenu.buttons[2].button[0]->w;
  mainMenu.buttons[2].pos.h = mainMenu.buttons[2].button[0]->h;  
  

  // SDL_Surface* btn = mainMenu.buttons[PLAY_BTN].button[0]; 
  // SDL_Rect pos = { 542, 260, btn->w, btn->h};
  // mainMenu.buttons[0].pos = pos;
  // for(int i=1; 3>i; i++) {
  //   SDL_Surface* currentBtn = mainMenu.buttons[i].button[0];
  //   SDL_Rect posPreviousBtn = mainMenu.buttons[i-1].pos;
  //   SDL_Rect currentBtnPos = { 
  //     posPreviousBtn.x,
  //     posPreviousBtn.y + posPreviousBtn.h + 10,
  //     currentBtn->w,
  //     currentBtn->h
  //   }; 
  //   mainMenu.buttons[i].pos = currentBtnPos;
  // }

  mainMenu.logo.logo = IMG_Load ("Images/Titles/Logo.png");

  mainMenu.logo.posLogo.x = 155;
  mainMenu.logo.posLogo.y = 125;
  mainMenu.logo.posLogo.w = mainMenu.logo.logo->w;
  mainMenu.logo.posLogo.h = mainMenu.logo.logo->h;

  game->mainMenu = mainMenu;
}

void initializeSettingsMenu(Game* game) {
  SettingsMenu settingsMenu = game->settingsMenu;
  settingsMenu.bg = IMG_Load("Images/Bg/backgroundSettings.png");
  settingsMenu.bgPosition.x = 0;
  settingsMenu.bgPosition.y = 0;
  settingsMenu.bgPosition.h = settingsMenu.bg->h;
  settingsMenu.bgPosition.w = settingsMenu.bg->w;

  

  for(int k=0; k<14; k++) {
    char Slider[100] = "Images/Slider/slider";
    char path[100];
    sprintf(path, "%s%i.png", Slider, k);
    settingsMenu.sliders1[k].slider = IMG_Load(path);
  }
  for(int k=0; k<14; k++) {
    settingsMenu.sliders1[k].pos.x = 340;
    settingsMenu.sliders1[k].pos.y = 100;
    settingsMenu.sliders1[k].pos.h = settingsMenu.sliders1[k].slider->h;
    settingsMenu.sliders1[k].pos.w = settingsMenu.sliders1[k].slider->w;
  }


  for(int k=0; k<14; k++) {
    char Slider[100] = "Images/Slider/slider";
    char path[100];
    sprintf(path, "%s%i.png", Slider, k);
    settingsMenu.sliders2[k].slider = IMG_Load(path);
  }
  for(int k=0; k<14; k++) {
    settingsMenu.sliders2[k].pos.x = 340;
    settingsMenu.sliders2[k].pos.y = 300;
    settingsMenu.sliders2[k].pos.h = settingsMenu.sliders2[k].slider->h;
    settingsMenu.sliders2[k].pos.w = settingsMenu.sliders2[k].slider->w;
  }

  settingsMenu.state1 = settingsMenu.state2 = 13;

  settingsMenu.buttons[0].button[0] = IMG_Load("Images/Buttons/plusbtn.png");


  settingsMenu.buttons[0].pos.x = 930;
  settingsMenu.buttons[0].pos.y = 170;
  settingsMenu.buttons[0].pos.h = settingsMenu.buttons[0].button[0]->h;
  settingsMenu.buttons[0].pos.w = settingsMenu.buttons[0].button[0]->w;

  settingsMenu.buttons[1].button[0] = IMG_Load("Images/Buttons/minusbtn.png");

  settingsMenu.buttons[1].pos.x = 290;
  settingsMenu.buttons[1].pos.y = 170;
  settingsMenu.buttons[1].pos.h = settingsMenu.buttons[1].button[0]->h;
  settingsMenu.buttons[1].pos.w = settingsMenu.buttons[1].button[0]->w;

  settingsMenu.buttons[2].button[0] = IMG_Load("Images/Buttons/plusbtn.png");


  settingsMenu.buttons[2].pos.x = 930;
  settingsMenu.buttons[2].pos.y = 370;
  settingsMenu.buttons[2].pos.h = settingsMenu.buttons[2].button[0]->h;
  settingsMenu.buttons[2].pos.w = settingsMenu.buttons[2].button[0]->w;

  settingsMenu.buttons[3].button[0] = IMG_Load("Images/Buttons/minusbtn.png");

  settingsMenu.buttons[3].pos.x = 290;
  settingsMenu.buttons[3].pos.y = 370;
  settingsMenu.buttons[3].pos.h = settingsMenu.buttons[2].button[0]->h;
  settingsMenu.buttons[3].pos.w = settingsMenu.buttons[2].button[0]->w;

  settingsMenu.btnS[0].button[0] = IMG_Load("Images/Buttons/soundSettings0.png");
  settingsMenu.btnS[0].button[1] = IMG_Load("Images/Buttons/soundSettings1.png");

  settingsMenu.btnS[0].pos.x = 300;
  settingsMenu.btnS[0].pos.y = 270;
  settingsMenu.btnS[0].pos.h = settingsMenu.btnS[0].button[0]->h;
  settingsMenu.btnS[0].pos.w = settingsMenu.btnS[0].button[0]->w;

  settingsMenu.btnS[1].button[0] = IMG_Load("Images/Buttons/controlSettings0.png");
  settingsMenu.btnS[1].button[1] = IMG_Load("Images/Buttons/controlSettings1.png");

  settingsMenu.btnS[1].pos.x = 840;
  settingsMenu.btnS[1].pos.y = 270;
  settingsMenu.btnS[1].pos.h = settingsMenu.btnS[1].button[0]->h;
  settingsMenu.btnS[1].pos.w = settingsMenu.btnS[1].button[0]->w;

  settingsMenu.currentMenu = 0;

  settingsMenu.btnS[0].state = 0;
  settingsMenu.btnS[1].state = 0;

  settingsMenu.btnSC[0].button[0] = IMG_Load ("Images/Buttons/right.png");
  settingsMenu.btnSC[1].button[0] = IMG_Load ("Images/Buttons/left.png");
  settingsMenu.btnSC[2].button[0] = IMG_Load ("Images/Buttons/sprint.png");
  settingsMenu.btnSC[3].button[0] = IMG_Load ("Images/Buttons/jump.png");

  settingsMenu.btnSC[0].pos.x = 662;
  settingsMenu.btnSC[0].pos.y = 17;
  settingsMenu.btnSC[0].pos.w = settingsMenu.btnSC[0].button[0]->w;
  settingsMenu.btnSC[0].pos.h = settingsMenu.btnSC[0].button[0]->h;

  settingsMenu.btnSC[1].pos.x = 662;
  settingsMenu.btnSC[1].pos.y = 202;
  settingsMenu.btnSC[1].pos.w = settingsMenu.btnSC[1].button[0]->w;
  settingsMenu.btnSC[1].pos.h = settingsMenu.btnSC[1].button[0]->h;

  settingsMenu.btnSC[2].pos.x = 662;
  settingsMenu.btnSC[2].pos.y = 374;
  settingsMenu.btnSC[2].pos.w = settingsMenu.btnSC[2].button[0]->w;
  settingsMenu.btnSC[2].pos.h = settingsMenu.btnSC[2].button[0]->h;

  settingsMenu.btnSC[3].pos.x = 662;
  settingsMenu.btnSC[3].pos.y = 544;
  settingsMenu.btnSC[3].pos.w = settingsMenu.btnSC[3].button[0]->w;
  settingsMenu.btnSC[3].pos.h = settingsMenu.btnSC[3].button[0]->h;

  for (int i=0; i<4; i++) {
    settingsMenu.btnSC[0].state = 0;
  }

  settingsMenu.cBg = IMG_Load ("Images/Bg/controlBg.png");

  game->settingsMenu = settingsMenu;
}

void initializeLevelSelect(Game* game) {
  LevelSelect levelSelect = game->levelSelect;

  levelSelect.bg = IMG_Load("Images/Bg/Level Select.png");
  levelSelect.bgPosition.x = 0;
  levelSelect.bgPosition.y = 0;
  levelSelect.bgPosition.h = levelSelect.bg->h;
  levelSelect.bgPosition.w = levelSelect.bg->w;

  char btn[30] = "Images/Buttons/";

  for(int k=0; k<3; k++) {
      char path[30];
      levelSelect.btn[k].state = 0;
      sprintf(path, "%s%i.png", btn, k+1);
      levelSelect.btn[k].button[0] = IMG_Load(path);
    }

  char btn1[30] = "Images/Buttons/";

  for (int k=0; k<3; k++) {
    char path[30];
    sprintf(path, "%s%i.png", btn1, k+4);
    levelSelect.btn[k].button[1] = IMG_Load(path);
  }
  
  levelSelect.btn[0].pos.x = 108;
  levelSelect.btn[0].pos.y = 303;
  levelSelect.btn[0].pos.w = levelSelect.btn[0].button[0]->w;
  levelSelect.btn[0].pos.h = levelSelect.btn[0].button[0]->h;

  levelSelect.btn[1].pos.x = 519;
  levelSelect.btn[1].pos.y = 303;
  levelSelect.btn[1].pos.w = levelSelect.btn[1].button[0]->w;
  levelSelect.btn[1].pos.h = levelSelect.btn[1].button[0]->h;

  levelSelect.btn[2].pos.x = 913;
  levelSelect.btn[2].pos.y = 303;
  levelSelect.btn[2].pos.w = levelSelect.btn[2].button[0]->w;
  levelSelect.btn[2].pos.h = levelSelect.btn[2].button[0]->h;

  levelSelect.btn[3].button[0] = IMG_Load("Images/Buttons/44.png");
  levelSelect.btn[3].button[1] = IMG_Load("Images/Buttons/444.png");

  levelSelect.btn[3].pos.x = 509;
  levelSelect.btn[3].pos.y = 523;
  levelSelect.btn[3].pos.w = levelSelect.btn[3].button[0]->w;
  levelSelect.btn[3].pos.h = levelSelect.btn[3].button[0]->h;

  levelSelect.btn[4].button[0] = IMG_Load("Images/Buttons/title.png");

  levelSelect.btn[4].pos.x = 315;
  levelSelect.btn[4].pos.y = 160;
  levelSelect.btn[4].pos.w = levelSelect.btn[4].button[0]->w;
  levelSelect.btn[4].pos.h = levelSelect.btn[4].button[0]->h;

  levelSelect.btn[5].button[0] = IMG_Load("Images/Buttons/skin1.png");
  levelSelect.btn[5].button[1] = IMG_Load("Images/Buttons/skin.png");

  levelSelect.btn[5].pos.x = 1180;
  levelSelect.btn[5].pos.y = 30;
  levelSelect.btn[5].pos.w = levelSelect.btn[4].button[0]->w;
  levelSelect.btn[5].pos.h = levelSelect.btn[4].button[0]->h;

  levelSelect.icon[0] = IMG_Load("Images/Buttons/brown.png");
  levelSelect.icon[1] = IMG_Load("Images/Buttons/blue.png"); 

  levelSelect.posIcon.x = 1216;
  levelSelect.posIcon.y = 40;
  levelSelect.posIcon.w = levelSelect.icon[0]->w;
  levelSelect.posIcon.h = levelSelect.icon[0]->h;
  

  game->levelSelect = levelSelect;
}

void initializeLevelOne (Game* game) {
  Levels levels = game->levels;

  levels.box[0].box = IMG_Load ("Images/Assets/box1.png");

  levels.box[0].pos.x = 569;
  levels.box[0].pos.y = 360;
  levels.box[0].pos.w = levels.box[0].box->w;
  levels.box[0].pos.h = levels.box[0].box->h;

  levels.box[1].box = IMG_Load ("Images/Assets/spike1.png");

  levels.box[1].pos.x = 771;
  levels.box[1].pos.y = 206;
  levels.box[1].pos.w = levels.box[1].box->w;
  levels.box[1].pos.h = levels.box[1].box->h;

  levels.box[2].box = IMG_Load ("Images/Assets/spike2.png");

  levels.box[2].pos.x = 1087;
  levels.box[2].pos.y = 377;
  levels.box[2].pos.w = levels.box[2].box->w;
  levels.box[2].pos.h = levels.box[2].box->h;

  levels.box[3].box = IMG_Load ("Images/Assets/box2.png");

  levels.box[3].pos.x = 1416;
  levels.box[3].pos.y = 360;
  levels.box[3].pos.w = levels.box[3].box->w;
  levels.box[3].pos.h = levels.box[3].box->h;

  levels.box[4].box = IMG_Load ("Images/Assets/spike1.png");

  levels.box[4].pos.x = 1386;
  levels.box[4].pos.y = 206;
  levels.box[4].pos.w = levels.box[4].box->w;
  levels.box[4].pos.h = levels.box[4].box->h;

  levels.barrel = IMG_Load ("Images/Assets/barrel.png");

  levels.barrelPos.x = 2032;
  levels.barrelPos.y = 333;
  levels.barrelPos.w = levels.barrel->w;
  levels.barrelPos.h = levels.barrel->h;

  levels.portal[0].portal = IMG_Load("Images/Assets/OrangePortal1.png");
  levels.portal[1].portal = IMG_Load("Images/Assets/OrangePortal2.png");
  levels.portal[2].portal = IMG_Load("Images/Assets/OrangePortal3.png");
  levels.portal[3].portal = IMG_Load("Images/Assets/OrangePortal4.png");
  levels.portal[4].portal = IMG_Load("Images/Assets/OrangePortal5.png");
  levels.portal[5].portal = IMG_Load("Images/Assets/OrangePortal6.png");
  levels.portal[6].portal = IMG_Load("Images/Assets/OrangePortal7.png");
  levels.portal[7].portal = IMG_Load("Images/Assets/OrangePortal8.png");
  levels.portal[8].portal = IMG_Load("Images/Assets/OrangePortal9.png");

  levels.portal[0].pos.x = 1760;
  levels.portal[0].pos.y = 309;
  levels.portal[0].pos.w = levels.portal[0].portal->w;
  levels.portal[0].pos.h = levels.portal[0].portal->h;

  game->levels = levels;
}

Game initializeGame() {
  Game game;
  game.done = 0;
  game.currentMenu = MAIN_MENU;
  game.screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
  game.currentLevel = 0;
  game.currentFloor = 388;
  game.avancement = 1;
  game.currentPortal = 0;
  initializeMainMenu(&game);
  initializeSettingsMenu(&game);
  initializeLevelSelect(&game);
  initializeLevelOne(&game);
  initBg(&game);
  initMc(&game);
  initMc1(&game);
  initChar(&game);
  initE(&game);
  initPause(&game);
  initEnigme(&game, "data.txt");
  initEnnemy(&game);
  initXo(&game);
  initCards(&game);
  return game;
}


Game gameInit() {
  initializeSDL();
  Game game = initializeGame();
  return game;
}