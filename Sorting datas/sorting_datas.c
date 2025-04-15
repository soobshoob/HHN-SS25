#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 100

struct Birthday {
    int day;
    int month;
    int year;
};

struct Person {
    char name[50];
    char city[50];
    struct Birthday date_of_birth;
};

void separator() {
    printf("\n");
    for (int i = 0; i < 60; i++) {
        printf("=");
    }
    printf("\n\n");
}

int is_older(struct Person a, struct Person b) {
    if (a.date_of_birth.year != b.date_of_birth.year){
        return a.date_of_birth.year < b.date_of_birth.year;
    }
    if (a.date_of_birth.month != b.date_of_birth.month){
        return a.date_of_birth.month < b.date_of_birth.month;
    }
    return a.date_of_birth.day < b.date_of_birth.day;
}

void swap(struct Person* a, struct Person* b) {
    struct Person temp = *a;
    *a = *b;
    *b = temp;
}

void sort_people(struct Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (!is_older(people[j], people[j + 1])) {
                swap(&people[j], &people[j + 1]);
            }
        }
    }
}

int load_people(const char* filename, struct Person people[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error while opening file\n");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%d %d %d %s %s",
        &people[count].date_of_birth.day,
        &people[count].date_of_birth.month,
        &people[count].date_of_birth.year,
        people[count].name,
        people[count].city) == 5)
    {
        count++;
        if (count >= MAX_PEOPLE) break;
    }

    fclose(file);
    return count;
}

void print_people(struct Person people[], int count) {
    separator();
    for (int i = 0; i < count; i++) {
        printf("%02d.%02d.%04d: %s, %s\n",
            people[i].date_of_birth.day,
            people[i].date_of_birth.month,
            people[i].date_of_birth.year,
            people[i].name,
            people[i].city);
    }
    separator();
}

int main() {
    struct Person people[MAX_PEOPLE];

    int count = load_people("input_file.txt", people);
    if (count < 0){
        return 1;
    }

    sort_people(people, count);
    print_people(people, count);

    return 0;
}
