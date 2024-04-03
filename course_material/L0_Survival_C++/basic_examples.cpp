#include <cstdio>
#include <iostream>
#include <vector>

// A program to introduce basic datatypes
int main(int argc, char** argv) {
    
    // Code block
    {
        // Declaring integers
        char a_i=1;         // Using char as an integer
        short b_i=4;        // 16 bit
        int c_i=2;          // 32 bit          
        unsigned int d_i=3; // 32 bit
        long e_i = 5;       // 64 bit
    }

    // This is a comment
    char a='s'; // Using char as a character
    char b = a+1; // Arithmetic with characters
    std::printf("b interpreted as an integer: %i\n", b); // print b with the memory interpreted as an integer
    std::printf("b interpreted as a character: %c\n", b); // print b with the memory interpreted as a character

    // Making a string from characters, notice that 
    // we have to have a null character '\0' 
    // at the end of the array
    char str[] = {'a', 'b', 'c', 'd', '\0'};
    std::printf("%s\n", str);

    // Declaring floating point values
    float x=5.0;
    double y=6.0;
    long double z=7.0;

    // Printing floats
    std::printf("float representation, x = %f y = %f\n", x, y); // Print x and y to the screen with their memory interpreted as floats

    //// For loops ////
    {
    
        // Demonstrating a 2D for loop

        // initialise loop limits
        int M=10, N=12;

        //   starting condition; continue condition; increment
        for (int m=0; m<M; m++) {
            for (int n=0; n<N; n++) {
                // Execute this code block each time we go around the loop
                std::printf("m is %i, n is %i\n", m, n);
            }
        }
    }
        
    //// If statements ////

    // Demonstrating if statements
    {
        int x=2;
        int y=3;

        // Using an if statement
        if (x > y) {
            // This line won't be executed because x is smaller than y
            std::printf("%i is greater than %i", x, y);
        }

        // Using an if statement with an else
        if (x > y) {
            std::printf("%i is greater than %i", x, y);
        } else {
            // This statement gets executed
            std::printf("%i is less than or equal to %i", x, y);  
        }

        // Using an if statement with an else if and an else
        if (x > y) {
            std::printf("%i is greater than %i", x, y);
        } else if (x == y) {
            std::printf("%i is equal to %i", x, y);  
        } else {
            // This statement gets executed
            std::printf("%i is less than %i", x, y);  
        }
    }

    {
        //// Vectors ////

        // Create a vector designed to hold ints
        std::vector<int> v;

        // Resize the vector to store 10 elements
        v.resize(10);

        // Access element 0
        std::cout << v[0] << "\n";

        // Get a pointer to the first element
        int* p = v.data();

        // Get the size
        std::cout << v.size() << "\n";
    }
}