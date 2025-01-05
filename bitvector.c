#include <stdio.h>
#include <stdlib.h>

#include "bitvector.h"

// Function to create a new bitvector
BitVector* bitvector_create(size_t size) {
    BitVector *bitvector = (BitVector*)malloc(sizeof(BitVector));
    bitvector->size = size;
    bitvector->bits = (unsigned long*)calloc((size / (sizeof(unsigned long) * 8)) + 1, sizeof(unsigned long)); // Allocate enough space
    return bitvector;
}

// Function to set a bit to true (1) at a particular index
void bitvector_set_true(BitVector *bitvector, size_t index) {
    if (index >= bitvector->size) {
        fprintf(stderr, "Index out of bounds!\n");
        return;
    }
    bitvector->bits[index / (sizeof(unsigned long) * 8)] |= (1UL << (index % (sizeof(unsigned long) * 8)));
}

// Function to set a bit to false (0) at a particular index
void bitvector_set_false(BitVector *bitvector, size_t index) {
    if (index >= bitvector->size) {
        fprintf(stderr, "Index out of bounds!\n");
        return;
    }
    bitvector->bits[index / (sizeof(unsigned long) * 8)] &= ~(1UL << (index % (sizeof(unsigned long) * 8)));
}

// Function to set a bit at a particular index
void bitvector_set(BitVector *bitvector, size_t index, Bit value) {
    if (index >= bitvector->size) {
        fprintf(stderr, "Index out of bounds!\n");
        return;
    }
    switch (value)
    {
    case 0:
        bitvector_set_false(bitvector, index);
        break;
    case 1:
        bitvector_set_true(bitvector, index);
        break;
    default:
        fprintf(stderr, "Range error: The value can only be 0 or 1, but not %d\n", value);
        break;
    }
}

// Function to get the value of a bit at a particular index
Bit bitvector_get(BitVector *bitvector, size_t index) {
    if (index >= bitvector->size) {
        fprintf(stderr, "Index out of bounds!\n");
        return -1;  // Return an invalid value if out of bounds
    }
    return (bitvector->bits[index / (sizeof(unsigned long) * 8)] >> (index % (sizeof(unsigned long) * 8))) & 1;
}

// Function to invert a bit at a particular index
void bitvector_inverse(BitVector *bitvector, size_t index) {
    if (index >= bitvector->size) {
        fprintf(stderr, "Index out of bounds!\n");
        return;
    }
    bitvector->bits[index / (sizeof(unsigned long) * 8)] ^= (1UL << (index % (sizeof(unsigned long) * 8)));
}

// Function to free the bitvector memory
void bitvector_free(BitVector *bitvector) {
    free(bitvector->bits);
    free(bitvector);
}

// Function to print the bitvector to stream
void bitvector_fprint(BitVector *bitvector, FILE *stream) {
    fprintf(stdout, "\033[42mB: b b b b b b b b\033[0m\n");

    size_t bytes = 0;
    for (size_t i = 0; i < bitvector->size; i++) {
        // Optionally, add a newline after every 8 bits for readability
        if (i % 8 == 0) {
            bytes++;
            fprintf(stream, "%zu: ", bytes);
        }

        // Print the index in decimal followed by a dot and the bit value
        fprintf(stream, "%d ", bitvector_get(bitvector, i));
        
        // Optionally, add a newline after every 8 bits for readability
        if (i % 8 == 7) {
            fprintf(stream, "\n");
        }
    }
    // Ensure the final newline if no 8-bit grouping
    if (bitvector->size % 8 != 0) {
        fprintf(stream, "\n");
    }
}