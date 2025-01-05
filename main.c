#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "bitvector.h"

void test_bitvector() {
    // Create a bitvector of size 32 (using the BITVECTOR_SIZE definition)
    BitVector *bitvector = bitvector_create(BITVECTOR_SIZE);

    // Test setting bits to true (1)
    bitvector_set_true(bitvector, 0);
    bitvector_set_true(bitvector, 5);
    bitvector_set_true(bitvector, 31);

    // Test setting bits to false (0)
    bitvector_set_false(bitvector, 5);
    bitvector_set_false(bitvector, 31);

    // Assert that the bits are set as expected
    assert(bitvector_get(bitvector, 0) == BIT_TRUE);   // Should be 1
    assert(bitvector_get(bitvector, 5) == BIT_FALSE);  // Should be 0
    assert(bitvector_get(bitvector, 31) == BIT_FALSE); // Should be 0

    // Test setting bits using the bitvector_set function
    bitvector_set(bitvector, 5, BIT_TRUE);
    assert(bitvector_get(bitvector, 5) == BIT_TRUE);   // Should be 1

    // Test inverting a bit
    bitvector_inverse(bitvector, 5); // Bit 5 should be inverted to 0
    assert(bitvector_get(bitvector, 5) == BIT_FALSE);  // Should be 0

    // Test freeing the bitvector
    bitvector_free(bitvector);

    printf("All tests passed!\n");
}

int main() {
    test_bitvector();

    return 0;
}
