#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "stds.h"

/*
 *
 */
struct Particle {
  float    x;
  float    y;
  float    dx;
  float    dy;
  float    delta_accel_x;
  float    delta_accel_y;
  float    delta_alpha;
  int32_t  w;
  int32_t  h;
  uint32_t angle;
  int32_t  life;
  uint32_t id_flags;
  uint32_t flags;

  SDL_Color    color;
  SDL_Texture *current_texture;

  animation_t *animation;

  void ( *particle_update )( particle_t * );
  void ( *particle_draw )( particle_t * );
};

/*
 *
 */
struct ParticleSystem {
  int32_t alive_count;
  int32_t dead_index;
  int32_t max_particles;

  particle_t *particles;
};

enum { PS_SUCCESS, PS_FULL, PS_INVALID_FP };

extern particle_system_t *Stds_CreateParticleSystem( int32_t max_particles );

extern int32_t Stds_InsertParticle( particle_system_t *ps, particle_t *p );

extern void Stds_ParticleSystemUpdate( particle_system_t *ps );

extern void Stds_ParticleSystemDraw( particle_system_t *ps );

#endif // PARTICLE_SYSTEM_H