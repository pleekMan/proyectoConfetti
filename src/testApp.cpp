#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	cout << "Hola Mundo" << endl;
	
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofSetCircleResolution(32);
	ofBackground(0);
	ofSetBackgroundAuto(true);
	
	origin = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	confettiVector = ofVec2f(0,0);
	
	drawVector = false;
	showIds = false;
	
	divergenceDegrees = 60;
	strengthVariation = 1;

	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
	if (fiesta.size() > 0) {
		for (int i=0; i < fiesta.size(); i++) {
			fiesta[i].move();
			if (fiesta[i].isOutOfFrame()) {
				fiesta.erase(fiesta.begin()+i);
			}
			
		}
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	//ofBackground(0);
	
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
		
	ofSetColor(0, 0, 255);
	ofNoFill();
	if (drawVector) {
		ofLine(origin.x, origin.y, mouseX, mouseY);
		drawDivergenceCone();
	}
	
	
	if (fiesta.size() > 0) {
		for (int i=0; i < fiesta.size(); i++) {
			fiesta[i].draw();
			if (showIds) {
				fiesta[i].showParticlesId();

			}
		}
		if (showIds) {
			int particleToDebug = fiesta.size() - 1;
			fiesta[particleToDebug].debugParticle();
		}
		

	}
	
	ofSetColor(0, 255, 255);
	ofFill();
	ofDrawBitmapString("Origin X: " + ofToString(origin.x) + " -- Y: " + ofToString(origin.y), 500,10);
	ofDrawBitmapString("Vector X: " + ofToString(confettiVector.x) + " -- Y: " + ofToString(confettiVector.y), 500,25);
	ofSetColor(0, 255, 0);
	ofDrawBitmapString("Divergencia (Grados): " + ofToString(divergenceDegrees), 500,40);
	ofDrawBitmapString("Fuerza Variacion: " + ofToString(strengthVariation), 500,55);


	
}

void testApp::drawDivergenceCone(){
	
	ofVec2f tempVector = ofVec2f(mouseX - origin.x, mouseY - origin.y);
	
	ofVec2f lowLimit = tempVector.getRotated(-divergenceDegrees);
	ofVec2f highLimit = tempVector.getRotated(divergenceDegrees);
	
	ofSetColor(0, 255, 0);
	ofLine(origin.x, origin.y, origin.x + lowLimit.x, origin.y + lowLimit.y);
	ofLine(origin.x, origin.y, origin.x + highLimit.x, origin.y + highLimit.y);


}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 'q') {
		divergenceDegrees += 5;
	}
	if (key == 'a') {
		divergenceDegrees -= 5;
	}
	if (key == 'w') {
		if (strengthVariation < 0.9) {
			strengthVariation += 0.1;
		}
	}
	if (key == 's') {
		if (strengthVariation > 0.1) {
			strengthVariation -= 0.1;
		}
	}
	if (key == 'd') {
		showIds = !showIds;
	}
	if (key == 'f') {
		int confettiCount = fiesta.size();
		ofVec2f tempForce = ofVec2f(5,0);
		for (int i=0; i < confettiCount; i++) {
			fiesta[i].setExternalForce(tempForce);
		}
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){	
	
	
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	cout << "Mouse Button Pressed: " << ofToString(button) << endl;

	
	drawVector = true;
	
	origin = ofVec2f(x, y);
	
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
	if (button == 0) {
		drawVector = false;
		
		float xVec = mouseX - origin.x;
		float yVec = mouseY - origin.y;
		
		confettiVector = ofVec2f(xVec, yVec);
		
		int confettiCount = int((ofRandom(20,50)));
		//int confettiCount = 5;
		
		for (int i=0; i < confettiCount; i++) {
			fiesta.push_back(Confetti(origin, confettiVector,divergenceDegrees, strengthVariation, i));
		}
	}
	
	if (button == 2) {
	
		drawVector = false;
		
		float xVec = mouseX - origin.x;
		float yVec = mouseY - origin.y;
		
		ofVec2f forceVector = ofVec2f(xVec, yVec);
		
		int confettiCount = fiesta.size();
		
		for (int i=0; i < confettiCount; i++) {
			fiesta[i].setExternalForce(forceVector);		}
		
	}
	
	
	
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}