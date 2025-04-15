#include <stdio.h>
#include <string.h>

struct Person{
    char name[50];
    int year;
    char city[50];
};

void separator(){
    printf("\n");
    for (int i = 0; i < 60; i++){
        printf("=");
    }
    printf("\n\n");
}

int main(){
    FILE *file = fopen("input_file.txt", "r");
    if (file == NULL){
        printf("Error while opening file\n");
        return 1;
    }

    struct Person people[100];
    int count = 0;

    while (fscanf(file, "%s %d %s",
        people[count].name,
        &people[count].year,
        people[count].city) == 3)
    {
            count ++;
    }

    fclose(file);

    char name_for_search[50];

    printf("Type in a Name: ");
    fgets(name_for_search, sizeof(name_for_search), stdin);
    name_for_search[strcspn(name_for_search, "\n")] = '\0';


    for (int i=0; i<count; i++){
        if (strcmp(people[i].name, name_for_search) == 0){
            separator();
            printf("%s is born in year %d and is living in %s\n", 
                people[i].name, 
                people[i].year, 
                people[i].city);
            separator();
                return 0;
        }
    }

    separator();
    printf ("%s isn't found.\n", name_for_search);
    separator();

    return 0;
}