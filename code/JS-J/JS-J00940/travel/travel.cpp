#include<bits/stdc++.h>

using namespace std;

int tong[5], tong2[5];

int main(){
    freopen("travel.in", "r", stdin);

    freopen("travel.out", "w", stdout);

    string ache, awei, bche, bwei;

    int sum = 0;

    tong[0] = 1;

    tong[1] = 1;

    tong[2] = 1;

    tong[3] = 0;

    tong[4] = 0;

    tong2[0] = 1;

    tong2[1] = 2;

    tong2[2] = 3;

    tong2[3] = 4;

    tong2[4] = 5;

    cin >> ache >> awei >> bche >> bwei;

    if (ache[0] == bche[0] && ache[1] == bche[1]){
        cout << 1;
        sum++;
        if (awei[0] == bwei[0] && awei[1] == bwei[1]){
            cout << 1;
            sum++;
            if (tong[awei[2] - 'A'] == tong[bwei[2] - 'A']){
                cout << 1;
                sum++;
                if (abs(tong2[awei[2] - 'A'] - tong2[bwei[2] - 'A']) <= 1){
                    cout << 1;
                    sum++;
                }
            }
        }
    }

    for (int i = 0; i < 4 - sum; i++){
        cout << 0;
    }
    return 0;
}
