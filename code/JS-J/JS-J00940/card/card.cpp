#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    freopen("card.in", "r", stdin);

    freopen("card.out", "w", stdout);

    int n, m;

    cin >> n >> m;

    int tong[m];

    int a[n];

    for (int i = 0; i < m; i++){
        tong[i] = 0;
    }

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            tong[a[j]]++;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = i - 1; j <= 0; j--){
            if (a[i] == a[j]){
                for (int z = j + 1; z < i; z++){
                    tong[a[z]]--;
                }
                break;
            }
        }
    }

    for (int i = 0; i < m; i++){
        cout << tong[i] << ' ';
    }

    return 0;
}
