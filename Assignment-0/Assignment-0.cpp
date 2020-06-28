/*
  Student Name: Isaiah Paparella
  Course info:  CIS 217
  Assignment:   Assignment 0
  IDE:          Website repl.it
  Description:  Calculates the Volume of a sphere, surface area of a cube, and the area of a trapezoid
                using user input & within the set of rules defined below.

                // Rules
                
                Take User Input
                Class that calculates the follwing:
                  - Vol of a sphere (V = 4/3 * Pi * r^3)
                  - Surface area of a cube (A = 6a^2)
                  - Area of a trapezoid (A=((a+b)/2)h)

*/


#include <iostream>
#include <math.h>

using namespace std;

class calculator{
  
  public:
    //Im using floats because doubles seem useless. 
    float volume_sphere(float radius){
      return (M_PI * (radius * radius * radius)) * (4.0/3.0);
    }
    float area_surface_cube(float area){
      return 6.0 * pow(area, 2);
    }
    float area_trapezoid(float a, float b, float h){
      return ((a+b)/2.0) * h;
    }
};


int main() {
  calculator calc;
  float userInput;
  int selector;
  bool iterator = false;
  bool loop = true;
  float output[3]; 

  while(loop){

    if(!iterator){

      cout << "Welcome to the calculator!\nPlease select an option" << endl;
      cout << "    (1) Volume of a Sphere" << endl;
      cout << "    (2) Surface area of a Cube" << endl;
      cout << "    (3) Area of a Trapezoid" << endl;
      cin >> selector;

      // I could probably use a switch, but there are only 3 choices.

      if(selector == 1){
        cout << "SELECTED: VOLUME of a SPHERE!" << endl;
        cout << "Please enter the desired spheres radius : ";
        cin >> userInput;
        
        //Requirement: Store calculation in array. Since we have a loop I wanna always store selection 1 as array pos 1 (or array[0])
        //I want it overwritten if they do it again. 
        output[0] = calc.volume_sphere(userInput);
        cout << "[OUT] The volume of your sphere (radius " << userInput << ") is " << output[0] << " units." << endl; 
        
        //force the user to be asked if they want to complete another calculation
        iterator = true;

        //break line so it looks nice. 
        cout << endl;

      } else if (selector == 2){
        cout << "SELECTED: SURFACE AREA of a CUBE!" << endl;
        cout << "Please enter the desired CUBES AREA : ";
        cin >> userInput;
        output[1] = calc.area_surface_cube(userInput);
        cout <<   "[OUT] the SURFACE AREA of your CUBE (area " << userInput <<") is " << output[1] << " units." << endl;
        iterator = true;
        cout << endl; 
      }
      else if(selector == 3){
        //we need variables a b and c for the calculaiton, to save another variable I am going to use my userInput var as our C. 
        float a, b;
        cout << "SELECTED:  AREA of a TRAPEZOID!" << endl;
        cout << "Please enter the area A: "<< endl;
        cin >> a;
        cout << "Enter the area B: "<< endl;
        cin >> b;
        cout << "Enter the height H: " << endl;
        cin >> userInput;
        output[2] = calc.area_trapezoid(a,b,userInput);
        cout <<   "[OUT] the AREA of your TRAPEZOID (area " << userInput <<") is " << output[2] << " units." << endl;
        iterator = true;
        cout << endl; 
      }
      //if user enters something other than 1-3
      else{
        cout << "[err] selection not found" << endl;
      }
    } else {
        //I want to initlaize the variable every time we get into this else so there are no issues. 
      int test;
      cout << "If you want to calculate another enter '1'" << endl;
      cin >> test;
      if(test == 1){
        iterator = false;
      }else{
        loop = false;
        cout << "Here is the data in the array: ";
        // loop through our array
        for(int i = 0; i < 3; i++){
          cout << output[i] << endl;
        }
        cout << "Goodbye! :)" << endl;
      }


    }
  }

}