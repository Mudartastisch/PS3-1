#include <iostream>

//"char** is a pointer to a char*. Making it a pointer to a pointer to a char"
int main(int argc, char** argv) {
    int sum = 0;
    unsigned int target;
    if(argv[1]){
        target = atoi(argv[1]); //http://www.cplusplus.com/reference/cstdlib/atoi/ String to int conversion
    for (int i = 1; i <= target ; i++){
        if (i % 3 == 0 || i % 5 == 0){
            sum = sum + i;
        }
    }

    std::cout << sum << "\n";
    }
    else{ std::cout << "Usage: sum-m <int>" << std::endl; exit (EXIT_FAILURE);}
}