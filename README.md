# Image-Stacker, By Gerardo Gonzalez and Daniel Way.  

## Design Decisions  
We decided to break the program into 5 different functions:

Stacker: Inializes everything  
stackImages: Opens the files and then runs the 3 functions below as needed  
processImage: Reads the files into a vector, then adds them to another vector, then clears the original vector for reuse.  
calculateAverages: Goes over each pixel's RGB value and devides it by the number of files  
writeStackedImage: Creates the new .ppm file   
  
  
## Challenges  
* The biggest challenge was working with vectors, as it is our first time using them.    
* Working with structs was new, using that took some getting used to.  
  * We ran into the issue where we did not know how to create a vector that was the correct length but filled with zeros for each color.  
  
  
## How To Run  
1. `make` to create the program  
2. `./stacker` to run the program  
3. You now need to pick one of the ppms to stack together  
   - `cone_nebula`  
   - `n44f`  
   - `orion`  
   - `wfc3_uvis`  
4. Enter how many of the images you wanna stack (1-10). 10 is reccomended for best color.  
  
  
## How Work Was Split  
For most of the coding process we worked on it together, or at least talked it over (most of it uploaded from Daniel's machine)  
Gerardo: Documentation of everything
Daniel: Makefile, .gitignore, README, and the initial creation of the skeleton files for all .cpp and .h files