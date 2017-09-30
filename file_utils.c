#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"




/***************************************************************************
 * Reads a user input to get a file and puts data from that file into a
 * buffer.
 * @param filename user input for file to be read
 * @param buffer array that will be holding file data
 * @return either the bytes read or a failed file read
 **************************************************************************/
int read_file(char* filename, char **buffer){
//char loc[17]= "C:\\Reverse\\read\\";

    FILE *in=fopen(filename,"r");

    //No file
    if(in==NULL){
        fprintf(stderr,"No file to read");
        return -1;
    }

    //Get file size
    fseek(in,0,SEEK_END);
    int sizeOf = ftell(in)+1;
    fseek(in,0,SEEK_SET);

    *buffer = (char*)malloc(sizeOf*sizeof(char));

    //int check = fread(*buffer,sizeof(char),(size_t)sizeOf,in);

    //Reads excess but attempts to stop on cause crashes?
    //Junk is not written to new file though
    size_t check = fread(*buffer,1,(size_t)sizeOf,in);
    //buffer[check+1] = '\0';

    //while((i = fgetc(in))!= EOF){
        //buffer[n++]= (char*)fgetc(in);
        //n++;
        //printf("%c",(char)i);
    //}

    fclose(in);
    return check;
}

/***************************************************************************
 * Gets user input for a name for a new file. The reads data from a buffer
 * into that file.
 * @param filename User input to create new file
 * @param buffer Array that holds reversed data
 * @param size bytes to be put into file
 * @return Succesful write or failed attempt.
 **************************************************************************/
int write_file(char* filename, char *buffer, int size){
    int k=size;
    FILE *out=fopen(filename,"w");

    //Error with new file
    if(out==NULL){
        fprintf(stderr,"How even?");
        return 0;
    }

    //catch empty?
    if(k==0){
        fprintf(stderr,"No data listed");
        return 0;
    }

    //fwrite(buffer, sizeof(char),(size_t)n,out);
    //for(int i=0; i<n;i++){
     //   fprintf(out, "%c",*(buffer+i));
    //}

    //fputs(buffer,out);
    //fclose(out);

    //return 0;

    //Write data from buffer to file, removes junk
    for (int i = 0; i < k; i++) {
        fwrite(buffer + i, sizeof(char), 1, out);
    }

    //fwrite(buffer,(size_t)k,1,out);

    fclose(out);
    free(buffer);
    return 0;
}