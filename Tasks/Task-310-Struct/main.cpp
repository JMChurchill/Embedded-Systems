#include "mbed.h"
#include <cstdio>
#include <string>
// #include <string>

// Date Type ComplexNumber_C
typedef struct {
  double real;
  double imag;
} ComplexNumber_C;


int main() {
    printf("test\n\n\n");
    //Create instance of a complex number
    ComplexNumber_C p;

    //Initialise each attribute 
    p.real = 2.0;
    p.imag = 3.0;
    
    //Create and Initialise 
    ComplexNumber_C q = {1.0, 1.0};

    // TASK:
    // Create another complex number y
    // Calculate the complex sum of p and q and store in y
    // Use printf to display as a complex number (hint: you need two placeholders)

    ComplexNumber_C y = {(p.real+q.real),(p.imag + q.imag)};
    string strY = to_string(y.imag);
    printf("Y imag: %f\n", y.imag);
    printf("Y real: %f\n", y.real);

    
    while (true) {
    }
}
