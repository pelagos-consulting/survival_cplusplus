#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

// Functions
void simple() { // Takes no arguments and returns no values, we use void as the return type
    int a=2;
}

int get_int() { // Takes zero arguments and returns an integer, notice we have to declare the return type
    int a=2;
    
    return a; // The return statement is necessary if the function returns something
}

float more_complex(float *p, float a) { // Takes two arguments, a pointer and a float
    *p = a; // dereference p and set the contents to a
    return *p + 1; // return the value pointed to by p, but add 1
}


// A program to introduce basic datatypes
int main(int argc, char** argv) {
    
    //// Code block for declaring integers ////
    {
        char a_i=1;         // Using char as an integer
        short b_i=4;        // 16 bit
        int c_i=2;          // 32 bit          
        unsigned int d_i=3u; // 32 bit
        long e_l = 5L;       // 64 bit
        unsigned long e_ul = 5UL;       // 64 bit
    }

    // This is a comment

    //// Working with characters ////
    {
        char a='s'; // Using char as a character
        char b = a+1; // Arithmetic with characters
        std::printf("b interpreted as an integer: %i\n", b); // print b with the memory interpreted as an integer
        std::printf("b interpreted as a character: %c\n", b); // print b with the memory interpreted as a character
    }
    
    //// Working with floats ////
    {
        // half precision (16-bit), only on some platforms
        //half a=2.0f16;

        // single precision (32-bit)
        float b=2.0f; //or 2.0f32

        // double precision (64-bit)
        double c=2.0; // or 2.0f64

        // quadruple precision (128-bit)
        long double d=2.0l; // or 2.0f128

        // Printing floats
        std::printf("float representation, b = %f c = %f\n", b, c); // Print b and c to the screen as floats

        // Print a float using scientific notation
        std::printf("%e\n", d);
    }

    //// Pointers ////
    {
        int *p;  // Create a pointer to an integer called p
        int a=2; // Create an integer and give it a value of 2
        p = &a;  // Get the address of the integer and assign it to p
        int y = *p; // Access the value pointed to by p and assign to y
        void *v = &a; // Void pointer
        v = NULL; // Set a pointer to NULL for some measure of safety
    }

    //// Functions ////
    {
        // Call a function that doesn't return anything
        simple();

        // Call a function that returns an integer
        int y = 0;
        y = get_int();

        // Calling more_complex
        float a = 1.0f;
        float b = 2.0f;

        float c = more_complex(&b, a);
        std::cout << "Result from more_complex is " << c << "\n";
    
    }

    //// If statements ////
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

    //// For loops ////
    {
        // Demonstrating a 2D for loop

        // initialise loop limits
        int M=3, N=2;

        //   starting condition; continue condition; increment
        for (int m=0; m<M; m++) {
            for (int n=0; n<N; n++) {
                // Execute this code block each time we go around the loop
                std::printf("m is %i, n is %i\n", m, n);
            }
        }
    }
    
    //// Statically allocated arrays ////
    {
        // Create an array of 3 elements
        int a[3]; 

        // Setting values in the array
        a[0]=0;
        a[1]=1;
        a[2]=2;

        // C++-style printing
        std::cout << "Statically allocated array a at index 0 is: " << a[0] << "\n";

        // C-style printing
        std::printf("%d\n", a[2]); // Using indexing operator
        std::printf("%d\n", *(a+2)); // Using pointer arithmetic
    }

    //// Dynamically allocated arrays ////
    {

        // C-style dynamic allocation
        size_t N = 1024;
        float *a = (float*)calloc(N, sizeof(float)); // Allocates memory for 1024 floats
        std::printf("Dynamically allocated array a at index 0 is: %f\n", a[0]);
        free(a); // Free memory when it is no longer needed

        // C++-style dynamic allocation
        a = new float[N];
        std::cout << "Dynamically allocated array a at index 0 is: " << a[0] << "\n";
        delete [] a; // Free memory when it is no longer needed
    }

    //// Demonstrating vectors for safer memory allocations ////
    {
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
    
    //// C strings ////
    {
    
        // Declare a C string
        // The values f, p, and q are just pointers to the first address in the array of characters
        char f[] = "first string"; // String whose contents may be modified
        const char p[] = "second string"; // String whose contents may not be modified
        const char *q = "third string"; // String whose contents may not be modified
    
        // Print the string, this prints all characters up to the null character 
        std::printf("%s\n", p);

        // Print element 0 as a character 
        std::printf("%c\n", p[0]);

        // Making a string from characters, notice that 
        // we have to have a null character '\0' 
        // at the end of the array
        char str[] = {'a', 'b', 'c', 'd', '\0'};
        std::printf("%s\n", str);
    }

    //// C++ strings ////
    {
        
        std::string words = "Hey there!";

        // String concatentation
        std::string morewords = words + " Nice to see you!";

        // Print the string with std::cout
        std::cout << words << "\n";
    
        // Print the size of the string (number of characters in the string)
        std::cout << morewords.size() << "\n";

        // Get a C-style string (string + termination character) from C++ style string
        std::cout << morewords.c_str() << "\n";
    }



}