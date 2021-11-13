#include <iostream>

using namespace std;

int power(int m, int n) { // time complexity O(n)
    if (n == 0)
        return 1;
    return m*power(m,n-1);
}

int power_Faster(int m, int n) { // time complexity O(log n)
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power_Faster(m*m,n/2);
    else
        return m* power_Faster(m*m,(n-1)/2);
}

int power_linear (int m, int n) { // time complexity - O(n)
    int sum = 1;
    if (m == 0)
        return 0;
    if (n == 0)
        return 1;
    for (int i=1; i <=n; i++) {
        sum = sum * m;
    }
    return sum;
}

int power_linear_faster (int m, int n) {
    int res = 1;
    if (m == 0)
        return 0;
    if (n == 0)
        return 1;
    while (n > 0) {
        if (n % 2 == 0) {
            m = m * m;
            n = n/2;
        }
        else {
           res = res * m;
           n = n-1;
        }
    }
    return res;
}

int power_linear_faster_forloop (int m, int n) {
    int res = 1;
    if (m == 0)
        return 0;
    if (n == 0)
        return 1;
    for (; true; ) {
        if (n <= 0)
            break;

        if (n % 2 == 0) {
            m = m * m;
            n = n/2;
        }
        else {
            res = res * m;
            n = n - 1;
        }
    }
    return res;
}
int main()
{
    int powerResult = power(2,9);
    cout<<"Result = "<<powerResult<<endl;
    int powerFastResult = power_Faster(2,9);
    cout<<"Power Fast Result = "<<powerFastResult<<endl;
    int powerLinearResult = power_linear(2,9);
    cout<<"Power Linear Result = "<<powerLinearResult<<endl;
    int powerLinearFasterResult = power_linear_faster(2,9);
    cout<<"Power linear faster result = "<<powerLinearFasterResult<<endl;
    int powerLinearFasterForLoopResult = power_linear_faster_forloop(2,9);
    cout<<"Power linear faster using for loop result = "<<powerLinearFasterForLoopResult;
    return 0;
}
