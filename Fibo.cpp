#include <iostream>
#include <ctime>

using namespace std;


int fibDP(int n, int* dp) {
    if (dp[n] != 0) return dp[n];
    if (n == 0) return dp[n] = 0;
    if (n == 1 || n == 2) return dp[n] = 1;
    return dp[n] = fibDP(n - 1, dp) + fibDP(n - 2, dp);
}

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int valSeq[] = {10, 20, 30, 40, 70, 100};
    int size = sizeof(valSeq) / sizeof(valSeq[0]);

    cout << "WITH DP:\n";
    for (int i = 0; i < size; i++) {
        int dp[105] = {0};
        clock_t start = clock();
        fibDP(valSeq[i], dp);
        clock_t end = clock();

        double duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Fibonacci ke-" << valSeq[i] << ", Running time: " << duration * 1000 << " ms" << endl;
        clock_t reset = clock();
    }

    cout << "\nWITHOUT DP:\n";
    for (int i = 0; i < size; i++) {
        clock_t start = clock();
         fib(valSeq[i]);
        clock_t end = clock();

        double duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Fibonacci ke-" << valSeq[i] << ", Running time: " << duration * 1000 << " ms" << endl;
        clock_t reset = clock();
    }

    return 0;
}
