#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 128

void array_copy(size_t* from, size_t* to) {
    for (size_t i = 0; i < ARRAY_LENGTH; i++) {
        to[i] = from[i];
    }
}

void print_array(size_t* array) {
    for (size_t i = 0; i < ARRAY_LENGTH; i++) {
        if (array[i] == 0) printf(".");
        if (array[i] == 1) printf("█");
    }
    printf("\n");
}
int main(int argc, char** argv) {
    size_t init[ARRAY_LENGTH] = {0};
    init[ARRAY_LENGTH - 1] = 1;

    if (argc != 2) {
        printf("Amount of iterations needed...\n");
        return 1;
    }
    int iterations = atoi(argv[1]);
    for (size_t i = 0; i < iterations; i++) {
        print_array(init);
        size_t new[ARRAY_LENGTH] = {0};
        for(size_t j = 1; j < ARRAY_LENGTH; j++) {
            size_t left = (j - 1);
            size_t right = (j + 1) % ARRAY_LENGTH;
            if (init[left] == 1 && init[j] == 1 && init[right] == 1) new[j] = 0; // 111 -> 0
            if (init[left] == 1 && init[j] == 1 && init[right] == 0) new[j] = 1; // 110 -> 1
            if (init[left] == 1 && init[j] == 0 && init[right] == 1) new[j] = 1; // 101 -> 1
            if (init[left] == 1 && init[j] == 0 && init[right] == 0) new[j] = 0; // 100 -> 0
            if (init[left] == 0 && init[j] == 1 && init[right] == 1) new[j] = 1; // 011 -> 1
            if (init[left] == 0 && init[j] == 1 && init[right] == 0) new[j] = 1; // 010 -> 1
            if (init[left] == 0 && init[j] == 0 && init[right] == 1) new[j] = 1; // 001 -> 1
            if (init[left] == 0 && init[j] == 0 && init[right] == 0) new[j] = 0; // 000 -> 0
        }
        array_copy(new, init);
    }
    return 0;
}
