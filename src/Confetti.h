#ifndef CONFETTI
#define CONFETTI

#pragma once

#include "ofMain.h"

class Confetti {
	
public:
	
	Confetti();
	Confetti(ofVec2f origin, ofVec2f velVector, float divergenceFactor, float tempStrengthVar, int tempId);
	
	ofVec3f pos, vel, accel, gravity, divergence, externalForce;
	float strength;
	float strengthVariation;
	ofColor color;
	float rotation;
	float rotationStep;
	int particleId;
	
	
	void setOrigin(ofVec2f origin);
	void setVector(ofVec2f velVector); // DIRECTION AND VELOCITY (MAGNITUDE)
	void setExternalForce(ofVec2f force);
	void move();
	void draw();
	bool isOutOfFrame();
	void debugParticle();
	void showParticlesId();
	
	
};
#endif
