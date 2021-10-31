#include <iostream>

using namespace std;

int sumRecursion(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return sumRecursion(n-1)+n;
    }
}

int sumLoop(int n) {
    int sum = 0;
    for (int i=1; i <=n; i++)
        sum += i;
    return sum;
}

int sumFormula(int n) {
    return n*(n+1)/2;
}
int main()
{
    int n;
    cout<<"Enter the nth number:"<<endl;
    cin>>n;
    int sum = 0;
    int sumloop = 0;
    int sumUsingFormula = 0;
    sum = sumRecursion(n);
    cout<<"Sum: "<<sum<<endl;
    sumloop = sumLoop(n);
    cout<<"Sum using loop: "<<sumloop<<endl;
    sumUsingFormula = sumFormula(n);
    cout<<"Sum using formula: "<<sumUsingFormula;
    return 0;
}
