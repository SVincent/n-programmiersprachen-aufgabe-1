#include <iostream>
#include <string>
#include <catch.hpp>

double mileToKilometer(double m){
  return double km = m/0.6213;
}

TEST_CASE("describe_mileToKilometer","[mileToKilometer]"){
  REQUIRE(mileToKilometer(1) == 1.60934708789); //read up on approx!
}

int main(){
    std :: cout << "Please enter the amount of miles:\ n " ;
    int miles = 0;
    std :: cin >> miles ;
    double result = mileToKilometer(double(miles));
    std :: cout << miles << " miles equal " << result << " kilometers.\n";
    return 0;
}