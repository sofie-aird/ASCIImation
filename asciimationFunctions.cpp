/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

List<pair<int, string>>* loadMovie(string filename) {
  ifstream myFile;
  string data;
  LinkedList<pair<int, string>>* mylist = new LinkedList<pair<int, string>>();
  myFile.open(filename);
  if(!myFile.is_open()) {
    throw runtime_error("file " + filename + " failed to open ");
  }
  getline(myFile, data);
  string first = data; 
  string temp; 
  while (!myFile.eof()) {
    for (int i=0; i<13; i++){
      getline(myFile, temp);
      data += temp; 
      data += "\n"; 
    }
    pair<int,string> p1;
    p1.first = stoi(first); 
    p1.second = data;
    mylist->insertFirst(p1); 
    data = " ";
  }
  return mylist;
}

void playMovie(List<pair<int, string>>* list) {
  pair<int, string> temp = list->removeLast();
  while (list->getSize() != 0){
    cout << temp.second << endl; 
    usleep(1000000/15 * temp.first); 
    pair<int, string> temp = list->removeLast();
    system("clear"); 
  }
}
