#include <iostream>
#include <vector>

int main(){
  std::cout << "Hello, World!\n";
  return 0;
}

void lowestcommondenominatorRange(int low, int high){
  std::cout << "The lowest common denominator of all numbers between"
  <<  low << "and" << high << "is" << result << std::endl;
}

int bruteforcefactorization(int number){
  int primessmallertwenty [8] = {2,3,5,7,11,13,17,19};
  //every number we check gets its own array, with the cells corresponding to the prime numbers in primessmallertwenty[]
  int factors [8] = {0,0,0,0,0,0,0,0};
  for (int i = 0; i < 8; ++i) {
    while (number % primessmallertwenty[i] == 0){
      factors[i] == factors[i]+1;
      number = number / factors[i];
    }
  }
}