#pragma once

/*
  Copyright (c) 2024
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2024
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/25wjykh8
*/

#include "adts/list.h"
#include <string>
#include <utility>

using std::pair;
using std::string;

/**
 * This function loads an ASCIImation file, returning a list of frames.  Each
 * frame is represented as a pair between a duration (in units of 15fps) and the
 * frame's contents (as a string).
 * @param filename The name of the file to load.
 * @return A pointer to the list that contains the data.  Ownership of this
 *         list belongs to the caller; that is, the caller must eventually
 *         delete the returned list.
 */
List<pair<int, string>>* loadMovie(string filename);

/**
 * This function plays an ASCIImation from the provided list.
 * @param list The list of frame data to use when playing the video.
 */
void playMovie(List<pair<int, string>>* list);

/**
 * This function plays an ASCIImation in reverse from 
 * the provided list.
 * @param list The list of frame data to use when playing the video.
*/
void playReverse(List<pair<int, string>>* list);
