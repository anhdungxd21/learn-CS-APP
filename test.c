#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(char *start, int n){
    int i;
    for(i = 0; i <n; i++)
        printf(" %.2x ", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void inplace_swap(int *a, int *b){
    *b = *a ^ *b;
    *a = *a ^ *b;
    *b = *a ^ *b;
}

void reverse_array(int a[], int cnt){
    int first, last;
    for(first = 0, last = cnt-1; first <= last; first++, last--){
        if(first == last) break;
        inplace_swap(&a[first], &a[last]);

    }
}

int main (){
    short x = 12345;
    unsigned short mx = 53191;
    show_bytes((byte_pointer) &x, sizeof(short));
    show_bytes((byte_pointer) &mx, sizeof(short));
    printf(" %d ", sizeof(short));

    printf("%d", (short) mx);
    return 0;
}
