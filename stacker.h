#ifndef STACKER_H
#define STACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class stacker{
 private:
  // Copied these from the assignment where it says the class needs to at least contain these
  string magic_number;
  int width;
  int height;
  int max_color;
  vector<int> pixels;

  struct pixel; // I don't remember how structs work so feel free to change this as needed
                // Not sure if the code for the struct goes in stacker.cpp (where it is now)
                //  or if it's supposed to go here

 public:
  // Still need to add the function prototypes here



};






#endif //STACKER_H
