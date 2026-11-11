#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010;
int C, n, m, d, q;
int w[N], k[N], p[N];
int a[N][N], t[N][N];
vector <int> is[N];
vector<int> g[N];
bool vis[N];
void dfs(int start, int end, int sum, int &ans){
    
    if (start == end){
        ans = min(ans, sum);
        return;
    }
    if (!g[start].size()) return;
    for (auto u : g[start]){
        vis[start] = 1;
        if (vis[u]) continue;
        int minn = INT_MAX;
        for (int i = 0; i < is[u].size(); ++ i){
            for (int j = 0; j < is[start].size(); ++ j){
                if (is[u][i] == is[start][j]){
                    minn = min(is[u][i], is[start][j]);
                }
            }
        }
        int temp = sum + t[minn][start] + t[minn][u];
        dfs(u, end, temp, ans);
        vis[start] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> C >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++ i)
        cin >> w[i];
    for (int i = 1; i <= n; ++ i){ // i th ways
        cin >> k[i]; // ki subway stations
        for (int j = 1; j <= k[i]; ++ j){
            cin >> a[i][j] >> t[i][a[i][j]]; // j th subway station ; 
            int tmp = a[i][j];
            is[tmp].push_back(i);
            p[tmp] = i;
            if (j != 1){
                for (int k = 1; k < j; ++ k){
                    g[a[i][j]].push_back(a[i][k]);
                    g[a[i][k]].push_back(a[i][j]);
                }
            }
        }
    }
    while (q --){
        memset(vis, 0, sizeof vis);
        int x, y;
        cin >> x >> y;
        int ans = INT_MAX;
        dfs(x, y, w[x] + w[y], ans);
        cout << ans << endl;
    }
    return 0;
}