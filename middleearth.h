#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

/*! Middle Heart declaraction file */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
public:
  MiddleEarth(int xsize, int ysize, int num_cities, int seed); /* contructor will create middleearth \emoji smile 
								*/
  void print(); /* this function will \em  print out the cities in middle earth */
    void printTable();
  float getDistance(const string& city1, const string& city2); /* function will get distance between two cities*/
  vector<string> getItinerary(unsigned int length); /*will get travel itinerary */

private:

  /* the following are private variables assocaited with middleearth file */
    int num_city_names, xsize, ysize; 
    unordered_map<string, float> xpos, ypos;
    vector<string> cities;
    unordered_map<string, unordered_map<string, float>> distances;

    mt19937 gen; // Mersenne-Twister random number engine
};

#endif
