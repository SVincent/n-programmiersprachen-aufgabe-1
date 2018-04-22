#include <iostream>

int main(){
  std::cout << "Task 1.10\n";
  return 0;
}

int sumMultiples(int low, int high){
    int result;
    for (int i = low; i<= high; i++){ //works for any range, not only 1-1000
        if(i%3 == 0 || i%5 == 0){
            result = result + i;
        }
    }
    return result;
}