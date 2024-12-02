#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>


int day02_1() {
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
    auto rep = reports[i];
    bool dir = rep[0] > rep[1];
    bool is_safe = true;
    for(int ii = 1; ii < rep.size(); ii++) {
      if( rep[ii] < rep[ii-1] != dir)    { is_safe = false; break; }
      if( abs(rep[ii] - rep[ii-1]) < 1)  { is_safe = false; break; }
      if( abs(rep[ii] - rep[ii-1]) > 3)  { is_safe = false; break; }
    }
    if (is_safe) { num_safe_reports++; }
  }
  std::cout<<num_safe_reports;
  return 0;
}
