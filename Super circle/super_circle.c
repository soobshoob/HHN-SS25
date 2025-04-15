#include <stdio.h>
#include <math.h>

#define MAX_AMOUNT 100

struct Circle {
    double x;
    double y;
    double radius;
};

int main() {
    FILE *file = fopen("input_file.txt", "r");
    if (file == NULL) {
        printf("Error while opening file\n");
        return 1;
    }

    struct Circle circles[MAX_AMOUNT];
    int count = 0;

    while (fscanf(file, "%lf %lf %lf", 
        &circles[count].x, 
        &circles[count].y, 
        &circles[count].radius) == 3) {
        count++;
        if (count >= MAX_AMOUNT){
            break;
        }
    }

    fclose(file);

    // Use average point as center for simplicity
    double center_x = 0, center_y = 0;
    for (int i = 0; i < count; i++) {
        center_x += circles[i].x;
        center_y += circles[i].y;
    }
    center_x /= count;
    center_y /= count;

    // Now calculate maximum distance to any circle's edge
    double max_distance = 0;
    for (int i = 0; i < count; i++) {
        double dx = circles[i].x - center_x;
        double dy = circles[i].y - center_y;
        double distance = sqrt(dx * dx + dy * dy) + circles[i].radius;
        if (distance > max_distance) {
            max_distance = distance;
        }
    }

    printf("The super circle has center (%.6f, %.6f) and radius %.6f\n", center_x, center_y, max_distance);

    return 0;
}
