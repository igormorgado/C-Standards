#ifndef STRUCTS_H
#define STRUCTS_H

#include "button.h"
#include "stds.h"

typedef struct delegate_t            delegate_t;
typedef struct entity_t              entity_t;
typedef struct button_t              button_t;
typedef struct mouse_t               mouse_t;
typedef struct app_t                 app_t;
typedef struct animation_t           animation_t;
typedef struct texture_t             texture_t;
typedef struct fade_color_t          fade_color_t;
typedef struct background_t          background_t;
typedef struct parallax_background_t parallax_background_t;
typedef struct font_t                font_t;
typedef struct trail_t               trail_t;
typedef struct circle_t              circle_t;
typedef struct button_t              button_t;
typedef struct particle_system_t     particle_system_t;
typedef struct particle_t            particle_t;



/*
 *
 */
struct ParallaxBackground {
  float parallax_scroll_speed;
  float normal_scroll_speed;
  bool  infinite_scroll;

  background_t *         background;
  parallax_background_t *next;
};

/*
 *
 */
struct Font {
  char     name[MAX_FILE_NAME_LEN];
  uint16_t size;

  TTF_Font *font;
  font_t *  next;
};

/*
 *
 */
struct Delegate {
  void ( *tick )( void );
  void ( *draw )( void );
};

/*
 *
 */
struct Mouse {
  int32_t x;
  int32_t y;
  uint8_t button[MAX_MOUSE_BUTTONS];
  uint8_t wheel;
  bool    is_moving;
};

/*
 *
 */
struct App {
  uint16_t keyboard[MAX_KEYBOARD_KEYS];

  uint32_t SCREEN_WIDTH;
  uint32_t SCREEN_HEIGHT;
  uint32_t LEVEL_WIDTH;
  uint32_t LEVEL_HEIGHT;

  bool        is_debug_mode;
  const char *original_title;

  SDL_Renderer *renderer;
  SDL_Window *  window;
  SDL_FRect     screen_bounds;
  SDL_FRect     camera;

  struct mouse_t               mouse;
  struct delegate_t            delegate;
  struct trail_t               trail_head, *trail_tail;
  struct texture_t             texture_head, *texture_tail;
  struct font_t                font_head, *font_tail;
  struct parallax_background_t parallax_head, *parallax_tail;
  struct button_t              button_head, *button_tail;

  enum GameState game_state;
};

/*
 *
 */
struct FadeColor {
  bool  is_first_color;
  float alpha;
  float time;

  SDL_Color c1;
  SDL_Color c2;
};

/*
 *
 */
struct Entity {
  float x;
  float y;

  //  Miscellaneous positioning variable.
  float variability;

  // Scales the entity in either the x or y
  // direction. This should default to 1.
  float scale_x;
  float scale_y;

  //  Directional velocity (yes, I know it's redundant).
  float dx;
  float dy;

  //  Acceleration or deceleration factors.
  float delta_accel_x;
  float delta_accel_y;

  // Change rate of alpha value.
  float delta_alpha;

  // Size of entity if not defined by a rectangle. These
  // should either be set manually, or defined by a call
  // to SDL_QueryTexture(...), where you pass the addresses
  // of these variables.
  int32_t  w;
  int32_t  h;
  uint32_t flags;
  uint32_t id_flags;
  uint32_t reload;
  uint32_t identifier;

  uint16_t angle;
  uint16_t radius;

  // Can be used interchangably for different purposes.
  int32_t health;
  int32_t life;

  SDL_Color    color;
  SDL_Texture *texture[TEXTURE_BUFFER_SIZE];

  animation_t *animation;
  entity_t *   next;

  void ( *tick )( entity_t * );
  void ( *draw )( entity_t * );
  void ( *touch )( entity_t * );
  void ( *die )( entity_t * );
};

#endif // STRUCTS_H
