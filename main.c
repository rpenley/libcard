#include <stdio.h>
#include "libcard.h"

int main() {
    // Test the functions from the library
    my_function();

    int sum = add(3, 5);
    printf("Sum of 3 and 5 is: %d\n", sum);

    double product = multiply(2.5, 4.0);
    printf("Product of 2.5 and 4.0 is: %.2f\n", product);

    return 0;
}

