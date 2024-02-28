#ifndef STACKER_H
#define STACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


/**
 * 
 *
 * @class Stacker stacker.h "Image-Stacker/stacker.h"
 * @brief a class called stacker that carries methods and members that will print out images from ppm files  
 *
 */

class Stacker {
private:


  // I'm not sure if this is supposed to be here but the compiler wasn't happy if I declared just a prototype here and implemented it in stacker.cpp
  struct Pixel{
    int red;
    int green;
    int blue;
  };
  
  std::string magic_number; // P3
  int width;
  int height;
  int max_color;
  
  std::vector<Pixel> pixelsVec; // vector of STACKED images (so what gets outputted to the file)
  std::vector<Pixel> vec1; // used to get all the parts of the vector for averaging reasons
  std::vector<Pixel> vec2;
  
  void processImage(const std::string& filename);
  
  void calculateAverages(int numImages);
  
  void writeStackedImage(const std::string& outputFilename);
 


  
public: // what gets called in main
  
  Stacker(const std::string& filename);
  
  void stackImages(const std::string& baseName, int numImages);
   
};

#endif //STACKER_H
