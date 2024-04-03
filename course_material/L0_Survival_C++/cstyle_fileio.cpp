#include <cstdio>
#include <cstdlib>
#include <iostream>

int main() {

    // Define the size of the array
    int N=5;
    const char *fname = "filename.dat";

    // Fill the array
    float* src = (float*)calloc(N, sizeof(float));
    for (int n=0; n<N; n++) {
        src[n] = (float)n;
    }

    // Open the file and write the array to it
    std::FILE *fp = std::fopen(fname, "wb");
    std::fwrite(src, sizeof(float), (size_t)N, fp);

    // free the source array and close the file
    std::fclose(fp);
    free(src);

    // Open the file for reading
    fp = std::fopen(fname, "rb");

    // Get the number of bytes in the file
    std::fseek(fp, 0, SEEK_END); // Zero offset relative to the end
    long int nbytes = std::ftell(fp);

    // Number of elements in an array
    long int nelements = nbytes/sizeof(float);

    // Allocate and read from the file
    float *dst = (float*)calloc(nelements, sizeof(float));
    std::fread(dst, sizeof(float), nelements, fp);

    // Free the destination array and close the file
    free(dst);
    std::fclose(fp);

}