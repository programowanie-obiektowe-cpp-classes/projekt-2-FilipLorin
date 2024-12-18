#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <ranges>
#include <iomanip>
#include <algorithm>

using namespace std::string_view_literals;

// Strategy
//  0. Sort rules by right(after) value
//  1. Iterate through sequence
//  2. Keep list of rules which right value appeared
//  3. Within the list, check if current number appears in the leftvalues

std::pair<int, int> find_rules(int rarg, std::vector<std::vector<int>> rules) 
{
  int l = 0;
  int r = rules.size() - 1; 
  int m;
  bool found = false;
  while( l < r ) {
    m = (r + l) / 2;
    if (rules[m][1] == rarg) {
      found = true;
      break;
    }
    else if (rules[m][1] < rarg) {
      l = m;
    }
    else {
      r = m;
    }
  }
  std::pair<int, int> fl_index{0, 0};
  if (found) {
    int l = m;
    int r = m;
    while(--l >= 0 && rules[l][1] == rarg) {}
    while(++r < rules.size()-1 && rules[r][1] == rarg) {}
    fl_index.first = l+1;
    fl_index.second = r-1;
  } 
  return fl_index;
}


int day05_1() 
{
  std::vector<std::vector<int>> rules;
  std::vector<std::vector<int>> sequences;
  int total_sum = 0;

  // Read file
  std::ifstream file("Input_AoC24-05.txt");
  std::ostringstream ss;
  std::string filecontents;
  ss << file.rdbuf();
  filecontents = ss.str();
  file.close();

  const auto input = std::string_view(filecontents);

  const size_t splitpoint = input.find("\n\n");

  const auto section1 = input.substr(0, splitpoint);
  const auto section2 = input.substr(splitpoint+2, input.size()-1);
  
  for (auto &&line : section1 | std::views::split('\n')) {
    std::vector<int> rule;
    for(auto &&num : line | std::views::split('|')) {
      const std::string s{std::string_view{num}};
      rule.push_back(std::stoi(s));
    }
    rules.push_back(std::move(rule));
  }

  for (auto &&line : section2 | std::views::split('\n')) {
    std::vector<int> seq;
    for(auto &&num : line | std::views::split(',')) {
      const std::string s{std::string_view{num}};
      seq.push_back(std::stoi(s));
    }
    sequences.push_back(std::move(seq));
  }

  // Sort rules
  std::sort(rules.begin(), rules.end(), 
      [](std::vector<int> a, std::vector<int> b) { return a[1] < b[1]; }
      );

  for (const std::vector<int> sequence : sequences) {
    std::vector<int> critical_numbers;
    bool correct = true;
    if(sequence.size() == 0) { continue; }
    for(const int num : sequence) {
      if (critical_numbers.size() > 0 && 
          std::any_of(
              critical_numbers.begin(), 
              critical_numbers.end(), 
              [&num](int a) { return a == num; }
            )) {
        // Conflict found
        correct = false;
        break;
      }
      auto aplicable_rules = find_rules(num, rules);
      if(aplicable_rules.second == 0) { continue; }
      for(int i = aplicable_rules.first; i <= aplicable_rules.second; i++) {
        critical_numbers.push_back(rules[i][0]);
      }
    }
    if(correct) {
      total_sum += sequence[sequence.size()/2];
    }
  }
  
  std::cout << total_sum << "\n";
  return 0;
}
