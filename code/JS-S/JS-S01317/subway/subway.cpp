#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;
const int M = 5e2 + 5;
int c, n, m, d, q;
struct node{
    int v, w;
};
vector<node> g[N * 2];
int w[N], cnt;
int dp[M][M];

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    for(int i = 1; i <= 500; i++){
        for(int j = 1; j <= 500; j++){
            dp[i][j] = 1e18;
        }
    }

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }

    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++){
            int v, lll;
            cin >> v >> lll;
            g[v].push_back({i, lll});
        }
    }

    for(int i = 1; i <= m; i++){
        for(auto v1 : g[i]){
            for(auto v2 : g[i]){
                if(v1.v == v2.v) continue;
                dp[v1.v][v2.v] = v1.w + v2.w;
                dp[v2.v][v1.v] = v1.w + v2.w;
                dp[v1.v][v1.v] = 0;
                dp[v2.v][v2.v] = 0;
            }
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = 1e18;
        for(auto v1 : g[l]){
            for(auto v2 : g[r]){
                int op = v1.w + v2.w;
                ans = min(ans, dp[v1.v][v2.v] + op);
            }
        }
        cout << ans + w[l] + w[r] << "\n";
    }

    return 0;
}