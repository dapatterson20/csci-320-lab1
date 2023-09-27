/*
 * Implement your solution in thi file
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char* readString(char* fileName);
char* mysteryExplode(const char* str);

char* readString(char* fileName) {
    //const char* filename="test1.txt";
    FILE *inFile=fopen(fileName, "r");
    if (!inFile) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    struct stat sb;
    if (stat(fileName, &sb)==-1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    char *line=malloc(sb.st_size);
    /*
    if (fscanf(inFile, "%[^\n] ", line)!=EOF) {
        printf("%s\n", line);
    }
    */
    fscanf(inFile, "%[^\n] ", line);
    printf("%s\n", line);
    return line;
}

char* mysteryExplode (const char* str) {
    int stringLen=0;
    for (int x=0; str[x]!='\0'; x++) {
        stringLen++;
    }
    int memAmount=1;
    for (int y=0; y<stringLen; y++) {
        memAmount+=y;
    }
    char* finalWord;
    finalWord=(char*)malloc(memAmount*sizeof(int));
    char currentChar='a';
    for (int i=0; str[i]!='\0'; i++) {
        for (int j=0; j<i+1; j++) {
            currentChar=str[j];
            strncat(finalWord, &currentChar, 1);
        }
    }
    printf("%s \n", finalWord);
    return finalWord;
}
