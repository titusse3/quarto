#ifndef MENU_H
#define MENU_H

#include <raylib.h>
#include <stdlib.h>

#include "utils.h"

typedef struct game_info_t {
  int screen_w;
  int screen_h;
  const char *game_name;
  bool exit_wind;
  bool play_music;
  bool play_sound;
} game_info_t;

typedef enum {
  RULES,
  HISTORY,
  PLAY,
  QUIT,
  NONE
} btn_t;

typedef struct {
  Font f;
  Texture2D explosion;
  Rectangle frameRec;
  bool has_end;
} win_display_info;

typedef struct {
  enum {
    MENU,
    GAME
  } currentScreen;
  btn_t menuType;
  union {
    struct {
      int rules_num;
      int rules_frames;
      Texture2D *rules_textures;
    } rules_values;
    struct {
      int history_frames;
      Texture2D history_texture;
    } history_values;
  } content;
  btn_t sound_play;
  Sound sound;
  win_display_info win_info;
} menu_content_t;

extern void display_menu(game_info_t *game, menu_content_t *menu, state_t *st);

extern bool display_exit_menu(game_info_t *game_info, int fontSize,
    const char *msg, int msg_size);

extern void display_end_animation(game_info_t *game_info,
    win_display_info *info, const char *text, bool win);

#endif
