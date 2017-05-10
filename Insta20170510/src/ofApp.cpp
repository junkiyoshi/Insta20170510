#include "ofApp.h"

//--------------------------------------------------------------
ofApp::~ofApp() {
	for (ofxBulletBox* tmp : this->obs) { delete tmp; }
	this->obs.clear();

	for (ofxBulletBox* tmp : this->boxes) { delete tmp; }
	this->boxes.clear();
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofEnableDepthTest();
	ofBackground(255);
	ofSetWindowTitle("moji!");

	this->loop = false;

	this->font_size = 30;
	this->font.loadFont("fonts/Kazesawa-Bold.ttf", this->font_size);

	this->world.setup();
	this->world.setGravity(ofVec3f(0.0, -1024.0, 0));

	ofxBulletBox* obstacle = new ofxBulletBox();
	obstacle->create(this->world.world, ofVec3f(0, -ofGetHeight(), -512), 0.0f, 4096, 64, 4096);
	obstacle->setProperties(1.0, 0.3);
	obstacle->add();
	this->obs.push_back(obstacle);

	float size = 50;
	int len = 3;
	for (int x = -size * len; x < size * len; x += size) {
		for (int y = -size * len; y < size * len; y += size) {
			for (int z = -size * len; z < size * len; z += size) {
				ofxBulletBox* box = new ofxBulletBox();
				box->create(this->world.world, ofVec3f(x, y + ofGetHeight() / 2, z), 1.0, size, size, size);
				box->setRestitution(1.0);
				box->add();

				this->boxes.push_back(box);

				ofColor color;
				color.setHsb(ofRandom(255), 255, 255);
				this->boxes_colors.push_back(color);
			}
		}
	}

	for (int x = -size * len; x < size * len; x += size) {
		for (int y = -size * len; y < size * len; y += size) {
			for (int z = -size * len; z < size * len; z += size) {
				ofxBulletBox* box = new ofxBulletBox();
				box->create(this->world.world, ofVec3f(x, y + ofGetHeight() * 20, z), 1.0, size, size, size);
				box->setRestitution(1.0);
				box->add();

				this->boxes.push_back(box);

				ofColor color;
				color.setHsb(ofRandom(255), 255, 255);
				this->boxes_colors.push_back(color);
			}
		}
	}


	for (int x = -size * len; x < size * len; x += size) {
		for (int y = -size * len; y < size * len; y += size) {
			for (int z = -size * len; z < size * len; z += size) {
				ofxBulletBox* box = new ofxBulletBox();
				box->create(this->world.world, ofVec3f(x, y + ofGetHeight() * 40, z), 1.0, size, size, size);
				box->setRestitution(1.0);
				box->add();

				this->boxes.push_back(box);

				ofColor color;
				color.setHsb(ofRandom(255), 255, 255);
				this->boxes_colors.push_back(color);
			}
		}
	}

	this->light.setPosition(ofVec3f(512, 512, 512));

}

//--------------------------------------------------------------
void ofApp::update(){
	if (this->loop) {
		this->world.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();

	ofEnableLighting();
	this->light.enable();

	for (int i = 0; i < this->obs.size(); i++) {
		ofSetColor(128);
		this->obs[i]->draw();
	}

	for (int i = 0; i < this->boxes.size(); i++) {
		ofSetColor(this->boxes_colors[i]);
		this->boxes[i]->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 32) {
		this->loop = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
