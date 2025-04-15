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

void replace_word(char *sentence, const char *old_word, const char *new_word) {
    char result[1000] = "";
    char *token = strtok(sentence, " \t\n\v\f\r,.;!?");
    
    while (token != NULL) {
        if (strcasecmp(token, old_word) == 0) {
            strcat(result, new_word);
        } else {
            strcat(result, token);  
        }

        char *next_char = sentence + (token - sentence) + strlen(token);
        while (*next_char != '\0' && strchr(" \t\n\v\f\r,.;!?\"'", *next_char) != NULL) {
            strncat(result, next_char, 1);
            next_char++;
        }

        strcat(result, " ");
        
        token = strtok(NULL, " \t\n\v\f\r,.;!?");
    }

    printf("The target sentence is: %s\n", result);
}

int main() {
    char sentence[1000];
    char old_word[100], new_word[100];

    printf("Enter the source sentence: \n");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; 

    printf("Enter the word to be replaced: \n");
    fgets(old_word, sizeof(old_word), stdin);
    old_word[strcspn(old_word, "\n")] = '\0';

    printf("Enter the replacement word: \n");
    fgets(new_word, sizeof(new_word), stdin);
    new_word[strcspn(new_word, "\n")] = '\0';

    replace_word(sentence, old_word, new_word);

    return 0;
}
