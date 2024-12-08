#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <iterator>
#include <fstream>

// strategy:
//  1. load text as lines from file
//  2. define all 4 posssible x-mas layouts
//  3. run 2D pattern matcher with marching squares


int day04_2() {
  std::vector<std::string> lines;
  std::ifstream file("Input_AoC24-04.txt");
  //std::ifstream file("day4test");

  // Load file as lines
  std::string line;  
  while( getline(file, line) ) {
    lines.push_back(line);
  }
  file.close();

  int found = 0;

  for(int i = 1; i < lines.size()-1; i++) {
    for(int ii = 1; ii < lines[0].size()-1; ii++) {
      if(lines[i][ii] == 'A') {
        bool d1 = (lines[i+1][ii+1] == 'M' && lines[i-1][ii-1] == 'S') || (lines[i+1][ii+1] == 'S' && lines[i-1][ii-1] == 'M');
        bool d2 = (lines[i+1][ii-1] == 'M' && lines[i-1][ii+1] == 'S') || (lines[i+1][ii-1] == 'S' && lines[i-1][ii+1] == 'M');

        if(d1 && d2) { ++found; }
      }
    }
  }

  std::cout << found << "\n";
  return 0;
}
