#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd(int a, int b) {
  //using Euclid's algorithm as per https://en.wikipedia.org/wiki/Euclidean_algorithm#Implementations 
  //using the recursive division/modulo based approach
  if (b == 0) return a;
  return gcd(b, a%b);
}

TEST_CASE("describe_gcd", "[gcd]") {
  REQUIRE(gcd(2 ,4) == 2);
  REQUIRE(gcd(9 ,6) == 3);
  REQUIRE(gcd(3 ,7) == 1);
  REQUIRE(gcd(48 ,18) == 6);
}

int checkSum(int i){
  //edge case 0, has to be caught
  int result = 0;
  int temp;
  while (i > 0) {
    temp = i %  10; //get last digit
    i = i / 10; //remove last digit
    result = result + temp;
  }
  if (result >= 10) { //repeat if result is not single digit
    return checkSum(result);
  }
  else{ return result;}
}

TEST_CASE("describe_checkSum", "[checkSum]") {
  REQUIRE(checkSum(0) == 0);
  REQUIRE(checkSum(117516) == 3);
  REQUIRE(checkSum(380511905) == 5);
}



int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
