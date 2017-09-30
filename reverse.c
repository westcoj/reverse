#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/***************************************************************************
 * Gets user input to define file names and reverses a files content
 * @return either failed or successful attempt
 **************************************************************************/
int main() {
    /** Max number of characters in file name */
    int max = 500;
    /** Names of files to be used */
    char* inName = (char*)malloc(max);
    char* outName = (char*)malloc(max);
    /** Array to hold file data forwards and reverse */
    char* fileData;
    char* fileDataBack;

    //Getting first filename and reading it
    printf("Please enter path and file to be read\n");
    scanf("%s",inName);
    int fileSize = read_file(inName,&fileData);
    //printf(fileData);

    //Unable to get file
    if(fileSize<=0){
        printf("No file found");
        return 0;
    }

    //Reversing the file
    fileDataBack = malloc(fileSize*sizeof(char));
    int i = fileSize;
    int k = 0;
    while(i>=0){
        fileDataBack[k++] = fileData[--i];
    }

    //fileDataBack[fileSize]='\0';
    //free(fileData);
    //int i;
    //for(int i=0;i<fileSize;i++){
    //    fileDataBack[i] = fileData[(fileSize-1)-i];
    //}

    //Set limiter?
    fileDataBack[fileSize] = '\0';
    //read_file(inName,&fileData);
    //printf(fileData[0]);
    //printf("Please enter path and file to be written\n");

    //Get new file name and write to it
    printf("Please enter path and file to be written\n");
    scanf("%s",outName);
    write_file(outName,fileDataBack,fileSize);
    return 0;
}