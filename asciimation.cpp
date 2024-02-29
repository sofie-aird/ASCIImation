/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;
using std::runtime_error;

int main(int argc, char** argv) {
  if ((argc < 2) || (argc > 3)) {
    throw runtime_error("Not the correct amount of arguments (must have 2-3)");  //If there aren't 4 arguments, give error message
  }
  if (argc == 3){ 
    string reverse = argv[1];
    if (reverse != "--reverse"){
      throw runtime_error("2nd argument must be --reverse if there are 3.");
    } else {
      List<pair<int, string>>* mylist = loadMovie(argv[2]); 
      playReverse(mylist); 
      delete mylist;
    }
  } else {
    List<pair<int, string>>* mylist = loadMovie(argv[1]); 
    playMovie(mylist); 
    delete mylist;
  }

  



  return 0;
}
