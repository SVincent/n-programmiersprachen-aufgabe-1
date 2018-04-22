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

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}