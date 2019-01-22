#include <iostream>

using namespace std;

void enter(int[], int);

void print(int[], int);

void QuickSort(int[],int,int);

int main() {
    int n;

    cin >> n;

    int array[n];

    enter(array,n);
    print(array,n);

    QuickSort(array,0,n - 1);

    print(array,n);
    return 0;
}

void enter(int ar[], int size)
{
    for(int i = 0; i < size; i++)
    {
        ar[i] = rand() % 30;
    }
}

void print(int ar[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << ar[i] << ' ';
    }

    cout << endl;
}

void QuickSort(int array[], int L, int R)
{
    int x;
    int b, i, j;

    x = array[(L + R) / 2];
    i = L; j = R;

    while(i < j)
    {
        while(array[i] < x)
        {
            i++;
        }

        while(array[j] > x)
        {
            j--;
        }

        if(i <= j)
        {
            b = array[i];
            array[i] = array[j];
            array[j] = b;
            i++;
            j--;
        }
    }


    if(L < j) QuickSort(array,L,j);

    if(i < R) QuickSort(array,i,R);
}