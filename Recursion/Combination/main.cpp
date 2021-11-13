#include <iostream>

using namespace std;

int fact(int n) {
    if (n == 0)
        return 1;
    int fact = 1;
    while (n > 0) {
        fact = fact * n;
        n--;
    }
    return fact;
}

int combinationIterative(int n, int r) {
    // n!/r!(n-r)!
    int nFact=0, rFact=0, nMrFact=0;
    nFact = fact(n);
    rFact = fact(r);
    nMrFact = fact(n-r);
    int result = nFact / (rFact*nMrFact);
    return result;
}

int combinationRecursive(int n, int r) {
    // to understand this you will have to understand pascal's triangle.
    if (n==r || r==0)
        return 1;
    return combinationRecursive(n-1,r-1) + combinationRecursive(n-1,r);
}
int main()
{
    int n,r;
    cout << "Enter n:"<<endl;
    cin>>n;
    cout<<"Enter r: "<<endl;
    cin>>r;
    int res = combinationIterative(n,r);
    cout<<"Combination Iterative = "<<res<<endl;
    res = combinationRecursive(n,r);
    cout<<"Combination Recursive = "<<res<<endl;
    return 0;
}
