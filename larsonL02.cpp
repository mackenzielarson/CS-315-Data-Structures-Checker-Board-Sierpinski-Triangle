/***************************
Author: Mackenzie Larson 
Date: 8/31/14
Class: CS 315 
Program Description: This program uses two functions to create 2 separate images. The first function board will create a 
                     black and red checker board. The second Sierpinski will create a  Sierpinski gasket. 
**************************/ 

#include "EasyBMP.h"
#include "stdlib.h"

using namespace std;

void board(BMP & Output) {
  int picWidth = 256;
  int picHeight = 256;
  int row;
  int col;
  for (int i = 0; i < picWidth-1; ++i)
    for (int j = 0; j < picHeight-1; ++j) {
      int row = i/32;
      int col = j/32;
      if (row%2==0 && col%2==0 || row%2!=0 && col%2!=0) {
        Output(i,j)->Red = 255;
        Output(i,j)->Blue = 0;
        Output(i,j)->Green = 0;
      }
      else
        {
          Output(i,j)->Red = 0;
          Output(i,j)->Blue = 0;
          Output(i,j)->Green = 0;
        }
    }
}

void  Sierpinski(BMP & Output, int n, int xA, int yA, int xB, int yB, int xC, int yC, int xP, int yP) {
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


int main( int argc, char* argv[])
{
  BMP myImage;
  myImage.SetSize(255, 255);
  board(myImage);
  myImage.WriteToFile(argv[1]);

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


  int n = 10000;
  myImage.SetSize(256, 256);
  Sierpinski(myImage, n, xA, yA, xB, yB, xC, yC, xP, yP);
  myImage.WriteToFile(argv[2]);
  return 0;

}
