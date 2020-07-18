#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../include/draw.h"
#include "stds.h"

/*
 *
 */
struct Background {
  float x;
  float y;
  float scroll_x;
  float scroll_y;
  float scale_x;
  float scale_y;

  int32_t w;
  int32_t h;

  SDL_Texture *background_texture;
};

extern app_t app;

extern void Stds_AddParallaxBackground( const char *bg_directory, size_t n,
                                      float default_scroll_speed, float modified_scroll_speeds[],
                                      bool is_infinite );

extern void Stds_ParallaxBackgroundUpdate( parallax_background_t *parallax );

extern void Stds_ParallaxBackgroundDraw( parallax_background_t *parallax );

extern background_t *Stds_AddBackground( const char *bg_directory );

extern void Stds_BackgroundUpdate( background_t *bg );

extern void Stds_BackgroundDraw( background_t *bg );

extern void Stds_BackgroundDie( background_t *bg );

#endif // BACKGROUND_H
