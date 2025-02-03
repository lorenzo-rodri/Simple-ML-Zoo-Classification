// Main Program

#include "givenA1.h"

int main(int argc, char *argv[]){

    
    char fileName[30];
    int result = 0;
    int choice = 1;
    int vector1[NUM_FEATURES] = {1,1,1,0,1,0,1,1,1,0,0,0,0,1,1,1};
    int vector2[NUM_FEATURES] = {1,0,0,1,0,0,1,1,1,1,0,0,4,0,0,1};
    int newSample[NUM_FEATURES] = {1,1,1,0,1,0,1,1,1,0,0,0,0,1,1,1};
    float euclideanDistance = 0.0;
    int hammingDistance = 0;
    float jaccardSimilarity = 0;
    int kNearestNeighbors [NUM_SAMPLES];
    float accuracy = 0.0;
    
    struct Animal dataZoo [NUM_SAMPLES];

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

    strcpy(fileName, argv[1]);

    while ((choice > 0) && (choice < 6)){
    printf("\nHere is the menu - enter a number between 1 and 5\n\nEnter your choice: ");
    scanf("%d", &choice);
        switch (choice){
            case 1:
                result = readFromFile(fileName, dataZoo);
                if (result == -1){
                    printf("Unsuccessfull read from file.");
                }
                else{
                    for (int i=0; i<NUM_SAMPLES; i++){
                        printf("\n%s ", dataZoo[i].animalName);
                        for (int j=0; j<NUM_FEATURES; j++){
                            printf("%d ", dataZoo[i].features[j]);
                        }
                        printf("%d ", dataZoo[i].classLabel);
                        
                    }
                }
                printf("\n");
                break;

            case 2:
                distanceFunctions(vector1, vector2, &euclideanDistance, &hammingDistance, &jaccardSimilarity);
                printf("\nEuclidean Distance: %f\nHamming Distance: %d\nJaccard Similarity: %f", euclideanDistance, hammingDistance, jaccardSimilarity);
                break;

            case 3: 
                findKNearestNeighbors(dataZoo, newSample, 5, 1, kNearestNeighbors);
                printf("\nNearest neighbors for new sample with Euclidean Distance: ");
                for (int i=0; i<5; i++){
                    printf("%d ", kNearestNeighbors[i]);
                }
                findKNearestNeighbors(dataZoo, newSample, 5, 2, kNearestNeighbors);
                printf("\nNearest neighbors for new sample with Hamming Distance: ");
                for (int i=0; i<5; i++){
                    printf("%d ", kNearestNeighbors[i]);
                }
                findKNearestNeighbors(dataZoo, newSample, 5, 3, kNearestNeighbors);
                printf("\nNearest neighbors for new sample with Jaccard Similarity: ");
                for (int i=0; i<5; i++){
                    printf("%d \n", kNearestNeighbors[i]);
                }
                break;
            case 4:
                printf("\nThe predicted class is: %d\n", predictClass(dataZoo, newSample, 1, 5));
                printf("\nThe predicted class is: %d\n", predictClass(dataZoo, newSample, 2, 5));
                printf("\nThe predicted class is: %d\n", predictClass(dataZoo, newSample, 3, 5));
                break;
            case 5: 
                accuracy = findAccuracy(dataZoo, 1, testData, 5);
                printf("\nThe accuracy for the test data is %f\n");
                accuracy = findAccuracy(dataZoo, 2, testData, 5);
                printf("\nThe accuracy for the test data is %f\n");
                accuracy = findAccuracy(dataZoo, 3, testData, 5);
                printf("\nThe accuracy for the test data is %f\n");
                break;
        }
    }
    
   
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
    /*
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
    //float accuracy = 0.0;
    */
    //accuracy = findAccuracy(dataZoo, whichDistanceFunction, testData, k);
    //printf("\nAccuracy: %f", accuracy);

    
    return 0;
}

