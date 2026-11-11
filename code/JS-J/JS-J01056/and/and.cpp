#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010], b[200010][35], len[200010], dp[2010][2010][35], ans;
bool vis[35];
int dfs(int p, int c, int x){
    if(c == m) return x;
    if(c + (n - p + 1) < m || c > m || p > n) return 0;
    if(dp[p][c][x] != -1) return dp[p][c][x];
    int res = max(dfs(p + 1, c, x), dfs(p + 1, c + 1, x & a[p]));
    return dp[p][c][x] = res;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = a[i]; j != 0; j /= 2) b[i][++len[i]] = j % 2;
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0, (1 << n) - 1);

    return 0;
}
