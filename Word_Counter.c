#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

// declaring all functions
void toLowerCase(char *);
void stripPunctuations(char *);
char *readFile(const char *);
char *replaceNewLines(char *);

// defining macros
#define MAX_ENTRIES 1000
#define MAX_WORD_LENGTH 50

// defining structures
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Dict;

// sorting the dictionary
void quickSort(Dict *, int, int);
int partition(Dict *, int, int);

// main function
int main(){

    // reading file from location
    char *file = readFile("AI For Space Transportation.txt");
    
    // replacing new lines with spaces
    char *text = replaceNewLines(file );

    // lower case
    toLowerCase(text);

    // strip punctuations
    stripPunctuations(text);

    // defining dictionary size
    Dict Word[MAX_ENTRIES];

    // token and delimiter
    char *token;
    char delimiter[] = " ";

    // tokenizing the string
    token = strtok(text, delimiter);

    // counting total words from the entire string
    int word_count = 0;

    // iterating for each token
    while (token) {

        // flags if words already exists in dictionary
        int word_exists = 0;

        // increase count of words that are already in the dictionary
        for (int i = 0; i < word_count; i++) {
            if (strcmp(Word[i].word, token) == 0) {
                Word[i].count++;
                word_exists = 1;
                break;
            }
        }

        // make new dictionary entries for words with count = 1
        if (!word_exists) {

            // add only if max limit not reached
            if (word_count < MAX_ENTRIES) {
                strcpy(Word[word_count].word, token);
                Word[word_count].count = 1;
                word_count++;
            } else {

                // stop if max limit has reached
                printf("MAX WORDS REACHED! Increase word count limit.\n");
                break;
            }
        }

        // next word
        token = strtok(NULL, delimiter);
    }

    // sorting the words in descending order of count
    quickSort(Word, 0, word_count - 1);

    // printing words and total counts
    printf("------------\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", Word[i].word, Word[i].count);
    }
    printf("------------\n");
    printf("Total Unique Words: %d\n", word_count);
    return 0;
}

// function to convert all letters to lower case
void toLowerCase(char *str){
    int i = 0;

    while(str[i] != '\0'){
        str[i] = tolower(str[i]);
        i++;
    }
}

// function to strip off all punctution marks
void stripPunctuations(char *str) {
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        // If the current character is not a punctuation mark, keep it
        if (!ispunct(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }

    // adding null terminator to the end of the modified string
    str[j] = '\0';
}

// reading contents of file
char *readFile(const char *filename) {
    FILE *file;
    char *text = NULL;
    int ch;
    long size = 0;

    // opening the file in read mode
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // determining the size of the file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    // allocating memory to hold the file contents
    text = (char *)malloc(size + 1); // allocating extra byte for null terminator

    if (text == NULL) {
        fclose(file);
        perror("Error allocating memory");
        return NULL;
    }

    // reading the file character by character and store in text
    int i = 0;
    while ((ch = fgetc(file)) != EOF) {
        text[i++] = (char)ch;
    }

    // Null-terminate the string
    text[i] = '\0';

    // closing the file
    fclose(file);

    return text;
}

// replacing newline characters with spaces
char *replaceNewLines(char *text) {
    int i = 0;
    while (text[i]) {
        if (text[i] == '\n') {
            text[i] = ' ';
        }
        i++;
    }
    return text;
}

// quicksort helper function
void quickSort(Dict *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// sorting the dictionary
int partition(Dict *arr, int low, int high) {
    int pivot;
    pivot = arr[high].count;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].count > pivot) {
            i++;
            Dict temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Dict temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
