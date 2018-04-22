#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd (int a, int b) { //recursive implementation
  int result;
  if (b == 0){
   result = a;
  }
  else {
    result = gcd(b, a%b);
  }
  return result;
}

TEST_CASE ("describe_gcd" , "[gcd]"){
REQUIRE ( gcd (2 ,4) == 2);
REQUIRE ( gcd (9 ,6) == 3);
REQUIRE ( gcd (3 ,7) == 1);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}