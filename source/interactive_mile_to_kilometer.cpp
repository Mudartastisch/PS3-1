#include <iostream>

double milesToKilometer(double miles)
{
    return miles * 1.609344;
}
int main()
{
    std::cout << "How many miles? \n";
    double miles;
    std::cin >> miles;
    std::cout << "This is equal to: " << milesToKilometer(miles) << " km" << std::endl;
    return 0;
}