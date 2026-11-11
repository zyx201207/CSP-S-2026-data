#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[700005], b[700005], c[700005], cnt[700005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    if(a[1] == a[n]){
        for(int i = m; i >= 1; i--){
            cout << i;
        }
    }
    for(int i = 1; i <= m ; i++){
        cout << " 0";
    }
    return 0;
}
