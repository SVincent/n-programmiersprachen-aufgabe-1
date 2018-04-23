#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <string>
#include <catch.hpp>

double mileToKilometer(double m){
  double km = m/0.62137;
  return km;
}

TEST_CASE("describe_mileToKilometer","[mileToKilometer]"){
  REQUIRE(mileToKilometer(1) == Approx(1.60934708789).epsilon(0.0001)); //read up on approx!
  REQUIRE(mileToKilometer(0) == Approx(0.0).epsilon(0.1));
  REQUIRE(mileToKilometer(12) == Approx(19.312128).epsilon(0.0001));
}

int main(int argc, char* argv[]){
  std::cout << "Please enter the amount of miles:\n";
  int miles = 0;
  std::cin >> miles ;
  double result = mileToKilometer(double(miles));
  std::cout << miles << " miles equal " << result << " kilometers.\n";
  return Catch::Session().run(argc, argv);
}