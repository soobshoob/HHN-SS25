#include <stdio.h>
#include <string.h>

// Display the horizontal line separating the matrices
void line() {
    printf("\n");
    for (int i=0; i<60; i++) {
        printf("=");
    }
    printf("\n\n");
}


void definer (char sentence[], const char *separator,char result[]){
    char *word = strtok (sentence, separator);
    if ( word == NULL){
        result[0]='\0'; //empty
        return;
    }

    strcpy (result, word);
    int max_len = strlen(word);

    while ((word = strtok (NULL, separator))!= NULL){
        int len = strlen(word);
        if (len > max_len){
            max_len = len;
            strcpy(result, word);
        }
    }
}

int main(){
    char sentence [1000], longest[1000];

    printf("Type in a sentence: \n");
    fgets (sentence, sizeof(sentence), stdin);
    
    const char *separator =" \t\n\v\f\r,.;!?";

    definer (sentence, separator, longest);

    line();

    if (strlen(longest)>0){
        printf("The longest word is %s\n", longest);
    }
    else {
        printf("No words found.\n");
    }

    line();
    
    return 0;
}