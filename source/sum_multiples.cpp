#include <iostream>
#include <cmath>

//"char** is a pointer to a char*. Making it a pointer to a pointer to a char" enabling me to use cli arguments
int main(int argc, char **argv)
{
    int sum = 0;
    unsigned int target;
    if (argv[1])
    {                           //check for existance
        target = atoi(argv[1]); //http://www.cplusplus.com/reference/cstdlib/atoi/ String to int conversion
        if (target != 0)
        { //check if its an int
            for (int i = 1; i <= target; i++)
            {
                if (i % 3 == 0 || i % 5 == 0)
                {
                    sum = sum + i;
                }
            }

            std::cout << sum << "\n";
        }
        else
        {
            std::cout << "Usage: sum-m <int> (no 0 or non-int)" << std::endl;
            exit(EXIT_FAILURE);
        }
        //http://www.cplusplus.com/reference/cstdlib/exit/
    }
    else
    {
        std::cout << "Usage: sum-m <int>" << std::endl;
        exit(EXIT_FAILURE);
    }
    //http://www.cplusplus.com/reference/cstdlib/exit/

    return 0;
}