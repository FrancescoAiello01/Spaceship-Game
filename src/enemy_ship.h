#pragma once

struct enemy * enemy_construct(float x, float y, float v, float w, float h, float t, int health);

void draw_enemy(struct enemy * e);
void enemy_move(struct enemy * e);
void initial_movement(struct enemy * e);
void enemy_bob(struct enemy * e);

void enemy_thrust_left(struct enemy * e);
void enemy_thrust_right(struct enemy * e);

bool enemy_is_at_edge(struct enemy * e);
void enemy_bounce(struct enemy * e);

