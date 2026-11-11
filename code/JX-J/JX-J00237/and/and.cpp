#include<bits/stdc++.h>
using namespace std;
int n, r, f;
int a[2000005];
long long b[2000005];
void dfs(int p, int e, long long q){
    if(p > n){
        return;
    }
    if(e == r){
        b[++f] = q;
        return;
    }
    for(int i = p + 1; i <= n; i++){
        dfs(i, e + 1, q & a[i]);
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dfs(1, 0, 268435455);
    long long maxn = -1;
    for(int i = 1;i <= f; i++){
        maxn = max(b[i], maxn);
    }
    cout << maxn;
    return 0;
}
