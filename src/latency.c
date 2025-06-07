#include <stdio.h>
#include <stdint.h>

// Count Leading Zeros (CLZ) function
// This function counts the number of leading zeros in a 32-bit integer.
int clz(int x)
{
    if (x == 0)
    {
        return 32;    // Handle zero case
    }
    int count = 0;
    while (((uint32_t)x & (1 << 31)) == 0)
    {
        count++;
        x <<= 1;
    }
    return count;
}

#define max(a, b)   ((a) > (b) ? (a) : (b))

int udiv_latency(int a, int b)
{
    if (b == 0)
    {
        return 3;
    }
    printf("clz(%d)=%d clz(%d)=%d\n", a, clz(a), b, clz(b));
    return 3 + max((clz(b) - clz(a) + 1) / 2, 0);
}

int sdiv_latency(int a, int b)
{
    if (b == 0)
    {
        return 4;
    }
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }
    printf("clz(%d)=%d clz(%d)=%d\n", a, clz(a), b, clz(b));
    return 4 + max((clz(b) - clz(a) + 1) / 2, 0);
}

void div_latency_calculation()
{
    int x;
    x = 0;
    printf("clz(%d) = %d\n", x, clz(x)); // Expect 32
    x = 1;
    printf("clz(%d) = %d\n", x, clz(x));
    x = 2;
    printf("clz(%d) = %d\n", x, clz(x));
    x = 0x7fffffff;
    printf("clz(%d) = %d\n", x, clz(x));
    x = 0x80000000;
    printf("clz(%d) = %d\n", x, clz(x));
    x = ~0;
    printf("clz(%d) = %d\n", x, clz(x));
    x = -1;
    printf("clz(%d) = %d\n", x, clz(x));
    x = -2;
    printf("clz(%d) = %d\n", x, clz(x));

    int r;
    uint32_t a;
    uint32_t b;
    a = UINT32_MAX; // 0xffffffff
    b = 1;
    r = udiv_latency(a, b);
    printf("udiv_latency(%8x, %8x) = %d\n", a, b, r);
    a = UINT32_MAX;
    b = 0;
    r = udiv_latency(a, b);
    printf("udiv_latency(%8x, %8x) = %d\n", a, b, r);
    a = 0;
    b = 1;
    r = udiv_latency(a, b);
    printf("udiv_latency(%8x, %8x) = %d\n", a, b, r);
    a = 0;
    b = UINT32_MAX;
    r = udiv_latency(a, b);
    printf("udiv_latency(%8x, %8x) = %d\n", a, b, r);

    int c;
    int d;
    c = INT32_MAX; // 0x7fffffff
    d = 1;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = INT32_MAX;
    d = 0;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = 0;
    d = 1;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = 0;
    d = INT32_MAX;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = UINT32_MAX; // 0xffffffff
    d = 1;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = UINT32_MAX;
    d = 0;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = 0;
    d = 1;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = 0;
    d = INT32_MIN;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = INT32_MIN; // 0x7fffffff
    d = 1;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = INT32_MIN;
    d = 0;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = 0;
    d = 1;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
    c = 0;
    d = INT32_MIN;
    r = sdiv_latency(c, d);
    printf("sdiv_latency(%8x, %8x) = %d\n", c, d, r);
}
