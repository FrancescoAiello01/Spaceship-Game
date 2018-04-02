#include "ship.h"
#include "ofMain.h"

static const float ACCELERATION = 0.25;

ofImage image;

struct ship {
	float x;
	float y;
	float v;
	float w;
	float h;
	float t;
};

struct ship * ship_construct(float x, float y, float v, float w, float h) {
	struct ship * thisShip = (struct ship *) malloc(sizeof(struct ship));
	image.loadImage("spaceship.png");
	thisShip->x = x;
	thisShip->y = y;
	thisShip->v = v;
	thisShip->w = 150;
	thisShip->h = 149;
	thisShip->t = 0;

	return thisShip;
}

void ship_move(struct ship * s) {
	s->x += s->v;
	s->v *= 0.989;
	s->y += 0.2 * (cos(s->t / 10));
	s->t += 0.3;
}

void ship_thrust_right(struct ship * s) {
	s->v += ACCELERATION;
}

void ship_thrust_left(struct ship * s) {
	s->v -= ACCELERATION;
}

void ship_draw(struct ship * s) {
	image.draw(s->x, s->y, s->w, s->h);
}

bool ship_is_at_edge(struct ship * s) {
	if (s->x <= 0) {
		s->x = 0;
		return true;
	}
	else if ((s->x + s->w) >= ofGetWidth()) {
	s->x = ofGetWidth() - s->w;
	return true;
	}
	else {
		return false;
	}
}

void ship_bounce(struct ship * s) {
	s->v *= -0.8;
}

float ship_get_x(struct ship * s) {
	return s->x;
}

float ship_get_y(struct ship * s) {
	return s->y;
}