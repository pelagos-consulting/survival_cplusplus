#include <cstdio>
#include <iostream>

// Helper routines to work with matrices
#include "mat_helper.hpp"

// Get the size of the matrices
#include "mat_size.hpp"

typedef float_type float;

// C++ function to fill an allocation 
// with the 
void fill(
    // pointer to allocation
    float_type* A, 
    // position along dimension 0
    int i0, 
    // position along dimension 1
    int i1, 
    // size of array along dimension 0
    size_t N0, 
    // size of array along dimension 1
    size_t N1) {

    // Guard clause to make sure we don't go over the end of the array
    if ((i0<N0) && (i1<N1)) {
        // Compute the offset into A as a function of i0 and i1, 
        // you may use either row-major or column major indexing

        // offset for row-major
        size_t offset = i0*n1 + i1;

        // offset for column-major
        //size_t offset = i0 + i1*n0;
        
        // Fill A at the calculated offset with i0*i1
        A[offset] = i0*i1;
    }
}

// Main program
int main(int argc, char** argv) {
        
    //// Begin Exercise 1 ////
    
    // The constants NROWS_C and NCOLS_C were defined in the file mat_size.hpp
    size_t N0=NROWS_C;
    size_t N1=NCOLS_C;

    // Make up array and fill it using nested for loops
    float *arr = (float*)calloc((size_t)(N0*N1), sizeof(float));

    for (int i0=0; i0<N0; i0++) {
        for (int i1=0; i1<N1; i1++) {
            fill(arr, i0, i1, N0, N1);    
        }
    }

    // Pretty-print the array
    // using a function called m_show_matrix
    std::cout << "The computed solution (arr) is\n";    
    m_show_matrix(arr, (size_t)N0, (size_t)N1);

    // Write the array to disk
    const char *fname = "image.dat";
    FILE *fp = fopen(fname, "wb");

    // Sanity check using an "if" statement
    if (fp != NULL) {
        std::fwrite(arr, sizeof(float), (size_t)(N0*N1), fp);
    } else {
        std::printf("File %s could not be opened\n", fname);
    }

    // Close the file and free the array
    std::fclose(fp);
    free(arr);
    
    //// End exercise 1 ////
}
