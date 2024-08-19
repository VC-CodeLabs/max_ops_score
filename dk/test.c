#include "main.h"
#include <criterion/criterion.h>

Test(MaxOps, maxOps1) {
    int array[] = {1, 1, 1, 1, 1, 1};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxOps2) {
    int array[] = {3, 2, 1, 2, 3, 4};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxOps3) {
    int array[] = {3, 2, 6, 1, 4};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 2);
}

Test(MaxOps, maxIt_basic_test) {
    int array[] = {3, 2, 1, 2, 3, 4};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxIt_no_operations_test) {
    int array[] = {1, 1, 1};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 1);
}

Test(MaxOps, maxIt_single_operation_test) {
    int array[] = {2, 2};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 1);
}

Test(MaxOps, maxIt_two_operations_test) {
    int array[] = {3, 2, 6, 1, 4};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 2);
}

Test(MaxOps, maxIt_large_identical_values_test) {
    int array[] = {10, 10, 10, 10};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 2);
}

Test(MaxOps, maxIt_mixed_values_test) {
    int array[] = {1, 3, 2, 5, 4, 6};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxIt_large_array_test) {
    int array[2000];
    for (int i = 0; i < 2000; ++i) {
        array[i] = i % 1000 + 1;
    }
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 1000);
}

Test(MaxOps, maxIt_alternating_values_test) {
    int array[] = {1, 1000, 1, 1000, 1, 1000};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxIt_all_same_values_test) {
    int array[] = {5, 5, 5, 5};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 2);
}

Test(MaxOps, maxIt_descending_values_test) {
    int array[] = {6, 5, 4, 3, 2, 1};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxIt_single_element_left_test) {
    int array[] = {2, 3, 4, 2};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 1);
}

Test(MaxOps, maxIt_no_possible_operations_test) {
    int array[] = {5};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 0);
}

Test(MaxOps, maxIt_large_sum_test) {
    int array[] = {1000, 999, 998, 1000, 999, 998};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxIt_minimal_sum_test) {
    int array[] = {1, 1, 1, 1};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 2);
}

Test(MaxOps, maxIt_alternating_high_low_test) {
    int array[] = {10, 1, 10, 1, 10, 1};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxIt_large_gaps_test) {
    int array[] = {1000, 1, 1000, 1, 1000, 1};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxIt_small_gaps_test) {
    int array[] = {2, 1, 2, 1, 2, 1};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

Test(MaxOps, maxIt_edge_case_test) {
    int array[] = {1, 2};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 1);
}

Test(MaxOps, maxIt_random_test) {
    int array[] = {7, 3, 4, 1, 9, 8, 6, 5};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 1);
}

Test(MaxOps, maxIt_large_random_test) {
    int array[2000];
    for (int i = 0; i < 2000; ++i) {
        array[i] = rand() % 1000 + 1;
    }
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert(result >= 1);
}

Test(MaxOps, maxIt_almost_identical_values_test) {
    int array[] = {5, 4, 5, 4, 5, 4};
    int length = sizeof(array) / sizeof(array[0]);
    int result = maxOps(array, length);

    cr_assert_eq(result, 3);
}

