#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int dfs(int l, int r, int a[]){
    if((r - l) == 1){
        return a[l] & a[r];
    }
    for (int i = l; i <= r; i++){
        for (int j = l; j <= r; j++){
            return dfs(i, j, a);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, maxr = -1, a[MAXN];
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if((a[i] & a[j]) > maxr){
                maxr = a[i] & a[j];
            }
        }
    }
    cout << maxr;
    return 0;
}
