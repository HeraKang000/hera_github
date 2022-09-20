#include "ofApp.h"
int mycircleX;
int mycircleY;
int A;
int B;
//--------------------------------------------------------------
void ofApp::setup(){
    
    font.loadFont("Kraftwerk.ttf", 90);
    ofBackground(0,0,0);
    
    ofSetCircleResolution(200);
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //sin waves
    ofSetColor(150+ofGetMouseX()*0.1,0,0);
    for (int i=0; i<1200; i++){
        ofDrawCircle(i,ofGetHeight()/2 + 100*sin(i*0.1+mouseX*0.05)*sin(ofGetElapsedTimef()), i*0.01);
    };
    
    //poly
    ofSetColor(0,0,255);
    ofBeginShape();
    ofVertex(ofGetWindowWidth()/4, 0);
    ofVertex(ofGetWindowWidth()/4, ofGetMouseX());
    ofVertex(ofGetWindowWidth()/4*3.1,ofGetMouseX());
    ofVertex(ofGetWindowWidth()/4*3.1, 0);
    ofEndShape();
    
    
    //curves
    ofSetColor(255, 255, 255, B);
    
    ofBeginShape();
    ofCurveVertex(0, ofGetHeight()/2);
    ofCurveVertex(0, ofGetHeight()/2);
    
    ofCurveVertex(ofGetMouseY()*1.5, 200);
    ofCurveVertex(200,ofGetMouseY()*1.5);
    
    ofCurveVertex(ofGetWidth(), ofGetHeight()/2);
    ofCurveVertex(ofGetWidth()/2, ofGetHeight()/2);
    ofEndShape();
  
    
    //beziercurves
    ofEnableAlphaBlending();
    float bez1X1 = 50 * cos(ofGetElapsedTimef()*2.0f);
    float bez1Y1 = 200 + 100 * sin(ofGetElapsedTimef()/3.5f);
    
    float bez1X2 = 1000 + 30 * cos(ofGetElapsedTimef()*5.0f);
    float bez1Y2 = 100 + 100 * sin(ofGetElapsedTimef());
    
    float bez2X1 = 350 + 50 * cos(ofGetElapsedTimef()*2.0f);
    float bez2Y1 = 200 - 100 * sin(ofGetElapsedTimef()/3.5f);
    
    float bez2X2 = 400 + 30 * cos(ofGetElapsedTimef()*5.0f);
    float bez2Y2 = 100 - 100 * sin(ofGetElapsedTimef());
    
    ofBeginShape();
    ofVertex(100,300);
    ofSetColor(255, 255, 0, A);
    ofVertex(512,0);
    ofBezierVertex(0, 300, bez1X1, bez1Y1, 650, 300);
    ofBezierVertex(500 , 300, bez1X1, bez1Y1, 650, 800);
    ofBezierVertex(650, 300, bez1X2, bez1Y2, 0, 300);
    ofVertex(800+ofGetMouseX()*0.5,512);
    ofEndShape();
    
    //kraftwerk text
    ofSetLineWidth(5);
    ofSetColor(255-ofGetMouseX()*0.3, ofGetMouseX()*0.3, 0, ofGetMouseX());
    font.drawString("KRAFTWERK",ofGetWindowWidth()/4, ofGetWindowHeight()/1.84);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout<<"Key Pressed!!!!"<<key<<endl;
   
    if (key>=0){
        A = 255;
        B = 0;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    cout<<"Key Released!!!!"<<key<<endl;
    if (key>=0){
        A = 0;
        B = 255;
    }
    B = ofGetMouseX();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    cout<<"Mouse X"<<x<<endl;

   
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
