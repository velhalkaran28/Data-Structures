#include <iostream>

using namespace std;

int factRecursion(int n) {
    if (n == 0)
        return 1;
    else
        return factRecursion(n-1)*n;
}

int factLoop(int n) {
    int fact = 1;
    for (int i=1;i<=n;i++)
        fact *= i;
    return fact;
}
int main()
{
    int n;
    cout << "Enter the nth number: "<<endl;
    cin>>n;
    int factR = 0;
    int factL = 0;
    factR = factRecursion(n);
    factL = factLoop(n);
    cout<<"Factorial using recursion: "<<factR<<endl;
    cout<<"Factorial using loop: "<<factL<<endl;
    return 0;
}
