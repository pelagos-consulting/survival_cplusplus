#include <cstdio>
#include <iostream>

// Helper routines to work with matrices
#include "mat_helper.hpp"

// Get the size of the matrices
#include "mat_size.hpp"

// Function to compute the square of two numbers
float square(int x, int y) {
    return (float)x * (float)y;
}

// Main program
int main(int argc, char** argv) {
        
    //// Begin Exercise 1 ////
    
    // The constants NROWS_C and NCOLS_C were defined in the file mat_size.hpp
    size_t N0_C=NROWS_C;
    size_t N1_C=NCOLS_C;

    // Make up strides for multi-dimensional indexing, use row-major ordering
    int s0 = N1_C;
    int s1 = 1;

    // Make up array and fill it using nested for loops
    float *arr = (float*)calloc((size_t)(N0_C*N1_C), sizeof(float));

    for (int i0=0; i0 < N0_C; i0++) {
        for (int i1=0; i1 < N1_C; i1++) {
            // Use the dot product to make up the position in the allocation
            int offset = i0*s0 + i1*s1;
    
            // Fill the allocation at offset by calling a function
            arr[offset] = square(i0, i1);
        }
    }

    // Pretty-print the array
    // using a function called m_show_matrix
    std::cout << "The computed solution (arr) is\n";    
    m_show_matrix(arr, (size_t)N0_C, (size_t)N1_C);

    // Write the array to disk
    const char *fname = "image.dat";
    FILE *fp = fopen(fname, "wb");

    // Sanity check using an "if" statement
    if (fp != NULL) {
        std::fwrite(arr, sizeof(float), (size_t)(N0_C*N1_C), fp);
    } else {
        std::printf("File %s could not be opened\n", fname);
    }

    // Close the file and free the array
    std::fclose(fp);
    free(arr);
    
    //// End exercise 1 ////
}
