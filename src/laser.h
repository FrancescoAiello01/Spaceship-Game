#pragma once

struct laser * laser_construct(float x, float y, float velocity, float width, float height, bool visible);

void laser_draw(struct laser * l);
void laser_move(struct laser * l);
bool laser_outside_field(struct laser * l);
bool laser_visible(struct laser * l);
void laser_invisible(struct laser * l);
void initialize_laser(struct laser * l, struct ship * s);

