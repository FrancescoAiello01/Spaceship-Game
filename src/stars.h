#pragma once

struct star * star_construct(float x, float y, float size, float velocity);

void star_draw(struct star * s);
void star_accelerate(struct star * s);
void star_reset(struct star * s);
bool star_outside_field(struct star * s);

void random_slowdown(struct star * s);

struct star ** stars_construct(int size);

