// Main Program

#include "givenA1.h"

int main(){

    int result, hammingDistance = 0;
    float euclideanDistance, jaccardSimilarity = 0.0;
    struct Animal dataZoo [NUM_SAMPLES];

    //TESTING Task 1
    result = readFromFile("a1Data.txt", dataZoo);
    printf("%d\n", result);
    printf("%s\n", dataZoo[0].animalName);
    printf("%s\n", dataZoo[3].animalName);
    printf("%s\n", dataZoo[20].animalName);

    //TESTING Task 2
    distanceFunctions(dataZoo[0].features, dataZoo[1].features, &euclideanDistance, &hammingDistance, &jaccardSimilarity);
    printf("euc: %.2f\nham: %d\njac: %.2f", euclideanDistance, hammingDistance, jaccardSimilarity);

    return 0;
}

//aardvark 1 0 0 1 0 0 1 1 1 1 0 0 4 0 0 1 1
//antelope 1 0 0 1 0 0 0 1 1 1 0 0 4 1 0 1 1