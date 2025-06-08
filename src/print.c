#include "types.h"
#include <stdio.h>

#ifdef AMD64
    // 64-bit pointer size in hex
    #define PTR_SIZE    (16)
#elif defined(X86)
    // 32-bit pointer size in hex
    #define PTR_SIZE    (8)
#else
    #error "Unsupported architecture."
#endif

void printb(const void *buf, size_t len)
{
    const unsigned char *c = buf;

    // print the column offset
    for (int i = 0; i < PTR_SIZE + 2; i++)
    {
        printf(" ");
    }

    // print the header for the hex dump
    for (int i = 0; i < 16; i++)
    {
        if (i && (i % 16 == 0))
        {
            printf("\n");
        }
        else if (i && (i % 8 == 0))
        {
            printf("  ");
        }
        printf("%2x ", i);
    }
    printf("\n");

    for (size_t i = 0; i < len; i++)
    {
        if (i && (i % 16 == 0))
        {
            printf("\n");
        }
        else if (i && (i % 8 == 0))
        {
            printf("  ");
        }

        // print the address at the start of each line
        if (i % 16 == 0)
        {
            printf("%8p: ", (byte *)buf + i);
        }

        // print the byte in hex format
        printf("%02x ", c[i]);
    }
    printf("\n");
}

void print_test()
{
    const char test_str[] = "The quick brown fox jumps over the lazy dog.";

    printf("Test string: %s\n", test_str);
    printf("Hex dump of the test string:\n");
    printb(test_str, sizeof(test_str));
    printf("End of print_test function.\n");
}
