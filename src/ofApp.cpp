#include "ofApp.h"
#include "ship.h"
#include "stars.h"
#include "laser.h"
#include "enemy_ship.h"

static const int star_array = 75;

ofSoundPlayer music;

void ofApp::setup(){
	ofSetFrameRate(60);
	// Music Play
	music.load("music.mp3");
	music.play();

	// Ship
	ship = ship_construct(ofGetWidth() / 2, ofGetHeight() - 200, 0, 100, 200);

	// Enemy
	enemy = enemy_construct(ofRandom(300, 900), ofGetHeight() - 2000, 0, 100, 200, 0, 5);

	//Laser
	laser = laser_construct(0, 0, 0, 100, 200, false);

	//Stars
	stars = stars_construct(star_array);

	for (int i = 0; i < star_array; ++i) {
		star = star_construct(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofRandom(0.3, 2), ofRandom(0.3, 4));
		stars[i] = star;
	}
}

void ofApp::update(){
	// Ship movements
	ship_move(ship);
	if (ship_is_at_edge(ship)) {
		ship_bounce(ship);	
	}

	//Enemy movements
	initial_movement(enemy);
	enemy_bob(enemy);
	enemy_move(enemy);
	if (enemy_is_at_edge(enemy)) {
		enemy_bounce(enemy);
	}
	

	// Star field
	for (int i = 0; i < star_array; ++i) {
		star_accelerate(stars[i]);
		if (star_outside_field(stars[i])) {
			star_reset(stars[i]);
			star_accelerate(stars[i]);
		}
	}
	for (int i = 0; i < star_array; i += 8) {
		random_slowdown(stars[i]);
	}

	// Laser
	laser_move(laser);
	if (laser_outside_field(laser)) {
		laser_invisible(laser);
	}

	// Draw FPS
	std::stringstream strm;
	strm << "Star Ship Game | FPS: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());
}

void ofApp::draw(){
	ofBackground(0, 0, 0);

	for (int i = 0; i < star_array; ++i) {
		star_draw(stars[i]);
	}

	ship_draw(ship);

	draw_enemy(enemy);


	ofDrawBitmapString("Score:", ofGetWidth() / 16, 100);

	laser_draw(laser);
}

void ofApp::keyPressed(int key){
	if (key == OF_KEY_LEFT) {
		ship_thrust_left(ship);
	}
	else if (key == OF_KEY_RIGHT) {
		ship_thrust_right(ship);
	}
	if (key == ' ') {
		initialize_laser(laser, ship);
		laser_visible(laser);
		laser_move(laser);
	}
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
