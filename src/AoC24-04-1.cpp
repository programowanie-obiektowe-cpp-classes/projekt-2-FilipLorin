#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <iterator>
#include <fstream>

// strategy:
//  1. load text as lines from file
//  2. generate all allowed rotations (horizontal, vertical, diagonal /, diagonal \)
//  3. regex count "XMAS|SAMX" on all above
//  4. add results

int count(std::vector<std::string> lines) {
  int sum = 0;
  for(auto line : lines) {
    std::regex pattern("(?=XMAS|SAMX)");
    std::sregex_iterator begin(line.begin(), line.end(), pattern);
    std::sregex_iterator end;
    sum += std::distance(begin, end);
  }
  return sum;
} 


int day04_1() {
  std::vector<std::string> lines_horizontal;
  std::ifstream file("Input_AoC24-04.txt");
  //std::ifstream file("day4test");

  // Load file as lines
  std::string line;  
  while( getline(file, line) ) {
    lines_horizontal.push_back(line);
  }
  file.close();

  // vertical lines
  std::vector<std::string> lines_vertical;
  for(int i = 0; i < lines_horizontal[0].size(); i++){
    std::string l = "";
    for(int ii = 0; ii < lines_horizontal.size(); ii++){
      l += lines_horizontal[ii][i];
    }
    lines_vertical.push_back(l);
  }
  // diagonal 1
  std::vector<std::string> lines_diag1;
  for(int i = 0; i < lines_horizontal[0].size(); i++) {
    std::string l = "";
    int ii = 0;
    while (ii <= i) {
      l += lines_horizontal[i-ii][ii];
      ii++;
    }
    //std::cout << l << "\n"; 
    lines_diag1.push_back(l);
  }
  for(int i = 1; i < lines_horizontal.size(); i++) {
    std::string l = "";
    int j = lines_horizontal[1].size()-1;
    int ii = 0;
    while(ii <= j && ii + i < lines_horizontal.size()) {
      l += lines_horizontal[i+ii][j-ii];
      ii++;
    }
    //std::cout << l << "\n"; 
    lines_diag1.push_back(l);
  }


  // diagonal 2
  std::vector<std::string> lines_diag2;
  for(int i = lines_horizontal[0].size()-1; i >= 0; i--) {
    std::string l = "";
    int ii = 0;
    while (ii < lines_horizontal.size() && i+ii < lines_horizontal[0].size()) {
      l += lines_horizontal[ii][i+ii];
      ii++;
    }
    //std::cout << l << "\n"; 
    lines_diag2.push_back(l);
  }
  for(int i = 1; i < lines_horizontal.size(); i++) {
    std::string l = "";
    int ii = 0;
    while(i + ii < lines_horizontal.size() && ii < lines_horizontal[0].size()) {
      l += lines_horizontal[i+ii][ii];
      ii++;
    }
    //std::cout << l << "\n"; 
    lines_diag2.push_back(l);
  }

  // count occur;
  int h = count(lines_horizontal);
  int v = count(lines_vertical);
  int d1 = count(lines_diag1);
  int d2 = count(lines_diag2);

  int found = h + v + d1 + d2;
  std::cout << h << " " << v << " " << d1 << " " << d2 << "\n";  
  std::cout << found << "\n";
  return 0;
}
