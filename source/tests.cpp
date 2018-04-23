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
    if (remainder > 9) {
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
  REQUIRE(checksum(-1) == -1);
}

double fract(double x){
  return (x-(int(x)));
}

TEST_CASE("describe_fract","[fract]"){
  REQUIRE(fract(1.0) == Approx(0.0).epsilon(0.1));
  REQUIRE(fract(2.4) == Approx(0.4).epsilon(0.1));
  //REQUIRE(e == Approx(d)); //unclear what approx is needed for or what it even does
}

double surfaceCyl(double r, double h){
  return 2*M_PI*r*(r+h);
}

TEST_CASE("describe_surfaceCyl","[surfaceCyl]"){
  REQUIRE(surfaceCyl(1,1) == Approx(12.566).epsilon(0.001));
  REQUIRE(surfaceCyl(5,2) == Approx(219.91149).epsilon(0.00001));
  REQUIRE(surfaceCyl(4,7) == Approx(276.4602).epsilon(0.0001));
  //need to check up on Approx to implement this test?
}

double volumeCyl(double r, double h){
  return M_PI*(r*r)*h;
}

TEST_CASE("describe_volumeCyl","[volumeCyl]"){
  REQUIRE(volumeCyl(1,1) == Approx(3.142).epsilon(0.001));
  REQUIRE(volumeCyl(5,2) == Approx(157.07963).epsilon(0.00001));
  REQUIRE(volumeCyl(4,7) == Approx(351.8584).epsilon(0.0001));
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
  return (factorial(n))/((factorial(k)*(factorial(n-k))));
}

TEST_CASE("describe_binomial","[binomial]"){
  REQUIRE(binomial(0,0) == 1);
  REQUIRE(binomial(1,1) == 1);
  REQUIRE(binomial(5,3) == 10);
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
  REQUIRE(is_prime(2) == true);
  REQUIRE(is_prime(3) == true);
  REQUIRE(is_prime(1) == false);
  REQUIRE(is_prime(4) == false);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}