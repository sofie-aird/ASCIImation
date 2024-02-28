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
  string movie; 
  string temp;
  pair<int,string> p1;
  while (!myFile.eof()) {
    int count = stoi(data);
    p1.first = count;
    movie = "";
    for (int i=0; i<13; i++){
      getline(myFile, temp);
      movie += temp + "\n"; 
    } 
    p1.second = movie;
    mylist->insertLast(p1); 
    getline(myFile, data);
  }
  myFile.close();
  return mylist;
}

void playMovie(List<pair<int, string>>* list) {
  pair<int, string> temp;
  while (list->getSize() != 0){
    system("clear");
    temp = list->getFirst();
    cout << temp.second << endl; 
    usleep((1000000/15) * temp.first); 
    pair<int, string> temp = list->removeFirst(); 
  }
  system("clear");
}

void playReverse(List<pair<int, string>>* list) {
  pair<int, string> temp;
  while (list->getSize() != 0) {
    system("clear");
    temp = list->getLast();
    cout << temp.second << endl;
    usleep((1000000/15) * temp.first);
    pair<int, string> temp = list->removeLast();
  }
  system("clear");
}