#include "ofApp.h"


// Extern variables have to be defined once and only once.


//--------------------------------------------------------------
void ofApp::setup(){

    
    osc = oscManager::Instance(); // get pointer to osc singleton instance
    
    osc->setup();
	ofBackground(0);
    ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_NOTICE);
    
    // scene setup
    dotScene.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

    osc->update();
    
    ///// -------------------- Scene selection
    
    ///// ----- simple scene
    dotScene.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

    // draw scenes
    dotScene.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if( key == 'm' ){

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

