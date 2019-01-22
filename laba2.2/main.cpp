#include <iostream>
#include <jansson.h>


using namespace std;

const int m = 8, n = 7;

void enter(int array[m][n]);

void print(int array[m][n]);

void vstavka1(int array[m][n]);

void vstavka2(int array[m][n]);

void vstavka3(int array[m][n]);

void vstavka4(int array[m][n]);

void vubir(int array[m][n]);

void obmin1(int array[m][n]);

void obmin2(int array[m][n]);

void obmin3(int array[m][n]);

void obmin4(int array[m][n]);

void shella(int array[m][n]);

int main() {
    int a[m][n];

    enter(a);
    print(a);

    cout << endl << endl;

    vstavka1(a);
//    vstavka2(a);
//  vstavka3(a);
//    vstavka4(a);

//    vubir(a);

//    obmin1(a);
//    obmin2(a);
//    obmin3(a);
//    obmin4(a);
//    shella(a);

    print(a);

    return 0;
}

void enter(int array[m][n]){
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            array[i][j] = rand() % 9;
        }
    }
}

void print(int array[m][n]){
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }
}

void vstavka1(int array[m][n]){
    int i, j, k, l, b;

    for(i = 0; i <= m - 1; i++) {

        for (j = 1; j <= n - 1; j++) {

            b = array[i][j];
            l = 0;

            while (b > array[i][l]) l++;

            for (k = j - 1; k >= l; k--) array[i][k + 1] = array[i][k];

            array[i][l] = b;
        }
    }
}

void vstavka2(int array[m][n]){
    int i, j, k, b;

    for(i = 0; i <= m - 1; i++) {

        for (j = 0; j <= n - 1; j++) {

            b = array[i][j];
            k = j;

            while (k > 0 && b < array[i][k - 1]) {
                array[i][k] = array[i][k - 1];
                k--;
            }

            array[i][k] = b;
        }
    }
}

void vstavka3(int array[m][n]){
    int i, j, k;

    for(i = 0; i <= m - 1; i++) {

        for (j = 2; j <= n-1; j++) {
            array[i][0] = array[i][j];
            k = j;

            while(array[i][0] < array[i][k - 1]){
                array[i][k] = array[i][k-1];
                k--;
            }

            array[i][k] = array[i][0];
        }

    }
}

void vstavka4(int array[m][n]){
    int i, j, k, R, l, L, x;

    for(i = 0; i <= m -1; i++){

        for(j = 1; j <= n - 1; j++){

            x = array[i][j];
            L = 0;
            R = j;

            while(L < R){
                l = (L + R)/2;

                if(array[i][l] <= x) L = l + 1;
                else R = l;
            }

            for(k = j - 1; k >= R; k--) array[i][k + 1] = array[i][k];

            array[i][R] = x;
        }

    }
}

void vubir(int array[m][n]){
    int i, j, S, jmin;
    int min;

    for(i = 0; i <= m - 1; i++) {

        for (S = 0; S <= n - 2; S++) {
            min = array[i][S];
            jmin = S;

            for (j = S + 1; j <= n - 1; j++) {
                if(array[i][j] < min){
                    min = array[i][j];
                    jmin = j;
                }
            }
            array[i][jmin] = array[i][S];
            array[i][S] = min;
        }
    }
}

void obmin1(int array[m][n]){
    int b, i, j, R;

    for(i = 0; i <= m - 1; i++){

        for(R = n - 1; R >= 1; R--){

            for(j = 0; j <= R - 1;j++){
                if(array[i][j] > array[i][j+1]) {
                    b = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = b;
                }
            }
        }
    }
}

void obmin2(int array[m][n]){
    int i, j, R, b;
    bool f;

    for(i = 0; i <= m -1; i++){
        R = n -1;
        f = true;

        while(f == true){
            f = false;

            for(j = 0; j <= R - 1;j++){
                if(array[i][j] > array[i][j+1]){
                    b = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = b;
                    f = true;
                }
            }
        }
    }
}

void obmin3(int array[m][n]){
    int b, i, j, k, R;
    for(i = 0; i <= m -1; i++){
        R = n - 1;

        while(R > 0){
            k = 0;

            for(j = 0; j <= R - 1; j++){
                if(array[i][j] > array[i][j+1]){
                    b = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = b;
                    k = j;
                }
            }

            R = k;
        }
    }
}

void obmin4(int array[m][n]){
    int i, j, k, L, R, b;
    for(i = 0; i <= m - 1; i++){
        L = 0;
        R = n - 1;
        k = 0;

        while(L < R){

            for(j = L; j <= R - 1; j++){
                if(array[i][j] > array[i][j+1]){
                    b = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = b;
                    k = j;
                }
            }
            R = k;

            for(j = R - 1; j >= L; j--){
                if(array[i][j] > array[i][j+1]){
                    b = array[i][j];
                    array[i][j] = array[i][j + 1];
                    array[i][j + 1] = b;
                    k = j;
                }
            }

            L = k + 1;
        }
    }
}

void shella(int array[m][n]){
    int i, j, k, step;
    int tmp;

    for(i = 0; i < m; i++) {
        for (step = n / 2; step > 0; step = step / 2) {
            for (j = step; j < n; j++) {
                tmp = array[i][j];
                for (k = j; k >= step; k = k - step) {
                    if (tmp < array[i][k - step])
                        array[i][k] = array[i][k - step];
                    else
                        break;
                }
                array[i][k] = tmp;
            }
        }
    }
}
