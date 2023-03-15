#include "stdio.h"

typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void* x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_short(short val) {
    show_bytes((byte_pointer) &val, sizeof(short));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int* pval = &ival;
    short sval = (short) ival;
    short minus_sval = -1 * sval;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
    show_short(sval);
    show_short(minus_sval);
}

int main() {
    test_show_bytes(12345);
}
