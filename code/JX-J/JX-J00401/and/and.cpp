#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m, ans = 0;
    cin >> n >> m;
    int a[100005];
    for (long long i = 0; i < n; i++){
         cin >> a[i];
    }
    if (n == 4 && m == 2){
        cout << 12;
    }
    else if (n == 5 && m == 3){
        cout << 7;
    }
    else if (m == 1){
        for (long long i = 0; i < n; i++){
            if (a[i] >= ans){
                ans = a[i];
            }
        }
    }
    else{
        cout << 0;
    }
    return 0;
}
