/**
 * @file stacker.cpp
 * @author Gerardo Gonzalez
 * @date 2024-02-27
 * @brief this is the meat of the methods from the stacker class
 * 
 * this file contains all of the methods from the stacker class and excutes them
 */


#include <iostream>
#include "stacker.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;



/**
 * this method opens the ppm file and implements all of its contents into the members of the stacker class
 *
 * @param const string& filename this allows the method to receive the name of the image file to be processed
 * @pre 
 * @post All of the header information has now been read into the members
 * 
 */
Stacker::Stacker(const string& filename){
  
  ifstream inFile(filename);

  if (!inFile.is_open()){
    cout << "Error opening input file: " << filename << endl;
    return;
  }
  
  // Reads header information
  inFile >> magic_number;
  inFile >> width >> height;
  inFile >> max_color;
  
  inFile.close();

  ///
  // sets all elements of vec2 to be all 0s so getting the average is easier 
  vec2.resize(width * height, {0, 0, 0});
  
}





/**
 * this method essentially looks for each ppm file name, processes n reads each ppm image from the file and pushes its contents into a new ppm file
 *
 * @param const string& baseName It represents the base name of the images that are going to be stacked
 * @param int numImages represents the number of images to be stacked and determines how many iterations the function will go through in the loop, processing each image
 * @pre 
 * @post this method processes each ppm image, gets an average of all the ppm images, and pushes the contents of all the files into a new ppm file 
 * 
 */
void Stacker::stackImages(const string& baseName, int numImages){
  cout << "Stacking images: " << endl;
  for(int i = 1; i <= numImages; ++i){
    string filename = "ppms/" + baseName + "/" + baseName + "_";

    // Doing this so that it has the correct amount of 0s in the file name 
    if(i <= 9){
      filename += "00" + to_string(i) + ".ppm";
    }
    else{
      filename += "0" + to_string(i) + ".ppm";
    }

    cout << "     " << filename << endl;
    
    // Read and process the ppm image
    processImage(filename);
  }
  
  // Calculate averages of the pixels for use in creating the final stacked image
  calculateAverages(numImages);
  
  // Write the stacked image to a new ppm file
  writeStackedImage(baseName + ".ppm");

  cout << endl;
  cout << "Stacking succeeded." << endl;
  cout << "Output written to: " << baseName + ".ppm" << endl;
  
}




/**
 * this method processes each ppm image by putting the header contents, reading in the pixel data into the members from the stracker class into vec1, which it's contents are then pushed and added together into vec2 clearing vec1, and then repeat for the next file. 
 *
 * @param const string& filename allows the method to receive the name of the image file to be processed
 * @pre 
 * @post it now skips the header information, reads in pixel data, adds the contents from vec1 into vec2 together, and repeats 
 * 
 */
void Stacker::processImage(const string& filename){

  ifstream inputFile(filename);
   
  if (!inputFile.is_open()){
    cout << "Error opening input file: " << filename << endl;
    return;
  }
  
  // Skip the header information since we read it all in the constructor
  string line;
  for (int i = 0; i < 3; ++i){
    getline(inputFile, line);
  }
  
  // Read pixel data
  Pixel pixel;
  while(inputFile >> pixel.red >> pixel.green >> pixel.blue){
    vec1.push_back(pixel);
  }
  
  inputFile.close();


  // adds elements of vec1 to vec2
  // I also have no idea why this has to be size_t but that's what google said would make the compiler stop giving me a weird error
  for(size_t i = 0; i < vec1.size(); i++){
    
    vec2[i].red += vec1[i].red;
    vec2[i].green += vec1[i].green;
    vec2[i].blue  += vec1[i].blue;
    
  }

  // clearing vec1 so that we can read the next file into an empty vector
  vec1.clear();
  
}




/**
 * this method calculates the average of all the added ppm images and sets pixelVec to vec2
 *
 * @param int numImages represents the number of images to be stacked 
 * @pre 
 * @post checks if vec2 is empty, divides the pixel data by the number of files there are, and sets the contents of vec2 into pixelVec 
 * 
 */
void Stacker::calculateAverages(int numImages){
  // checks if vec2 is empty for debugging purposes
  if(vec2.empty()){
    cout << "No pixel data available for averaging." << endl;
    return;
  }



  /// we might need to make sure the numbers don't go above max_color



  // loops through the vec2, which contains all the RBG elements from all the files added together and then divides each by how many files there are
  for(Pixel& pixel : vec2){
    pixel.red /= numImages;
    pixel.green /= numImages;
    pixel.blue /= numImages;
    
  }

  // sets pixelsVec to vec2. 
   
  pixelsVec = vec2;

  /// I'm kind of thinking that I probably could have just used pixelsVec instead of ever even creating or using vec2
  
}



// Writes the final outputted image

/**
 * Writes the final outputted image
 *
 * @param const string& outputFilename represents the filename of the output image
 * @pre 
 * @post It writes the header and the pixel data into the file
 * 
 */
void Stacker::writeStackedImage(const string& outputFilename){

  ofstream outFile(outputFilename);

  // checks if file is open
  if (!outFile.is_open()){
    cout << "Error opening output file: " << outputFilename << endl;
    return;
  }


  // Writes header for the file
  outFile << magic_number << "\n";
  outFile << width << " " << height << "\n";
  outFile << max_color << "\n";


  // Write pixel data into the file
  for (const Pixel& pixel : pixelsVec){
    outFile << pixel.red << " " << pixel.green << " " << pixel.blue << "\n";
  }
  
  outFile.close();
    
    
}
