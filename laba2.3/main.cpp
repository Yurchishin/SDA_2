#include <iostream>
#include <cmath>

using namespace std;

double sum(int n);

double RecursDown(int n, int i,  double F, double sum);

double RecursUp(int n, int i,  double F);

double RecursUpDown(int n, int i,  double F);

int main() {
    int n;
    double res;
    cin >> n;

    res = sum(n);
    cout << "Result = " << res << endl << endl;

    res = RecursDown(n,2,1, 0);
    cout << "Recursion Down = " << res << endl << endl;

    res = RecursUp(n, 2, 1);
    cout << "Recursion Up = " << res << endl << endl;

    res = RecursUpDown(n, 2, 1);
    cout << "Recursion Up and Down = " << res << endl << endl;
    return 0;
}

double sum(int n)
{
    double res = 1, ar[1000];
    ar[1] = 1;
    for (int i = 2 ; i <= n; i++ ) {
        ar[i] = sqrt(ar[i-1] * log(i + 1));
        res  += ar[i];
    }
    return res;
}

double RecursDown(int n, int i,  double F, double sum)
{
    sum = sum + F;
    if (i <= n) sum = RecursDown(n, i + 1, sqrt(F * log(i + 1)), sum);
    return sum;
}

double RecursUp(int n, int i,  double F)
{
    double sum = 0;
    if (i <= n) sum += RecursUp(n, i + 1, sqrt(F * log(i + 1)));
    return sum + F;
}

double RecursUpDown(int n, int i,  double F)
{
    double sum = 0;
    sum = sum +  F;
    if (i <= n) sum += RecursUpDown(n, i + 1, sqrt(F * log(i + 1)));
    return sum;
}