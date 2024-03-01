/**
 * @file stacker.h
 * @author Gerardo Gonzalez n Daniel Way
 * @date 2024-03-01
 * @brief where the methods n members of the program live
 * 
 * this is where we initialize the required methods n memebers for the actual assignment 
 */


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
  
  void processImage(const std::string& filename); //reads and and processes each ppm file 
  
  void calculateAverages(int numImages); // calculates the average of all the added pixel images
  
  void writeStackedImage(const std::string& outputFilename); //writes the final outputted image
 


  
public: // what gets called in main
  
  Stacker(const std::string& filename); //opens a ppm file and implements its contents into the
                                       // members of the class

  void stackImages(const std::string& baseName, int numImages); //essentially looks for each ppm file,                                                                //names it, goes thru the processImage                                                                //method, calculates the average of all                                                               //the pixels, and wrties the stacked image                                                            //into a new ppm file
   
};

#endif //STACKER_H
