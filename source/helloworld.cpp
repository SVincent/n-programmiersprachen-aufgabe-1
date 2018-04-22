#include <iostream>
#include <algorithm>    // std::max

int main(){
  std::cout << "Hello, World!\n";
  return 0;
}

int[8] bruteforcefactorization(int number){ //c++ doesn't allow return type of array? should I use a pointer?
  int primessmallertwenty [8] = {2,3,5,7,11,13,17,19}; //hardcoded prime numbers in our range
  //every number we check gets its own array, with the cells corresponding to the prime numbers in primessmallertwenty[]
  int factors [8] = {0,0,0,0,0,0,0,0};
  //factors[] will store the prime factors of one of the numbers between 1 and 20
  for (int i = 0; i < 8; ++i) {
    while (number % primessmallertwenty[i] == 0){
      //for every prime number we check if the current number can be divided by it
      //if so, we increase the corresponding cell in the factors array and divide our current number by the prime number we are comparing it with
      factors[i] = factors[i]+1;
      number = number / primessmallertwenty[i];
    }
  }
  //at the end of this for-loop factors should include all prime factors of the number we checked
  return factors;
}

void lowestcommondenominatorRange(int low, int high){
  //low and high define the range which we test, in our case low = 1, high = 20.
  //until a better way to know the prime numbers within that range exist however this doesn't really work, since the primes are hardcoded
  int lcd [8] = {0,0,0,0,0,0,0,0}; //lcd is short for lowest common denominator - structure is the same as factors from the previous function
  int primessmallertwenty [8] = {2,3,5,7,11,13,17,19}; //hardcoded prime numbers in our range
  for (int i = low; i < high; ++i) {
    //for every number in our range we calculate their prime factors and store the result in a temporary variable
    int templcd [8] = bruteforcefactorization(i);
    for (int j = 0; j < 8; ++j) {
    //we then update the lcd array with the highest amount a prime number was used in the factorization
    //the result is a collection of prime numbers which can be used to factorize every single number in our range
    lcd[j] = max(lcd[j],templcd[j]);
    }
  }
  int result = 1; //since the lowest common denominator is calculated by multiplying all prime factors, we need to initialize our result with the neutral element of multiplication
  for (int k = 0; k < 8; ++k) {
    while(lcd[k]>0){
      result = result * primessmallertwenty[k];
      lcd[k] = lcd[k]-1;
    }
  }
  //our actual output - we could also return an int value in case we need the result for further calculations
  std::cout << "The lowest common denominator of all numbers between"
  <<  low << "and" << high << "is" << result << std::endl;
}


