#include <iostream>
#include <iomanip>

using namespace std;

int taylorRecursion(int x, int n) {
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    r = taylorRecursion(x, n-1);
    p = p * x;
    f = f * n;
    return r+p/f;

}

int taylorHornerRuleRecursion (int x, int n) {
    static int s = 1;
    if (n == 0)
        return s;
    s = 1+x/n * s;
    return taylorHornerRuleRecursion(x,n-1);
}

int taylorHornerRuleIterative (int x, int n) {
    int s = 1;
    for (;n>0;n--) {
        s = 1+x/n * s;
    }
    return s;
}
int main()
{
    cout<<setprecision(15);
    double taylorResult = taylorRecursion(1,10);
    cout<<" Taylor Series result = "<<setprecision(5)<<taylorResult<<endl;
    double taylorHornerRuleRecursionResult = 0.00000000;
    taylorHornerRuleRecursionResult = taylorHornerRuleRecursion(1,10);
    cout<<"Taylor Horner Rule Recursion = "<<taylorHornerRuleRecursionResult<<endl;
    double taylorHornerRuleIteration = taylorHornerRuleIterative(1,10);
    cout<<"Taylor Horner Rule Iteration = "<<taylorHornerRuleIteration<<endl;
    return 0;
}
