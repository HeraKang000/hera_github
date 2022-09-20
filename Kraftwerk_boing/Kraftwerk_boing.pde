import processing.sound.*;
SoundFile sound;
PFont font;
int A;
int B=255;

//canvas
void setup(){
  size (600,600);
  sound = new SoundFile(this, "data/boom copy.mp3");
  font = createFont("KraftwerkRegular.ttf",128);
  frameRate(20);
}

void draw(){

  background(0);
  fill(255,255,0,B);
  text("Touch to Play", 300,300);
  
  //push();
  translate(mouseX, mouseY);
  
//boing shapes
  
  fill(150+mouseX,mouseY,0,A);
  star(0,0,200,50,40,10);
  
  //pop();
  
//text on the star
  fill(255,0,0, A);
  textSize(100+sin(10));
  textFont(font);
  textAlign(CENTER);
  text("BOING", 0, 0);

}


//bubble shape 

void star(float x, float y, float radius1, float radius2, int npoints, int rot) {

  float angle = TWO_PI / npoints;
  float halfAngle = angle/2.0;
 
  beginShape();
  for (float a = 0; a < TWO_PI; a += angle) {
    float sx = x + random(cos(a)) * radius2 *2;
    float sy = y + sin(a) * radius2;
    vertex(sx, sy);
    sx = x + cos(a+halfAngle) * radius1;
    sy = y + sin(a+halfAngle) * radius1;
    vertex(sx, sy);
  }
  rotate(PI/rot);
  endShape(CLOSE);
  
}

//mouse pressed, bubble comes out and music is played
void mousePressed(){
  if(A==0){
    A=255;
    B=0;
    sound.play();
    
  } else{
    A=0;
    B=255;
    sound.pause();
    
  }
}
