// Main Program

#include "givenA1.h"

int main(){

    int result;
    struct Animal dataZoo [NUM_SAMPLES];

    result = readFromFile("a1Data.txt", dataZoo);

    //PRINTS FOR TESTING
    printf("%d", result);
    printf("%s\n", dataZoo[0].animalName);
    printf("%s\n", dataZoo[3].animalName);
    printf("%s\n", dataZoo[20].animalName);
    

    return 0;
}