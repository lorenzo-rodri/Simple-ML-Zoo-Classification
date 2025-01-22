// FUNCTION DEFINITIONS
#include "givenA1.h"

/*  TASK 1: Read each line of a1Data.txt into animal struct array starting from position 0. 
Each struct element will have animalName, features, and classLabel  */
//MAY NEED TO CHANGE TO -> NOTATION???
int readFromFile (char fName [30], struct Animal dataZoo [NUM_SAMPLES]){

    char name [MAX_LENGTH_ANIMAL_NAME];
    int line_number;

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
            fscanf(fPtr, "%d", dataZoo[line_number].features[i]);   // Loops 16 times to get and populate features
        }

        // Get and store class label
        fscanf(fPtr, "%d", dataZoo[line_number].classLabel);

        line_number++;
    }
    
    fclose(fPtr);
    return 1;
}
