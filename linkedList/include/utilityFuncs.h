#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


template<class InIt>
void print_range(InIt first, InIt last, char const* delim = "\n"){
  --last;
  for(; first != last; ++first){
    std::cout << *first << delim;
  }
  std::cout << *first;

  std::cout<<"\n";
}