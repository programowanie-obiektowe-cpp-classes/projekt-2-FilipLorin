#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iterator>


int day03_2() {
  unsigned int total_sum = 0;

  // Read file
  std::string input = "", line;
  std::ifstream file("Input_AoC24-03.txt");

  while( getline(file, line) ) {
    input.append(line);
  }
  file.close();

  std::regex pattern("mul\\((\\d+),(\\d+)\\)|do\\(\\)|don't\\(\\)");

  std::sregex_token_iterator iterator{
        input.begin(), 
        input.end(), 
        pattern, 
        {0, 1, 2}};
  std::sregex_token_iterator end;

  int seqence_counter = 0, arg1, arg2;
  bool do_flag = true;

  while(iterator != end) {
    auto res = (*iterator);
    if(seqence_counter % 3 == 0) {
      std::cout << res << "\n";
      if(res == "do()") { do_flag = true; ++iterator; ++iterator; seqence_counter += 2;}
      else if(res == "don't()") { do_flag = false; }
    }
    else {
      std::cout << res << "\t" << do_flag << "\t" << total_sum << "\n";
      if(do_flag && seqence_counter % 3 == 1) { arg1 = stoi(res); }
      if(do_flag && seqence_counter % 3 == 2) {
        arg2 = stoi(res);
        total_sum += arg1 * arg2;
      }
    }
    ++seqence_counter;
    ++iterator;
  }

  std::cout << total_sum << "\n";
  return 0;
}
