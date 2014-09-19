/*****
Author: Mackenzie Larson
Date: 9/19/14
Class: CS 315 LAB02
Description: Program creates a sierpinski triangle. 
******/

#include "EasyBMP.h"
#include "stdlib.h"

using namespace std;

void RandomDots(BMP & Output, int n, int xA, int yA, int xB, int yB, int xC, int yC, int xP, int yP) {
  int picWidth = 256;
  int picHeight = 256;
  for(int i = 0; i < n; i++) { 
    int randint = (rand() % 3) +1; 
    if (randint==1){
      int x = (xP + xA)/2; 
      int y = (yP + yA)/2; 
      Output(x, y)->Red = 255;
      Output(x, y)->Blue = 0;
      Output(x, y)->Green = 0;
      xP = x; 
      yP = y; 
    }
    else if (randint==2){
      int x = (xB+xP)/2; 
      int y = (yB+yP)/2; 
      Output(x, y)->Red = 255;
      Output(x, y)->Blue = 0;
      Output(x, y)->Green = 0;
      xP = x;
      yP = y;
    }
    else{
      int x = (xC+xP)/2; 
      int y = (yC+yP)/2; 
      Output(x, y)->Red = 255;
      Output(x, y)->Blue = 0;
      Output(x, y)->Green = 0;
      xP = x;
      yP = y;
    }
  }
}

int main(int argc, char*argv[]){

  int xA, yA, xB, yB, xC, yC, xP, yP;  
 
  cout << "Enter a x value for point X: "; 
  cin >> xA; 
  cout << "Enter a y value for point X: "; 
  cin >> yA; 
  cout << "Enter a x value for point Y: "; 
  cin >> xB; 
  cout << "Enter a y value for point Y: "; 
  cin >> yB; 
  cout << "Enter a x value for point Z: "; 
  cin >> xC; 
  cout << "Enter a y value for point Z: "; 
  cin >> yC; 
  cout << "Enter a x value for center point Po: "; 
  cin >> xP; 
  cout << "Enter a y value for center point Po: "; 
  cin >> yP; 
  //8 numbers 3 points one center point  
  
  int n = 10000; 
  BMP myImage;
  myImage.SetSize(256, 256);
  RandomDots(myImage, n, xA, yA, xB, yB, xC, yC, xP, yP);
  myImage.WriteToFile(argv[1]);
  return 0;
}

