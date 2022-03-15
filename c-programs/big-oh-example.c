#include <string.h>

// This will run a constant time, independent of the size of a dataset.
void o_1(char arr[], char * c) {
    
    char temp = arr[0];
    arr[0] = *c;
    *c = temp;
}

// This runs n times. So if the size of the array (n) = 100, this runs 100 times. If n = 1 million, this runs 1 million times.
int o_n(char arr[]) {
    
    int sum = 0;
    int n = strlen(arr); // Corrected from the videos.
    for(int i = 0;i < n;i++) {
        sum += arr[i];
    }
    return sum;
}

// This is also O(n) but it technically runs O(1/2 * n) times. However for Big-Oh, we don't care about the constant 1/2. So it's still O(n).
int o_n_example2(char arr[]) {
    int sum = 0;
    int n = strlen(arr); // Corrected from the videos.
    for(int i = 0;i < n / 2;i++) {
        sum += arr[i];
    }
    return sum;
}

// This is also O(n) but it technically runs O(2n) times. However, similarly, we don't care about the constant 2. Thus it's still O(n).
int o_n_example3(char arr[]) {
    int sum = 0;
    int n = strlen(arr); // Corrected from the videos.
    for(int i = 0;i < n;i++) {
        sum += arr[i];
    }
    
    for(int i = 0;i < n;i++) {
        sum += arr[i];
    }
    
    return sum;
}

// This is O(n^2) time. See how there's 2 nested for loops both running up to n? This is also Selection Sort.
void o_n2(char arr[]) {
    int i, j, min_idx;
    char temp;
    int n = strlen(arr); // Corrected from the videos.
  
    // One by one move boundary of unsorted subarray.
    for (int i = 0;i < n - 1;i++)
    {
        // Find the minimum element in unsorted array.
        min_idx = i;
        for (int j = i + 1;j < n - 1;j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element.
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// This is exponential time. Don't write code this slow!
int o_2n(int num) {
    if (num <= 1) {
        return num;
    }
    return o_2n(num - 2) + o_2n(num - 1);
}

// This is factorial time. Please for the sake of all that is Computer Science, don't write code this slow!
void nFacRuntimeFunc(int n) {
    for(int i=0; i<n; i++) {
        nFacRuntimeFunc(n-1);
    }
}

// This is O(logn) time. Notice how for each iteration, i multiplies by 2 instead of incrementing.
int o_logn(int n) {
    
    int sum = 0;
    for(int i = 1;i < n;i *= 2) {
        sum += i;
    }
    
    return sum;
}

// Also O(logn). This is also binary search. If you analyze the code, you'll notice the amount of data we iterate through is cut in half for each iteration.
// Note about binary search: the array must be sorted in order for it to work.
int o_logn_example2(char arr[], char x) {
    
    int l = 0, r = strlen(arr);
    while (l <= r) {
        int m = l + (r - l) / 2;
        // Check if x is present at mid.
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half.
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half.
        else
            r = m - 1;
    }
 
    // if we reach here, then element was not present.
    return -1;
}

// Here's O(n logn) time. This is essentially like having an O(logn) loop nested in an O(n) loop.
int o_nlogn(int n) {
    
    int sum = 0;
    for(int i = 0;i < n;i++) {
        
        for(int j = 1;j < n;j *= 2) {
            sum += j;
        }
    }
    
    return sum;
}

int main(void) {
    return 0;
}