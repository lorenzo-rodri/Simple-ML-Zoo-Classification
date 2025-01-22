// Main Program

#include "givenA1.h"

int main(){

    int result;
    struct Animal dataZoo [NUM_SAMPLES];

    result = readFromFile("a1Data.txt", &dataZoo[NUM_SAMPLES]);

    printf("%d", result);
    printf("%s", dataZoo[0]);

    return 0;
}