#include <stdio.h>
#include <string.h>

int counter (char sentence[], const char *separator){
    int number =0;
    char *word = strtok (sentence, separator);
    while (word != NULL){
        number++;
        word = strtok(NULL, separator);
    }
    return number;
}

int main(){
    int number =0;
    char sentence [1000];

    printf("Type in a sentence: \n");
    fgets (sentence, sizeof(sentence), stdin);
    
    const char *separator =" \t\n\v\f\r,.;!?";

    number = counter (sentence, separator);

    if (number == 1){
        printf("The sentence consists of %d word\n", number);
    }
    else {
        printf("The sentence consists of %d words\n", number);
    }

    return 0;
}