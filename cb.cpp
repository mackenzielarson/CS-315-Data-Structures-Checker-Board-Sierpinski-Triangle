/*****
Author: Mackenzie Larson
Date: 9/19/14
Class: CS 315 LAB02
Description: Program creates a red and black checkerboard 
******/ 

#include "EasyBMP.h"
using namespace std;

void colorToGray(BMP & Output) {
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
 
int main( int argc, char* argv[])
{
  BMP myImage;
  myImage.SetSize(255, 255); 
  colorToGray(myImage);
  myImage.WriteToFile(argv[1]);
  return 0;
}
