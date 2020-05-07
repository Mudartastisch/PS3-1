#include <iostream>

double milesToKilometer(double miles)
{
    return miles * 1.609344;
}

//"char** is a pointer to a char*. Making it a pointer to a pointer to a char" enabling me to use cli arguments
int main(int argc, char **argv)
{
    if (argv[1])
    { //check for existance
        double result = atof(argv[1]);
    http: //www.cplusplus.com/reference/cstdlib/atof/ String to double conversion
        if (result != 0)
        {
            result = milesToKilometer(result);
            std::cout << result << std::endl;
        }
        else
        {
            std::cout << "Usage: mile_to_kilometer <double> (no 0 or non-double)" << std::endl;
            exit(EXIT_FAILURE);
            //http://www.cplusplus.com/reference/cstdlib/exit/
        }
    }
    else
    {
        std::cout << "Usage: mile_to_kilometer <double> (no 0 or non-double)" << std::endl;
        exit(EXIT_FAILURE);
        //http://www.cplusplus.com/reference/cstdlib/exit/
    }
    return 0;
}