// FUNCTION DEFINITIONS
#include "givenA1.h"

/*  TASK 1: Read each line of a1Data.txt into animal struct array starting from position 0. 
Each struct element will have animalName, features, and classLabel  */

int readFromFile (char fName [30], struct Animal dataZoo [NUM_SAMPLES]){

    int line_number = 0;


    // Open file in read mode
    FILE * fPtr;  
    fPtr = fopen(fName, "r");   
    
    // File validation
    if (fPtr == NULL){   
        printf("File no work :( ");
        return -1;
    }
    
    // Loop through file to gather info until eof is reached
    while (!feof (fPtr)){
        
        // Get animal name and store at element line_number of struct array
        fscanf(fPtr, "%s", dataZoo[line_number].animalName);   
        //strcpy(dataZoo[line_number].animalName, name);   // Add name to struct of a specified line number MAY NEED TO USE THIS IF U GET ERROR
        
        // Get animal features
        for (int i = 0; i<NUM_FEATURES; i++){
            fscanf(fPtr, "%d", &dataZoo[line_number].features[i]);   // Loops 16 times to get and populate features
        }

        // Get and store class label
        fscanf(fPtr, "%d", &dataZoo[line_number].classLabel);
        
        line_number++;
    }
    //printf("Populated animals: %s", dataZoo[line_number].animalName);
    fclose(fPtr);
    return 1;
}

/* TASK 2: Calculate euclidean distance, hamming distance, and jaccard similarity*/
void distanceFunctions (int vector1 [NUM_FEATURES], int vector2 [NUM_FEATURES], float * euclideanDistance, int * hammingDistance, float * jaccardSimilarity){
    int tempResult = 0;
    float oneMatch, zeroMatch = 0.0;

    // Calculate euclidean distance
    for (int i=0; i<NUM_FEATURES; i++){
        tempResult = (vector1[i] - vector2[i]);
        tempResult = tempResult * tempResult;
        *euclideanDistance += tempResult;
    }
    *euclideanDistance = sqrt(*euclideanDistance);
    
    // Calculate hamming distance
    for (int i=0; i<NUM_FEATURES; i++){
        if (vector1[i] != vector2[i]){
            (*hammingDistance)++;
        }
    }

    // Calculate Jaccard Similarity
    for (int i=0; i<NUM_FEATURES; i++){
        if (vector1[i] == 1 && vector2[i] == 1){
            oneMatch++;
        }
        else if (vector1[i] == 0 && vector2[i] == 0){
            zeroMatch++;
        }
    }

    if (NUM_FEATURES - zeroMatch > 0){
    *jaccardSimilarity = oneMatch / (NUM_FEATURES - zeroMatch);
    } 
    else{
    *jaccardSimilarity = 0.0; // for the case where all features are 0
    }

}

/* TASK 3: finds the "k" number of closest neighbors in decreasinf or increaseing order depending on the type
of distance function. The indices of the associated samples are saved in knearestneighbors*/
void findKNearestNeighbors (struct Animal dataZoo [NUM_SAMPLES], int newSample [NUM_FEATURES], int k, int whichDistanceFunction, int kNearestNeighbors [NUM_SAMPLES]){
    float sortedArray[NUM_SAMPLES][NUM_SAMPLES];
    for (int i=1; i<NUM_SAMPLES; i++){
        int hammingDistance = 0;
        float euclideanDistance, jaccardSimilarity = 0.0;
        distanceFunctions(newSample, dataZoo[i].features, &euclideanDistance, &hammingDistance, &jaccardSimilarity);
        // If distance function is euclidean or hamming, sort in decreasing order, else, sort in increasing order 
        if (whichDistanceFunction == 1 || whichDistanceFunction == 2){
            
        }

    }
}

//QUESTIONS: why do i start from i=1 in the findknearestneighbors