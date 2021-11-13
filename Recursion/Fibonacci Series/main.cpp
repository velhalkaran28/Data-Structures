#include <iostream>

using namespace std;

int fibIterative(int n) {
    int t0=0, t1=1, s=0, i;
    if (n <= 1)
        return n;
    for (i = 2; i <=n; i++){
        s = t0+t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n-2) + fibRecursive(n-1);
}

int f[20];
int fibRecursiveMemoization(int n) {
    if (n <= 1) {
        f[n] = n;
        return n;
    }
    if (f[n-2] == -1)
        f[n-2] = fibRecursiveMemoization(n-2);
    if (f[n-1] == -1)
        f[n-1] = fibRecursiveMemoization(n-1);
    f[n] = f[n-2] + f[n-1];
    return f[n-2] + f[n-1];
}
int main()
{
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    int result = fibIterative(n);
    cout<<"Result of Fib Series using Iteration: "<<result<<endl;
    result = fibRecursive(n);
    cout<<"Result of Fib Series using Recursion: "<<result<<endl;
    for (int i=0; i<20; i++){
        f[i] = -1;
    }
    result = fibRecursiveMemoization(n);
    cout<<"Result of Fib Series using Recursion + Memoization = "<<result<<endl;
    return 0;
}
