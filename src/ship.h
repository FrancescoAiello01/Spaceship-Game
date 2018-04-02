#pragma once

struct ship * ship_construct(float x, float y, float v, float w, float h);

void ship_move(struct ship * s);
void ship_thrust_right(struct ship * s);
void ship_thrust_left(struct ship * s);
void ship_draw(struct ship * s);

bool ship_is_at_edge(struct ship * s);
void ship_bounce(struct ship * s);

float ship_get_x(struct ship * s);
float ship_get_y(struct ship * s);
