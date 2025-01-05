#if !defined(BITVECTOR_H)
#define BITVECTOR_H

#include <stdint.h>
#include <stddef.h>

#if !defined(BITVECTOR_SIZE_DEFINED)
#define BITVECTOR_SIZE_DEFINED

#define BITVECTOR_SIZE 64   // Define the size of the bitvector (in bits)

#endif // BITVECTOR_SIZE_DEFINED

typedef struct {
    unsigned long *bits;
    size_t size;             // Size of the bitvector (in bits)
} BitVector;

typedef enum {
    BIT_FALSE = 0,    // Boolean false
    BIT_TRUE = 1,     // Boolean true
    BIT_0 = 0,        // Binary 0
    BIT_1 = 1,        // Binary 1
} Bit;

// Function to create a new bitvector
BitVector* bitvector_create(size_t size);

// Function to set a bit to true (1) at a particular index
void bitvector_set_true(BitVector *bitvector, size_t index);

// Function to set a bit to false (0) at a particular index
void bitvector_set_false(BitVector *bitvector, size_t index);

// Function to set a bit at a particular index
void bitvector_set(BitVector *bitvector, size_t index, Bit value);

// Function to get the value of a bit at a particular index
Bit bitvector_get(BitVector *bitvector, size_t index);

// Function to invert a bit at a particular index
void bitvector_inverse(BitVector *bitvector, size_t index);

// Function to free the bitvector memory
void bitvector_free(BitVector *bitvector);

// Function to print the bitvector to stream
void bitvector_fprint(BitVector *bitvector, FILE *stream);

#endif // BITVECTOR_H
