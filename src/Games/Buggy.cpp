#include "Buggy.h"



Buggy::Buggy(std::shared_ptr<KinectProjector> const & k)
{
	kinectProjector = k;
	onMap = false;
	lastUpdate = clock();
}

Buggy::~Buggy()
{
}

void Buggy::setLocation(int x, int y) {
		if (0 < x && x < 640 && 0 < y && y < 480) {
			if(!onMap){
				currentLocation.x = x;
				currentLocation.y = y;
				onMap = true;
			}
			targetLocation.x = x;
			targetLocation.y = y;
		}
		else {
			onMap = false;
		}
	}

void Buggy::draw()
{
	if (!onMap)
		return;

	float scale = 10;

	ofPushMatrix();
	ofTranslate(projectorCoord);

	ofSetLineWidth(2.0);
	ofColor c = ofColor(180, 180, 180);
	ofSetColor(c);
	//fish.draw();


	c = ofColor(255,255,255);
	ofSetColor(c);
	ofFill();
	ofDrawCircle(0, 0, scale*0.5);
	ofNoFill();
	ofPopMatrix();

}

void Buggy::update() {
	projectorCoord = kinectProjector->kinectCoordToProjCoord(currentLocation.x,currentLocation.y);
	float delta = clock()-lastUpdate;
	ofPoint diff = targetLocation - currentLocation;


	lastUpdate = clock();
}