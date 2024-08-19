#include "main.h"
#include <stdio.h>
/*#include <time.h>*/

#define max(a, b)                                                                                                      \
    ({                                                                                                                 \
        __typeof__(a) _a = (a);                                                                                        \
        __typeof__(b) _b = (b);                                                                                        \
        _a > _b ? _a : _b;                                                                                             \
    })

int findMax(int *array, int score, int leftIndex, int rightIndex, int count) {
    if (rightIndex - leftIndex > 1) { // 3 or more items.
        int c1 = count;
        int c2 = count;
        int c3 = count;

        int score1 = array[leftIndex] + array[leftIndex + 1];
        if (score1 == score) {
            c1 = findMax(array, score1, leftIndex + 2, rightIndex, count + 1);
        }

        int score2 = array[leftIndex] + array[rightIndex];
        if (score2 == score) {
            c2 = findMax(array, score2, leftIndex + 1, rightIndex - 1, count + 1);
        }

        int score3 = array[rightIndex - 1] + array[rightIndex];
        if (score3 == score) {
            c3 = findMax(array, score3, leftIndex, rightIndex - 2, count + 1);
        }

        return max(c1, max(c2, c3));
    } else if (rightIndex - leftIndex == 1) { // 2 items.
        int tempScore = array[leftIndex] + array[rightIndex];
        if (tempScore == score) {
            return count + 1;
        } else {
            return count;
        }
    } else { // 1 or 0 items.
        return count;
    }
}

int maxOps(int *array, int length) {
    if (length <= 1) {
        return 0;
    }

    int leftIndex = 0;
    int rightIndex = length - 1;

    int score1 = array[leftIndex] + array[leftIndex + 1];
    int score2 = array[leftIndex] + array[rightIndex];
    int score3 = array[rightIndex - 1] + array[rightIndex];

    int max1 = findMax(array, score1, leftIndex + 2, rightIndex, 1);
    int max2 = findMax(array, score2, leftIndex + 1, rightIndex - 1, 1);
    int max3 = findMax(array, score3, leftIndex, rightIndex - 2, 1);

    int retVal = max(max1, max(max2, max3));
    printf("%d\n", retVal);
    return retVal;
}

int main() {
    /*struct timespec start_time, end_time;*/
    /*// Start time*/
    /*clock_gettime(CLOCK_MONOTONIC, &start_time);*/

    int array[] = {3, 2, 1, 2, 3, 4};
    int length = sizeof(array) / sizeof(array[0]);

    maxOps(array, length);

    /*// End time*/
    /*clock_gettime(CLOCK_MONOTONIC, &end_time);*/
    /**/
    /*// Calculate elapsed time in nanoseconds*/
    /*long elapsed_ns = (end_time.tv_sec - start_time.tv_sec) * 1e9 + (end_time.tv_nsec - start_time.tv_nsec);*/
    /*printf("Time: %ld ns\n", elapsed_ns);*/
}

