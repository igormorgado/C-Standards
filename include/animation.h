#ifndef ANIMATION_H
#define ANIMATION_H

#include "draw.h"
#include "stds.h"

/*
 *
 */
struct Animation {
  float    pos_x;
  float    pos_y;
  float    frame_delay;
  float    frame_timer;
  uint32_t splice_x;
  uint32_t splice_y;
  uint32_t id_flags;
  uint32_t flags;
  uint16_t angle;
  uint16_t start_x;
  uint16_t start_y;
  int32_t  w;
  int32_t  h;
  int32_t  sprite_sheet_width;
  int32_t  sprite_sheet_height;
  uint8_t  current_frame_id;
  size_t   number_of_frames;

  bool cycle_once;

  SDL_RendererFlip flip;

  SDL_Texture * current_texture;
  SDL_Texture * default_texture;
  SDL_Texture **frames;
  SDL_Texture * sprite_sheet;

  animation_t *next;
};

extern app_t app;

extern animation_t *Stds_AddSpritesheet( const char *file_directory, uint8_t n, float frame_time,
                                     uint16_t start_x, uint16_t start_y );

extern animation_t *Stds_AddAnimation( const char *files_directory, uint8_t n, float frame_time );

extern void Stds_AnimationUpdate( animation_t *animation );

extern void Stds_AnimationDraw( animation_t *animation );

extern void Stds_AnimationDie( animation_t *animation );

#endif // ANIMATION_H
