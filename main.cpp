
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
