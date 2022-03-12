#include <stdio.h>
#include <assert.h>

int add(int x, int y);

int main(void) {
    
    assert(add(4, 5) == 9);
    puts("All tests successful.");
    return 0;
}

int add(int x, int y) {
    return x + y;
}