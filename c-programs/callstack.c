int fib(int n) {
    if(n <= 1) {
        return 1;
    }
    int fib_1 = fib(n - 1);
    int fib_2 = fib(n - 2);
    return fib_1 + fib_2;
}

int foo(int x) {
    if(x < 5) {
        return 0;
    }
    
    return x + 2;
}

int bar(int x) {
    int y = 10;
    int z = foo(x);
    y += x * z;
    while(y < 20) {
        y += foo(x + y);
    }
    return y - x;
}