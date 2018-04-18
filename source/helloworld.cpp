#include <iostream>
#include <algorithm>    // std::max

int main(){
  std::cout << "Hello, World!\n";
  return 0;
}

int[8] bruteforcefactorization(int number){
  int primessmallertwenty [8] = {2,3,5,7,11,13,17,19};
  //every number we check gets its own array, with the cells corresponding to the prime numbers in primessmallertwenty[]
  int factors [8] = {0,0,0,0,0,0,0,0};
  for (int i = 0; i < 8; ++i) {
    while (number % primessmallertwenty[i] == 0){
      factors[i] = factors[i]+1;
      number = number / factors[i];
    }
  }
  return factors;
}

void lowestcommondenominatorRange(int low, int high){
  int lcd [8] = [0,0,0,0,0,0,0,0];
  int primessmallertwenty [8] = {2,3,5,7,11,13,17,19};
  for (int i = low; i < high; ++i) {
    int templcd [8] = bruteforcefactorization(i);
    for (int j = 0; j < 8; ++j) {
    lcd[j] = max(lcd[j],templcd[j]);
    }
  }
  int result = 1;
  for (int k = 0; k < 8; ++k) {
    while(lcd[k]>0){
      result = result * primessmallertwenty[k];
      lcd[k] = lcd[k]-1;
    }
  }
  std::cout << "The lowest common denominator of all numbers between"
  <<  low << "and" << high << "is" << result << std::endl;
}

