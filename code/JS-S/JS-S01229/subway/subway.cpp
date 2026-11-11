#include <bits/stdc++.h>//read for 15:18
using namespace std;
#define endl '\n'
const int N = 505;
const int M = 1e3 + 10;
#define int long long

int c, n, m, d, Q;
int w[M];
int dp[M][M];
int k;
int a[M], t[M];

void solve(int x){
    for(int i = 1; i <= k; i ++){
        for(int j = 1; j <= k; j ++){
            if(i == j) {
                dp[i][i] = min(dp[i][i], t[i]);
                continue;
            }
            int u = a[i];
            int v = a[j];
            if(dp[u][v] > t[i] + t[j]){
                // id[u][v] = x;
                dp[u][v] = t[i] + t[j];
                dp[v][u] = min(dp[v][u], dp[u][v]);
            }
        }
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= k; j ++){//zhuan yi dian
            int mid = a[j];
            for(int p = 1; p <= k; p ++){
                int to = a[p];
                dp[i][to] = min(dp[i][to], dp[i][mid] + t[j] + t[p]);
                dp[to][i] = min(dp[i][to], dp[to][i]);
            }
        }
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1; i <= m; i ++){
        cin >> w[i];
    }
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= m; j ++)
            dp[i][j] = (long long)(1e12 + 1ll);
    for(int i = 1; i <= n; i ++){
        cin >> k;
        for(int j = 1;j <= k; j ++){
            cin >> a[j] >> t[j];
        }
        solve(i);
    }
    // return 0;
    while(Q --){
        int aa, bb;
        cin >> aa >> bb;
        if(aa == bb){
            cout << 0 << endl;
            continue;
        }
        cout << min(dp[aa][bb], dp[bb][aa]) + w[aa] + w[bb] << endl;
    }
    return 0;
}
//duancuowu shishenme a aaaaaaa 
//