#include "stdlib.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#define MAIN_MENU 0
#define SETTINGS_MENU 1
#define LEVELSELECT 2
#define LEVELONE 3
#define LEVELTWO 4
#define LEVELTHREE 5
#define PAUSEMENU 6
#define RIDDLE 7
#define TICTACTOE 8
#define CARDS 9

#define PLAY_BTN 0
#define SETTINGS_BTN 1
#define QUIT_BTN 2

#define MOUSE_OUTSIDE 0
#define MOUSE_HOVER 1
#define MOUSE_CLICK 2

#define FULLSCREEN 0
#define WINDOWED 1


#define LEFT 0
#define RIGHT 1

#define IDLE 0
#define WALKING 1
#define RUNNING 2
#define JUMPING 3
#define FALLING 4
#define ATTACKING 5
#define HURT 6

#define WALK 0
#define DEATH 1
#define ATTACK 2

#define FLOOR 277

SDL_TimerID animateMC;
SDL_TimerID animateEC;
SDL_TimerID animateEnnemyy;

SDL_Surface* bg;
SDL_Rect pos;
SDL_Rect camera;
SDL_Surface* times;
TTF_Font* font;
SDL_Rect timePos = {1130, 90};
SDL_Color co = {255,255,255};
int collision[8];


#define CORRECT 1
#define WRONG 0

typedef struct Answer {
    SDL_Surface* answer;
    SDL_Rect answerPos;
    int state;
} Answer;

typedef struct Data {
    char question[30];
    char answer1[30];
    char answer2[30];
    char answer3[30];
    char sound[30];
    signed int answer;
} Data;

typedef struct Enigme{
    int done;
    SDL_Surface* bg[135];
    SDL_Rect posBg;
    Data data[9];
    SDL_Surface* question;
    SDL_Rect questPos;
    Answer answer[3];
    FILE* f;
    SDL_Event event;
    int currentMenu;
    SDL_Rect rightAnswerPos;
    int currentBg;
    SDL_Surface* sprite[10];
    SDL_Rect spritePos;
    SDL_Surface* screen;
    int currentAnswer;
    SDL_Surface* soundIcon;
    SDL_Rect soundIconPos;
    int soundPlaying;
    Mix_Music* sound;
    SDL_Surface* nono;
    int hint;
} Enigme;

typedef struct Char {
  int id;
  int state;
  int currentSprite;
  int direction;
  SDL_Surface* spriteSheet[2][100][100];
  SDL_Rect spritePos;
  Uint8* keystate;
  int health;
  SDL_Surface* hearts[4];
  SDL_Rect heartsPos;
} Char;

typedef struct Bg {
  SDL_Surface* img[306];
  SDL_Rect pos;
  SDL_Rect camera;
  Uint8* keystate;
  int state;
  int num;
} Bg;

typedef struct Logo {
  SDL_Surface* logo;
  SDL_Rect posLogo;
} Logo;

typedef struct Text {
  char              text[20];
  int               fontSize;
  int               showing;
  SDL_Surface*      textSurface;
  SDL_Color         c;
  SDL_Rect          pos;
} Text;

typedef struct Button {
  SDL_Rect pos;
  SDL_Surface* button[3];
  int state;
} Button;

typedef struct Slider {
  SDL_Surface* slider;
  SDL_Rect pos;
  int state;
} Slider;

typedef struct Spike {
  SDL_Surface* spike;
  SDL_Rect pos;
} Spike;

typedef struct Box {
  SDL_Surface* box;
  SDL_Rect pos;
} Box;

typedef struct SettingsMenu {
  SDL_Surface* bg;
  SDL_Surface* cBg;
  SDL_Rect bgPosition;
  Button buttons[4];
  Button btnS[2];
  Button btnSC[5];
  Slider sliders1[15];
  int state1;
  Slider sliders2[15];
  int state2;
  int currentMenu;
} SettingsMenu;

SDL_TimerID startTimer;
SDL_TimerID startTimer1;

typedef struct MainMenu {
  SDL_Surface* bg[304];
  SDL_Rect bgPosition;
  Button buttons[3];
  Logo logo;
  int stateNewGame;
  int currentBg;
  int mouseX,mouseY;
  int currentFullscreen;
} MainMenu;

typedef struct LevelSelect {
  SDL_Surface* bg;
  SDL_Rect bgPosition;
  Button btn[6];
  SDL_Surface* icon[2];
  SDL_Rect posIcon;
} LevelSelect;

typedef struct Portal {
  SDL_Surface* portal;
  SDL_Rect pos;
} Portal;

typedef struct Levels {
  Spike spikes[10];
  Box box[10];
  SDL_Surface* barrel;
  SDL_Rect barrelPos;
  Portal portal[10];
} Levels;

typedef struct Cursor {
  SDL_Surface* cursor;
  SDL_Rect cursorPos;
} Cursor;

typedef struct Minimap {
  SDL_Surface* miniChar;
  SDL_Rect miniPos;

  SDL_Surface* miniMap[3];
  SDL_Rect miniMapPos;
} Minimap;

typedef struct Entity {
  char name[40];
  int state;
  int currentSprite;
  int direction;
  SDL_Surface* spriteSheet[2][100][100];
  SDL_Rect spritePos;
  Uint8* keystate;
  int velX;
  int velY;
  float angle;
  int mode;
} Entity;

typedef struct PauseMenu {
  SDL_Surface* bg;
  SDL_Rect bgPos;
  Button btn[3];
} PauseMenu;

typedef struct NPC {
    SDL_Surface* spriteSheet [2][3][10];
    SDL_Rect spritePos;
    int currentSprite;
    int currentDirection;
    int currentState;
    int state;
    int limit;
    int limitR;
    int velX;
} NPC;

int mouseX, mouseY;
SDL_Event event;

typedef struct Board {
    SDL_Rect pos;
    int xo;
    SDL_Surface* carre;
    SDL_Surface* x;
    SDL_Surface* o;
    int xoro;
    int holder;
} Board;

typedef struct Xo {
    Board board[3][3];
    int done;
    SDL_Surface* screen;
    int currentPlayer;
} Xo;

typedef struct Card {
    SDL_Surface* img[2];
    SDL_Rect pos;
    int state;
    int id;
} Card;

typedef struct Cards {
    Card card[10];
} Cards;

typedef struct Game {
  Cards cards;
  Xo xo;
  Mix_Music* bgMusic;
  Mix_Chunk* hoverSFX;
  Mix_Chunk* clickSFX;
  int currentFloor;
  int musicPlaying;
  int done;
  int currentMenu;
  int currentLevel;
  int bgMusicVolume, sfxVolume;
  int currentMp;
  TTF_Font* font;
  SDL_Surface* screen;
  int fullScreen;
  MainMenu mainMenu;
  SettingsMenu settingsMenu;
  LevelSelect levelSelect;
  Text text;
  Cursor cursor;
  int keys[5];
  Bg bg;
  Char character[2];
  Levels levels;
  int avancement;
  int currentPortal;
  Minimap minimap;
  Entity entity;
  PauseMenu pauseMenu;
  Enigme enigme;
  NPC npc[5];
} Game;