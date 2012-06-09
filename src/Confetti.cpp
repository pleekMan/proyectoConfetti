#include "Confetti.h"

Confetti::Confetti(){
}

Confetti::Confetti(ofVec2f origin, ofVec2f velVector, float divergenceFactor, float tempStrengthVar, int tempId){
	
	particleId = tempId; 
	
	color = ofColor(ofRandom(200),ofRandom(200),ofRandom(200));
	//color = ofColor(255);
	gravity = ofVec3f(0,1,0);
	
	strengthVariation = tempStrengthVar;
	externalForce = ofVec2f(0,0);
	
	pos = ofVec3f(origin.x, origin.y, 0);
	
	accel = velVector;
	accel.z = ofRandom(-100,100);
	
	divergence = velVector.getRotated(ofRandom(-divergenceFactor,divergenceFactor));

	//vel = ofVec3f(velVector.x, velVector.y, velVector.x); // ASSIGNO X AL Z
	vel = accel;
	
	vel.x += divergence.x;
	vel.y += divergence.y;
	//vel.z += divergence.x;
	
	strength = (ofRandom(1 - strengthVariation,1));
	
	//strength = 1;
	vel *= strength;
	
	accel = 0;

	
	rotation = ofRandom(360);
	rotationStep = ofRandom(-10,10);

}


void Confetti::setVector(ofVec2f velVector){
	
	// RE-HACER ESTA FUNCION
	
	vel = ofVec3f(velVector.x, velVector.y, 0);
	vel *= 0.3; // ATENUADOR;
	//vel.y *=  0.2;
	
	accel = ofVec3f(1,1,1);

	rotation = ofRandom(360);
	rotationStep = ofRandom(-10,10);
	

} // NO USO

void Confetti::setOrigin(ofVec2f origin){
	
	pos = ofVec3f(origin.x, origin.y, 0);

} // NO USO

void Confetti::move(){
	
	vel += accel;
	if (vel.y < 5) {
		vel += gravity;
	}
	
	vel += externalForce; // Agregar fuerza externa 2D
	
	vel *= 0.75; // ATENUAR LA VELOCIDAD (RESISTENCIA AL VIENTO)
	
	rotation += rotationStep;
	
	pos += vel;


	
}

void Confetti::draw(){
	
	ofSetColor(color);
	ofFill();
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofPushMatrix();
	
	ofTranslate(pos);
	ofRotate(rotation);
	ofRotateX(rotation);

	ofRect(0,0, 20, 20);
	
	ofPopMatrix();
	
	
	

}

void Confetti::setExternalForce(ofVec2f force){
	
	float attenuation = 0.1; // ATENUO FORCE
	
	force.x = ofRandom(force.x * 0.5, force.x);
	force.y = ofRandom(force.y * 0.5, force.y);
	
	externalForce = force * attenuation;
}

void Confetti::debugParticle(){
	
	ofSetColor(255, 255, 0);
	ofDrawBitmapString("Pos X: " + ofToString(pos.x) + " -- Y: " + ofToString(pos.y) + " -- Z: " + ofToString(pos.z), 10,15);
	ofDrawBitmapString("vel X: " + ofToString(vel.x) + " -- Y: " + ofToString(vel.y) + " -- Z: " + ofToString(vel.z), 10,30);
	ofDrawBitmapString("Accel X: " + ofToString(accel.x) + " -- Y: " + ofToString(accel.y)  + " -- Z: " + ofToString(accel.z), 10,45);
	ofDrawBitmapString("Divergence X: " + ofToString(divergence.x) + " -- Y: " + ofToString(divergence.y)  + " -- Z: " + ofToString(divergence.z), 10,60);
	ofDrawBitmapString("Rotation: " + ofToString(rotation), 10,75);

}

void Confetti::showParticlesId(){
	ofSetColor(0, 255, 0);
	ofDrawBitmapString(ofToString(particleId),pos);
}

bool Confetti::isOutOfFrame(){
	
	if (pos.x < 0 || pos.x > ofGetWindowWidth() || pos.y > ofGetWindowHeight()) {
		return true;
	} else {
		return false;
	}

	
}

