#include "ship.h"
#include "ofMain.h"
#include "laser.h"

ofImage laser;

struct laser {
	float x;
	float y;
	float v;
	float w;
	float h;
	bool visible;
};

struct ship;

struct laser * laser_construct(float x, float y, float v, float w, float h, bool visible) {
	struct laser * thisLaser = (struct laser *) malloc(sizeof(struct laser));
	laser.loadImage("laser.png");
	thisLaser->x = x;
	thisLaser->y = y;
	thisLaser->v = v;
	thisLaser->w = 150;
	thisLaser->h = 149;
	thisLaser->visible = visible;

	return thisLaser;
}

bool laser_visible(struct laser * l) {
	l->visible = true;
	return l->visible;
}

void laser_invisible(struct laser * l) {
	l->visible = false;
}

void initialize_laser(struct laser * l, struct ship * s) {
		l->x = ship_get_x(s);
		l->y = ship_get_y(s) - 120;
}

void laser_draw(struct laser * l) {
	if (l->visible == true) {
		laser.draw(l->x, l->y, l->w, l->h);
	}
}

void laser_move(struct laser * l) {
	l->y -= 15;
}

bool laser_outside_field(struct laser * l) {
	if ((l->y + l->w) >= ofGetHeight()) {
		return true;
	}
	else {
		return false;
	}
}


