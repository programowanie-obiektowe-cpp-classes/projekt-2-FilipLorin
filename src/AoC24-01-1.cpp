#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>


int day01_1() {
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

  // Sort lists
  std::sort(list1.begin(), list1.end());
  std::sort(list2.begin(), list2.end());

  // Calculate distance
  unsigned long total_distance = 0;

  for(int i = 0; i < list1.size(); i++) {
    total_distance += abs(list1[i] - list2[i]);
  }

  std::cout << total_distance;
  return 0;
}
