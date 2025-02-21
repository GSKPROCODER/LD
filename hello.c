#include <stdio.h>

int main() {
    int number, k = 2, i = 2;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Calculate factorial starting from 2
    // k starts at 2 and gets multiplied by each number from 2 up to number
    while (i <= number) {
        k = k * i;    // Multiply k by current number i
        i = i + 1;    // Increment i to move to next number
    }
    
    // Print the final result
    printf("Result: %d\n", k);
    
    return 0;
}


