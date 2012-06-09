#pragma once

#include "ofMain.h"
#include "Confetti.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	void drawDivergenceCone();
	
	vector<Confetti> fiesta;
	ofVec2f origin;
	ofVec2f confettiVector;
	float divergenceDegrees;
	float strengthVariation;
	bool drawVector;
	bool showIds;
		
};
