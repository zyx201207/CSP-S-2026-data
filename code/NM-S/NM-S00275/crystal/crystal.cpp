#include <bits/stdc++.h>
using namespace std;
int a[500005] = {},ans[500005] = {};

int dfs(int x, int now, int m, int num){
    if(now < 1){
        return num;
    }
    if(a[now] + m >= a[x]){
        return dfs(x, now - 1, m - (a[x] - a[now]), num + 1);
    }
    else{
        return num;
    }
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int maxn = 0;
    for(int i = 2;i <= n;i++){
        ans[i] = dfs(i, i - 1, m, 1);
        maxn = max(maxn, ans[i]);
    }
    cout << maxn;
    return 0;
}