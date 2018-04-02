#include "stars.h"
#include "ofMain.h"

struct star {
	float x;
	float y;
	float size;
	float velocity;
};

struct star * star_construct(float x, float y, float size, float velocity) {
	struct star * thisStar = (struct star *) malloc(50 * sizeof(struct star *));

	thisStar->x = x;
	thisStar->y = y;
	thisStar->size = size;
	thisStar->velocity = velocity;
	return thisStar;
}

void star_draw(struct star * s) {
	ofDrawCircle(s->x, s->y, s->size);
}

void star_accelerate(struct star * s) {
	s->velocity = ofRandom(1, 10) * 0.989;
	s->y += s->velocity;
}

bool star_outside_field(struct star * s) {
	if (s->y > ofGetHeight()) {
		return true;
	}
	else {
		return false;
	}
}

void star_reset(struct star * s) {
	s->y = 0;
	s->x = ofRandom(0, ofGetWidth());
}

struct star ** stars_construct(int size) {
	struct star** stars = (struct star**) malloc(sizeof(struct star *) * size);
	return stars;
}

void random_slowdown(struct star * s) {
	s->velocity -= ofRandom(4, 8);
}