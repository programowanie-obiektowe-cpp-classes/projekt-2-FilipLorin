#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>


int day01_2() {
  // Initialize listst
  std::vector<int> list1;
  std::vector<int> list2;

  // Load input from text file
  std::ifstream istrm("Input_AoC24-01-1.txt");
  int a, b;
  while(istrm >> a >> b) {
    list1.push_back(a);
    list2.push_back(b);
  }

  // Calculate score
  unsigned long total_score = 0;

  for(int i = 0; i < list1.size(); i++) {
    total_score += list1[i] * std::count(list2.begin(), list2.end(), list1[i]);
  }

  std::cout << total_score;
  return 0;
}
