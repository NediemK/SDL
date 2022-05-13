void saveGame(Game* game) {
  FILE* f = fopen("Process.bin", "ab");
  fwrite(&game, sizeof(Game), 1, f);
  fclose(f);
}

void loadGame(Game* game) {
  FILE* f = fopen("Process.bin", "ab");
  fread(&game, sizeof(Game), 1, f);
  fclose(f);
}