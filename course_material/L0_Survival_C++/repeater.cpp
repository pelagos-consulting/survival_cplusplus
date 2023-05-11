#include <cstdio>
#include <string>
#include <iostream>

/// Print all the arguments passed into the application
int main(int argc, char** argv) {
    
    // argc is the total number of arguments
    // argv is a memory allocation of pointers to string arguments
    
    for (int i=0; i<argc; i++) {
        std::cout << argv[i] << " ";
    }
    
    // Put a new line 
    std::cout << std::endl;
    
    //std::string words = "Hey!";
    
    //std::cout << words << "\n";
}
