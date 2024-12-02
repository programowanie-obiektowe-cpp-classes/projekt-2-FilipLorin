#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

bool is_safe_r(std::vector<int> rep) { 
    bool dir = rep[0] > rep[1];
    for(int ii = 1; ii < rep.size(); ii++) {
      if( rep[ii] < rep[ii-1] != dir)    { return false; }
      if( abs(rep[ii] - rep[ii-1]) < 1)  { return false; }
      if( abs(rep[ii] - rep[ii-1]) > 3)  { return false; }
    }
    return true;
}

bool is_safe(std::vector<int> rep) {
  if ( is_safe_r(rep) ) { return true; }

  for(int i = 0; i < rep.size(); i++) {
    std::vector<int> new_vec = rep;
    new_vec.erase(new_vec.begin() + i);
    if ( is_safe_r (new_vec) ) { return true; }
  }

  return false;
}


int day02_2() {
  std::vector<std::vector<int>> reports;
  unsigned int num_safe_reports = 0;

  // Read file
  std::string line, num;
  std::ifstream file("Input_AoC24-02-1.txt");

  while( getline(file, line) ) {
    std::vector<int> report;
    std::stringstream ss{line};

    while( getline(ss, num, ' ') ) {
      report.push_back(stoi(num));
    }
    reports.push_back(report);
  }
  file.close();

  for(int i = 0; i < reports.size(); i++) {
    if (is_safe(reports[i])) { num_safe_reports++; }
  }
  std::cout<<num_safe_reports;
  return 0;
}
