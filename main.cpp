/**
 * @file main.cpp
 * @author Gerardo Gonzalez & Daniel Way
 * @date 2024-03-01
 * @brief where the execution procces takes place
 * 
 * this is where the main function and any other nescessary code, like stacker and stackImages from the stacker class, are executed in the program 
 */


#include <iostream>
#include "stacker.h"
#include <string>


using namespace std;

int main() {

  string imageName;
  int numImages;

  cout << "Please enter the image you wish to stack: ";
  cin >> imageName;


  cout << "Please enter the number of images: ";
  cin >> numImages;



  Stacker stacker("ppms/" + imageName + "/" + imageName + "_001.ppm");
  stacker.stackImages(imageName, numImages);
  return 0;
}
