#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    


    // \b sort without starting and ending
    float thisDistance;
    float minDistance = 100000;

    vector<string> min;
    string start = dests[0];
   


    sort(dests.begin() + 1, dests.end() - 1);
    // \b sort for any number of cities less than 3
    if (cities_to_visit < 3){
      //cout << "1" << endl;
      //cout << dests.size() << endl;
      minDistance = computeDistance(me,start,dests);
      //cout << "2" << endl;
      min = dests;
      // cout << "3" << endl;
  
	
    }

    // cout << "4" << endl;

      
      


    // \b sort for any number of distances greater tha 2
    else{
   
    while(next_permutation(dests.begin() + 1, dests.end())){
     
	thisDistance = computeDistance(me, start, dests);
	if (thisDistance < minDistance){
	  minDistance = thisDistance;
	  min = dests;
	}

      }
	
    }
	


      

    


    
    
    
   

    cout << "Minimum path has distance " << minDistance << ": ";

    printRoute(start, min);
    

    
	
	
    

    

    // TODO: YOUR CODE HERE
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
  float total = 0;
  total += me.getDistance(start, dests[0]);

  if (dests.size() == 3){
    total += me.getDistance(dests[0], dests[1]);
    total += me.getDistance(dests[1], dests[2]);
  }
  else{

  
  for (int i = 1; i < dests.size(); i++){
    
    total += me.getDistance(dests[i - 1], dests[i]);
  }
  }

  total += me.getDistance(dests[dests.size() - 1], start);
  return total;


}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {

  for (int i = 0; i < dests.size(); i++){
    if (i != 0){
      cout << " -> ";
    }
    cout << dests[i];
  }

  cout << " -> " << dests[0] << endl;

  
}
