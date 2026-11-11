#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
int n, k, c, T;
vector<int> g[N];
int dp[N][N][N][3][2][2];

void dfs(int x, int f){
    for(auto v : g[x]){
        if(v == f) continue;
        dfs(v, x);
    }
    for(int i = 0; i <= n; i++){
        for(auto v : g[x]){
            dp[x][i][0][0][0][0] = max(dp[v][i - 1][0][0][0][0] + 1, dp[x][i][0][0][0][0]);
            for(int op = 1; op <= 2; op++){
                for(int ij = op; ij <= k; ij++){
                    dp[x][i][ij][op][0][0] = max(dp[x][i][ij][op][0][0], dp[v][i][ij][op][0][0]);
                }
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> T;

    while(T--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            g[i].clear();
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, 0);
    }

    return 0;
}