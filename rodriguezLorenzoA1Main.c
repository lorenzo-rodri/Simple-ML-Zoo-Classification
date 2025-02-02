// Main Program

#include "givenA1.h"

int main(int argc, char *argv[]){

    char fileName[30];
    int result, hammingDistance = 0;
    float euclideanDistance, jaccardSimilarity = 0.0;
    struct Animal dataZoo [NUM_SAMPLES];

    strcpy(fileName, argv[1]);

    //TESTING Task 1
    result = readFromFile(fileName, dataZoo);
    printf("%d\n", result);
    printf("%s\n", dataZoo[0].animalName);
    printf("%s\n", dataZoo[3].animalName);
    printf("%s\n", dataZoo[20].animalName);

    //TESTING Task 2
    distanceFunctions(dataZoo[0].features, dataZoo[1].features, &euclideanDistance, &hammingDistance, &jaccardSimilarity);
    printf("euc: %.2f\nham: %d\njac: %.2f", euclideanDistance, hammingDistance, jaccardSimilarity);

    //TESTING Task 3
    int kNearestNeighbors [NUM_SAMPLES];
    int newSample [NUM_FEATURES] = {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1};
    int k = 5;
    int whichDistanceFunction = 3;
    findKNearestNeighbors(dataZoo, newSample, k, whichDistanceFunction, kNearestNeighbors);
    for (int i=0;i<k; i++){
        printf("\n%d ", kNearestNeighbors[i]);
    }

    // TESTING Task 4
    int predictedClass;
    predictedClass = predictClass(dataZoo, newSample, whichDistanceFunction, k);
    printf("\n%d", predictedClass);
    return 0;
}

