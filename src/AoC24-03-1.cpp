#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iterator>


int day03_1() {
  unsigned int total_sum = 0;

  // Read file
  std::string input = "", line;
  std::ifstream file("Input_AoC24-03.txt");

  while( getline(file, line) ) {
    input.append(line);
  }
  file.close();

  std::regex pattern("mul\\((\\d+),(\\d+)\\)");

  std::sregex_token_iterator iterator{
        input.begin(), 
        input.end(), 
        pattern, 
        {1, 2}};
  std::sregex_token_iterator end;

  int seqence_counter = 0, arg1, arg2;
  bool do_flag = true;

  while(iterator != end) {
    auto res = (*iterator);
    //std::cout << res << "\n";
    if(seqence_counter % 2 == 0) { arg1 = stoi(res); }
    if(seqence_counter % 2 == 1) {
      arg2 = stoi(res);
      if(do_flag) { total_sum += arg1 * arg2; }
    }
    
    ++seqence_counter;
    ++iterator;
  }

  std::cout << total_sum << "\n";
  return 0;
}
