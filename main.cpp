
// Not sure how many of these we need in main but I went ahead and added them all.
// Probably best to delete unneeded ones before turn in
#include <iostream>
#include "stacker.h"
#include <fstream>
#include <string>
#include <vector>


using namespace std;

int main() {

  string imageName;
  int numImages;

  // this output does not match the test case she showed on canvas. Not sure if we have to match it exactly but it might not be a bad idea to do so

  cout << "Please enter the image you wish to stack: ";
  cin >> imageName;


  cout << "Please enter the number of images: ";
  cin >> numImages;



  Stacker stacker("ppms/" + imageName + "/" + imageName + "_001.ppm");
  stacker.stackImages(imageName, numImages);
  return 0;
}
