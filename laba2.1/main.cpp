#include <iostream>
#include <math.h>

using namespace std;

const int m = 7, n = 5;

void enter(int array[m][n]);

void print(int array[m][n]);

void shella(int array[m][n]);

void find(int array[m][n]);

int main(){
    int a[m][n];
    enter(a);
    shella(a);
    print(a);
    find(a);
    return 0;
}

void shella(int array[m][n]){
    int i, j, k, step;
    int tmp;

    for(i = 0; i < n; i++) {

        for (step = n / 2; step > 0; step = step / 2) {

            for (j = step; j < m; j++) {
                tmp = array[j][i];

                for (k = j; k >= step; k = k - step) {
                    if (tmp > array[k - step][i])
                        array[k][i] = array[k - step][i];
                    else
                        break;
                }
                array[k][i] = tmp;
            }
        }
    }
}

void enter(int array[m][n])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            array[i][j] = rand() % 9;
        }
    }
}

void print(int array[m][n])
{
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }
}

void find(int array[m][n])
{
    int L, R, i;
    for(int j = 0;j < n;j++)
    {
        L = 0;
        R = m - 1;
        while(L <= R)
        {
            i = floor((L + R)/2);
            if(array[i][j] >= 0 && array[i][j] <= 5) break;
            else if(array[i][j] > 5) L = i + 1;
            else if(array[i][j] < 0)R = i - 1;
        }
        if(L <= R) cout << " column " << j + 1 << " and raw "<< i + 1 << endl;
        else cout << "Element not found on column" << endl;
    }
}
