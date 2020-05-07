//least common multiple
//as  per https://en.wikipedia.org/wiki/Least_common_multiple#Calculation//
//we can assume lcm(a,b) = (|a*b|) / (gcd(a,b))
//in this special case we can assume lcm(a,b) = (|a*b|)
//as gcd(1,x) is always 1

#include <iostream>

//we can assume a big numer
long simple_lcm = 1;

int main() {
    for(int i = 1; i <= 20; i++){
        simple_lcm = simple_lcm * i;
    }

    std::cout << simple_lcm << "\n";
}