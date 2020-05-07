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


double fract(double d){
  if( d > 0){
    return (d - floor(d)); //subtract next lower int from double
  }
  else{
    return (d - ceil(d)); //add next higher int to double (mathematical -x -y)
  }
}

TEST_CASE("describe_fract", "[fract]") {
  REQUIRE(fract(5.134) == Approx(0.134));
  REQUIRE(fract(-5.134) == Approx(-0.134));
}

double cylinder_volume(float radius, float hight) { //V=πr2h
	return (M_PI*radius*radius*hight);
}

double cylinder_area(float radius, float hight) {	//A=2πrh+2πr^2
	return (2 * M_PI*radius*radius + 2 * M_PI*radius*hight);
}

TEST_CASE("describe_cylinder_volume", "[cylinder_volume]") {
  REQUIRE(cylinder_volume(10,5) == Approx(1570.8)); //https://www.google.com/search?q=cylinder+volume
  REQUIRE(cylinder_volume(3,7) == Approx(197.92)); 
}

TEST_CASE("describe_cylinder_area", "[cylinder_area]") { 
  REQUIRE(cylinder_area(10,5) == Approx(942.478)); //https://www.google.com/search?q=cylinder+area
  REQUIRE(cylinder_area(3,7) == Approx(188.496));
}



long factorial(int i) { //this might get big very soon
  if (i == 0 || i < 0) return 0;
	if (i == 1) return 1;
	else return i*(factorial(i - 1)); //recursive multiplication
}

TEST_CASE("describe_factorial", "[factorial]") {
  REQUIRE(factorial(1) == 1);
	REQUIRE(factorial(2) == 2);
  REQUIRE(factorial(3) == 6);
  REQUIRE(factorial(20) == 2432902008176640000);//https://en.wikipedia.org/wiki/Factorial
}


bool isPrime(int s) {
	if (s == 2 || s == 1) { //catch most simple cases
		return true;
	}
	if (s % 2 == 0) { //ignore all even numbers
		return false;
	}
	for (int i = 3; i*i <= s; i = i + 2) { //increment odd numbers 
		if (s%i == 0) { 
			return false; //break out if an odd number modulo is 0
		}
	}
	return true; //if the runner reaches the number without it, it must be a prime
}

TEST_CASE("describe_is_prime", "[is_prime]") {
  REQUIRE(isPrime(1) == true);
	REQUIRE(isPrime(2) == true);
	REQUIRE(isPrime(3) == true);
	REQUIRE(isPrime(4) == false);
	REQUIRE(isPrime(7) == true);
	REQUIRE(isPrime(42) == false);
  REQUIRE(isPrime(7829) == true); //https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
}



int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
