#include "ofMain.h"
#include "enemy_ship.h"
#include "laser.h"

ofImage enemy;
static const float ACCELERATION = 0.25;


struct enemy {
	float x;
	float y;
	float v;
	float w;
	float h;
	float t;
	int health;
};

struct laser;

struct enemy * enemy_construct(float x, float y, float v, float w, float h, float t, int health) {
	struct enemy * thisEnemy = (struct enemy *) malloc(sizeof(struct enemy));
	enemy.loadImage("enemy.png");
	thisEnemy->x = x;
	thisEnemy->y = y;
	thisEnemy->v = v;
	thisEnemy->w = 150;
	thisEnemy->h = 149;
	thisEnemy->t = t;
	thisEnemy->health = 5;

	return thisEnemy;
}

void draw_enemy(struct enemy * e) {
	enemy.draw(e->x, e->y, e->w, e->h);
}

void enemy_move(struct enemy * e) {
	//Set up velocity for smooth movements
	e->x += e->v;
	e->v *= 0.989;

	int randomNumber = ofRandom(0, 101);

	// Section I
	if (e->x < ofGetWidth() / 4) {
		if (randomNumber > 45) {
			enemy_thrust_right(e);
		}
		if (randomNumber < 45) {
			enemy_thrust_left(e);
		}
	}
	// Section II
	if (e->x > 550 && e->x < 1100) {
		if (randomNumber > 50) {
			enemy_thrust_right(e);
		}
		if (randomNumber < 50) {
			enemy_thrust_left(e);
		}
	}
	// Section III
	if (e->x > 1100 && e->x < 1650) {
		if (randomNumber > 50) {
			enemy_thrust_left(e);
		}
		if (randomNumber < 50) {
			enemy_thrust_right(e);
		}
	}
	// Section IV
	if (e->x > (ofGetWidth() - 550)) {
		if (randomNumber > 45) {
			enemy_thrust_left(e);
		}
		if (randomNumber < 45) {
			enemy_thrust_right(e);
		}
	}
}

void enemy_thrust_right(struct enemy * e) {
	e->v += ACCELERATION;
}

void enemy_thrust_left(struct enemy * e) {
	e->v -= ACCELERATION;
}


void initial_movement(struct enemy * e) {
	if (e->y < 235) {
		e->y += 5;
	}
}

void enemy_bob(struct enemy * e) {
	e->y += 0.2 * (sin(e->t / 10));
	e->t += 0.3;
}


bool enemy_is_at_edge(struct enemy * e) {
	if (e->x <= 0) {
		e->x = 0;
		return true;
	}
	else if ((e->x + e->w) >= ofGetWidth()) {
		e->x = ofGetWidth() - e->w;
		return true;
	}
	else {
		return false;
	}
}

void enemy_bounce(struct enemy * e) {
	e->v *= -0.8;
}
