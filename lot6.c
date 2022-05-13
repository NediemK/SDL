
void initEnigme (Game* game, char* nomFichier) {
    int i = 0;

    game->enigme.currentMenu = 0;

    game->enigme.f = fopen (nomFichier, "r");

    while(!feof(game->enigme.f)) {
        fscanf(game->enigme.f,"%s %s %s %s %d %s", game->enigme.data[i].question, game->enigme.data[i].answer1, game->enigme.data[i].answer2, game->enigme.data[i].answer3, &game->enigme.data[i].answer, game->enigme.data[i].sound);
        i++;
    }

    srand(time(NULL));
    i = rand() % 9;
    

    game->enigme.question = IMG_Load (game->enigme.data[i].question);

    game->enigme.answer[0].answer = IMG_Load (game->enigme.data[i].answer1);
    game->enigme.answer[1].answer = IMG_Load (game->enigme.data[i].answer2);
    game->enigme.answer[2].answer = IMG_Load (game->enigme.data[i].answer3);
    game->enigme.sound = Mix_LoadMUS(game->enigme.data[i].sound);

    game->enigme.posBg.x = 0;
    game->enigme.posBg.y = 0;


    int pos[3] = {315, 440, 572};

    game->enigme.questPos.x = 20;
    game->enigme.questPos.y = 124;

    srand(time(NULL));
     i = rand() % 3;

    game->enigme.answer[0].answerPos.y = pos[i];
    game->enigme.answer[0].answerPos.x = 380;

    int pos1[2];
    int o = 0;
    for (int k=0; k<3; k++) {
        if (pos[i] != pos[k]) {
            pos1[o] = pos[k];
            o++;
        }
    }

    srand(time(NULL));
    int t = rand() % 2;

    game->enigme.answer[1].answerPos.y = pos1[t];
    game->enigme.answer[1].answerPos.x = 380;

    if (t==0) {
        game->enigme.answer[2].answerPos.y = pos1[1];
    }else{
        game->enigme.answer[2].answerPos.y = pos1[0];
    }
    game->enigme.answer[2].answerPos.x = 380;

    fclose(game->enigme.f);

    for(int k=0; k<135; k++) {
        char btn[30] = "Bg/bg";
        char path[30];
        sprintf(path, "%s%i.png", btn, k);
        game->enigme.bg[k] = IMG_Load(path);
    }
    game->enigme.currentBg = 0;

    game->enigme.soundIcon = IMG_Load("soundicon.png");

    game->enigme.soundIconPos.x = 1145;
    game->enigme.soundIconPos.y = 35;

    game->enigme.soundPlaying = 0;

    game->enigme.nono = IMG_Load("nono.png");
    game->enigme.hint = 0;
}

void afficherEnigme (Game* game) {
    SDL_BlitSurface (game->enigme.bg[game->enigme.currentBg], NULL, game->screen, &game->enigme.posBg);
    SDL_BlitSurface (game->enigme.question, NULL, game->screen, &game->enigme.questPos);
    SDL_BlitSurface (game->enigme.answer[0].answer, NULL, game->screen, &game->enigme.answer[0].answerPos);
    SDL_BlitSurface (game->enigme.answer[1].answer, NULL, game->screen, &game->enigme.answer[1].answerPos);
    SDL_BlitSurface (game->enigme.answer[2].answer, NULL, game->screen, &game->enigme.answer[2].answerPos);
    SDL_BlitSurface (game->enigme.soundIcon, NULL, game->screen, &game->enigme.soundIconPos);
    if(game->enigme.hint == 1) {
        SDL_BlitSurface(game->enigme.nono, NULL, game->screen, &game->enigme.answer[2].answerPos);
    }
}

void resolutionEnigme (Game* game) {
    while(SDL_PollEvent(&game->enigme.event))
    {switch (game->enigme.event.type) {
        case SDL_KEYDOWN: {
            int key = game->enigme.event.key.keysym.sym;
            if (SDLK_1 == key) {
                if(game->enigme.answer[0].answerPos.y == 315) {
                    game->currentMenu += 1;
                } else {
                    // data
                }
            }else if (SDLK_2 == key) {
                if(game->enigme.answer[0].answerPos.y == 440) {
                    game->currentMenu += 1;
                } else {
                    game->enigme.currentMenu = 1;
                }
            }else if (SDLK_3 == key) {
                if(game->enigme.answer[0].answerPos.y == 572) {
                    game->currentMenu += 1;
                } else {
                    game->enigme.currentMenu = 1;
                }
            }else if (SDLK_ESCAPE == key) {
                game->done = 1;
            }else if (SDLK_h == key) {
                game->enigme.hint = 1;
            }else {
                printf("Not right key\n");
            }
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            int mouseX, mouseY;

            SDL_GetMouseState(&mouseX, &mouseY);

            SDL_Rect pos0 = game->enigme.answer[0].answerPos;
            SDL_Rect pos1 = game->enigme.answer[1].answerPos;
            SDL_Rect pos2 = game->enigme.answer[2].answerPos;
            SDL_Rect pos3 = game->enigme.soundIconPos;

            int mouseInside0 = checkMouseInside(pos0, mouseX, mouseY);
            int mouseInside1 = checkMouseInside(pos1, mouseX, mouseY);
            int mouseInside2 = checkMouseInside(pos2, mouseX, mouseY);
            int mouseInside3 = checkMouseInside(pos3, mouseX, mouseY);

            if (mouseInside0) {
                game->currentMenu = LEVELTWO;
                game->character[game->character->id].spritePos.x = 0;
            }
            if (mouseInside1) {
                // game->enigme.currentMenu = 1;
            }
            if (mouseInside2) {
                // game->enigme.currentMenu = 1;
            } 
            if (mouseInside3) {
                Mix_VolumeMusic(10);
                if(game->enigme.soundPlaying == 0) {
                    Mix_PlayMusic(game->enigme.sound, 1);
                    game->enigme.soundPlaying = 1;
                }
            }
        }
    }}
}

SDL_TimerID startTimer3;

Uint32 animateSprite(Uint32 interval, void* param) {
    Game* game = param;
    game->enigme.currentBg++;
    if(game->enigme.currentBg == 134) {
        game->enigme.currentBg = 0;
        return interval;
        }
    return 0;
}

