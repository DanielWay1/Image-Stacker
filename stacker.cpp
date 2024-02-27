
#include <iostream>
#include "stacker.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;


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



void Stacker::stackImages(const string& baseName, int numImages){

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
  
  cout << "Stacking succeeded." << endl;
  
}



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
