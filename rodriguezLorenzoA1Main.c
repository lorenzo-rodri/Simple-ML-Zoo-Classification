// Main Program

#include "givenA1.h"

int main(int argc, char *argv[]){

    char fileName[30];
    int result = 0;
    //int hammingDistance = 0;
    //float euclideanDistance, jaccardSimilarity = 0.0;
    struct Animal dataZoo [NUM_SAMPLES];

    strcpy(fileName, argv[1]);

    //TESTING Task 1
    result = readFromFile(fileName, dataZoo);
    printf("%d\n", result);
    printf("%s %d\n", dataZoo[2].animalName, dataZoo[2].classLabel);
    printf("%s\n", dataZoo[3].animalName);
    printf("%s\n", dataZoo[20].animalName);
    int k = 5;
    int whichDistanceFunction = 1;
    /*
    //TESTING Task 2
    distanceFunctions(dataZoo[0].features, dataZoo[1].features, &euclideanDistance, &hammingDistance, &jaccardSimilarity);
    printf("euc: %.2f\nham: %d\njac: %.2f", euclideanDistance, hammingDistance, jaccardSimilarity);

    //TESTING Task 3
    int kNearestNeighbors [NUM_SAMPLES];
    int newSample [NUM_FEATURES] = {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1};
    
    findKNearestNeighbors(dataZoo, newSample, k, whichDistanceFunction, kNearestNeighbors);
    for (int i=0;i<k; i++){
        printf("\n%d ", kNearestNeighbors[i]);
    }

    // TESTING Task 4
    int predictedClass;
    predictedClass = predictClass(dataZoo, newSample, whichDistanceFunction, k);
    printf("\n%d", predictedClass);
    */
    // Task 5
    // Hardcoded csv
    struct Animal testData[NUM_TEST_DATA] = {
    {"calf", {1,0,0,1,0,0,0,1,1,1,0,0,4,1,1,1}, 1},
    {"cheetah", {1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1}, 1},
    {"crab", {0,0,1,0,0,1,1,0,0,0,0,0,4,0,0,0}, 7},
    {"dogfish", {0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,1}, 4},
    {"elephant", {1,0,0,1,0,0,0,1,1,1,0,0,4,1,0,1}, 1},
    {"flamingo", {0,1,1,0,1,0,0,0,1,1,0,0,2,1,0,1}, 2},
    {"fruitbat", {1,0,0,1,1,0,0,1,1,1,0,0,2,1,0,0}, 1},  
    {"gnat", {0,0,1,0,1,0,0,0,0,1,0,0,6,0,0,0}, 6}, 
    {"gorilla", {1,0,0,1,0,0,0,1,1,1,0,0,2,0,0,1}, 1},  
    {"haddock", {0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0}, 4},
    {"sealion", {1,0,0,1,0,1,1,1,1,1,0,1,2,1,0,1}, 1},
    {"seasnake", {0,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0}, 3},
    {"seawasp", {0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0}, 7},
    {"skimmer", {0,1,1,0,1,1,1,0,1,1,0,0,2,1,0,0}, 2},
    {"skua", {0,1,1,0,1,1,1,0,1,1,0,0,2,1,0,0}, 2},
    {"slowworm", {0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0}, 3},
    {"slug", {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0}, 7},
    {"sole", {0,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0}, 4},
    {"sparrow", {0,1,1,0,1,0,0,0,1,1,0,0,2,1,0,0}, 2},
    {"squirrel", {1,0,0,1,0,0,0,1,1,1,0,0,2,1,0,0}, 1}  
    };
    float accuracy = 0.0;

    accuracy = findAccuracy(dataZoo, whichDistanceFunction, testData, k);
    printf("\nAccuracy: %f", accuracy);
    return 0;
}

