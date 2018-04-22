#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd(int a, int b){ //recursive implementation
  int result;
  if (b == 0){
   result = a;
  }
  else {
    result = gcd(b, a%b);
  }
  return result;
}

TEST_CASE("describe_gcd" , "[gcd]"){
  REQUIRE( gcd (2 ,4) == 2);
  REQUIRE( gcd (9 ,6) == 3);
  REQUIRE( gcd (3 ,7) == 1);
}

int checksum(int x){
  int remainder = x;
  int chksm = 0;
  while (remainder != 0){
    chksm = chksm + (remainder%10); //adds the last digit of our number to the checksum
    if (chksm > 9) {
      remainder = remainder / 10; 
    }
    else {
      remainder = 0;
    }
  }
  return chksm;
}

TEST_CASE("describe_checksum" , "[checksum]"){
  REQUIRE(checksum(118764) == 27);
  REQUIRE(checksum(10) == 1);
  REQUIRE(checksum(0) == 0);
}

double fract(double x){
  return double result = x-(int(x);
}

TEST_CASE("describe_fract","[fract]"){
  REQUIRE(e == Approx(d)); //unclear what approx is needed for or what it even does
}

double surfaceCyl(double r, double h){
  return double surface = 2*M_PI*r*(r+h);
}

double volumeCyl(double r, double h){
  return double volume = M_PI*(r*r)*h;
}

TEST_CASE("describe_volumeCyl","[volumeCyl]"){
  //need to check up on Approx to implement this test?
}

int factorial(int f){
  int result = 1;
  for (int i=f; i>0; i--){
    result = result*i;
  }
  return result;
}

TEST_CASE("describe_factorial","[factorial]"){
  REQUIRE(factorial(0) == 1);
  REQUIRE(factorial(1) == 1);
  REQUIRE(factorial(10) == 3628800);
}

int binomial(int n, int k){
  return int result = (factorial(n))/((factorial(k)*(factorial(n-k))));
}

TEST_CASE("describe_binomial","[binomial]"){
  REQUIRE(binomial(0,0) == 1);
  REQUIRE(binomial(1,1) == 1);
  REQUIRE(binomial(20,10) == 184756);
}

bool is_prime(int p){
  int divisors = 0;
  for (int i = 1; i<=p; i++){
    if (p%i == 0){
      divisors++;
    }
  }
  return (divisors == 2); //if p only has two divisors (1 and p), it's prime, otherwise not.
}

TEST_CASE("describe_is_prime","[is_prime]"){
  REQUIRE(is_prime(2) == TRUE);
  REQUIRE(is_prime(3) == TRUE);
  REQUIRE(is_prime(1) == FALSE);
  REQUIRE(is_prime(4) == FALSE);
}

double mileToKilometer(double m){
  return double km = m/0.6213;
}

TEST_CASE("describe_mileToKilometer","[mileToKilometer]"){
  REQUIRE(mileToKilometer(1) == 1.60934708789); //read up on approx!
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}